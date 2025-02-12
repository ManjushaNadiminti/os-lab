#include<stdio.h>

int main() {
    int p[20], bt[20], wt[20], tat[20], pri[20], i, k, n, temp;
    float wtavg = 0, tatavg = 0;
    printf("\nEnter the number of processes: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        p[i] = i;
        printf("Enter burst time and priority for process %d: ", i);
        scanf("%d %d", &bt[i], &pri[i]);
    }
    for(i = 0; i < n; i++) {
        for(k = i + 1; k < n; k++) {
            if(pri[i] > pri[k]) {
                temp = p[i];
                p[i] = p[k];
                p[k] = temp;
                temp = bt[i];
                bt[i] = bt[k];
                bt[k] = temp;
                temp = pri[i];
                pri[i] = pri[k];
                pri[k] = temp;
            }
        }
    }
    wt[0] = 0; 
    tat[0] = bt[0]; 
    
   
    for(i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];  
        tat[i] = tat[i - 1] + bt[i];    
        wtavg += wt[i];
        tatavg += tat[i];
    }
    printf("\n\tProcess\t\tPriority\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for(i = 0; i < n; i++) {
        printf("\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i], pri[i], bt[i], wt[i], tat[i]);
    }
    printf("\nAverage Waiting Time: %.2f", wtavg / n);
    printf("\nAverage Turnaround Time: %.2f", tatavg / n);

    return 0;
}
