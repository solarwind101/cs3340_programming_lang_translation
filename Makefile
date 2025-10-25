parser: Manohar_Bikaneri_PA2.tab.c lex.yy.c main.c 
	gcc -o parser Manohar_Bikaneri_PA2.tab.c lex.yy.c main.c -ll

lex.yy.c: Manohar_Bikaneri_PA2.tab.h Manohar_Bikaneri_PA2.l
	flex Manohar_Bikaneri_PA2.l

Manohar_Bikaneri_PA2.tab.h:  Manohar_Bikaneri_PA2.y
	bison -d Manohar_Bikaneri_PA2.y

Manohar_Bikaneri_PA2.tab.c: Manohar_Bikaneri_PA2.y
	bison -d Manohar_Bikaneri_PA2.y 	
clean:
	rm -r parser Manohar_Bikaneri_PA2.tab.c Manohar_Bikaneri_PA2.tab.h lex.yy.c 
