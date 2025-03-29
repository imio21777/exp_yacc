# yacc简易教程

`yacc`（Yet Another Compiler Compiler）是一个用于构建语法分析程序的工具。它根据用户提供的文法说明，基于 `LALR(1)` 分析算法，自动生成一个语法分析器，并在语法规则匹配成功时执行用户定义的语义动作。

## 1. yacc 文件结构

一个典型的 `yacc` 文件分为三个部分，格式如下：

```yacc
%{
声明
%}
辅助定义
%%
语法规则
%%
用户子程序
```

 - **声明（可选）**

    用于包含头文件、声明全局变量、辅助函数等。语法同 C 语言。在实验或项目中，可以将 `main` 函数也写在这里，作为一个可行的简化方式。

    ```c
    %{
    #include <stdio.h>
    #include <stdlib.h>
    void yyerror(const char *s);
    int yylex();
    %}
    ```

- **辅助定义（可选）**

    这一部分定义词法中的终结符、符号的优先级和结合性。常用关键字包括：
    - `%token`：定义终结符
    - `%left` / `%right` / `%nonassoc`：定义运算符优先级和结合性

    例如：

    ```yacc
    %token NUMBER PLUS MINUS TIMES DIVIDE
    %left PLUS MINUS
    %left TIMES DIVIDE
    ```

    > 💡 **注意**：和词法分析器结合时，词法分析器应返回这些终结符对应的 token，如 `return PLUS;`。

- **语法规则（必选）**

    这是 yacc 文件的核心，用于定义语言的文法。每个规则形式如下：

    ```yacc
    表达式: 表达式 PLUS 表达式 { /* 语义动作 */ }
        | 表达式 MINUS 表达式 { /* 语义动作 */ }
        | NUMBER
        ;
    ```

    语义动作写在大括号 `{}` 中，使用 `$1`, `$2`, ... 来访问匹配到的符号的语义值。可以在这里构造语法树、进行计算或执行语义检查等。

    > 建议：如果有规则匹配空串（即 ε），务必加注释标明，以免遗漏。

    ---

## 四则运算器示例

下面我们将一步步带领同学们构建一个四则运算器的语法分析器。四则运算器的语法规则如下:

```
E -> E + T | E - T | T
T -> T * F | E / T | F
F -> (E) | digit
```

1. 对于上述的语法规则，我们首先创建两个文件`lex.l`和`parser.y`


2. 在`parser.y`中，我们定义终结符DIGIT和优先级，
- **结合性：** `%left`表示后面的符号是左结合的，即解析`a + b + c`时，它会被解析为`(a + b) + c`。同理`%right`表示后面的符号是右结合的。而`%nonassoc`表示没有结合性
- **优先级：** 在声明结合性时，声明越靠下，其符号的优先级越高。在下面的例子中`*`的优先级就高于`+`，在同一行说明其优先级相同，即`+`和`-`的优先级相同

    ```
    # parser.y
    
    %{
    #include <stdio.h>
    #include <stdlib.h>

    int yylex();
    void yyerror(const char *s);
    %}

    %token DIGIT       // 定义终结符
    %left '+' '-'      // 定义结合性和优先级 
    %left '*' '/'

    %%

    %%

    void yyerror(const char *s) {
        fprintf(stderr, "Error: %s\n", s);
    }

    int main() {
        return yyparse();
    }
    ```

3. 编写`lex.l`文件，识别终结符DIGIT并返回。当`lex`和`yacc`一起使用时，`lex`就相当于是`yacc`的词法识别器，因此这时`lex.l`文件里就不需要`main`函数了。而且因为`lex.l`需要返回`parser.y`文件中定义的终结符，因此`lex.l`必须要包含`y.tab.h`文件。如下
    ```
    # lex.l:
    %option noyywrap
    %{
    #include "parser.tab.h"
    %}

    %%
    [0-9]+    { yylval = atoi(yytext); return DIGIT; }
    [+\-*/()] { return yytext[0]; }
    [ \t\n]   ; // 忽略空白字符
    .         { return yytext[0]; }
    %%
    ```
    注意：
    - 这里我们使用了`yylval`，`yylval`是词法分析器（`lex/flex`）和语法分析器（`yacc/bison`）之间传递“语义值”的变量。在上面的例子中，词法分析器看到数字，比如"42"，把这个"42"转换成整型`42`，放到`yylval`中，然后返回`DIGIT`给`yacc`。然后`yacc`程序就可以通过`$`取出终结符中的值.

    - `atoi`函数用于把文本转化为一个`int`


4. 编写`parser.y`中的文法规则
    ```
    %%
    R   : E         { $$ = $1; printf("%d\n", $$); }

    E   : E '+' T   { $$ = $1 + $3; }
        | E '-' T   { $$ = $1 - $3; }
        | T         { $$ = $1; }
    ;

    T   : T '*' F   { $$ = $1 * $3; }
        | T '/' F   {
                        if ($3 == 0) {
                            yyerror("divide by zero");
                            YYABORT;
                    }
                    $$ = $1 / $3;
                }
        | F         { $$ = $1; }
    ;

    F   : '(' E ')' { $$ = $2; }
        | DIGIT     { $$ = $1; }
    ;
    %%
    ```
    注意：

    - `$$` 表示当前非终结符的值；

    - `$1`, `$3` 表示规则右侧的第1、第3个符号的语义值；

    - 在上面的规则中，语义动作中用到了printf打印结果，也返回了值供父节点使用。

5. 编译运行
    ```bash
    bison -d parser.y      # 生成 parser.tab.c 和 parser.tab.h
    flex lex.l             # 生成 lex.yy.c
    gcc lex.yy.c parser.tab.c -o calc -lm

    ./calc < test.txt
    ```

## 进阶
### 1. 自定义终结符和非终结符的类型
刚才其实只使用了非常基础的数值运算做例子，因此这里我们没有定义非终结符的类型。
**通常，如果没有显示的定义，文法中出现的非终结符的类型都是`int`！包括`yylval`的类型也是`int`**。但是当我们有更复杂的需求时，可能需要非终结符包含更复杂的类型。此时我们可以使用`%union`。

例如，我们在`union`中定义下面的类型：
```yacc
%union {
    int ival;            // ival表示 int 类型
    float fval;          // fval 表示 float 类型
    char* sval;          // sval 表示 sval 类型
    struct Node* node;   // node 表示 自定义Node结构体类型
}
```
在上面的代码中，我们定义了4种类型，其中前三种是系统自带的类型，最后一种结构体是我们自定义的类型。因此如果我们需要使用`node`类型，我们就需要给出定义，例如：
```cpp
// 定义语法树结构
typedef struct Node {
    char op;
    struct Node* left;
    struct Node* right;
} Node;

Node* make_op(char op, Node* l, Node* r) {
    Node* n = malloc(sizeof(Node));
    n->op = op;
    n->left = l;
    n->right = r;
    return n;
}
```
然后我们就可以分别给终结符和非终结符标记类型，使用`<>`标记类型：

```yacc
%token <ival> DIGIT
%type  <node> expr term factor
```

这表示：

- `DIGIT` 这个终结符对应的是一个整数值（`ival`）
- `expr`、`term`、`factor` 是语法树节点类型（`node`）

然后你就可以在规则中写：
```
expr: expr '+' term   { $$ = make_op('+', $1, $3); }
    | expr '-' term   { $$ = make_op('-', $1, $3); }
    | term            { $$ = $1; }
;
```

### 2. yacc冲突处理规则

`yacc`语法分析时主要会出现两种冲突：
1. **归约-归约冲突（reduce/reduce）**：选择**文件中靠前**的产生式归约；
2. **移进-归约冲突（shift/reduce）**：选择**移进（shift）**。

**归约-归约冲突（Reduce/Reduce）**
假设我们写了下面两个产生式，它们都可以匹配单个 `a`：

```yacc
S: A
 | B
 ;

A: 'a' ;
B: 'a' ;
```

词法输入：`a`

yacc 会发现 `A` 和 `B` 都可以归约成 `S`，但不知道选哪个。这就是**归约-归约冲突**。 yacc 怎么做？

它会**选择先写的产生式**，也就是：

```yacc
S: A   ← 被选中！
```

所以最终会走 `S → A → 'a'`。

---

**移进-归约冲突（Shift/Reduce）**假设有下面的一个产生式
```yacc
%token ID

%%
stmt: ID           // 规则 1：把 ID 当成一个语句
    | stmt ID      // 规则 2：语句后接一个 ID（看起来像一个语句块）
    ;
```
输入：`x y`

yacc 在读完 `x` 后看到 `y`，此时可能会发生冲突：

- 归约 `x` 为 `stmt`（走规则 1）
- 还是继续读下一个 `ID`（尝试匹配 `stmt ID`，规则 2）？

这时就是**移进-归约冲突**。这里 yacc 怎么做？

**默认选择移进（shift）**，继续向后看，也就是先不归约，把 `y` 加进来，看能不能组成更长的句子。

所以这里会走 `stmt → stmt ID → x y`，避免了太早归约。

## 参考资料


