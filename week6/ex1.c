#include <stdio.h>

int main() {
    int n;
    printf("Write number of processes:\n");
    scanf("%d", &n);
    char * spaces="   ";
    int arrTime[n], bursTime[n], CT[n], TAT[n], WT[n];
    float averageTAT = 0, averageWT=0;
    for(int i=0; i<n; i++){
        printf("Enter the process %d arrival time\n ", i);
        scanf("%d", &arrTime[i]);
        printf("Enter the process %d burst time\n ", i);
        scanf("%d", &bursTime[i]);
    }
    printf("P#\tCT\tTAT\tWT\n");
    for(int i=0; i<n; i++) {
        WT[i]=-arrTime[i];
        for(int j=0; j<i; j++)
            WT[i]+=bursTime[j];
        TAT[i]=WT[i]+bursTime[i];
        averageTAT+=TAT[i];
        averageWT+=WT[i];
        CT[i]=WT[i]+arrTime[i]+bursTime[i];
        printf("%d\t%d\t%d\t%d\n", i, CT[i], TAT[i],WT[i]);
    }
    printf("Average TAT=%f\nAverageWT=%f", averageTAT/n,averageWT/n);


    return 0;
}
