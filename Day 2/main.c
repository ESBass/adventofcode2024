#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv){

    int safeReports = 0, unsafeReports = 0;
    FILE* reportstext;

    reportstext = fopen("../Day 2/input.txt", "r");

    if(reportstext == NULL){
        return -1;
    }

    char str[50] = {0};

    int dir = 0;
    int current = 0;
    int prev = 0;

    while(fgets(str, 50, reportstext)){
        printf("%s", str);

        char* tok = strtok(str, ' ');

        current = tok - '0';

        while(tok != NULL){
            prev = current;
            printf("%s", tok);
            tok = strtok(NULL, ' ');
        }
        
    }

    fclose(reportstext);

    return 0;
}