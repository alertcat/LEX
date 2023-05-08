x:=0.9
<=
<
___1
string
{
这是注释

comme
nt
}
1.5+3
program example(input, output);
    var x, y: integer;
    var str: string;
    function gcd(a, b: integer): integer;
        begin
            if b=0 then gcd:=a
            else gcd:=gcd(b, a mod b)
        end;
    begin
        read(x, y);
        write(gcd(x, y));
    end.
