#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b){
    return (*(int*)a - *(int*)b);
}

int main(int argc, char** argv){
    FILE *fpointer;
    
    fpointer = fopen("../Day 1/input.txt", "r");

    char line[14];

    int flag = 0;
    int endofRep1, endofRep2;
    int startofrep2;

    while(fgets(line, 14, fpointer)){
        int head = 0;

        printf("%s\n", line);


        int report[14];

        for(int i; i < 14; i++){
            //if(line[i] == ' ' || line[i] == '\0') continue;
            // else{
                report[head] = line[i] - '0';
                printf(" ");
                printf("%d", line[i]);
                printf(" ");
                head++;
            // }
        }

        

        for(int p = 0; p < 10; p++){
            printf("%d", report[p]);
        }

        printf("\n");

        break;
    }
}