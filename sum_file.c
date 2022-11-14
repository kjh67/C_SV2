#include <stdio.h>
#include <stdlib.h>


int main() {
    FILE *fp;
    if ((fp=fopen("to_read.txt", "r")) == 0) {
        printf("fopen error :(\n");
        return 1;
    }

    long int sum = 0;
    while (!feof(fp)) {
        unsigned char buffer[1];
        fread(buffer, sizeof(char), 1, fp);
        sum += buffer[0];
    }
    printf("%ld\n", sum);
    fclose(fp);
}


