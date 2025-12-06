#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// This function corresponds to nanoPascal's readln.
// It is designed to read an INTEGER value and store it at the memory address 
// provided by the assembly code.
// The assembly code must pass the ADDRESS of the INTEGER variable (leal).
void readln(int *address) {
    if (address == NULL) {
        fprintf(stderr, "readln error: Null address provided.\n");
        return;
    }
    
   
    if (scanf("%d", address) != 1) {
        fprintf(stderr, "readln error: Failed to read integer input.\n");
        *address = 0; 
    }
}

// This function corresponds to nanoPascal's writeln.
// It is designed to print an INTEGER value or a STRING constant.
// The assembly code passes the VALUE (for integers) or the ADDRESS.
void writeln(int value) {
    // In simple compiler models, printing a 32-bit integer handles both 
    // the integer value itself and the address of a string constant 
    // (which is treated as a pointer).
    
   
    printf("%d", value);
    printf("\n"); 
}

/*
int main() {
    // Example usage of readln/writeln
    int x;
    printf("Enter an integer: ");
    readln(&x);
    printf("You entered: ");
    writeln(x);
    return 0;
}
*/
