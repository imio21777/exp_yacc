# 如何运行这个实例？

1. 编写`example.l`词法文件

2. 编译`example.l`
    ```shell
    flex example.l
    gcc lex.yy.c -o a
    ```

3. 使用编译出来的程序，对`test.txt`做词法分析

    ```shell
    ./a < test.txt > myoutput.txt
    ```

对于上述流程我们编写了一个脚本，也可以直接运行这个脚本
```shell
bash run.sh
```