#include <stdio.h>

int atoi(const char *str) {
    int res = 0;
    int sign = 1;

    while (*str == ' ' || *str == '\t' || *str == '\n') {
        str++;
    }

    if (*str == '-') {
        sign = -1;
        str++;
    } else if (*str == '+') {
        str++;
    }

    while (*str >= '0' && *str <= '9') {
        res = res * 10 + (*str - '0');
        str++;
    }

    return res * sign;
}

int main() {
    FILE *file = fopen("in.txt", "r");
    if (file == NULL) {
        printf("eroare deschidere.\n");
        return 1;
    }

    char line[4096];
    int sum = 0;

    while (fgets(line, sizeof(line), file) != NULL) {
        char *ptr = line;

        while (*ptr != '\0') {
            if ((*ptr >= '0' && *ptr <= '9') ||
                ((*ptr == '-' || *ptr == '+') && *(ptr+1) >= '0' && *(ptr+1) <= '9')) {

                sum += atoi(ptr);

                if (*ptr == '-' || *ptr == '+') {
                    ptr++;
                }
                while (*ptr >= '0' && *ptr <= '9') {
                    ptr++;
                }
            } else {
                ptr++;
            }
        }
    }

    printf("%d\n", sum);

    fclose(file);
    return 0;
}
