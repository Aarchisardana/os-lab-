fork valeh mae
 use carrefull  
  wait(NULL)
  perror
  
   pid<0  return 1

 use of sleep 

 for orphan
     if(pid<0)
  {
     perror("fork");
     return 1;
  }
 In this program, the sleep(2) and sleep(3) functions are used to introduce delays in the
 execution of the parent and child processes, respectively.
 These delays are crucial for demonstrating the orphan process concept

  orphan code is 
 
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
int main()
{
  pid_t pid;
  pid=fork();
  if(pid<0)
  {
     perror("fork");
     return 1;
  }
  else if(pid==0)
  { 
     printf("Child Process Pid is %d\nParent Process Pid is %d\n",getpid(),getppid());
     sleep(3);     // yah pae child soyah which means it was doind somwork 
    abb voh again chek kregah getppid sae kie parnet hae yah nhi 
     thenn uska new parnet bnegah 
    
     printf("Child process : I am still alive. My new parent is %d\n",getppid());
  }
  else
  {
     printf("Parent Process Pid is %d\nChild Process Pid is %d\n",getpid(),pid);   //dhyan sae yah pae pid ayegha nah
    // kie 2 bar getpid and parent kae lieyh bhi getpid ayegha yah 
     sleep(2);
     printf("Parent process exiting\n");
  }
  return 0;
}


getpid() is used to get the current process ID, which in this case is the parent process's ID. 
Since we are in the parent process, we want to print the parent's own PID.

getppid() is used to get the parent of the current process, which is the parent process's parent.
In most cases, this would be the shell or some other process that launched the progra




   
