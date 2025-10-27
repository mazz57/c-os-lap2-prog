#include <stdio.h>

3 int main() {
4 int time, burst_time[10], at[10], ct[10], tat[10], wt[10];
5 int sum_burst_time = 0, smallest, n, i;
6 int sumt = 0, sumw = 0;
7
8 printf("Enter the number of processes: ");
9 scanf("%d", &n);
10
11 for (i = 0; i < n; i++) {
12 printf("Arrival time for process P%d: ", i + 1);
13 scanf("%d", &at[i]);
14 printf("Burst time for process P%d: ", i + 1);
15 scanf("%d", &burst_time[i]);
16 sum_burst_time += burst_time[i];
17 }
18
19 int bt_copy[10];
20 for (i = 0; i < n; i++) {
21 bt_copy[i] = burst_time[i];
22 }
23
24 burst_time[9] = 9999;
25
26 printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
27
28 for (time = 0; time < sum_burst_time;) {
29 smallest = 9;
30 for (i = 0; i < n; i++) {
31 if (at[i] <= time && burst_time[i] > 0 && burst_time[i] < burst_time[
smallest])
32 smallest = i;
33 }
34
35 time += burst_time[smallest];
36 ct[smallest] = time;
37 tat[smallest] = ct[smallest] - at[smallest];
38 wt[smallest] = tat[smallest] - bt_copy[smallest];
39
40 sumt += tat[smallest];
41 sumw += wt[smallest];
42
43 burst_time[smallest] = 0;
44
45 printf("P%d\t%d\t%d\t%d\t%d\t%d\n", smallest + 1, at[smallest], bt_copy[
smallest], ct[smallest], tat[smallest], wt[smallest]);
46 }
47
48 printf("\nAverage Waiting Time = %.2f", (float)sumw / n);
49 printf("\nAverage Turnaround Time = %.2f\n", (float)sumt / n);
50
51 return 0;