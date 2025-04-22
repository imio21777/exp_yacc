#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <memory>
#include <iostream>
#include <sstream>
#include <string>

// 全局节点ID计数器，用于生成唯一的节点标识
static int node_id_counter = 0;

// AST节点基类
class BaseAST {
public:
    int node_id;

    BaseAST() : node_id(NewNodeID()) {}
    virtual ~BaseAST() = default;
    
    virtual std::string DumpDOT() const = 0;

    virtual int GetNodeID() const { return node_id; }
    
    static int NewNodeID() {
        return node_id_counter++;
    }
};

// 类型枚举
enum Type {
    TYPE_INT,
    TYPE_VOID
};

// 编译单元AST节点
class CompUnitAST : public BaseAST {
private:
    int node_id;

public:
    std::vector<std::unique_ptr<BaseAST>> global_items; // 全局声明和函数定义
    std::unique_ptr<BaseAST> main_func_def;            // 主函数定义

    CompUnitAST() : node_id(NewNodeID()) {}

    std::string DumpDOT() const override {
        std::stringstream ss;
        
        // 定义此节点
        ss << "  node" << node_id << " [label=\"CompUnit\", shape=box, style=filled, fillcolor=lightblue];\n";
        
        // 输出全局项
        for (size_t i = 0; i < global_items.size(); ++i) {
            ss << "  node" << node_id << " -> node" << global_items[i]->GetNodeID() 
               << " [label=\"global_item" << i << "\"];\n";
            ss << global_items[i]->DumpDOT();
        }
        
        // 输出主函数
        if (main_func_def) {
            ss << "  node" << node_id << " -> node" << main_func_def->GetNodeID() 
               << " [label=\"main_func_def\"];\n";
            ss << main_func_def->DumpDOT();
        }
        
        return ss.str();
    }
};

// 声明AST节点
class DeclAST : public BaseAST {
private:
    int node_id;

public:
    enum DeclKind {
        CONST_DECL,
        VAR_DECL
    };

    DeclKind kind;
    std::unique_ptr<BaseAST> decl;  // 可以是 ConstDecl 或 VarDecl

    DeclAST() : node_id(NewNodeID()) {}

    std::string DumpDOT() const override {
        std::stringstream ss;
        
        ss << "  node" << node_id << " [label=\"Decl\", shape=box];\n";
        
        if (decl) {
            ss << "  node" << node_id << " -> node" << decl->GetNodeID() 
               << " [label=\"decl\"];\n";
            ss << decl->DumpDOT();
        }
        
        return ss.str();
    }
};

// 常量声明AST节点
class ConstDeclAST : public BaseAST {
private:
    int node_id;

public:
    Type type;
    std::string ident;
    int value;

    ConstDeclAST() : node_id(NewNodeID()) {}
    
    // 从C风格字符串构造
    ConstDeclAST(const char* id) : node_id(NewNodeID()), ident(id) {}

    std::string DumpDOT() const override {
        std::stringstream ss;
        
        std::string label = "ConstDecl\\nident: " + ident + 
                            "\\ntype: " + (type == TYPE_INT ? "int" : "void") +
                            "\\nvalue: " + std::to_string(value);
        
        ss << "  node" << node_id << " [label=\"" << label << "\", shape=box, style=filled, fillcolor=lightyellow];\n";
        
        return ss.str();
    }
};

// 变量声明AST节点
class VarDeclAST : public BaseAST {
private:
    int node_id;

public:
    Type type;
    std::string ident;
    std::unique_ptr<BaseAST> init_val; // 初始值，nullptr表示无初始值

    VarDeclAST() : node_id(NewNodeID()) {}
    
    // 从C风格字符串构造
    VarDeclAST(const char* id) : node_id(NewNodeID()), ident(id) {}

    std::string DumpDOT() const override {
        std::stringstream ss;
        
        std::string label = "VarDecl\\nident: " + ident + 
                            "\\ntype: " + (type == TYPE_INT ? "int" : "void");
        
        ss << "  node" << node_id << " [label=\"" << label << "\", shape=box, style=filled, fillcolor=lightgreen];\n";
        
        if (init_val) {
            ss << "  node" << node_id << " -> node" << init_val->GetNodeID() 
               << " [label=\"init_val\"];\n";
            ss << init_val->DumpDOT();
        }
        
        return ss.str();
    }
};

// 主函数定义AST节点
class MainFuncDefAST : public BaseAST {
private:
    int node_id;

public:
    std::unique_ptr<BaseAST> block;

    MainFuncDefAST() : node_id(NewNodeID()) {}

    std::string DumpDOT() const override {
        std::stringstream ss;
        
        ss << "  node" << node_id << " [label=\"MainFuncDef\\nint main()\", shape=box, style=filled, fillcolor=lightcoral];\n";
        
        if (block) {
            ss << "  node" << node_id << " -> node" << block->GetNodeID() 
               << " [label=\"block\"];\n";
            ss << block->DumpDOT();
        }
        
        return ss.str();
    }
};

// 函数定义AST节点
class FuncDefAST : public BaseAST {
private:
    int node_id;

public:
    Type return_type;               // 返回类型
    std::string ident;              // 函数名
    std::vector<std::unique_ptr<BaseAST>> params; // 参数列表
    std::unique_ptr<BaseAST> block; // 函数体

    FuncDefAST() : node_id(NewNodeID()) {}

    std::string DumpDOT() const override {
        std::stringstream ss;
        ss << "  node" << node_id << " [label=\"FuncDef\\nname: " << ident
           << "\\nreturn_type: " << (return_type == TYPE_INT ? "int" : "void")
           << "\", shape=box, style=filled, fillcolor=lightblue];\n";
        
        for (size_t i = 0; i < params.size(); ++i) {
            ss << "  node" << node_id << " -> node" << params[i]->GetNodeID() 
               << " [label=\"param" << i << "\"];\n";
            ss << params[i]->DumpDOT();
        }
        
        if (block) {
            ss << "  node" << node_id << " -> node" << block->GetNodeID() 
               << " [label=\"block\"];\n";
            ss << block->DumpDOT();
        }
        
        return ss.str();
    }
};

// 左值AST节点
class LValAST : public BaseAST {
private:
    int node_id;

public:
    std::string ident;              // 标识符名称
    std::vector<std::unique_ptr<BaseAST>> indices; // 数组索引

    LValAST() : node_id(NewNodeID()) {}

    std::string DumpDOT() const override {
        std::stringstream ss;
        
        ss << "  node" << node_id << " [label=\"LVal\\nident: " << ident 
           << "\", shape=box, style=filled, fillcolor=lightyellow];\n";
        
        for (size_t i = 0; i < indices.size(); ++i) {
            ss << "  node" << node_id << " -> node" << indices[i]->GetNodeID() 
               << " [label=\"index" << i << "\"];\n";
            ss << indices[i]->DumpDOT();
        }
        
        return ss.str();
    }
};

// 代码块AST节点
class BlockAST : public BaseAST {
private:
    int node_id;

public:
    std::vector<std::unique_ptr<BaseAST>> items;

    BlockAST() : node_id(NewNodeID()) {}

    std::string DumpDOT() const override {
        std::stringstream ss;
        
        ss << "  node" << node_id << " [label=\"Block\", shape=box, style=filled, fillcolor=lightgrey];\n";
        
        // 连接所有子项目
        for (size_t i = 0; i < items.size(); i++) {
            if (items[i]) {
                ss << "  node" << node_id << " -> node" << items[i]->GetNodeID() 
                   << " [label=\"item" << i << "\"];\n";
                ss << items[i]->DumpDOT();
            }
        }
        
        return ss.str();
    }
};

// 块项目AST节点
class BlockItemAST : public BaseAST {
private:
    int node_id;

public:
    std::unique_ptr<BaseAST> item;  // 可以是 Decl 或 Stmt

    BlockItemAST() : node_id(NewNodeID()) {}

    int GetNodeID() const override {
        return node_id;
    }

    std::string DumpDOT() const override {
        std::stringstream ss;
        
        ss << "  node" << node_id << " [label=\"BlockItem\", shape=box];\n";
        
        if (item) {
            ss << "  node" << node_id << " -> node" << item->GetNodeID() 
               << " [label=\"item\"];\n";
            ss << item->DumpDOT();
        }
        
        return ss.str();
    }
};

// 语句AST节点
class StmtAST : public BaseAST {
private:
    int node_id;

public:
    enum StmtKind {
        ASSIGNMENT,
        BLOCK,
        RETURN,
        EXPR,
        IF,
        WHILE,
        BREAK,
        CONTINUE,
        GETINT,
        PRINTF
    };

    StmtKind kind;
    std::unique_ptr<BaseAST> content;  // Assignment, Block 或 返回值标识符
    std::unique_ptr<BaseAST> else_stmt; // 用于if-else和while语句
    std::string return_ident;  // 如果是RETURN类型，存储返回的标识符

    StmtAST() : node_id(NewNodeID()) {}

    std::string DumpDOT() const override {
        std::stringstream ss;
        std::string kind_str;
        
        switch (kind) {
            case ASSIGNMENT: kind_str = "ASSIGNMENT"; break;
            case EXPR: kind_str = "EXPR"; break;
            case BLOCK: kind_str = "BLOCK"; break;
            case RETURN: kind_str = "RETURN"; break;
            case IF: kind_str = "IF"; break;
            case WHILE: kind_str = "WHILE"; break;
            case BREAK: kind_str = "BREAK"; break;
            case CONTINUE: kind_str = "CONTINUE"; break;
            case GETINT: kind_str = "GETINT"; break;
            case PRINTF: kind_str = "PRINTF"; break;
        }
        
        ss << "  node" << node_id << " [label=\"Stmt\\nkind: " << kind_str;
        if (!return_ident.empty()) {
            ss << "\\nident: " << return_ident;
        }
        ss << "\", shape=box, style=filled, fillcolor=lightskyblue];\n";
        
        if (content) {
            std::string edge_label;
            switch (kind) {
                case ASSIGNMENT: edge_label = "assignment"; break;
                case BLOCK: edge_label = "block"; break;
                case IF: edge_label = "condition"; break;
                case WHILE: edge_label = "condition"; break;
                default: edge_label = "content"; break;
            }
            
            ss << "  node" << node_id << " -> node" << content->GetNodeID() 
               << " [label=\"" << edge_label << "\"];\n";
            ss << content->DumpDOT();
        }
        
        if (else_stmt) {
            std::string edge_label = (kind == IF) ? "else" : "body";
            ss << "  node" << node_id << " -> node" << else_stmt->GetNodeID() 
               << " [label=\"" << edge_label << "\"];\n";
            ss << else_stmt->DumpDOT();
        }
        
        return ss.str();
    }
};

// 赋值语句AST节点
class AssignmentAST : public BaseAST {
private:
    int node_id;

public:
    std::string ident;

    AssignmentAST() : node_id(NewNodeID()) {}
    
    // 从C风格字符串构造
    AssignmentAST(const char* id) : node_id(NewNodeID()), ident(id) {}

    int GetNodeID() const override {
        return node_id;
    }

    std::string DumpDOT() const override {
        std::stringstream ss;
        
        std::string label = "Assignment\\nident: " + ident;
        
        ss << "  node" << node_id << " [label=\"" << label << "\", shape=box, style=filled, fillcolor=lightsalmon];\n";
        
        return ss.str();
    }
};

// 数字AST节点
class NumberAST : public BaseAST {
private:
    int node_id;

public:
    int value;

    NumberAST() : node_id(NewNodeID()) {}

    NumberAST(int val) : node_id(NewNodeID()), value(val) {}

    int GetNodeID() const override {
        return node_id;
    }

    std::string DumpDOT() const override {
        std::stringstream ss;
        
        std::string label = "Number\\nvalue: " + std::to_string(value);
        
        ss << "  node" << node_id << " [label=\"" << label << "\", shape=ellipse, style=filled, fillcolor=lightpink];\n";
        
        return ss.str();
    }
};

// 表达式AST节点
class ExprAST : public BaseAST {
private:
    int node_id;

public:
    enum ExprKind {
        NUMBER,     // 数字字面量
        LVAL,       // 左值（变量引用）
        BINARY,     // 二元运算
        UNARY,      // 一元运算
        CALL        // 函数调用
    };
    
    ExprKind kind;
    std::unique_ptr<BaseAST> left;  // 左操作数
    std::unique_ptr<BaseAST> right; // 右操作数
    std::string op;                 // 运算符
    int value;                      // 数字值（用于NUMBER）
    std::string ident;              // 标识符（用于LVAL和CALL）

    ExprAST() : node_id(NewNodeID()) {}

    std::string DumpDOT() const override {
        std::stringstream ss;
        std::string kind_str;
        
        switch (kind) {
            case NUMBER: kind_str = "NUMBER"; break;
            case LVAL: kind_str = "LVAL"; break;
            case BINARY: kind_str = "BINARY"; break;
            case UNARY: kind_str = "UNARY"; break;
            case CALL: kind_str = "CALL"; break;
        }
        
        ss << "  node" << node_id << " [label=\"Expr\\nkind: " << kind_str;
        if (!op.empty()) ss << "\\nop: " << op;
        if (!ident.empty()) ss << "\\nident: " << ident;
        if (kind == NUMBER) ss << "\\nvalue: " << value;
        ss << "\", shape=box, style=filled, fillcolor=lightcyan];\n";
        
        if (left) {
            ss << "  node" << node_id << " -> node" << left->GetNodeID() 
               << " [label=\"left\"];\n";
            ss << left->DumpDOT();
        }
        
        if (right) {
            ss << "  node" << node_id << " -> node" << right->GetNodeID() 
               << " [label=\"right\"];\n";
            ss << right->DumpDOT();
        }
        
        return ss.str();
    }
};


