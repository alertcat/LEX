##说明
yacc.tab_copy.cpp没有使用
yacc.tab.cpp、yacc.tab.h是由语法分析器yacc生成的文件，需要和main.cpp链接到一起生成可执行文件，请按下列方法生成可执行文件

```shell
生成可执行文件：
$ g++ yacc.tab.cpp main.cpp -o 程序名称.exe

运行可执行文件：
$ .\程序名称.exe 要识别的文件名称.pas 0或1
示例：
$ .\test3.exe testd.pas 0
```
语法分析模块尚未全部做完，但基本功能已经实现

##2023/4/27更新
添加了语法错误报错，某些错误可导致语法树为空；
无法正常识别用单引号引用的单个字符，会报错.

##2023/5/2
运行文件夹中的test.exe可以查看c++版本，对应的源代码是test.cpp，可以不用管

更改了生成和执行可执行文件的步骤如下，例子中要测试的文件名为testd.pas，建议放在同.exe文件的相同路径下
```shell
$ g++ yacc.tab.cpp main.cpp -o test_5_2.exe 这里的test_5_2.exe文件名任意
$ .\test.exe testd.pas 0 这里的testd.pas表示输入的测试文件 0表示debug不输出,默认为0
```