/*Program to simulate SJF Processor scheduling algorithm. Compute TAT, WT, ATAT, AWT.*/

#include <stdio.h>
#include <stdlib.h>
int main(){
    int BT[10], j, n, i, TAT[10], WT[10], TTAT, TWT, temp;
    float ATAT, AWT;
    system("clear");
    printf("\nEnter the no of processes : ");
    scanf("%d", &n);
    TTAT = TWT = 0;
    ATAT = AWT = 0.0;
    for (i = 0; i < n; i++)
        TAT[i] = WT[i] = 0;
    for (i = 0; i < n; i++){
        printf("\nEnter BT of PID[%d] : \t", i + 1);
        scanf("%d", &BT[i]);
    }
    WT[0] = 0;
    for (i = 0; i < n; i++){
        for (j = i + 1; j < n; j++){
            if (BT[i] > BT[j]){
                temp = BT[i];
                BT[i] = BT[j];
                BT[j] = temp;
            }
        }
    }
    for (i = 1; i < n; i++)
        for (j = 0; j < i; j++)
            WT[i] += BT[j];
    for (i = 0; i < n; i++){
        TAT[i] = WT[i] + BT[i];
        TTAT += TAT[i];
        TWT += WT[i];
    }
    ATAT = (float)TTAT / n;
    AWT = (float)TWT / n;
    printf("\nPID\tBT\tWT\tTAT\n");
    for (i = 0; i < n; i++)
        printf("\n%d\t%d\t%d\t%d", i + 1, BT[i], WT[i], TAT[i]);
    printf("\n\nTTAT = %d\tTWT = %d\n\nATAT = %.2f\tAWT = %.2f\n\n", TTAT, TWT, ATAT, AWT);
}