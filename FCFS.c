#include <stdio.h>

void findWaitingTime(int processes[], int n, int bt[], int wt[])
{
  wt[0] = 0;

  for (int i = 1; i < n; i++)
    wt[i] = bt[i - 1] + wt[i - 1];
}

void findTurnAroundTime(int processes[], int n, int bt[], int wt[], int tat[])
{
  for (int i = 0; i < n; i++)
    tat[i] = bt[i] + wt[i];
}

void findAverageTime(int processes[], int n, int bt[])
{
  int wt[1000], tat[1000];

  findWaitingTime(processes, n, bt, wt);
  findTurnAroundTime(processes, n, bt, wt, tat);

  printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");

  float total_wt = 0, total_tat = 0;

  for (int i = 0; i < n; i++)
  {
    total_wt += wt[i];
    total_tat += tat[i];

    printf("%d\t%d\t\t%d\t\t%d\n", processes[i], bt[i], wt[i], tat[i]);
  }

  printf("\nAverage Waiting Time: %.2f", total_wt / n);
  printf("\nAverage Turnaround Time: %.2f\n", total_tat / n);
}

int main()
{
  int n;

  printf("Enter the number of processes: ");
  scanf("%d", &n);

  int processes[1000];
  int burst_time[1000];

  printf("Enter the burst time for each process:\n");

  for (int i = 0; i < n; i++)
  {
    printf("Enter burst time for process %d: ", i + 1);
    scanf("%d", &burst_time[i]);
    processes[i] = i + 1;
  }

  findAverageTime(processes, n, burst_time);

  return 0;
}
