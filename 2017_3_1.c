#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char *reverse(char *input) {
    int len = strlen(input);
    printf("Length is: %d\n", len);
    char output[len]; //potential bug; no room for terminating character
    for (int i = 0; i < len; i++) {
        output[len - i - 1] = input[i];
    }

    printf(output);
    printf("\n");
    printf("%ld\n", strlen(output));

    printf("%d\n", input[5]);
    printf("%d\n", output[5]);

    return output; // returning a local var!
}


int main(void) {
    char* s = "howdy";
    char* result = reverse(s);
    printf(result);
    printf("\n");
    printf("%ld\n", strlen(result));

    printf("%d\n", s[5]);
    printf("%d\n", result[5]);

}