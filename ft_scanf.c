#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>



int ft_scanf(const char *format, ... )
{
    va_list     ap;
    int         ret;

    va_start (ap, format);
    ret = vfscanf(stdin, format, ap);
    va_end (ap);
    return ret; 
    
}


int main() {
    int vek;
    float vaha;
    char jmeno[50];
    int n;

    printf("Zadej jmeno, vek a vahu: ");
    
    // Použití ft_scanf
    // Vrací počet úspěšně načtených položek
    n = ft_scanf("%s %d %f", jmeno, &vek, &vaha);

    if (n == 3) {
        printf("Načteno: %s (%d let, %.1f kg)\n", jmeno, vek, vaha);
    } else {
        printf("Chyba při načítání dat!\n");
    }

    return 0;
}