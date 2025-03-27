flex example.l
gcc lex.yy.c -o a
./a < test.txt > myoutput.txt

rm a lex.yy.c
