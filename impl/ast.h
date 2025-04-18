// ast.h
#pragma once
#include <string>
#include <sstream>

class BaseAST {
public:
    int node_id;

    BaseAST() : node_id(NewNodeID()) {}
    virtual ~BaseAST() = default;

    // 将节点以 DOT 语言格式输出
    virtual std::string DumpDOT() const = 0;

    // 获取节点 ID（用于连边）
    virtual int GetNodeID() const { return node_id; }

protected:
    static int node_id_counter;
    static int NewNodeID() { return node_id_counter++; }
};

// 静态成员初始化
inline int BaseAST::node_id_counter = 0;

std::string BlockItemAST::DumpDOT() const {
    std::stringstream ss;
    ss << "  node" << node_id << " [label=\"BlockItem\", shape=box];\n";
    
    if (item) {
        ss << "  node" << node_id << " -> node" << item->GetNodeID()
           << " [label=\"item\"];\n";
        ss << item->DumpDOT();
    }
    return ss.str();
}