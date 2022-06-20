#include<stdio.h>

int main() {
    int noOfPrcess;
    int process[noOfPrcess];
    printf("Enter the number of processes: ");
    scanf("%d", &noOfPrcess);

    int priority[noOfPrcess];
    int burstTime[noOfPrcess];

    printf("Enter the priority and burst time of each process: \n");
    for (int i = 0; i < noOfPrcess; i++) {
        process[i] = i + 1;
        printf("Process %d\n", i + 1);
        printf("Priority: ");
        scanf("%d", &priority[i]);
        printf("Burst time: ");
        scanf("%d", &burstTime[i]);
    }

    //sorting according to priority
    for(int i = 0; i < noOfPrcess; i++) {
        for(int j = 0; j < noOfPrcess; j++) {
            if(priority[i] < priority[j]) {
                int temp = process[i];
                process[i] = process[j];
                process[j] = temp;

                temp = priority[i];
                priority[i] = priority[j];
                priority[j] = temp;

                temp = burstTime[i];
                burstTime[i] = burstTime[j];
                burstTime[j] = temp;
            }
        }
    }

    int waitTime[noOfPrcess];
    int turnAroundTime[noOfPrcess];

    for(int i = 0; i < noOfPrcess; i++) {
        if(i == 0) {
            waitTime[i] = 0;
        } else {
            waitTime[i] = waitTime[i - 1] + burstTime[i - 1];
        }
        turnAroundTime[i] = waitTime[i] + burstTime[i];
    }

    printf("\nProcess\t\tpriority\tBurst Time\tWait Time\tTurn Around Time\n");
    for(int i=0; i<noOfPrcess; i++) {
        printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\n", process[i], priority[i], burstTime[i], waitTime[i], turnAroundTime[i]);
    }

    int totalWaitTime = 0;
    int totalTurnAroundTime = 0;

    for(int i=0; i<noOfPrcess; i++) {
        totalWaitTime += waitTime[i];
        totalTurnAroundTime += turnAroundTime[i];
    }

    float avgWaitTime = (float)totalWaitTime/noOfPrcess;
    float avgTurnAroundTime = (float)totalTurnAroundTime/noOfPrcess;

    printf("\nAverage wait time: %f\n", avgWaitTime);
    printf("Average turn around time: %f\n", avgTurnAroundTime);

    return 0;
}