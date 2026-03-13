#include <stdio.h>

int main() {
    int n, i, time = 0, count = 0, highest;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    int pid[n], at[n], bt[n], pr[n], rt[n], ct[n], wt[n], tat[n];
    for(i = 0; i < n; i++) {
        pid[i] = i + 1;

        printf("\nProcess %d\n", i+1);
        printf("Arrival Time: ");
        scanf("%d", &at[i]);

        printf("Burst Time: ");
        scanf("%d", &bt[i]);

        printf("Priority: ");
        scanf("%d", &pr[i]);

        rt[i] = bt[i];
    }
    while(count < n) {
        highest = -1;
        int best = 999;
        for(i = 0; i < n; i++) {
            if(at[i] <= time && rt[i] > 0) {
                if(pr[i] < best) {
                    best = pr[i];
                    highest = i;
                }
            }
        }

        if(highest != -1) {
            rt[highest]--;
            time++;

            if(rt[highest] == 0) {
                count++;
                ct[highest] = time;
                tat[highest] = ct[highest] - at[highest];
                wt[highest] = tat[highest] - bt[highest];
            }
        }
        else {
            time++;
        }
    }
    printf("\nPID\tAT\tBT\tPR\tWT\tTAT\n");
    for(i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",
        pid[i], at[i], bt[i], pr[i], wt[i], tat[i]);
    }
    return 0;
}
