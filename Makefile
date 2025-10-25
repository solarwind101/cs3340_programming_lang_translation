parser: Manohar_Bikaneri_PA2.tab.c lex.yy.c main.c
	 gcc -o parser Manohar_Bikaneri_PA2.tab.c lex.yy.c main.c -lfl

lex.yy.c: Manohar_Bikaneri_PA2.l Manohar_Bikaneri_PA2.tab.h
	 flex Manohar_Bikaneri_PA2.l

Manohar_Bikaneri_PA2.tab.c Manohar_Bikaneri_PA2.tab.h: Manohar_Bikaneri_PA2.y
	 bison -d Manohar_Bikaneri_PA2.y

.PHONY: clean
clean:
	 rm -f parser lex.yy.c Manohar_Bikaneri_PA2.tab.c Manohar_Bikaneri_PA2.tab.h Manohar_Bikaneri_PA2.output
