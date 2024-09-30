// code of  non primitive sjf shortest job first 



#include<stdio.h>
#include<limits.h>
#define max 10
void sjfNon(int at[], int bt[], int process[], int n){
    int wt[n], tat[n], ct[n], total_wt=0, total_tat=0;
    int current_time=0, minimum , min_index, completed[max] ={0}, complete =n;

    while(complete !=0){
        minimum= INT_MAX;
        min_index=-1;
        for(int j=0;j<n ;j++){
            if(at[j] <= current_time && completed[j]==0){
                if(bt[j] <minimum){
                    minimum= bt[j];
                    min_index = j; 
                }
            }
            
            if(bt[j] == minimum){
                if(at[j] < at[min_index]){
                    minimum = bt[j];
                    min_index = j;
                }
            }
        }
        
        if(min_index ==-1){
            current_time++;
        }
        else{
            completed[min_index] =1;
            complete--;
            current_time += bt[min_index];
            ct[min_index] =current_time; 
            tat[min_index] = current_time - at[min_index];
            wt[min_index] = tat[min_index] -bt[min_index];
            total_wt += wt[min_index];
            total_tat += tat[min_index];
        }
    }

  printf("\nProcesses\tArrival time\tBurst time\tCompletion time\tWaiting time\tTurn arounnd time\n");
    for(int i=0; i<n ; i++){
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",i+1, at[i], bt[i], ct[i], wt[i], tat[i]);
    }
    float avg_wt=(float)total_wt/n;
    float avg_tat= (float)total_tat/n;
    printf("Average waiting time - %2f", avg_wt);
    printf("\nAverage turn around time -%2f", avg_tat);
}

int main(){
    int n, at[max], bt[max], process[max];
    printf("Enter no. of processes: ");
    scanf("%d", &n);
    for(int i=0; i<n ;i++){
        printf("\nEnter Arrival time and burst time of process %d - ", i+1);
        scanf("%d %d", &at[i], &bt[i]);
        process[i] =i+1;
    }
    sjfNon(at,bt, process, n);
return 0;
}
