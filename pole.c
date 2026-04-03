#include <stdio.h>
#include <unistd.h>

char status[] = "neco neco";

char *get_status() {
    //char *status = "Vrtání v pořádku";
    return status;
}

int main() {
    char *res = get_status();
    printf("%s\n", res);
    return 0;
}