#include<stdio.h>
struct process {
    char process_name;
    int arrival_time, burst_time, ct, waiting_time, turnaround_time, priority;
    int status;
}p[10];
int limit;
 
//function to sort processes by arrival time
void Arrival_Time_Sorting() {
    struct process temp;
    int i, j;
    for(i = 0; i < limit - 1; i++) {
        for(j = i + 1; j < limit; j++) {
            if(p[i].arrival_time > p[j].arrival_time) {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
}
 
void main() {
	int i, time = 0, burst_time = 0, largest;
	char c;
	float wait_time = 0, turnaround_time = 0; 
	float average_waiting_time, average_turnaround_time;
	printf("\nEnter Total Number of Processes : ");
	scanf("%d", &limit);
 
    //taking input process details
    for(i = 0, c = 'A'; i < limit; i++, c++) {
        p[i].process_name = c;
        printf("\nEnter Details For Process[%C] : \n", p[i].process_name);
        printf("Enter Arrival Time : ");
        scanf("%d", &p[i].arrival_time );
        printf("Enter Burst Time : ");
        scanf("%d", &p[i].burst_time);
        printf("Enter Priority : ");
        scanf("%d", &p[i].priority);
        p[i].status = 0;
        burst_time = burst_time + p[i].burst_time;
    }
      
    Arrival_Time_Sorting(); //sorting by arrival time
    p[9].priority = -9999;
    printf("\nProcess Name\tArrival Time\tBurst Time\tPriority\tWaiting Time");
    for(time = p[0].arrival_time; time < burst_time;) {
        largest = 9;
        for(i = 0; i < limit; i++) {
            if(p[i].arrival_time <= time && p[i].status != 1 && p[i].priority > p[largest].priority)
                largest = i;
        }
        time = time + p[largest].burst_time;
        p[largest].ct = time;
        p[largest].waiting_time = p[largest].ct - p[largest].arrival_time - p[largest].burst_time;
        p[largest].turnaround_time = p[largest].ct - p[largest].arrival_time;
        p[largest].status = 1;
        wait_time = wait_time + p[largest].waiting_time;
        turnaround_time = turnaround_time + p[largest].turnaround_time;
        printf("\n%c\t\t%d\t\t%d\t\t%d\t\t%d", p[largest].process_name,
        p[largest].arrival_time, p[largest].burst_time,
        p[largest].priority, p[largest].waiting_time);
    }
    average_waiting_time = wait_time / limit;  //cal avg waiting time
    average_turnaround_time = turnaround_time / limit;
    printf("\n\nAverage waiting time:%f\n", average_waiting_time);
    printf("Average Turnaround Time:%f\n", average_turnaround_time);
}
