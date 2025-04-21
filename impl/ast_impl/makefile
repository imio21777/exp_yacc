# Makefile for AST builder

# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wno-unused-function # Use C++11, enable warnings
LDFLAGS = -lfl # Link flex library

# Bison and Flex
BISON = bison
FLEX = flex

# Source files
YACC_SRC = yacc.y
LEX_SRC = lex.l
CPP_SRCS = main.cpp yacc.tab.cpp lex.yy.c # Bison generates .cpp, Flex generates .c

# Generated files
YACC_GEN_SRC = yacc.tab.cpp
YACC_GEN_HDR = yacc.tab.hpp # Bison uses .hpp with C++
LEX_GEN_SRC = lex.yy.c

# Executable name
TARGET = parser

# Default target
all: $(TARGET)

# Link the executable
$(TARGET): $(CPP_SRCS:.cpp=.o) $(LEX_GEN_SRC:.c=.o) # Link object files
	$(CXX) $(CXXFLAGS) $^ -o $(TARGET) $(LDFLAGS)

# Compile C++ sources (including generated yacc.tab.cpp)
%.o: %.cpp $(YACC_GEN_HDR) ast.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compile generated lex.yy.c (using C++ compiler)
%.o: %.c $(YACC_GEN_HDR) ast.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Generate parser source and header from Yacc file
$(YACC_GEN_SRC) $(YACC_GEN_HDR): $(YACC_SRC)
	$(BISON) -d $(YACC_SRC) -o $(YACC_GEN_SRC) --defines=$(YACC_GEN_HDR)

# Generate lexer source from Flex file
$(LEX_GEN_SRC): $(LEX_SRC) $(YACC_GEN_HDR) # Depends on Yacc header for tokens
	$(FLEX) -o $(LEX_GEN_SRC) $(LEX_SRC)

# Clean up generated files
clean:
	rm -f $(TARGET) *.o $(YACC_GEN_SRC) $(YACC_GEN_HDR) $(LEX_GEN_SRC) *.dot *.png yacc.output

.PHONY: all clean 