flex lex.l
gcc lex.yy.c -o lexer

./lexer < ../../tests/flex_tests/testfile1.txt > output/output1.txt
./lexer < ../../tests/flex_tests/testfile2.txt > output/output2.txt

diff output/output1.txt ../../tests/flex_tests/output1.txt
diff output/output2.txt ../../tests/flex_tests/output2.txt