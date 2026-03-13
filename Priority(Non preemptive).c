#include <stdio.h>

int main()
{
    int n, i, pos;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    int pid[n], at[n], bt[n], pr[n], wt[n], tat[n], ct[n];
    int completed[n];
    for(i = 0; i < n; i++)
        completed[i] = 0;
    for(i = 0; i < n; i++)
    {
        pid[i] = i + 1;

        printf("\nProcess %d\n", i + 1);
        printf("Arrival Time: ");
        scanf("%d", &at[i]);

        printf("Burst Time: ");
        scanf("%d", &bt[i]);

        printf("Priority: ");
        scanf("%d", &pr[i]);
    }
    int time = 0, count = 0;
    while(count < n)
    {
        int highest = 999;
        pos = -1;

        for(i = 0; i < n; i++)
        {
            if(at[i] <= time && completed[i] == 0)
            {
                if(pr[i] < highest)
                {
                    highest = pr[i];
                    pos = i;
                }
            }
        }
        if(pos != -1)
        {
            time += bt[pos];
            ct[pos] = time;
            tat[pos] = ct[pos] - at[pos];
            wt[pos] = tat[pos] - bt[pos];
            completed[pos] = 1;
            count++;
        }
        else
        {
            time++;
        }
    }
    printf("\nPID\tAT\tBT\tPR\tWT\tTAT\n");
    for(i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",
        pid[i], at[i], bt[i], pr[i], wt[i], tat[i]);
    }
    return 0;
}
