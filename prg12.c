/*Program to simulate Round Robin Processor scheduling algorithm. Compute TAT, WT, ATAT, AWT.*/

#include <stdio.h>
#include <stdlib.h>
int main(){
    int BT[10], RBT[10], TAT[10], WT[10];
    int i, TS, n, count, curt, TTAT = 0, TWT = 0;
    float ATAT, AWT;
    system("clear");
    printf("\nEnter the number of process : ");
    scanf("%d", &n);
    printf("\nEnter the processes Burst Time :\n");
    for (i = 0; i < n; i++){
        printf("\nEnter PID[%d] Burst time : ", i + 1);
        scanf("%d", &BT[i]);
        RBT[i] = BT[i];
    }
    curt = 0;
    printf("\nEnter the Time slice value : ");
    scanf("%d", &TS);
    count = 0;
    while (1){
        for (i = 0; i < n; i++){
            if (RBT[i] > 0){
                if (RBT[i] > TS){
                    curt += TS;
                    RBT[i] -= TS;
                }
                else{
                    curt += RBT[i];
                    RBT[i] = 0;
                    TAT[i] = 0;
                    TAT[i] = curt;
                    WT[i] = TAT[i] - BT[i];
                    count++;
                    TTAT += TAT[i];
                    TWT += WT[i];
                }
            }
        }
        if (count == n)
            break;
    }
    printf("\nPID\tBT\tTAT\tWT\n");
    for (i = 0; i < n; i++)
        printf("\n%d\t%d\t%d\t%d\n", i + 1, BT[i], TAT[i], WT[i]);
    ATAT = (float)TTAT / n;
    AWT = (float)TWT / n;
    printf("\nTTAT : %d\tTWT : %d\n\nATAT : %.2f\tAWT : %.2f\n\n", TTAT, TWT, ATAT, AWT);
}