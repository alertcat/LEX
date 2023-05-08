%{
//
// Created by LSJ on 4/19/2023.
//
#include "yyheader.h"
//#include "Lexer.h"
#include "yacc.tab.h"

extern "C"{
    void yyerror(const char *s);
    int yyparse();
    int yylex();
    int yywrap();
    // vector<MyToken> yylex_init();
    // Lexer yylex_init();
}

void yyerror(const char *s, YYLTYPE *loc);
void yyerror(const char *s, int line, int col);
void yyerror(const char *s, int startLine, int startCol, int endLine, int endCol);

extern Lexer yyLexer;

bool isLexerInit = false;

//extern YYSTYPE yylval;

//bool haveSemanticError = false;

MyType* ParseTreeHead = NULL;

vector<string> syntaxErrorInformation;

%}
%locations

%token SINGLE_QUOTES
%token ARRAY
%token _BEGIN
%token CONST
%token DO
%token ELSE
%token END
%token FOR
%token FUNCTION
%token IF
%token NOT
%token OF
%token PROCEDURE
%token PROGRAM
%token THEN
%token TO
%token TYPE
%token VAR
%token READ
%token WRITE
%token UMINUS

%token AND
%token DIV
%token MOD
%token OR

%token INTEGER
%token REAL
%token CHAR
%token BOOLEAN

%token IDENTIFIER
%token FLOAT
%token INT
%token CHARACTER
%token LPAREN
%token RPAREN
%token LSQUAR
%token RSQUAR
%token COMMA
%token PERIOD
%token SEMICO
%token RANGEDOT

%token LESSEQ
%token MOREEQ
%token NOTEQ
%token LESS
%token MORE
%token EQUAL
%token ASSIGN
%token COLON

%left ADD
%left SUB
%left MULT
%left DIVIDE

%start programstruct

%%
programstruct:      program_head SEMICO program_body PERIOD{
                        ParseTreeHead = $$ = new MyType;
                        $$->name = "programstruct";
                        $$->children.push_back($1);
                        $$->children.push_back($2);
                        $$->children.push_back($3);
                        $$->children.push_back($4);
                    }|program_head error program_body PERIOD{//没有分号
                      ParseTreeHead = $$ = new MyType;
                      $$->name = "programstruct";
                      yyerror("missing a SEMICO here", @1.last_line, @1.last_column+1);
                    }|program_head SEMICO program_body error{//没有点号
                      ParseTreeHead = $$ = new MyType;
                      $$->name = "programstruct";
                      yyerror("missing a PERIOD here", @3.last_line, @3.last_column+1);
                    }|error SEMICO program_body PERIOD{//没有 program_head
                      ParseTreeHead = $$ = new MyType;
                      $$->name = "programstruct";
                      yyerror("missing a 'program_head' here", @1.first_line, @1.first_column, @1.last_line, @1.last_column);
                    }|program_head SEMICO error PERIOD{//没有 program_body
                      ParseTreeHead = $$ = new MyType;
                      $$->name = "programstruct";
                      yyerror("missing a 'program_body' here");
                    }|error program_head SEMICO program_body PERIOD{//program_head前有非法字符
                      ParseTreeHead = $$ = new MyType;
                      $$->name = "programstruct";
                      yyerror("invalid symbol before 'program_head'", @$.first_line, @$.first_column, @2.first_line, @2.first_column-1);
                    }|error program_head error program_body PERIOD{//program_head前包含非法字符,没有分号
                      ParseTreeHead = $$ = new MyType;
                      $$->name = "programstruct";
                      yyerror("invalid symbol before 'program_head' and missing a SEMICO here", @$.first_line, @$.first_column, @2.first_line, @2.first_column-1);
                    }|error program_head SEMICO program_body error{//program_head前包含非法字符,没有点号
                      ParseTreeHead = $$ = new MyType;
                      $$->name = "programstruct";
                      yyerror("invalid symbol before 'program_head' and missing a PERIOD here", @$.first_line, @$.first_column, @2.first_line, @2.first_column-1);
                    }|error program_head SEMICO error PERIOD{
                      ParseTreeHead = $$ = new MyType;
                      $$->name = "programstruct";
                      yyerror("invalid symbol before 'program_head' and missing a 'program_body' here", @$.first_line, @$.first_column, @2.first_line, @2.first_column-1);
                    };
program_head:       PROGRAM IDENTIFIER LPAREN idlist RPAREN{
                        $$ = new MyType;
                        $$->name = "program_head";
                        $$->children.push_back($1);
                        $$->children.push_back($2);
                        $$->children.push_back($3);
                        $$->children.push_back($4);
                        $$->children.push_back($5);
                    }|PROGRAM IDENTIFIER{
                        $$ = new MyType;
                        $$->name = "program_head";
                        $$->children.push_back($1);
                        $$->children.push_back($2);
                    }|PROGRAM error LPAREN idlist RPAREN{//缺少 IDENTIFIER
                        $$ = new MyType;
                        $$->name = "program_head";
                        yyerror("missing IDNETIFIER here", @1.last_line, @1.last_column+1);
                    }|PROGRAM IDENTIFIER error idlist RPAREN{//缺少 LPAREN
                        $$ = new MyType;
                        $$->name = "program_head";
                        yyerror("missing a LPAREN here", @4.first_line, @4.first_column-1);
                    }|PROGRAM IDENTIFIER LPAREN error RPAREN{//缺少 idlist
                        $$ = new MyType;
                        $$->name = "program_head";
                        yyerror("missing a 'idlist' here", @4.first_line, @4.first_column, @4.last_line, @4.last_column);
                    }|PROGRAM IDENTIFIER LPAREN idlist error{//缺少 RPAREN
                        $$ = new MyType;
                        $$->name = "program_head";
                        yyerror("missing a RPAREN here", @4.last_line, @4.last_column+1);
                    }|PROGRAM error{//缺少IDENTIFIER
                        $$ = new MyType;
                        $$->name = "program_head";
                        yyerror("missing a IDENTIFIER here", @1.first_line, @1.first_column, @1.last_line, @1.last_column);
                    };
program_body:       const_declarations var_declarations subprogram_declarations compound_statement{
                        $$ = new MyType;
                        $$->name = "program_body";
                        $$->children.push_back($1);
                        $$->children.push_back($2);
                        $$->children.push_back($3);
                        $$->children.push_back($4);
                    };
idlist:             idlist COMMA IDENTIFIER{
                        $$ = new MyType;
                        $$->name = "idlist";
                        $$->children.push_back($1);
                        $$->children.push_back($2);
                        $$->children.push_back($3);
                    }|IDENTIFIER{
                        $$ = new MyType;
                        $$->name = "idlist";
                        $$->children.push_back($1);
                    };
const_declarations: CONST const_declaration SEMICO{
                        $$ = new MyType;
                        $$->name = "const_declarations";
                        $$->children.push_back($1);
                        $$->children.push_back($2);
                        $$->children.push_back($3);
                    }|{
                        $$ = new MyType;
                        $$->name = "const_declarations";
                    }|CONST error SEMICO{//缺少const_declaration
                        $$ = new MyType;
                        $$->name = "const_declarations";
                        yyerror("missing a 'const_declarations' here", @2.first_line, @2.first_column, @2.last_line, @2.last_column);
                    }|CONST const_declaration error{//缺少SEMICO
                        $$ = new MyType;
                        $$->name = "const_declarations";
                        yyerror("missing a SEMICO here", @2.first_line, @2.first_column, @2.last_line, @2.last_column);
                    };
const_declaration:  const_declaration SEMICO IDENTIFIER EQUAL const_value{
                        $$ = new MyType;
                        $$->name = "const_declaration";
                        $$->children.push_back($1);
                        $$->children.push_back($2);
                        $$->children.push_back($3);
                        $$->children.push_back($4);
                        $$->children.push_back($5);
                    }|IDENTIFIER EQUAL const_value{
                        $$ = new MyType;
                        $$->name = "const_declaration";
                        $$->children.push_back($1);
                        $$->children.push_back($2);
                        $$->children.push_back($3);
                    }|const_declaration SEMICO IDENTIFIER EQUAL error{//缺少const_value
                        $$ = new MyType;
                        $$->name = "const_declaration";
                        yyerror("missing a 'const_value' here", @4.first_line, @4.first_column, @4.last_line, @4.last_column);
                    }|IDENTIFIER EQUAL error{//缺少const_value
                        $$ = new MyType;
                        $$->name = "const_declaration";
                        yyerror("missing a 'const_value' here", @3.first_line, @3.first_column, @3.last_line, @3.last_column);
                    }|const_declaration error IDENTIFIER EQUAL const_value{//缺少SEMICO
                        $$ = new MyType;
                        $$->name = "const_declaration";
                        yyerror("missing a SEMICO here", @1.first_line, @1.first_column, @1.last_line, @1.last_column+1);
                    }|const_declaration SEMICO IDENTIFIER error const_value{//缺少EQUAL
                        $$ = new MyType;
                        $$->name = "const_declaration";
                        yyerror("missing a EQUAL here", @3.first_line, @3.first_column, @3.last_line, @3.last_column);
                    }|IDENTIFIER error const_value{//缺少EQUAL
                        $$ = new MyType;
                        $$->name = "const_declaration";
                        yyerror("missing a EQUAL here", @2.first_line, @2.first_column, @2.last_line, @2.last_column);
                    };
const_value:        ADD INT{
                        $$ = new MyType;
                        $$->name = "const_value";
                        $$->children.push_back($1);
                        $$->children.push_back($2);
                    }|SUB INT{
                        $$ = new MyType;
                        $$->name = "const_value";
                        $$->children.push_back($1);
                        $$->children.push_back($2);
                    }|INT{
                        $$ = new MyType;
                        $$->name = "const_value";
                        $$->children.push_back($1);
                    }|ADD FLOAT{
                        $$ = new MyType;
                        $$->name = "const_value";
                        $$->children.push_back($1);
                        $$->children.push_back($2);
                    }|SUB FLOAT{
                        $$ = new MyType;
                        $$->name = "const_value";
                        $$->children.push_back($1);
                        $$->children.push_back($2);
                    }|FLOAT{
                        $$ = new MyType;
                        $$->name = "const_value";
                        $$->children.push_back($1);
                    }|SINGLE_QUOTES CHARACTER SINGLE_QUOTES{
                        $$ = new MyType;
                        $$->name = "const_value";
                        $$->children.push_back($1);
                        $$->children.push_back($2);
                        $$->children.push_back($3);
                    };
var_declarations:   VAR var_declaration SEMICO{
                        $$ = new MyType;
                        $$->name = "var_declarations";
                        $$->children.push_back($1);
                        $$->children.push_back($2);
                        $$->children.push_back($3);
                    }|{ 
                        $$ = new MyType;
                        $$->name = "var_declarations";
                    }|VAR error SEMICO{//缺少var_declaration
                        $$ = new MyType;
                        $$->name = "var_declaration";
                        yyerror("missing a 'var_declaration' here", @1.first_line, @1.first_column, @1.last_line, @1.last_column);
                    }|VAR var_declaration error{//缺少SEMICO
                        $$ = new MyType;
                        $$->name = "var_declarations";
                        yyerror("missing a SEMICO here", @2.last_line, @2.last_column+1);
                    };
var_declaration:    var_declaration SEMICO idlist COLON type{
                        $$ = new MyType;
                        $$->name = "var_declaration";
                        $$->children.push_back($1);
                        $$->children.push_back($2);
                        $$->children.push_back($3);
                        $$->children.push_back($4);
                        $$->children.push_back($5);
                    }|idlist COLON type{
                        $$ = new MyType;
                        $$->name = "var_declaration";
                        $$->children.push_back($1);
                        $$->children.push_back($2);
                        $$->children.push_back($3);
                    }|var_declaration error idlist COLON type{//缺少SEMICO
                        $$ = new MyType;
                        $$->name = "var_declaration";
                        yyerror("missing a SEMICO here", @1.last_line, @1.last_column+1);
                    }|var_declaration SEMICO idlist error type{//缺少COLON
                        $$ = new MyType;
                        $$->name = "var_declaration";
                        yyerror("missing a COLON here", @3.last_line, @3.last_column+1);
                    }|var_declaration SEMICO id_varpart COLON error{//缺少type
                        $$ = new MyType;
                        $$->name = "var_declaration";
                        yyerror("missing a 'type' here", @4.last_line, @4.last_column+1);
                    }|idlist COLON error{//缺少type
                        $$ = new MyType;
                        $$->name = "var_declaration";
                        yyerror("missing a 'type' here", @3.last_line, @3.last_column+1);
                    }|idlist error type{//缺少COLON
                        $$ = new MyType;
                        $$->name = "var_declaration";
                        yyerror("missing a COLON here", @1.last_line, @1.last_column+1);
                    };
type:               basic_type{
                        $$ = new MyType;
                        $$->name = "type";
                        $$->children.push_back($1);
                    }|ARRAY LSQUAR period RSQUAR OF basic_type{
                        $$ = new MyType;
                        $$->name = "type";
                        $$->children.push_back($1);
                        $$->children.push_back($2);
                        $$->children.push_back($3);
                        $$->children.push_back($4);
                        $$->children.push_back($5);
                        $$->children.push_back($6);
                    }|ARRAY error period RSQUAR OF basic_type{//缺少LSQURA
                        $$ = new MyType;
                        $$->name = "type";
                        yyerror("missing a LSQUAR here", @1.last_line, @1.last_column+1);
                    }|ARRAY LSQUAR period RSQUAR error basic_type{//缺少OF
                        $$ = new MyType;
                        $$->name = "type";
                        yyerror("missing a OF here", @4.last_line, @4.last_column+1, @6.first_line, @6.first_column-1);
                    }|ARRAY LSQUAR period RSQUAR OF error{//缺少basic_type
                        $$ = new MyType;
                        $$->name = "type";
                        yyerror("missing a 'type' here", @5.last_line, @5.last_column+1);
                    }|ARRAY error{//缺少ARRAY type
                      $$ = new MyType;
                      $$->name = "type";
                      yyerror("incomplete array type", &@$);
                    }|ARRAY LSQUAR error{//缺少ARRAY type
                        $$ = new MyType;
                        $$->name = "type";
                        yyerror("incomplete array type", &@$);
                    }|ARRAY LSQUAR period error{//缺少ARRAY type
                        $$ = new MyType;
                        $$->name = "type";
                        yyerror("incomplete array type", &@$);
                    };
basic_type:         INTEGER{
                        $$ = new MyType;
                        $$->name = "basic_type";
                        $$->children.push_back($1);
                    }|REAL{
                        $$ = new MyType;
                        $$->name = "basic_type";
                        $$->children.push_back($1);
                    }|BOOLEAN{
                        $$ = new MyType;
                        $$->name = "basic_type";
                        $$->children.push_back($1);
                    }|CHAR{
                        $$ = new MyType;
                        $$->name = "basic_type";
                        $$->children.push_back($1);
                    };
period:             period COMMA INT RANGEDOT INT{
                        $$ = new MyType;
                        $$->name = "period";
                        $$->children.push_back($1);
                        $$->children.push_back($2);
                        $$->children.push_back($3);
                        $$->children.push_back($4);
                        //$$->children.push_back($5);
                    }|INT RANGEDOT INT{
                        $$ = new MyType;
                        $$->name = "period";
                        $$->children.push_back($1);
                        $$->children.push_back($2);
                        $$->children.push_back($3);
                        //$$->children.push_back($4);
                    }|period error INT RANGEDOT INT{//缺少COMMA
                        $$ = new MyType;
                        $$->name = "period";
                        yyerror("missing a COMMA here", @1.last_line, @1.last_column+1);
                    }|period COMMA INT error INT{//缺少RANGEDOT
                        $$ = new MyType;
                        $$->name = "period";
                        yyerror("missing a RANGEDOT here", @3.last_line, @3.last_column+1);
                    };
subprogram_declarations:    subprogram_declarations subprogram SEMICO{
                        $$ = new MyType;
                        $$->name = "subprogram_declarations";
                        $$->children.push_back($1);
                        $$->children.push_back($2);
                        $$->children.push_back($3);
                    }|{
                        $$ = new MyType;
                        $$->name = "subprogram_declarations";
                    }|subprogram_declarations subprogram error{//缺少SEMICO
                        $$ = new MyType;
                        $$->name = "subprogram_declarations";
                        yyerror("missing a SEMICO here", @2.last_line, @2.last_column+1);
                    };
subprogram:         subprogram_head SEMICO subprogram_body{
                        $$ = new MyType;
                        $$->name = "subprogram";
                        $$->children.push_back($1);
                        $$->children.push_back($2);
                        $$->children.push_back($3);
                    }|subprogram_head error subprogram_body{//缺少SEMICO
                        $$ = new MyType;
                        $$->name = "subprogram";
                        yyerror("missing a SEMICO here", @1.last_line, @1.last_column+1);
                    };
subprogram_head:    PROCEDURE IDENTIFIER formal_parameter{
                        $$ = new MyType;
                        $$->name = "subprogram_head";
                        $$->children.push_back($1);
                        $$->children.push_back($2);
                        $$->children.push_back($3);
                    }|FUNCTION IDENTIFIER formal_parameter COLON basic_type{
                        $$ = new MyType;
                        $$->name = "subprogram_head";
                        $$->children.push_back($1);
                        $$->children.push_back($2);
                        $$->children.push_back($3);
                        $$->children.push_back($4);
                        $$->children.push_back($5);
                    }|FUNCTION error formal_parameter COLON basic_type{//缺少IDENTIFIER
                        $$ = new MyType;
                        $$->name = "subprogram_head";
                        yyerror("missing a IDENTIFIER here", @1.last_line, @1.last_column+1);
                    }|FUNCTION IDENTIFIER formal_parameter error basic_type{//缺少COLON
                        $$ = new MyType;
                        $$->name = "subprogram_head";
                        yyerror("missing a COLON here", @3.last_line, @3.last_column);
                    }|FUNCTION IDENTIFIER formal_parameter COLON error{//缺少basic_type
                        $$ = new MyType;
                        $$->name = "subprogram_head";
                        yyerror("missing a 'basic_type' here", @4.last_line, @4.last_column+1);
                    }|FUNCTION IDENTIFIER formal_parameter error{//缺少basic_type
                        $$ = new MyType;
                        $$->name = "subprogram_head";
                        yyerror("missing a 'basic_type' keyword here", @3.last_line, @3.last_column+1);
                    }|FUNCTION error{//缺少function_head
                        $$ = new MyType;
                        $$->name = "subprogram_head";
                        yyerror("incomplete function head", &@$);
                    }|PROCEDURE error{//缺少procedure_head
                        $$ = new MyType;
                        $$->name = "subprogram_head";
                        yyerror("incomplete procedure head", &@$);
                    };
formal_parameter:   LPAREN parameter_list RPAREN{
                        $$ = new MyType;
                        $$->name = "formal_parameter";
                        $$->children.push_back($1);
                        $$->children.push_back($2);
                        $$->children.push_back($3);
                    }|{
                        $$ = new MyType;
                        $$->name = "formal_parameter";
                    }|LPAREN error{//缺少parameter_list
                        $$ = new MyType;
                        $$->name = "formal_parameter";
                        yyerror("incomplete 'parameter_list' here", &@$);
                    }|LPAREN parameter_list error{//缺少RPAREN
                        $$ = new MyType;
                        $$->name = "formal_parameter";
                        yyerror("missing a RPAREN here", @2.last_line, @2.last_column+1);
                    };
parameter_list:     parameter_list SEMICO parameter{
                        $$ = new MyType;
                        $$->name = "parameter_list";
                        $$->children.push_back($1);
                        $$->children.push_back($2);
                        $$->children.push_back($3);
                    }|parameter{
                        $$ = new MyType;
                        $$->name = "parameter_list";
                        $$->children.push_back($1);
                    }|parameter_list error parameter{
                       $$ = new MyType;
                        $$->name = "parameter_list";
                        yyerror("missing a SEMICO here", @1.last_line, @1.last_column+1);
                    };
parameter:          var_parameter{
                        $$ = new MyType;
                        $$->name = "parameter";
                        $$->children.push_back($1);
                    }|value_parameter{
                        $$ = new MyType;
                        $$->name = "parameter";
                        $$->children.push_back($1);
                    };
var_parameter:      VAR value_parameter{
                        $$ = new MyType;
                        $$->name = "var_parameter";
                        $$->children.push_back($1);
                        $$->children.push_back($2);
                    }|VAR error{
                        $$ = new MyType;
                        $$->name = "var_parameter";
                        yyerror("incomplete 'value_parameter' here", &@$);
                    };
value_parameter:    idlist COLON basic_type{
                        $$ = new MyType;
                        $$->name = "value_parameter";
                        $$->children.push_back($1);
                        $$->children.push_back($2);
                        $$->children.push_back($3);
                    }|idlist error basic_type{
                        $$ = new MyType;
                        $$->name = "value_parameter";
                        yyerror("missing a COLON here", @1.first_line, @1.last_column+1);
                    }|idlist COLON error{
                        $$ = new MyType;
                        $$->name = "value_parameter";
                        yyerror("missing a 'basic_type' here", @2.last_line, @2.last_column+1);
                    }|idlist error{
                        $$ = new MyType;
                        $$->name = "value_parameter";
                        yyerror("missing a 'basic_type' here", @1.last_line, @1.last_column+1);
                    };
subprogram_body:    const_declarations var_declarations compound_statement{
                        $$ = new MyType;
                        $$->name = "subprogram_body";
                        $$->children.push_back($1);
                        $$->children.push_back($2);
                        $$->children.push_back($3);
                    };
compound_statement: _BEGIN statement_list END{
                        $$ = new MyType;
                        $$->name = "compound_statement";
                        $$->children.push_back($1);
                        $$->children.push_back($2);
                        $$->children.push_back($3);
                    }|_BEGIN statement_list error{
                        $$ = new MyType;
                        $$->name = "compound_statement";
                        yyerror("missing a END here", @2.last_line, @2.last_column+1);
                    };
statement_list:     statement_list SEMICO statement{
                        $$ = new MyType;
                        $$->name = "statement_list";
                        $$->children.push_back($1);
                        $$->children.push_back($2);
                        $$->children.push_back($3);
                    }|statement{
                        $$ = new MyType;
                        $$->name = "statement_list";
                        $$->children.push_back($1);
                    }|statement_list error statement{
                        $$ = new MyType;
                        $$->name = "statement_list";
                        yyerror("missing a SEMICO here", @1.last_line, @1.last_column+1);
                    };
statement:          variable ASSIGN expression{
                        $$ = new MyType;
                        $$->name = "statement";
                        $$->children.push_back($1);
                        $$->children.push_back($2);
                        $$->children.push_back($3);
                    }|procedure_call{
                        $$ = new MyType;
                        $$->name = "statement";
                        $$->children.push_back($1);
                    }|compound_statement{
                        $$ = new MyType;
                        $$->name = "statement";
                        $$->children.push_back($1);
                    }|IF expression THEN statement else_part{
                        $$ = new MyType;
                        $$->name = "statement";
                        $$->children.push_back($1);
                        $$->children.push_back($2);
                        $$->children.push_back($3);
                        $$->children.push_back($4);
                        $$->children.push_back($5);
                    }|FOR IDENTIFIER ASSIGN expression TO expression DO statement{
                        $$ = new MyType;
                        $$->name = "statement";
                        $$->children.push_back($1);
                        $$->children.push_back($2);
                        $$->children.push_back($3);
                        $$->children.push_back($4);
                        $$->children.push_back($5);
                        $$->children.push_back($6);
                        $$->children.push_back($7);
                        $$->children.push_back($8);
                    }|READ LPAREN variable_list RPAREN{
                        $$ = new MyType;
                        $$->name = "statement";
                        $$->children.push_back($1);
                        $$->children.push_back($2);
                        $$->children.push_back($3);
                        $$->children.push_back($4);
                    }|WRITE LPAREN expression_list RPAREN{
                        $$ = new MyType;
                        $$->name = "statement";
                        $$->children.push_back($1);
                        $$->children.push_back($2);
                        $$->children.push_back($3);
                        $$->children.push_back($4);
                    }|{
                        $$ = new MyType;
                        $$->name = "statement";
                    }|IF expression error statement else_part{
                        $$ = new MyType;
                        $$->name = "statement";
                        yyerror("missing a THEN here", @2.last_line, @2.last_column+1);
                    }|FOR IDENTIFIER error expression TO expression DO statement{
                        $$ = new MyType;
                        $$->name = "statement";
                        yyerror("missing a ASSIGN here", @2.last_line, @2.last_column+1);
                    }|FOR IDENTIFIER ASSIGN expression error expression DO statement{
                        $$ = new MyType;
                        $$->name = "statement";
                        yyerror("missing a TO here", @4.last_line, @4.last_column+1);
                    }|FOR IDENTIFIER ASSIGN expression TO expression error statement{
                        $$ = new MyType;
                        $$->name = "statement";
                        yyerror("missing a DO here", @6.last_line, @4.last_column+1);
                    };
variable_list:      variable_list COMMA variable{
                        $$ = new MyType;
                        $$->name = "variable_list";
                        $$->children.push_back($1);
                        $$->children.push_back($2);
                        $$->children.push_back($3);
                    }|variable{
                        $$ = new MyType;
                        $$->name = "variable_list";
                        $$->children.push_back($1);
                    };
variable:           IDENTIFIER id_varpart{
                        $$ = new MyType;
                        $$->name = "variable";
                        $$->children.push_back($1);
                        $$->children.push_back($2);
                    };
id_varpart:         LSQUAR expression_list RSQUAR{
                        $$ = new MyType;
                        $$->name = "id_varpart";
                        $$->children.push_back($1);
                        $$->children.push_back($2);
                        $$->children.push_back($3);
                    }|{
                        $$ = new MyType;
                        $$->name = "id_varpart";
                    }|LSQUAR error{
                        $$ = new MyType;
                        $$->name = "id_varpart";
                        yyerror("incomplete 'expression_list' here", &@$);
                    }|LSQUAR expression_list error{
                        $$ = new MyType;
                        $$->name = "id_varpart";
                        yyerror("missing a RSQUAR here", @2.last_line, @2.last_column+1);
                    };
procedure_call:     IDENTIFIER{
                        $$ = new MyType;
                        $$->name = "procedure_call";
                        $$->children.push_back($1);
                    }|IDENTIFIER LPAREN expression_list RPAREN{
                        $$ = new MyType;
                        $$->name = "procedure_call";
                        $$->children.push_back($1);
                        $$->children.push_back($2);
                        $$->children.push_back($3);
                        $$->children.push_back($4);
                    }|IDENTIFIER LPAREN expression_list error{
                        $$ = new MyType;
                        $$->name = "procedure_call";
                        yyerror("missing a RPAREN here", @3.last_line, @3.last_column+1);
                    };
else_part:          ELSE statement{
                        $$ = new MyType;
                        $$->name = "else_part";
                        $$->children.push_back($1);
                        $$->children.push_back($2);
                    }|{
                        $$ = new MyType;
                        $$->name = "else_part";
                    };
expression_list:    expression_list COMMA expression{
                        $$ = new MyType;
                        $$->name = "expression_list";
                        $$->children.push_back($1);
                        $$->children.push_back($2);
                        $$->children.push_back($3);
                    }|expression{
                        $$ = new MyType;
                        $$->name = "expression_list";
                        $$->children.push_back($1);
                    }|expression_list error expression{
                        $$ = new MyType;
                        $$->name = "expression_list";
                        yyerror("missing a COMMA here", @1.last_line, @1.last_column+1);
                    };
expression:         simple_expression rel_option simple_expression{
                        $$ = new MyType;
                        $$->name = "expression";
                        $$->children.push_back($1);
                        $$->children.push_back($2);
                        $$->children.push_back($3);
                    }|simple_expression{
                        $$ = new MyType;
                        $$->name = "expression";
                        $$->children.push_back($1);
                    };
simple_expression:  simple_expression add_option term{
                        $$ = new MyType;
                        $$->name = "simple_expression";
                        $$->children.push_back($1);
                        $$->children.push_back($2);
                        $$->children.push_back($3);
                    }|term{
                        $$ = new MyType;
                        $$->name = "simple_expression";
                        $$->children.push_back($1);
                    };
term:               term mul_option factor{
                        $$ = new MyType;
                        $$->name = "term";
                        $$->children.push_back($1);
                        $$->children.push_back($2);
                        $$->children.push_back($3);
                    }|factor{
                        $$ = new MyType;
                        $$->name = "term";
                        $$->children.push_back($1);
                    };
factor:             INT{
                        $$ = new MyType;
                        $$->name = "factor";
                        $$->children.push_back($1);
                    }|FLOAT{
                        $$ = new MyType;
                        $$->name = "factor";
                        $$->children.push_back($1);
                    }|CHARACTER{
                        $$ = new MyType;
                        $$->name = "factor";
                        $$->children.push_back($1);
                    }|variable{
                        $$ = new MyType;
                        $$->name = "factor";
                        $$->children.push_back($1);
                    }|IDENTIFIER LPAREN expression_list RPAREN{
                        $$ = new MyType;
                        $$->name = "factor";
                        $$->children.push_back($1);
                        $$->children.push_back($2);
                        $$->children.push_back($3);
                        $$->children.push_back($4);
                    }|LPAREN expression_list RPAREN{
                        $$ = new MyType;
                        $$->name = "factor";
                        $$->children.push_back($1);
                        $$->children.push_back($2);
                        $$->children.push_back($3);
                    }|SUB factor{
                        $$ = new MyType;
                        $$->name = "factor";
                        $$->children.push_back($1);
                        $$->children.push_back($2);
                    }UMINUS factor{
                        $$ = new MyType;
                        $$->name = "factor";
                        $$->children.push_back($1);
                        $$->children.push_back($2);
                    }|IDENTIFIER LPAREN expression_list error{
                        $$ = new MyType;
                        $$->name = "factor";
                        yyerror("missing a RPAREN here", @3.last_line, @3.last_column+1);
                    }|IDENTIFIER LPAREN error{
                        $$ = new MyType;
                        $$->name = "factor";
                        yyerror("missing 'expression_list' here", @2.last_line, @2.last_column+1);
                    }|LPAREN expression error{
                        $$ = new MyType;
                        $$->name = "factor";
                        yyerror("missing a RPAREN here", @2.last_line, @2.last_column+1);
                    };
rel_option:         LESSEQ{
                        $$ = new MyType;
                        $$->name = "rel_option";
                        $$->children.push_back($1);
                    }|MOREEQ{
                        $$ = new MyType;
                        $$->name = "rel_option";
                        $$->children.push_back($1);
                    }|NOTEQ{
                        $$ = new MyType;
                        $$->name = "rel_option";
                        $$->children.push_back($1);
                    }|LESS{
                        $$ = new MyType;
                        $$->name = "rel_option";
                        $$->children.push_back($1);
                    }|MORE{
                        $$ = new MyType;
                        $$->name = "rel_option";
                        $$->children.push_back($1);
                    }|EQUAL{
                        $$ = new MyType;
                        $$->name = "rel_option";
                        $$->children.push_back($1);
                    };
add_option:         ADD{
                        $$ = new MyType;
                        $$->name = "add_option";
                        $$->children.push_back($1);
                    }|OR{
                        $$ = new MyType;
                        $$->name = "add_option";
                        $$->children.push_back($1);
                    };
mul_option:         MULT{
                        $$ = new MyType;
                        $$->name = "mul_option";
                        $$->children.push_back($1);
                    }|DIVIDE{
                        $$ = new MyType;
                        $$->name = "mul_option";
                        $$->children.push_back($1);
                    }|DIV{
                        $$ = new MyType;
                        $$->name = "mul_option";
                        $$->children.push_back($1);
                    }|MOD{
                        $$ = new MyType;
                        $$->name = "mul_option";
                        $$->children.push_back($1);
                    }|AND{
                        $$ = new MyType;
                        $$->name = "mul_option";
                        $$->children.push_back($1);
                    };
%%

/*
void yyerror(const char* s){
    haveSemanticError = true;
    string errorInformation;
    errorInformation += string(s);
    //errorInformation += ", location: " + itos(yylineno-1) + "." + itos(yycolumn-yyleng);//添加错误位置
	syntaxErrorInformation.push_back(errorInformation);//存放错误信息
}
*/
void yyerror(const char* s){
  cout << "yyerror: Have error" << endl;
}

void yyerror(const char *s, YYLTYPE *loc){//处理单个字符的错误
	string errorInformation;
	errorInformation = "syntax error, " + string(s) + ", location: " + to_string(loc->first_line) + "." + to_string(loc->first_column) + "-" + to_string(loc->last_line) + "." + to_string(loc->last_column);
	syntaxErrorInformation.push_back(errorInformation);
}
void yyerror(const char *s, int line, int col){
    string errorInfo;
    errorInfo += string(s);
    cout << "yyerror: Have Error: " << errorInfo << " at: " << to_string(line) << ", " << to_string(col) << endl;
}
void yyerror(const char *s, int startLine, int startCol, int endLine, int endCol){
    string errorInfo;
    errorInfo += string(s);
    cout << "yyerror: Have Error: " << errorInfo << " at: " << to_string(startLine) << ":" << to_string(startCol) << ", " << to_string(endLine) << ":" << to_string(endCol) << endl;
}

int yylex(){
    MyToken c = yyLexer.getToken();
    yylval = new MyType;
    string tmpType = yylval->type = c.type;
    int tmpNum = c.lin;
    // yylval->linenum = tmpNum;
    yylval->linenum = c.lin;
    // cout << "yylex: " << yylval->linenum << " "<< yylval->type << " " << yylval->name << endl;
    cout << "yylex: " << yylval->linenum << " "<< yylval->type << " ";
    if(string *tmp = any_cast<string>(&(c.value))){
      yylval->name = *tmp;
      cout << *tmp << endl;
    }else if(float *tmp = any_cast<float>(&(c.value))){
      yylval->name = to_string(*tmp);
      cout << *tmp << endl;
    }else if(int *tmp = any_cast<int>(&(c.value))){
      yylval->name = to_string(*tmp);
      cout << *tmp << endl;
    }
    if(tmpType == "end"){
      // yylex_exit();
      return 0;
    }if(tmpType == "ARRAY"){
      return ARRAY;
    }if(tmpType == "_BEGIN"){
      return _BEGIN;
    }if(tmpType == "CONST"){
      return CONST;
    }if(tmpType == "DO"){
      return DO;
    }if(tmpType == "ELSE"){
      return ELSE;
    }if(tmpType == "FOR"){
      return FOR;
    }if(tmpType == "END"){
      return END;
    }if(tmpType == "FUNCTION"){
      return FUNCTION;
    }if(tmpType == "IF"){
      return IF;
    }if(tmpType == "NOT"){
      return NOT;
    }if(tmpType == "OF"){
      return OF;
    }if(tmpType == "PROCEDURE"){
      return PROCEDURE;
    }if(tmpType == "PROGRAM"){
      return PROGRAM;
    }if(tmpType == "RANGEDOT"){
      return RANGEDOT;
    }if(tmpType == "THEN"){
      return THEN;
    }if(tmpType == "TO"){
      return TO;
    }if(tmpType == "TYPE"){
      return TYPE;
    }if(tmpType == "VAR"){
      return VAR;
    }if(tmpType == "READ"){
      return READ;
    }if(tmpType == "WRITE"){
      return WRITE;
    }if(tmpType == "UMINUS"){
      return UMINUS;
    }if(tmpType == "AND"){
      return AND;
    }if(tmpType == "DIV"){
      return DIV;
    }if(tmpType == "MOD"){
      return MOD;
    }if(tmpType == "OR"){
      return OR;
    }if(tmpType == "INTEGER"){
      return INTEGER;
    }if(tmpType == "REAL"){
      return REAL;
    }if(tmpType == "CHAR"){
      return CHAR;
    }
    if(tmpType == "BOOLEAN"){
      return BOOLEAN;
    }
    if(tmpType == "IDENTIFIER"){
      return IDENTIFIER;
    }
    if(tmpType == "FLOAT"){
      // yylval->name = to_string(any_cast<float>(c.value));
      return FLOAT;
    }
    if(tmpType == "INT"){
      // yylval->name = to_string(any_cast<int>(c.value));
      return INT;
    }
    if(tmpType == "CHARACTER"){
      return CHARACTER;
    }
    if(tmpType == "LPAREN"){
      return LPAREN;
    }
    if(tmpType == "RPAREN"){
      return RPAREN;
    }
    if(tmpType == "LSQUAR"){
      return LSQUAR;
    }
    if(tmpType == "RSQUAR"){
      return RSQUAR;
    }
    if(tmpType == "COMMA"){
      return COMMA;
    }
    if(tmpType == "PERIOD"){
      return PERIOD;
    }
    if(tmpType == "SEMICO"){
      return SEMICO;
    }
    if(tmpType == "ADD"){
      return ADD;
    }if(tmpType == "SUB"){
      return SUB;
    }
    if(tmpType == "MULT"){
      return MULT;
    }if(tmpType == "DIVIDE"){
      return DIVIDE;
    }if(tmpType == "LESSEQ"){
      return LESSEQ;
    }if(tmpType == "MOREEQ"){
      return MOREEQ;
    }if(tmpType == "LESS"){
      return LESS;
    }if(tmpType == "MORE"){
      return MORE;
    }if(tmpType == "EQUAL"){
      return EQUAL;
    }if(tmpType == "ASSIGN"){
      return ASSIGN;
    }if(tmpType == "COLON"){
      return COLON;
    }if(tmpType == "SINGLE_QUOTES"){
      return SINGLE_QUOTES;
    }
    return 0;
}


int yywrap(){
  return 1;
}