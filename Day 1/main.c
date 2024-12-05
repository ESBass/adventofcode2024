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

    while(fgets(line, 25, fpointer)){
        char vals[14];
        int head = 0;

        for(int i = 0; i < 25; i++){
            if(line[i] == '\0') {vals[head] = 'R'; endofRep2 = head; break;}

            if(line[i] == ' ' && vals[head-1] == 'X') continue;
            else if(line[i] == ' ') {vals[head] = 'X'; head++; endofRep1 = head; startofrep2 = head +1;}
            else {vals[head] = line[i]; head++;}
        }

        printf("%s\n", line);


        int report1[5];
        int report2[5];

        for (int i = 0; i < endofRep1; i++)
        {
            int val = vals[i] - '0';
            report1[i-1] = val;
        }

        //continue;
        
        for(int i = 0; i < (endofRep2 + startofrep2); i++){
            int val = vals[i + startofrep2] - '0';
            report2[i] = val;
        }

        for(int p = 0; p < 5; p++){
            printf("%d", report1[p]);
        }

        printf("\n");

        printf("%d\n", report2[0]);

        break;
    }
}