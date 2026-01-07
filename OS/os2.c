#include <stdio.h>
int main()
{
    int pid[15], bt[15], n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter process id of all the processes: ");
    for(int i = 0; i < n; i++) scanf("%d", &pid[i]);
    printf("Enter burst time of all the processes: ");
    for(int i = 0; i < n; i++) scanf("%d", &bt[i]);
    int wt[n]; 
    wt[0] = 0;
    for(int i = 1; i < n; i++)
        wt[i] = bt[i-1] + wt[i-1];
    float twt = 0, tat = 0;
    printf("Process ID Burst Time Waiting Time TurnAround Time\n");
    for(int i = 0; i < n; i++)
    {
        printf("%d\t\t%d\t\t%d\t\t%d\n", pid[i], bt[i], wt[i], bt[i] + 
wt[i]);
        twt += wt[i];
        tat += bt[i] + wt[i];
    }
    printf("Avg. waiting time= %f\n", twt / n);
    printf("Avg. turnaround time= %f", tat / n);
    return 0;
}