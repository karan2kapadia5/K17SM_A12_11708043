#include<stdio.h>
struct process {
    char process_name;
    int arrival_time, burst_time, waiting_time, priority, rb_time, status;
}p[10];

int limit, i, j, largest, bt[10], rt[20], k, x, rtime;
int time=0, burst_time=0, count=0, cs=0, temp=0, flag=0, total=0;
char queue1[50], queue[50], c, f;

//function to sort processes by arrival time
void Arrival_Time_Sorting() {
    struct process temp;
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

//function to calculate waiting time for each processes
void waiting_time_calculate() {
	for(rtime=0;rtime<flag+1;rtime++) {
		switch(queue[rtime]) {
			case 'A':
				if(p[0].waiting_time == 0)
					p[0].waiting_time = rt[rtime] - p[0].arrival_time;
				else 
					p[0].waiting_time += (rt[rtime] - p[0].rb_time);	
				p[0].rb_time = rt[rtime+1];
				break;
			case 'B' :
				if(p[1].waiting_time == 0)
					p[1].waiting_time = rt[rtime] - p[1].arrival_time;
				else
					p[1].waiting_time += (rt[rtime] - p[1].rb_time - 1);
				p[1].rb_time = rt[rtime+1];
				break;
			case 'C' :
				if(p[2].waiting_time == 0)
					p[2].waiting_time = rt[rtime] - p[2].arrival_time;
				else
					p[2].waiting_time += (rt[rtime] - p[2].rb_time);
				p[2].rb_time = rt[rtime+1];
				//printf("\n\n%d", p[1].waiting_time);
				break;
			case 'D' :
				if(p[3].waiting_time == 0)
					p[3].waiting_time = rt[rtime] - p[3].arrival_time;
				else
					p[3].waiting_time += (rt[rtime] - p[3].rb_time);
				p[3].rb_time = rt[rtime+1];
				break;
			case 'E' : 
				if(p[4].waiting_time == 0)
					p[4].waiting_time = rt[rtime] - p[4].arrival_time;
				else
					p[4].waiting_time += (rt[rtime] - p[4].rb_time);
				p[4].rb_time = rt[rtime+1];
				break;
			case 'F' : 
				if(p[5].waiting_time == 0)
					p[5].waiting_time = rt[rtime] - p[5].arrival_time;
				else
					p[5].waiting_time += (rt[rtime] - p[5].rb_time);
				p[5].rb_time = rt[rtime+1];
				break;
			default :
				printf("\nInvalid\n");
		}
	}
}
 
void main() {
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
        p[i].waiting_time = 0;
    }
      
    Arrival_Time_Sorting(); //sorting by arrival time
    p[9].priority = -9999;
    for(time = p[0].arrival_time; time < burst_time + cs;) {
        largest = 9;
        for(i = 0; i < limit; i++) {
            if(p[i].arrival_time <= time && p[i].status!=1 && p[i].priority > p[largest].priority)
                largest = i;
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
    for(k=0;k<temp;k++) {
    	if(flag==0){
			queue[0] = queue1[k];
			flag = 1;
			total = 1;
			rt[0] = 0;
			rt[1] = total;
		}
		else {
			queue[flag] = queue1[k];
			if(queue[flag] == queue[flag-1]){
				total++;
				rt[flag]=total;
			}
			else {
				//total+=2;   //For the latency of 2 sec
				total++;
				rt[flag+1] = total;
				flag++;
			}
		}	
	}
	printf("\n\t");
	for(x=0;x<flag;x++)
		printf("%c\t", queue[x]);
	printf("\n");
	for(x=0;x<flag+1;x++)
		printf("%d\t", rt[x]);
		
	//To calculate waiting time for each process
	waiting_time_calculate();
	p[0].waiting_time--;
	printf("\n");
	for(x=0; x < limit; x++) {
		printf("\n Waiting time of %c process is : %d", p[x].process_name, p[x].waiting_time);
		printf("\n Turn Around time of %c process is : %d\n", p[x].process_name, (p[x].waiting_time+p[x].burst_time));
	}
}
