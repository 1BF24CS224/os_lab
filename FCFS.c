 #include <stdio.h>

// Function to swap two numbers
void swap(int *a, int *b)
{
    int temp;
    temp = *a;   // store value of a in temp
    *a = *b;     // copy value of b into a
    *b = temp;   // copy temp into b (swap completed)
}

int main()
{
    int n,i,j;

    // Arrays to store process details
    int p[20];   // process numbers
    int at[20];  // arrival time
    int bt[20];  // burst time
    int ct[20];  // completion time
    int tat[20]; // turnaround time
    int wt[20];  // waiting time

    // Input number of processes
    printf("Enter number of processes: ");
    scanf("%d",&n);

    // Input arrival time and burst time for each process
    for(i=0;i<n;i++)
    {
        p[i] = i+1; // assign process number

        printf("\nProcess %d Arrival Time: ",p[i]);
        scanf("%d",&at[i]);

        printf("Process %d Burst Time: ",p[i]);
        scanf("%d",&bt[i]);
    }

    // Sort processes according to Arrival Time (FCFS rule)
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            // if arrival time of first process is greater, swap them
            if(at[i] > at[j])
            {
                swap(&at[i],&at[j]); // swap arrival times
                swap(&bt[i],&bt[j]); // swap burst times
                swap(&p[i],&p[j]);   // swap process numbers
            }
        }
    }

    // Calculate Completion Time for first process
    ct[0] = at[0] + bt[0];

    // Calculate Completion Time for remaining processes
    for(i=1;i<n;i++)
    {
        // if CPU is idle (next process arrives later)
        if(ct[i-1] < at[i])
            ct[i] = at[i] + bt[i];
        else
            ct[i] = ct[i-1] + bt[i];
    }

    // Calculate Turnaround Time and Waiting Time
    for(i=0;i<n;i++)
    {
        tat[i] = ct[i] - at[i]; // Turnaround Time
        wt[i] = tat[i] - bt[i]; // Waiting Time
    }

    // Display results
    printf("\nP\tAT\tBT\tCT\tTAT\tWT\n");

    for(i=0;i<n;i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",p[i],at[i],bt[i],ct[i],tat[i],wt[i]);
    }

    return 0; // program finished successfully
}
