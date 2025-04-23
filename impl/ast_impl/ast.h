#pragma once
#include <string>
#include <vector>
#include <memory>
#include <sstream>

// 基础AST节点类
class BaseAST
{
public:
    int node_id;

    BaseAST() : node_id(NewNodeID()) {}
    virtual ~BaseAST() = default;

    // 将节点以DOT语言格式输出
    virtual std::string DumpDOT() const = 0;

    // 获取节点ID（用于连边）
    virtual int GetNodeID() const { return node_id; }

protected:
    static int node_id_counter; // 静态成员变量，直接在头文件中定义
    static int NewNodeID() { return node_id_counter++; }
};

// 静态成员初始化 - 使用inline避免多重定义问题（C++17特性）
inline int BaseAST::node_id_counter = 0;

// 表达式节点基类
class ExpAST : public BaseAST
{
public:
    virtual ~ExpAST() = default;
};

// 数值常量节点
class NumberAST : public ExpAST
{
public:
    int value;

    std::string DumpDOT() const override
    {
        std::stringstream ss;
        ss << "  node" << node_id << " [label=\"Number\\nvalue: " << value
           << "\", shape=box, style=filled, fillcolor=lightpink];\n";
        return ss.str();
    }
};

// 左值表达式节点
class LValAST : public ExpAST
{
public:
    std::string ident;
    std::unique_ptr<ExpAST> array_index; // 可能为nullptr表示非数组

    std::string DumpDOT() const override
    {
        std::stringstream ss;
        ss << "  node" << node_id << " [label=\"LVal\\nident: " << ident
           << "\", shape=box, style=filled, fillcolor=lightyellow];\n";

        if (array_index)
        {
            ss << "  node" << node_id << " -> node" << array_index->GetNodeID()
               << " [label=\"index\"];\n";
            ss << array_index->DumpDOT();
        }
        return ss.str();
    }
};

// 一元表达式节点
class UnaryExpAST : public ExpAST
{
public:
    enum UnaryOp
    {
        PLUS,
        MINUS,
        NOT
    };
    UnaryOp op;
    std::unique_ptr<ExpAST> exp;

    std::string DumpDOT() const override
    {
        std::stringstream ss;
        ss << "  node" << node_id << " [label=\"UnaryExp\\nop: ";
        switch (op)
        {
        case PLUS:
            ss << "+";
            break;
        case MINUS:
            ss << "-";
            break;
        case NOT:
            ss << "!";
            break;
        }
        ss << "\", shape=box, style=filled, fillcolor=lightblue];\n";

        ss << "  node" << node_id << " -> node" << exp->GetNodeID()
           << " [label=\"exp\"];\n";
        ss << exp->DumpDOT();
        return ss.str();
    }
};

// 二元表达式节点
class BinaryExpAST : public ExpAST
{
public:
    enum BinaryOp
    {
        ADD,
        SUB,
        MUL,
        DIV,
        MOD, // 算术运算
        LT,
        GT,
        LE,
        GE,
        EQ,
        NE, // 关系运算
        AND,
        OR // 逻辑运算
    };
    BinaryOp op;
    std::unique_ptr<ExpAST> lhs, rhs;

    std::string DumpDOT() const override
    {
        std::stringstream ss;
        ss << "  node" << node_id << " [label=\"BinaryExp\\nop: ";
        switch (op)
        {
        case ADD:
            ss << "+";
            break;
        case SUB:
            ss << "-";
            break;
        case MUL:
            ss << "*";
            break;
        case DIV:
            ss << "/";
            break;
        case MOD:
            ss << "%";
            break;
        case LT:
            ss << "<";
            break;
        case GT:
            ss << ">";
            break;
        case LE:
            ss << "<=";
            break;
        case GE:
            ss << ">=";
            break;
        case EQ:
            ss << "==";
            break;
        case NE:
            ss << "!=";
            break;
        case AND:
            ss << "&&";
            break;
        case OR:
            ss << "||";
            break;
        }
        ss << "\", shape=box, style=filled, fillcolor=lightgreen];\n";

        ss << "  node" << node_id << " -> node" << lhs->GetNodeID()
           << " [label=\"lhs\"];\n";
        ss << lhs->DumpDOT();

        ss << "  node" << node_id << " -> node" << rhs->GetNodeID()
           << " [label=\"rhs\"];\n";
        ss << rhs->DumpDOT();
        return ss.str();
    }
};

// 函数调用节点
class FuncCallAST : public ExpAST
{
public:
    std::string func_name;
    std::vector<std::unique_ptr<ExpAST>> args;

    std::string DumpDOT() const override
    {
        std::stringstream ss;
        ss << "  node" << node_id << " [label=\"FuncCall\\nfunc: " << func_name
           << "\", shape=box, style=filled, fillcolor=lightsalmon];\n";

        for (size_t i = 0; i < args.size(); ++i)
        {
            ss << "  node" << node_id << " -> node" << args[i]->GetNodeID()
               << " [label=\"arg" << i << "\"];\n";
            ss << args[i]->DumpDOT();
        }
        return ss.str();
    }
};

// 语句节点
class StmtAST : public BaseAST
{
public:
    enum StmtKind
    {
        ASSIGN,
        EXPR,
        BLOCK,
        IF,
        WHILE,
        BREAK,
        CONTINUE,
        RETURN,
        GETINT,
        PRINTF
    };
    StmtKind kind;

    virtual ~StmtAST() = default;
};

// 赋值语句节点
class AssignStmtAST : public StmtAST
{
public:
    std::unique_ptr<LValAST> lval;
    std::unique_ptr<ExpAST> exp;

    AssignStmtAST()
    {
        kind = ASSIGN;
    }

    std::string DumpDOT() const override
    {
        std::stringstream ss;
        ss << "  node" << node_id << " [label=\"Stmt\\nkind: ASSIGNMENT\", shape=box, style=filled, fillcolor=lightskyblue];\n";

        ss << "  node" << node_id << " -> node" << lval->GetNodeID()
           << " [label=\"lval\"];\n";
        ss << lval->DumpDOT();

        ss << "  node" << node_id << " -> node" << exp->GetNodeID()
           << " [label=\"exp\"];\n";
        ss << exp->DumpDOT();
        return ss.str();
    }
};

// GetInt语句节点
class GetIntStmtAST : public StmtAST
{
public:
    std::unique_ptr<LValAST> lval;

    GetIntStmtAST()
    {
        kind = GETINT;
    }

    std::string DumpDOT() const override
    {
        std::stringstream ss;
        ss << "  node" << node_id << " [label=\"Stmt\\nkind: GETINT\", shape=box, style=filled, fillcolor=lightskyblue];\n";

        ss << "  node" << node_id << " -> node" << lval->GetNodeID()
           << " [label=\"lval\"];\n";
        ss << lval->DumpDOT();
        return ss.str();
    }
};

// 表达式语句节点
class ExprStmtAST : public StmtAST
{
public:
    std::unique_ptr<ExpAST> exp; // 可能为nullptr表示空语句

    ExprStmtAST()
    {
        kind = EXPR;
    }

    std::string DumpDOT() const override
    {
        std::stringstream ss;
        ss << "  node" << node_id << " [label=\"Stmt\\nkind: EXPR\", shape=box, style=filled, fillcolor=lightskyblue];\n";

        if (exp)
        {
            ss << "  node" << node_id << " -> node" << exp->GetNodeID()
               << " [label=\"exp\"];\n";
            ss << exp->DumpDOT();
        }
        return ss.str();
    }
};

// 语句块节点
class BlockAST : public BaseAST
{
public:
    std::vector<std::unique_ptr<BaseAST>> items; // BlockItem可以是Decl或Stmt

    std::string DumpDOT() const override
    {
        std::stringstream ss;
        ss << "  node" << node_id << " [label=\"Block\", shape=box, style=filled, fillcolor=lightgrey];\n";

        for (size_t i = 0; i < items.size(); ++i)
        {
            ss << "  node" << node_id << " -> node" << items[i]->GetNodeID()
               << " [label=\"item" << i << "\"];\n";
            ss << items[i]->DumpDOT();
        }
        return ss.str();
    }
};

// 条件语句节点
class IfStmtAST : public StmtAST
{
public:
    std::unique_ptr<ExpAST> cond;
    std::unique_ptr<StmtAST> then_stmt;
    std::unique_ptr<StmtAST> else_stmt; // 可能为nullptr表示没有else分支

    IfStmtAST()
    {
        kind = IF;
    }

    std::string DumpDOT() const override
    {
        std::stringstream ss;
        ss << "  node" << node_id << " [label=\"Stmt\\nkind: IF\", shape=box, style=filled, fillcolor=lightskyblue];\n";

        ss << "  node" << node_id << " -> node" << cond->GetNodeID()
           << " [label=\"cond\"];\n";
        ss << cond->DumpDOT();

        ss << "  node" << node_id << " -> node" << then_stmt->GetNodeID()
           << " [label=\"then\"];\n";
        ss << then_stmt->DumpDOT();

        if (else_stmt)
        {
            ss << "  node" << node_id << " -> node" << else_stmt->GetNodeID()
               << " [label=\"else\"];\n";
            ss << else_stmt->DumpDOT();
        }
        return ss.str();
    }
};

// 循环语句节点
class WhileStmtAST : public StmtAST
{
public:
    std::unique_ptr<ExpAST> cond;
    std::unique_ptr<StmtAST> body;

    WhileStmtAST()
    {
        kind = WHILE;
    }

    std::string DumpDOT() const override
    {
        std::stringstream ss;
        ss << "  node" << node_id << " [label=\"Stmt\\nkind: WHILE\", shape=box, style=filled, fillcolor=lightskyblue];\n";

        ss << "  node" << node_id << " -> node" << cond->GetNodeID()
           << " [label=\"cond\"];\n";
        ss << cond->DumpDOT();

        ss << "  node" << node_id << " -> node" << body->GetNodeID()
           << " [label=\"body\"];\n";
        ss << body->DumpDOT();
        return ss.str();
    }
};

// Break语句节点
class BreakStmtAST : public StmtAST
{
public:
    BreakStmtAST()
    {
        kind = BREAK;
    }

    std::string DumpDOT() const override
    {
        std::stringstream ss;
        ss << "  node" << node_id << " [label=\"Stmt\\nkind: BREAK\", shape=box, style=filled, fillcolor=lightskyblue];\n";
        return ss.str();
    }
};

// Continue语句节点
class ContinueStmtAST : public StmtAST
{
public:
    ContinueStmtAST()
    {
        kind = CONTINUE;
    }

    std::string DumpDOT() const override
    {
        std::stringstream ss;
        ss << "  node" << node_id << " [label=\"Stmt\\nkind: CONTINUE\", shape=box, style=filled, fillcolor=lightskyblue];\n";
        return ss.str();
    }
};

// Return语句节点
class ReturnStmtAST : public StmtAST
{
public:
    std::unique_ptr<ExpAST> exp; // 可能为nullptr表示无返回值

    ReturnStmtAST()
    {
        kind = RETURN;
    }

    std::string DumpDOT() const override
    {
        std::stringstream ss;
        ss << "  node" << node_id << " [label=\"Stmt\\nkind: RETURN\", shape=box, style=filled, fillcolor=lightskyblue];\n";

        if (exp)
        {
            ss << "  node" << node_id << " -> node" << exp->GetNodeID()
               << " [label=\"exp\"];\n";
            ss << exp->DumpDOT();
        }
        return ss.str();
    }
};

// Printf语句节点
class PrintfStmtAST : public StmtAST
{
public:
    std::string format_string;
    std::vector<std::unique_ptr<ExpAST>> args;

    PrintfStmtAST()
    {
        kind = PRINTF;
    }

    // 转义DOT语言中的特殊字符
    std::string EscapeForDOT(const std::string &str) const
    {
        std::string result;
        for (char c : str)
        {
            if (c == '%')
                result += "%%"; // %需要转义为%%
            else if (c == '"')
                result += "\\\""; // "需要转义为\"
            else if (c == '\\')
                result += "\\\\";
            else if (c == '<')
                result += "\\<";
            else if (c == '>')
                result += "\\>"; // >需要转义为\>
            else if (c == '{')
                result += "\\{"; // {需要转义为\{
            else if (c == '}')
                result += "\\}"; // }需要转义为\}
            else if (c == '|')
                result += "\\|"; // |需要转义为\|
            else
                result += c;
        }
        return result;
    }

    std::string DumpDOT() const override
    {
        std::stringstream ss;
        ss << "  node" << node_id << " [label=\"Stmt\\nkind: PRINTF\\nformat: " << EscapeForDOT(format_string)
           << "\", shape=box, style=filled, fillcolor=lightskyblue];\n";

        for (size_t i = 0; i < args.size(); ++i)
        {
            ss << "  node" << node_id << " -> node" << args[i]->GetNodeID()
               << " [label=\"arg" << i << "\"];\n";
            ss << args[i]->DumpDOT();
        }
        return ss.str();
    }
};

// 声明节点
class DeclAST : public BaseAST
{
public:
    enum DeclKind
    {
        VAR,
        CONST
    };
    DeclKind kind;

    virtual ~DeclAST() = default;
};

// 变量声明节点
class VarDeclAST : public DeclAST
{
public:
    std::string type;
    std::string ident;
    std::unique_ptr<ExpAST> array_size; // 可能为nullptr表示非数组
    std::unique_ptr<ExpAST> init_val;   // 可能为nullptr表示无初始值

    VarDeclAST()
    {
        kind = VAR;
    }

    std::string DumpDOT() const override
    {
        std::stringstream ss;
        ss << "  node" << node_id << " [label=\"VarDecl\\nident: " << ident
           << "\\ntype: " << type << "\", shape=box, style=filled, fillcolor=lightgreen];\n";

        if (array_size)
        {
            ss << "  node" << node_id << " -> node" << array_size->GetNodeID()
               << " [label=\"size\"];\n";
            ss << array_size->DumpDOT();
        }

        if (init_val)
        {
            ss << "  node" << node_id << " -> node" << init_val->GetNodeID()
               << " [label=\"init\"];\n";
            ss << init_val->DumpDOT();
        }
        return ss.str();
    }
};

// 常量声明节点
class ConstDeclAST : public DeclAST
{
public:
    std::string type;
    std::string ident;
    std::unique_ptr<ExpAST> array_size; // 可能为nullptr表示非数组
    std::unique_ptr<ExpAST> init_val;

    ConstDeclAST()
    {
        kind = CONST;
    }

    std::string DumpDOT() const override
    {
        std::stringstream ss;
        ss << "  node" << node_id << " [label=\"ConstDecl\\nident: " << ident
           << "\\ntype: " << type;
        if (init_val)
        {
            // 如果初始值是数字常量，直接显示值
            auto num_val = dynamic_cast<NumberAST *>(init_val.get());
            if (num_val)
            {
                ss << "\\nvalue: " << num_val->value;
            }
        }
        ss << "\", shape=box, style=filled, fillcolor=lightyellow];\n";

        if (array_size)
        {
            ss << "  node" << node_id << " -> node" << array_size->GetNodeID()
               << " [label=\"size\"];\n";
            ss << array_size->DumpDOT();
        }

        if (init_val && !dynamic_cast<NumberAST *>(init_val.get()))
        {
            ss << "  node" << node_id << " -> node" << init_val->GetNodeID()
               << " [label=\"init\"];\n";
            ss << init_val->DumpDOT();
        }
        return ss.str();
    }
};

// 函数定义节点
class FuncDefAST : public BaseAST
{
public:
    std::string return_type;
    std::string func_name;
    std::vector<std::pair<std::string, std::string>> params; // <type, name>
    std::unique_ptr<BlockAST> body;

    std::string DumpDOT() const override
    {
        std::stringstream ss;
        ss << "  node" << node_id << " [label=\"FuncDef\\nname: " << func_name
           << "\\nreturn: " << return_type << "\", shape=box, style=filled, fillcolor=lightcoral];\n";

        if (!params.empty())
        {
            std::stringstream params_ss;
            params_ss << "  node" << node_id + 10000 << " [label=\"Params\\n";
            for (const auto &param : params)
            {
                params_ss << param.first << " " << param.second << "\\n";
            }
            params_ss << "\", shape=box, style=filled, fillcolor=wheat];\n";

            ss << params_ss.str();
            ss << "  node" << node_id << " -> node" << node_id + 10000
               << " [label=\"params\"];\n";
        }

        ss << "  node" << node_id << " -> node" << body->GetNodeID()
           << " [label=\"body\"];\n";
        ss << body->DumpDOT();
        return ss.str();
    }
};

// main函数定义节点
class MainFuncDefAST : public BaseAST
{
public:
    std::unique_ptr<BlockAST> body;

    std::string DumpDOT() const override
    {
        std::stringstream ss;
        ss << "  node" << node_id << " [label=\"MainFuncDef\\nint main()\", shape=box, style=filled, fillcolor=lightcoral];\n";

        ss << "  node" << node_id << " -> node" << body->GetNodeID()
           << " [label=\"block\"];\n";
        ss << body->DumpDOT();
        return ss.str();
    }
};

// 编译单元节点（程序的顶层节点）
class CompUnitAST : public BaseAST
{
public:
    std::vector<std::unique_ptr<DeclAST>> global_decls;
    std::vector<std::unique_ptr<FuncDefAST>> func_defs;
    std::unique_ptr<MainFuncDefAST> main_func_def;

    std::string DumpDOT() const override
    {
        std::stringstream ss;
        ss << "  node" << node_id << " [label=\"CompUnit\", shape=box, style=filled, fillcolor=lightblue];\n";

        for (size_t i = 0; i < global_decls.size(); ++i)
        {
            ss << "  node" << node_id << " -> node" << global_decls[i]->GetNodeID()
               << " [label=\"decl" << (i > 0 ? std::to_string(i) : "") << "\"];\n";
            ss << global_decls[i]->DumpDOT();
        }

        for (size_t i = 0; i < func_defs.size(); ++i)
        {
            ss << "  node" << node_id << " -> node" << func_defs[i]->GetNodeID()
               << " [label=\"func_def" << i << "\"];\n";
            ss << func_defs[i]->DumpDOT();
        }

        if (main_func_def)
        {
            ss << "  node" << node_id << " -> node" << main_func_def->GetNodeID()
               << " [label=\"main_func_def\"];\n";
            ss << main_func_def->DumpDOT();
        }
        return ss.str();
    }
};