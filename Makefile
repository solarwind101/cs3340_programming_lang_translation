EXECUTABLE = compiler

all: $(EXECUTABLE)

$(EXECUTABLE): Suraj_Sharma_PA4.tab.c lex.yy.c Suraj_Sharma_PA4_translator.o
	gcc -g -w -o $(EXECUTABLE) Suraj_Sharma_PA4.tab.c lex.yy.c Suraj_Sharma_PA4_translator.o -lfl

Suraj_Sharma_PA4_translator.o: Suraj_Sharma_PA4_translator.c Suraj_Sharma_PA4_translator.h
	gcc -g -w -c Suraj_Sharma_PA4_translator.c

Suraj_Sharma_PA4.tab.c Suraj_Sharma_PA4.tab.h: Suraj_Sharma_PA4.y Suraj_Sharma_PA4_translator.h
	bison -d -o Suraj_Sharma_PA4.tab.c Suraj_Sharma_PA4.y

lex.yy.c: Suraj_Sharma_PA4.l Suraj_Sharma_PA4.tab.h Suraj_Sharma_PA4_translator.h
	flex -o lex.yy.c Suraj_Sharma_PA4.l

clean:
	rm -f $(EXECUTABLE) Suraj_Sharma_PA4.tab.c Suraj_Sharma_PA4.tab.h lex.yy.c *.o
	#rm -f *.out
	#rm -f *.asm

.PHONY: all clean test
