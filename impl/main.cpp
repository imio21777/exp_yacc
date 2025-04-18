// main.cpp
#include <iostream>
#include <fstream>
#include "ast.h"

extern FILE* yyin;
extern int yyparse();
extern int yydebug;
extern std::unique_ptr<BaseAST> root;

int main(int argc, char* argv[]) {
    bool debug_mode = false;
    std::string input_file, output_file;

    // 命令行参数处理
    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        if (arg == "-d" || arg == "--debug") {
            debug_mode = true;
        } else if (arg == "-o" && i + 1 < argc) {
            output_file = argv[++i];
        } else if (arg[0] != '-') {
            input_file = arg;
        } else {
            std::cerr << "Unknown option: " << arg << std::endl;
            return 1;
        }
    }

    yydebug = debug_mode ? 1 : 0;

    if (!input_file.empty()) {
        yyin = fopen(input_file.c_str(), "r");
        if (!yyin) {
            std::cerr << "Cannot open input file: " << input_file << std::endl;
            return 1;
        }
    } else {
        yyin = stdin;
    }

    if (yyparse() != 0) {
        std::cerr << "Parsing failed." << std::endl;
        return 1;
    }

    // 打印 AST（DOT 格式）
    if (root) {
        std::ofstream out(output_file.empty() ? "ast.dot" : output_file);
        out << "digraph AST {\n";
        out << root->DumpDOT();
        out << "}\n";
        out.close();
        std::cout << "AST written to " << (output_file.empty() ? "ast.dot" : output_file) << std::endl;
    }

    if (yyin != stdin) fclose(yyin);
    return 0;
}