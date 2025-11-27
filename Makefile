all: translator

translator: Manohar_Bikaneri_PA3.tab.c lex.yy.c Manohar_Bikaneri_PA3_translator.o
	gcc -g -w -o translator Manohar_Bikaneri_PA3.tab.c lex.yy.c Manohar_Bikaneri_PA3_translator.o -lfl

Manohar_Bikaneri_PA3_translator.o: Manohar_Bikaneri_PA3_translator.c Manohar_Bikaneri_PA3_translator.h
	gcc -g -w -c Manohar_Bikaneri_PA3_translator.c

Manohar_Bikaneri_PA3.tab.c Manohar_Bikaneri_PA3.tab.h: Manohar_Bikaneri_PA3.y Manohar_Bikaneri_PA3_translator.h
	bison -d -o Manohar_Bikaneri_PA3.tab.c Manohar_Bikaneri_PA3.y

lex.yy.c: Manohar_Bikaneri_PA3.l Manohar_Bikaneri_PA3.tab.h Manohar_Bikaneri_PA3_translator.h
	flex -o lex.yy.c Manohar_Bikaneri_PA3.l

clean:
	rm -f translator Manohar_Bikaneri_PA3.tab.c Manohar_Bikaneri_PA3.tab.h lex.yy.c *.o *.output Manohar_Bikaneri_PA3_quads.out

.PHONY: all clean
