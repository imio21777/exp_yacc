make clean && make
./parser ../../tests/ast_tests/testfile.txt > ast.dot
dot -Tpng ast.dot -o ast.png