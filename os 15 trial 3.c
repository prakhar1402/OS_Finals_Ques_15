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
}
