#include <stdio.h>
#include "Manohar_Bikaneri_PA2.tab.h" 

int yyparse();  

int main()
{
    if (yyparse() == 0) {  
        
    printf("Parsed successfully.\\n\n");

 }
    return 0;
}
