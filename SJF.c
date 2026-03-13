#include <stdio.h>
int main()
{
    int n,i,j;

    int p[20];
    int at[20];
    int bt[20];
    int ct[20];
    int tat[20];
    int wt[20];
    int completed[20] = {0};

    int time = 0, count = 0;
    int min_bt, index;

    printf("Enter number of processes: ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        p[i] = i+1;

        printf("\nProcess %d Arrival Time: ",p[i]);
        scanf("%d",&at[i]);

        printf("Process %d Burst Time: ",p[i]);
        scanf("%d",&bt[i]);
    }
    while(count < n)
    {
        min_bt = 9999;
        index = -1;

        for(i=0;i<n;i++)
        {
            if(at[i] <= time && completed[i]==0)
            {
                if(bt[i] < min_bt)
                {
                    min_bt = bt[i];
                    index = i;
                }
            }
        }

        if(index == -1)
        {
            time++;
        }
        else
        {
            time = time + bt[index];
            ct[index] = time;
            completed[index] = 1;
            count++;
        }
    }
    for(i=0;i<n;i++)
    {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
    }
    printf("\nP\tAT\tBT\tCT\tTAT\tWT\n");
    for(i=0;i<n;i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",p[i],at[i],bt[i],ct[i],tat[i],wt[i]);
    }
    return 0;
}
