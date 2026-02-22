#include <stdio.h>
#include <string.h>

int main() {
    char prop[4096];
    char cuv[1000][256];
    int  cnt = 0;

    if (scanf("%4095[^\n]", prop) == 1) {
        char *token = strtok(prop, " ");

        while (token != NULL && cnt < 1000) {
            strcpy(cuv[cnt], token);
            cnt++;
            token = strtok(NULL, " ");
        }


        for (int i = 0; i < cnt - 1; i++) {
            for (int j = i + 1; j < cnt; j++) {
                int len1 = strlen(cuv[i]);
                int len2 = strlen(cuv[j]);
                int trb_swap = 0;

                if (len1 < len2) {

                    trb_swap = 1;
                } else if (len1 == len2 && strcmp(cuv[i], cuv[j]) > 0) {

                    trb_swap = 1;
                }

                if (trb_swap) {
                    char temp[256];
                    strcpy(temp, cuv[i]);
                    strcpy(cuv[i], cuv[j]);
                    strcpy(cuv[j], temp);
                }
            }
        }

        for (int i = 0; i < cnt; i++) {
            printf("%s\n", cuv[i]);
        }
    }

    return 0;
}
