#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void* a, const void* b){
    return (*(int*)a - *(int*)b);
}

int main(int argc, char** argv){
    FILE *fpointer;
    
    fpointer = fopen("../Day 1/input.txt", "r");

    char line[14];

    int totalDistance = 0;
    int similarityScore = 0;

    int list1[1000], list2[1000];
    int numReps[1000];

    int head = 0;

    while(fgets(line, 14, fpointer)){

        if(line[0] == '\n') continue;

        int lhead = 0;

        printf("\n%s\n", line);


        char list1c[6], list2c[6];
        list1c[5] = '\0'; list2c[5] = '\0';

        for (int i = 0; i < 5; i++)
        {
            list1c[lhead] = line[i];
            list2c[lhead] = line[i+8];
            lhead++;
        }

        printf("%s %s\n", list1c, list2c);

        list1[head] = atoi(list1c);
        list2[head] = atoi(list2c);

        printf("%d %d\n", list1[head], list2[head]);

        head++;

    }

    qsort(list1, 1000, sizeof(int), compare);
    qsort(list2, 1000, sizeof(int), compare);

    for(int p = 0; p < 1000; p++){
        printf("@P%d, list 1: %d & list 2: %d\n", p, list1[p], list2[p]);
    }

    for(int i = 0; i < 1000; i++){
        totalDistance += abs(list1[i] - list2[i]);
        printf("Difference between lists 1 & 2 @ %d is %d\n", i, abs(list1[i] - list2[i]));
    }

    for(int i = 0; i < 1000; i++){
        int reps = 0;
        int val  = list1[i];
        printf("Checking number %d @ %d for repeats\n", val, i);
        for(int j = 0; j < 1000; j++){
            if(list2[j] == val) reps++;
        }
        printf("Number %d has %d duplicates in list 2\n", val, reps);
        numReps[i] = reps;
    }

    for(int i = 0; i < 1000; i++){
        if(numReps[i] == 0) continue;
        similarityScore += (list1[i] * numReps[i]);
    }

    printf("\nTotal difference between lists: %d\n", totalDistance);
    printf("Total Similarity Score Between lists: %d\n", similarityScore);
}