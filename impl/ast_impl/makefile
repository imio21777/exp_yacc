# Makefile for AST implementation

CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Wno-unused-function

FLEX = flex
BISON = bison

# 源文件和目标文件
SRCS = yacc.tab.c lex.yy.c
OBJS = yacc.tab.o lex.yy.o

all: parser

parser: $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

yacc.tab.o: yacc.tab.c yacc.tab.h ast.h
	$(CXX) $(CXXFLAGS) -c -o $@ $<

lex.yy.o: lex.yy.c yacc.tab.h ast.h
	$(CXX) $(CXXFLAGS) -c -o $@ $<

lex.yy.c: lex.l yacc.tab.h
	$(FLEX) $<

yacc.tab.c yacc.tab.h: yacc.y
	$(BISON) -d -v $<

clean:
	rm -f parser lex.yy.c yacc.tab.c yacc.tab.h ast.dot ast.png yacc.output *.o

.PHONY: all clean 