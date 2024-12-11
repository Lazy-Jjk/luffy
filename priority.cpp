#include <stdio.h> 
void findAvgTime(int n, int bt[], int at[], int pr[]) { 
int wt[n], tat[n], totalWT = 0, totalTAT = 0; 
int complete[n]; 
int i, j, t = 0, minPr, minIdx; 
for (i = 0; i < n; i++) { 
wt[i] = 0; 
tat[i] = 0; 
complete[i] = 0; 
} 
for (i = 0; i < n; i++) { 
minPr = 9999;   
minIdx = -1; 
for (j = 0; j < n; j++) { 
if (at[j] <= t && !complete[j] && pr[j] < minPr) { 
minPr = pr[j]; 
minIdx = j; 
} 
} 
//if (minIdx == -1) { 
//t++;  
//continue; 
//} 
complete[minIdx] = 1; 
t += bt[minIdx]; 
wt[minIdx] = t - bt[minIdx] - at[minIdx]; 
if (wt[minIdx] < 0) wt[minIdx] = 0; 
tat[minIdx] = bt[minIdx] + wt[minIdx]; 
} 
		printf("P  BT   AT  PR  WT  TAT\n"); 
for (int i = 0; i < n; i++) { 
totalWT += wt[i]; 
totalTAT += tat[i]; 
printf("%d   %d   %d   %d  %d   %d\n", i+1, bt[i], at[i],pr[i], wt[i], tat[i]); 
} 
printf("Avg WT = %.2f\n", (float)totalWT / n); 
printf("Avg TAT = %.2f\n", (float)totalTAT / n);
}
int main() { 
int i,at[4],bt[4],pr[4];
for(i=0;i<4;i++){
	printf("at:\n");
	scanf("%d",&at[i]);
	printf("bt:\n");
	scanf("%d",&bt[i]);

printf("pr:\n");
scanf("%d",&pr[i]);
}
int n = sizeof(bt) / sizeof(bt[0]); 
findAvgTime(n, bt, at,pr); 
return 0; 
}
