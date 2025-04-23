#!/bin/zsh

# 确保脚本在出错时退出
set -e

echo "开始编译..."
# 编译项目
make clean
make

echo "运行语法分析器并生成AST..."
# 运行语法分析器
mkdir -p output
./parser ../../tests/ast_tests/testfile.txt 2>&1 | tee output/ast_output.txt

# 检查是否生成了ast.dot文件
if [ -f "ast.dot" ]; then
    # 使用graphviz生成可视化语法树
    echo "AST已写入ast.dot文件"
    echo "使用graphviz生成语法树图片..."
    dot -Tpng ast.dot -o ast.png
    
    # 检查是否成功生成图片
    if [ -f "ast.png" ]; then
        echo "成功生成AST语法树图片: ast.png"
    else
        echo "生成图片失败！"
        exit 1
    fi
else
    echo "未找到ast.dot文件，AST生成失败！"
    cat parse_output.txt
    exit 1
fi

echo "全部完成！" 