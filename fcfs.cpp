#include <stdio.h> 
void findWT(int n, int bt[], int at[]) { 
int wt[n];
int tat[n];
wt[0] = 0; 
for (int i = 1; i < n; i++) { 
wt[i] = bt[i-1] + wt[i-1] - at[i] + at[i-1]; 
if (wt[i] < 0) wt[i] = 0; 
} 
for (int i = 0; i < n; i++) { 
tat[i] = bt[i] + wt[i]; 
} 
int totalWT = 0, totalTAT = 0;  
printf("ID  BT  AT  WT  TAT\n"); 
for (int i = 0; i < n; i++) { 
totalWT += wt[i]; 
totalTAT += tat[i]; 
printf("%d   %d   %d   %d   %d\n", i+1, bt[i], at[i], wt[i], tat[i]); 
} 
printf("Avg WT = %.2f\n", (float)totalWT / n); 
printf("Avg TAT = %.2f\n", (float)totalTAT / n); 
}
int main() { 
int i,at[5],bt[5];
for(i=0;i<5;i++){
	printf("at:\n");
	scanf("%d",&at[i]);
	printf("bt:\n");
	scanf("%d",&bt[i]);
} 
int n = sizeof(bt) / sizeof(bt[0]); 
findWT(n, bt, at); 
return 0; 
} 
