#include <stdio.h>

void calculateTimes(int arrival[], int burst[], int priority[], int n) {
    int remaining_time[n], completion_time[n], turn_around_time[n], waiting_time[n];
    int total_time = 0, completed = 0, min_priority = 1000, current_process = -1;

    // Initialize remaining time
    for (int i = 0; i < n; i++) {
        remaining_time[i] = burst[i];
    }

    // Loop until all processes are completed
    while (completed < n) {
        min_priority = 1000;
        current_process = -1;

        // Find the process with the highest priority (lowest priority number)
        for (int i = 0; i < n; i++) {
            if (arrival[i] <= total_time && remaining_time[i] > 0) {
                if (priority[i] < min_priority) {
                    min_priority = priority[i];
                    current_process = i;
                }
            }
        }

        // Execute the selected process for 1 unit of time
        if (current_process != -1) {
            remaining_time[current_process]--;
            total_time++;

            // If the process finishes, update its completion time, waiting time, and turnaround time
            if (remaining_time[current_process] == 0) {
                completion_time[current_process] = total_time;
                turn_around_time[current_process] = completion_time[current_process] - arrival[current_process];
                waiting_time[current_process] = turn_around_time[current_process] - burst[current_process];
                completed++;
            }
        } else {
            // If no process is ready, just increment time
            total_time++;
        }
    }

    // Calculate average turnaround and waiting times
    float total_turnaround_time = 0, total_waiting_time = 0;
    printf("\nProcess ID  Arrival Time  Burst Time  Priority  Completion Time  Turnaround Time  Waiting Time\n");
    for (int i = 0; i < n; i++) {
        total_turnaround_time += turn_around_time[i];
        total_waiting_time += waiting_time[i];
        printf("%4d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               i + 1, arrival[i], burst[i], priority[i], completion_time[i], turn_around_time[i], waiting_time[i]);
    }

    printf("\nAverage Turnaround Time: %.2f", total_turnaround_time / n);
    printf("\nAverage Waiting Time: %.2f", total_waiting_time / n);
}

int main() {
    int n;

    // Get the number of processes from the user
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int arrival[n], burst[n], priority[n];

    // Get the process details from the user
    for (int i = 0; i < n; i++) {
        printf("\nEnter details for Process %d\n", i + 1);
        printf("Arrival Time: ");
        scanf("%d", &arrival[i]);
        printf("Burst Time: ");
        scanf("%d", &burst[i]);
        printf("Priority: ");
        scanf("%d", &priority[i]);
    }

    // Sort processes by arrival time
    sortProcessesByArrivalTime(arrival, burst, priority, n);

    // Calculate the completion, turnaround, and waiting times
    calculateTimes(arrival, burst, priority, n);

    return 0;
}

