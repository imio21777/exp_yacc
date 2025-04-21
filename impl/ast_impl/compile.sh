    # 清理
    rm -f lex.yy.c yacc.tab.cpp yacc.tab.hpp parser *.o *.dot *.png

    # 生成代码 (Bison 可能生成 .cpp 和 .hpp)
    bison -d yacc.y -o yacc.tab.cpp --defines=yacc.tab.hpp
    flex -o lex.yy.c lex.l

    # 编译 (使用 g++)
    g++ -std=c++11 main.cpp yacc.tab.cpp lex.yy.c -o parser -lfl

    # （注意：文件名和 C++ 标准可能需要根据您的环境调整）