// Objective:- To Demonstrate the creation of a child process and use of wait() function using the fork() system call in C.
//   pid ==0  fork 
//     pid ==1  parent 
//       pid ==-1 fork failed
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
int main(){
    pid_t pid;
    pid = fork();
     if(pid<0){
          printf("no child process \n");
     }
     else if(pid==0){
         printf("then your process id %d\n" ,pid);
         printf(" the child is %dgenerated\n" ,getppid());
     }
      else{
          wait(NULL);
          printf("parent id is %d", getpid());
      }
      
}




