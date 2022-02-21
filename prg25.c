/*SSTF disk scheduling algorithm*/

#include <stdio.h>
#include <stdlib.h>
int main(){
    int RQ[100], i, n, TotalHeadMoment = 0, initial, count = 0;
    printf("\nEnter the number of Requests: ");
    scanf("%d", &n);
    printf("\nEnter the Requests sequence\n");
    for (i = 0; i < n; i++)
        scanf("%d", &RQ[i]);
    printf("\nEnter initial head position: ");
    scanf("%d", &initial);

    // logic for sstf disk scheduling

    /* loop will execute until all process is completed*/
    while (count != n){
        int min = 1000, d, index;
        for (i = 0; i < n; i++){
            d = abs(RQ[i] - initial);
            if (min > d){
                min = d;
                index = i;
            }
        }
        TotalHeadMoment = TotalHeadMoment + min;
        initial = RQ[index];
        // 1000 is for max
        // you can use any number
        RQ[index] = 1000;
        count++;
    }

    printf("\nTotal head movement is %d \n\n", TotalHeadMoment);
    return 0;
}