#!/bin/bash

# mkdir -p output
/home/imio/exp_yacc/impl/yacc_impl/parser < ../../tests/ast_tests/testfile.txt > output/yacc_output.txt

diff output/yacc_output.txt output/ast_output.txt