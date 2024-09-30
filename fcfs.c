//first come first server  code  




#include<stdio.h>
#define max 30
   void fcfs( int at[] , int bt[] , int process[] , int n ){
     int t  ,tat[n] , wt[n],  ct[n] ;
       int current_time= 0 , total_wt=0 , total_tat=0;
  //sort krro arrival tiem kae accoridng 
  for(int i=0; i<n; i++){
      for(int j= i+1; j<n; j++){
          if(at[i]>at[j]){
      //swap
      t =at[i];
      at[i] = at[j];
      at[j] = t ;
       // swap  burts time also 
       
       t = bt[i];
       bt[i] = bt[j];
       bt[j] =t;
       
       //swap process id as well
        t = process[i];
       process[i] = process[j];
       process[j] =t;
       
      
  }
 }
  }
   current_time =  at[0];
    // Calculate completion time, waiting time, and turnaround time
   for(int k=0; k<n; k++){
    ct[k] = current_time + bt[k];
    current_time =ct[k];
    tat[k] = ct[k]- at[k];
    wt[k] = tat[k]- bt[k];
    
    
      total_wt += wt[k];
        total_tat += tat[k];
    }
       float avg_wt = (float)total_wt / n;
    float avg_tat = (float)total_tat / n;
    
    // Output the results
    printf("\nPROCESSES\tArrival time\tBurst time\tCompletion time\tWaiting time\tTurn around time\n");
    for(int i = 0; i < n; i++){
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", process[i], at[i], bt[i], ct[i], wt[i], tat[i]);
    }
    printf("Average waiting time - %f", avg_wt);
    printf("\nAverage turn around time - %f", avg_tat);
}
  
    int main(){
          int  n, at[max], bt[max], process[max];
         printf("Enter the number of processes: ");
    scanf("%d", &n);
    
     for(int i = 0; i < n; i++){
        printf("Enter Arrival time of process %d: ", i + 1);
        scanf("%d", &at[i]);
        process[i] = i + 1; // Process number // imp hae
       
    }
     for(int i = 0; i < n; i++){
        printf("Enter burst time of process %d: ", i + 1);
        scanf("%d", &bt[i]);
    }
    
    fcfs(at , bt , process , n);
    }
