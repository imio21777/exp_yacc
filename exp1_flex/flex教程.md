# Flex简易教程

编译器的第一阶段是读入`源代码`，然后把字符串转换为对应的`标记`。借助`Flex`工具，我们可以编写`正则表达式`从输入代码中扫描和匹配字符串。

## Flex文件结构
```flex
%option noyywrap
%{
声明
%}
辅助定义
%%
识别规则
%%
用户子程序
```

- 声明：该部分用于编写需要使用的头文件、全局变量等等，可以为空，代码语法同C。

- 辅助定义：该部分可以用一个名字来代表一个正则表达式，以便于后续规则的编写。特别地是，后面的辅助定义也可以用前面的辅助定义。。
    ```bash
    NAME EXPRESSION
    // 例如
    INTEGER [0-9]+
    IDENTIFER [a-zA-Z_][a-zA-Z0-9_]*
    ```
- 识别规则：该部分由正则表达式式和相应的动作组成。表示匹配到每个正则表达式之后，需要进行的操作。该部分的正则表达式可以使用辅助定义中的内容（需要加大括号，例如{NAME}表示名字为NAME的辅助定义）。
    ```
    EXPRESSION {
        CODE
    }
    // 例如
    {INTEGER} { 
        printf("INTEGER %s\n", yytext); 
    }
    ```

    其中，EXPRESSION表示正则表达式，CODE表示匹配到这个正则表达式之后需要进行的操作。CODE部分的代码为C代码。

- 用户子程序：该部分编写包括main函数在内的所有需要用到的函数。flex会将其插入到生成的C代码中。需要注意的是，main函数中需要调用yylex函数，执行正则表达式的匹配。对于文件的输入输出，仅需要讲yyin赋值为所需要处理的文件指针（可以是标准输入`stdin`），其余的yylex会自动处理


## 编译运行lex代码

编写完程序之后，使⽤如下指令运⾏flex：
```shell
flex example.l
gcc lex.yy.c -o a
```
上面的命令，会在当前文件夹生成词法分析的程序`a`

使用编译出来的程序，对`test.txt`做词法分析
```shell
./a < test.txt 
```

## 正则表达式

正则表达式的详细内容可以参考[正则表达式](https://tool.oschina.net/uploads/apidocs/jquery/regexp.html)


## 动作中可能会用到的全局变量

1. yytext：char *类型，指向当前正被某规则匹配的字符串。

2. yyleng：整型，存储yytext中字符串的长度。被匹配的串在yytext[0]～yytext[yyleng-1]中。

## 二义性

有时输入串中的字符可以与多条规则匹配，在这
种情况下，LEX有两个处理原则：

1. 能匹配最多字符的规则优先；

2. 若各规则匹配的字符数目相同，先给出的规则优先。
    
例如，给定规则如下：
```
void        {return T_Void;}
[A-Za-z]+   {return T_Identifier;}
```

那么，`void`将被识别为`T_Void`，`voida`将被识别为`T_Identifier`。
