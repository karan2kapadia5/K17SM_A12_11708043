//Demand Paged Memory 
#include<stdio.h>
#include<math.h>
int main () {
	//Initializing variables with given values 
	float page_fault_not_modify = 8;
	float page_fault_modify = 20;
	float memory_access_time = 100;
	float effective_access_time = 200;
	float percentage_modified = 70;
	float page_fault_rate;
	char ch = '%';
	
	//Displaying the details of values that are given
	printf("Values Given : ");
	printf("\nPage fault when replaced page is not modified : %.0f ms", page_fault_not_modify);
	printf("\nPage fault when replaced page is modify : %.0f ms", page_fault_modify);
	printf("\nMemory access time : %.0f ns", memory_access_time);
	printf("\nEffective access time : %.0f ns", effective_access_time);
	printf("\nPercentage modified : %.0f %c", percentage_modified, ch);
	printf("\n\n");
	
	//Displaying Formula
	printf("Formula : \n\nEffective_access_time = ");
	printf("page_fault_rate*(percentage_modified * page_fault_modify + (1-percentage_modify)*page_fault_not_modify)+(1-page_fault_rate)*memory_access_time");
	printf("\n\nPage_fault_rate =  \t\t\t\tEffective_access_time - memory_access_time");
	printf("\n\t\t_________________________________________________________________________________________________________");
	printf("\n\n\t\t(percentage_modified * page_fault_modify) +(1-percentage_modified)*page_fault_not_modify - memory_access_time");
	
	//Converting values into ms and ns
	page_fault_not_modify = 0.008f;
	page_fault_modify = 0.02f;
	memory_access_time = 1e-7f;
	effective_access_time = 2e-7f;
	percentage_modified = 0.7f;
	
	//Calculating page fault rate
	float X = (percentage_modified * page_fault_modify + (1-percentage_modified)*page_fault_not_modify);
	page_fault_rate = (effective_access_time - memory_access_time) / (X - memory_access_time);
	printf("\n\nPage fault rate is : %f",page_fault_rate);
	
	//Taking values from the user to calculate the pafe fault rate
	printf("\n\n\nEnter your values : ");
	printf("\nPage fault when replaced page is not modified : ");
	scanf("%f", &page_fault_not_modify);
	page_fault_not_modify *= pow(10,-3);
	printf("Page fault when replaced page is modify : ");
	scanf("%f", &page_fault_modify);
	page_fault_modify *= pow(10,-3);
	printf("Memory access time : ");
	scanf("%f", &memory_access_time);
	memory_access_time *= pow(10,-9);
	printf("Effective access time : ");
	scanf("%f", &effective_access_time);
	effective_access_time *= pow(10,-9);
	printf("Percentage modified : ");
	scanf("%f", &percentage_modified);
	percentage_modified = (percentage_modified/100);
	
	//Calculating page fault rate	
	double X2 = (percentage_modified * page_fault_modify + (1-percentage_modified)*page_fault_not_modify);
	page_fault_rate = (effective_access_time - memory_access_time) / (X2 - memory_access_time);
	printf("\n\nPage fault rate is : %f",page_fault_rate);
	return 0;	
}
