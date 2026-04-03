#include <stdio.h>
#include <unistd.h> 
#include <stdlib.h>

int pocet_bitu(int n)
{

//int n = 8;
int pocet = 0;

if (n == 0) pocet = 1; // Nula zabírá aspoň jeden bit
else {
    while (n > 0) {
        n >>= 1;   // Posuneme o jeden bit doprava
        pocet++;   // Přičteme "použitý" bit
    }
}
return (pocet);
}


int main(int argc, char *argv[]) 
{
   // int n = 8;
int i = atoi(argv[1]);
  printf("Číslo %d \n ", i);
int n = pocet_bitu(i);

    int posun = 7; // Začneme u 31. bitu (úplně vlevo)

    printf("Číslo %d binárně: ", i);

    while (posun >= 0) {
        // 1. Posuneme i-tý bit na nultou pozici (úplně doprava)
        // 2. & 1 nám řekne, jestli je to 1 nebo 0
        int bit = (i >> posun) & 1;

        printf("%d", bit);

        // Každých 8 bitů dáme mezeru pro čitelnost (bajt)
        if (posun % 8 == 0) printf(" ");

        posun--; // Jdeme na další bit směrem doprava
    }

    printf("\n");
    return 0;
}