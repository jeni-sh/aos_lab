#include <stdio.h>
int main()
{
    int n, i, qt, count=0, temp, sq=0, bt[10], wt[10], tat[10], rem_bt[10];
    float awt=0, atat=0;
    printf("Enter the number of process: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Enter the burst time of Process %d: ", i+1 );
        scanf("%d", &bt[i]);
        rem_bt[i]=bt[i];
    }
    printf("Enter quantum time: ");
    scanf("%d", &qt);
    while(1)
    {
        for(i=0, count=0; i<n; i++)
        {
            temp=qt;
            if(rem_bt[i]==0)
            {
                count++;
                continue;
            }
            if(rem_bt[i]>qt){
            rem_bt[i] = rem_bt[i]-qt;}
            else
            if(rem_bt[i]>=0){
                temp = rem_bt[i];
                rem_bt[i]=0;
            }
            sq=sq+temp;
            tat[i]=sq;

        }
        if(n==count)
        break;
    }
    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        wt[i]=tat[i]-bt[i];
        awt += wt[i];
        atat += tat[i];
        printf("%d\t%d\t\t%d\t\t%d\n", i+1, bt[i], wt[i], tat[i]);

    }
    
    printf("Average Waiting Time: %.2f\n", awt / n);
    printf("Average Turnaround Time: %.2f\n", atat / n);
    
    return 0;


}