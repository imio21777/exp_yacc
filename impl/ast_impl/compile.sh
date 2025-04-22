make clean && make
./parser ../../tests/asts_tests/testfile.txt > ast.dot
# dot -Tpng ast.dot -o ast.png