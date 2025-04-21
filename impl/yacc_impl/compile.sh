# remove old files
rm -f lex.yy.c yacc.tab.c yacc.tab.h parser yacc.output

# compile
bison -d yacc.y
flex lex.l
gcc yacc.tab.c lex.yy.c -o parser -lm

mkdir -p output

# check
./parser < ../../tests/yacc_tests/testfile1.txt > output/output1.txt
./parser < ../../tests/yacc_tests/testfile2.txt > output/output2.txt
./parser < ../../tests/yacc_tests/testfile3.txt > output/output3.txt

diff output/output1.txt ../../tests/yacc_tests/output1.txt
diff output/output2.txt ../../tests/yacc_tests/output2.txt
diff output/output3.txt ../../tests/yacc_tests/output3.txt