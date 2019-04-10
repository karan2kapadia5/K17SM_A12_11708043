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
	int i, time = 0, burst_time = 0, largest, bt[10], count=0, cs=0, temp=0, limit, flag=0, total=0, rt[20], k, x;
	char queue1[50], queue[50];
	char c, f;
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
        bt[i] = p[i].burst_time;
        printf("Enter Priority : ");
        scanf("%d", &p[i].priority);
        p[i].status = 0;
        burst_time = burst_time + p[i].burst_time; //Calculating total burst time
    }
      
    Arrival_Time_Sorting(); //sorting by arrival time
    p[9].priority = -9999;
    for(time = p[0].arrival_time; time < burst_time + cs;) {
        largest = 9;
        for(i = 0; i < limit; i++) {
            if(p[i].arrival_time <= time && p[i].status!=1 && p[i].priority > p[largest].priority) {
                largest = i;
			}
        }
        time += 1;
		bt[largest] -= 1;
		count++;
        if(bt[largest	] == 0)
        	p[largest].status = 1;
        queue1[temp] = p[largest].process_name;
        temp++;
    }
    
    //Appying preemption on the given processes and adding 2 sec latency
    for(k=0;k<21;k++) {
    	if(flag==0){
			queue[0] = queue1[k];
			flag = 1;
			total = 1;
			rt[0] = total;
		}
		else {
			queue[flag] = queue1[k];
			if(queue[flag] == queue[flag-1]){
				total++;
				rt[flag-1]=total;
			}
			else {
				total+=2;
				total++;
				rt[flag] = total;
				flag++;
			}
		}	
	}
	printf("\n");
	for(x=0;x<9;x++)
		printf("%c\t", queue[x]);
	printf("\n");
	for(x=0;x<9;x++)
		printf("%d\t", rt[x]);
}
