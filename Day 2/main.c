#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define UP 1
#define DOWN -1

int GetSign(int i){
    if(i < 0) return -1;
    if(i > 0) return 1;
    else return 0;
}

int main(int argc, char** argv){

    int safeReports = 0;
    FILE* reportstext;

    reportstext = fopen("../Day 2/input.txt", "r");

    if(reportstext == NULL){
        return -1;
    }

    char line[50] = {0};
    const char delim[2] = " ";

    int it = 1;

    while(fgets(line, 50, reportstext)){
        int numreps = 1;
        int reports[10] = {0};

        if(line[0] == '\n') continue;

        printf("%s", line);
        

        char* token = strtok(line, delim);
        // printf("%s\n", token);

        while(token != NULL){
            //printf("%s\n", token);
            reports[numreps - 1] = atoi(token);
            token = strtok(NULL, delim);
            numreps++;
        }

        printf("\n");

        int dir = GetSign(reports[1] - reports[0]);
        int prev = 0;

        if(!dir) goto next;

        for(int i = 0; i < numreps - 2; i++){
            int diff = reports[i+1] - reports[i];

            if(abs(diff) < 1 || abs(diff) > 3){
                goto next;
            }

            if(GetSign(diff) != dir) goto next;
        }

        safeReports++;

        printf("Report %d is safe, there are %d safe reports\n", it, safeReports);

next:

        it++;
    }

    printf("\nThere are %d safe reports out of %d\n", safeReports, it);

    fclose(reportstext);

    return 0;
}