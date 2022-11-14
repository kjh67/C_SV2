#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>

int main() {
    unsigned char *fp;
    struct stat st;
    stat("to_read.txt", &st);
    int fd = open("to_read.txt", O_RDONLY);

    fp = (unsigned char *) mmap (NULL, st.st_size, PROT_READ, MAP_SHARED, fd, 0);

    long int sum = 0;
    for (int i=0; i < st.st_size; i++) {
        sum+= fp[i];
    }

    printf("%ld\n", sum);
}


