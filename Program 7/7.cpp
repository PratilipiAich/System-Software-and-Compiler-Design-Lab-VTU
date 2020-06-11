/*
Design, develop and implement a C/C++/Java program to simulate the working of 
Shortest remaining time (SJF) and Round Robin (RR) scheduling algorithms. 
Experiment with different quantum sizes for RR algorithm.
*/

#include<stdio.h>

typedef struct J {
	int arrival, finish, burst, tat, wt;
} Job;

void scheduler(Job job[], int n, int quantum, int c) {
	int bursts[100];
	
  for(int i=0;i<n;i++)
		bursts[i] = job[i].burst;
	
  int t = 0, done = 0, curr, diff;
	
	// RR
	if (c == 0) 
		curr = -1;
		
	// SJF	
	else 
		curr = 0;
	
  while (done < n) {
  	
  		// SJF	
		if(c == 1) {
			for(int x=0; x<n; x++) {
				
				// If current job has finished	
				if(job[curr].burst == 0) 
					curr = x;
				if(job[x].burst < job[curr].burst)		
					if(job[x].burst > 0 && job[x].arrival <= t)
						curr = x;
			}
			
			diff = 1;		// Preemptive mode
			
			// diff = job[curr].burst;	// Non preemptive mode
		} else { // RR
			while(1) {
				curr = (curr + 1) % n;
				if(job[curr].burst != 0)
					break;
			}
      
			diff = (quantum <= job[curr].burst) ? quantum : job[curr].burst;		
		}
		
    job[curr].burst -= diff;
		t += diff;
		
    // If curr job has finished
    if(job[curr].burst == 0) {
			done++;		
			job[curr].finish = t;		
		}
	}	

	if(c == 1)	
		printf("\nShortest Job First (SJF) schedulind details are:\n");
	else
		printf("\nRound Robin (RR)) scheduling details are:\n");	
	
	// Restore burst values for displaying	
  for (int i=0; i<n; i++) 
		job[i].burst = bursts[i];
	
  printf("\nJob\tTaT\tWT\n");
	for(int i=0; i<n; i++) {
		job[i].tat = job[i].finish - job[i].arrival * c;
		job[i].wt = job[i].tat - job[i].burst;
		printf("%d\t%d\t%d\n", i, job[i].tat, job[i].wt);
	}
}

int main() {
	Job job[100];
	int n, quantum, choice;
	
  printf("Enter the number of processes/jobs:\t");
	scanf("%d", &n);
	
  printf("\nEnter Arrival and Burst time (repectively):\n");
	for(int i=0;i<n;i++) {
		printf("Process/Job %d: ", i);
		scanf("%d%d", &job[i].arrival, &job[i].burst);
	}

	printf("\n1: Round Robin\n2: Shortest Job First\n");
	scanf("%d", &choice);
	switch (choice) {
		case 1:	
			printf("Enter quantum size for Round Robin:\t");
			scanf("%d",&quantum);
			scheduler(job, n, quantum, 0);	
			break;
		case 2:scheduler(job, n, quantum, 1);
	}
}
