# Flex实验

## 实验目标

借助`flex`⼯具实现⼀个词法分析器，从`SysY`源程序中识别出单词，记录其单词类别和单词值.

## 实验内容

同学们需要仔细阅读仓库中的[flex教程](./exp_flex.md)，并编写`SysY`语言的词法解析器。并使用自己编写的词法解析器解析[tests](./tests/)文件夹中的三个测试文件，并使用`diff`命令检查输出是否和标准输出匹配

参考资料：
1. [`flex`样例代码](./example/)
2. [`flex`简易教程](./flex教程.md)
3. [`flex`讲解PPT](./编译原理实验1.pptx)

## 输入输出要求

输入输出要求同词法分析实验，具体要求如下：

1. 类别码需按下表格式统一定义:

    | 单词名称 | 类别码 | 单词名称 | 类别码 | 单词名称 | 类别码 | 单词名称 | 类别码 | 
    | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- |
    | Ident | IDENFR | ! | NOT | * |	MULT | 	=	| ASSIGN |
    | IntConst | INTCON | && | AND | / | DIV | ; | SEMICN |
    | FormatString | STRCON	| \|\| | OR |	% |MOD	|, |	COMMA |
    | main | MAINTK	|while	|WHILETK|	<	|LSS|	(	|LPARENT|
    | const	|CONSTTK|	getint|	GETINTTK	|<=|	LEQ|	)|	RPARENT|
    | int |	INTTK|	printf	|PRINTFTK|	>	|GRE|	[	|LBRACK|
    | break |	BREAKTK|	return|	RETURNTK|	>=	|GEQ|	]	|RBRACK|
    | continue |	CONTINUETK	|+	|PLUS|	==	|EQL|	{	|LBRACE|
    | if | IFTK | - | MINU	|!=	|NEQ	|}	|RBRACE|
    | else | ELSETK	| void | VOIDTK |

2. 输出的结果文件中每行按如下方式组织：
    - 单词类别码 单词的字符/字符串形式(中间仅用一个空格间隔)


## 输入输出样例

测试程序输入
```
const int array[2] = {1,2};

int main(){
    int c;
    c = getint();
    printf("output is %d",c);
    return c;
}
```

词法分析输出
```
CONSTTK const
INTTK int
IDENFR array
LBRACK [
INTCON 2
RBRACK ]
ASSIGN =
LBRACE {
INTCON 1
COMMA ,
INTCON 2
RBRACE }
SEMICN ;
INTTK int
MAINTK main
LPARENT (
RPARENT )
LBRACE {
INTTK int
IDENFR c
SEMICN ;
IDENFR c
ASSIGN =
GETINTTK getint
LPARENT (
RPARENT )
SEMICN ;
PRINTFTK printf
LPARENT (
STRCON "output is %d"
COMMA ,
IDENFR c
RPARENT )
SEMICN ;
RETURNTK return
IDENFR c
SEMICN ;
RBRACE }

```


## 实验验收方式

本次实验采用线下验收的方式。同学们使用自己编写的词法分析器，分析tests文件夹中的测试样例，并和给定的答案做比对（提示：可以使用`linux`系统下的`diff`指令）。所有测试样例通过之后可以找助教验收