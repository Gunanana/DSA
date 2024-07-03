#include <stdio.h>

int main() {
    // Attempt to modify the page tables directly
    asm("movl $0x12345678, %cr0"); // This is a privileged operation
    
    // This line will not be reached if a privilege exception occurs
    printf("Modified page tables successfully!\n");
    
    return 0;
}