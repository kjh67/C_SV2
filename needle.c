#include <string.h>
#include <stdio.h>

char* stringsearch(char* needle, char* hay) {
    int i = 0;
    int j = 0;

    while (i < (strlen(hay) - strlen(needle))) {
        while (needle[j] == hay[i+j] && j < strlen(needle)) { j++; }
        if (j == strlen(needle)) {
            return &(hay[i]);
        }
        j = 0; i++;
    }

    return NULL;
}


int main() {
    char* needle = "fam";
    char* hay = "It ain't familiar";

    printf(stringsearch(needle, hay));
}

