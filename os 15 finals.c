#include<stdio.h>
#include<limits.h>
int main(){
    int no;
    printf("Welcome to the wait time and turnaround time calculator!");
    printf("\nEnter the number of processes: ");
    scanf("%d",&no);
    int burst_time[no+2],arrival_time[no+2],turnaround_time[no+2],wait_time[no+2],temp[no+2];
    int total_wait_time=0,total_turn_time=0;
    int i,time,count=0,mini,finish;
    for(i=0;i<no;i++){
        printf("\nEnter the arrival time of the process %d: ",i+1);
        scanf("%d",&arrival_time[i]);
        printf("Enter the burst time of the process %d: ",i+1);
        scanf("%d",&burst_time[i]);
        temp[i]=burst_time[i];
    }

    burst_time[no+1]=INT_MAX;
    for(time=0;count!=no;time++){
        mini=no+1;
        for(i=0;i<no;i++){
            if(arrival_time[i]<=time && burst_time[i]<burst_time[mini] && burst_time[i]>0){
                mini=i;
            }
        }

        burst_time[mini]--;
        if(burst_time[mini]==0){
                count++;
                finish=time+1;
                turnaround_time[mini]=finish-arrival_time[mini];
                wait_time[mini]=turnaround_time[mini]-temp[mini];
                total_wait_time=finish+total_wait_time-arrival_time[mini]-temp[mini];
                total_turn_time=finish+total_turn_time-arrival_time[mini];
        }
    }
    printf("\nProcesses|Turnaround Time(TAT)|Waiting Time(WT)");
    printf("\n-----------------------------------------------\n");
    for(i=0;i<no;i++){
        printf("P[%d]\t\t%d\t\t   %d\n",i+1,turnaround_time[i],wait_time[i]);
    }

    printf("\nAverage turnaround time of all the processes is: %f",total_turn_time*1.0/no);
    printf("\nAverage waiting time of all the processes is: %f",total_wait_time*1.0/no);

}
