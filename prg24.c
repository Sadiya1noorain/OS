/*FCFS disk scheduling algorithm*/

#include <stdio.h>
#include <stdlib.h>
int main(){
    int RQ[100], i, n, TotalHeadMoment = 0, initial;
    printf("\nEnter the number of Requests: ");
    scanf("%d", &n);
    printf("\nEnter the Requests sequence\n");
    for (i = 0; i < n; i++)
        scanf("%d", &RQ[i]);
    printf("\nEnter initial head position: ");
    scanf("%d", &initial);

    // logic for FCFS disk scheduling

    for (i = 0; i < n; i++){
        TotalHeadMoment += abs(RQ[i] - initial);
        initial = RQ[i];
    }

    printf("\nTotal head moment is %d \n\n", TotalHeadMoment);
    return 0;
}