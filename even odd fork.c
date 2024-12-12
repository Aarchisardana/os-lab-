// Objective:- To Demonstrate process creation with fork() where the parent process calculates
// the sum of even numbers and the child process calculates the sum of odd numbers from an array.

// Program:-
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
int main()
{
  int nums[]={1,2,3,4,5,6,7,8,9,10};
  int n=sizeof(nums)/sizeof(nums[0]);
  pid_t pid;
  pid=fork();
  if(pid<0)
  {
     fprintf(stderr,"Fork Failed");
     return 1;
  }
  else if(pid>0)
  { 
     int even_sum=0;
     for(int i=0;i<n;i++)
     {
       if(nums[i]%2==0)
        even_sum+=nums[i];
     }
     wait(NULL);
     printf("Parent Process Even Sum is %d\n",even_sum);
  }
  else
  {
     int odd_sum=0;
     for(int i=0;i<n;i++)
     {
       if(nums[i]%2!=0)
        odd_sum+=nums[i];
     }
     wait(NULL);
     printf("Child Process Odd Sum is %d\n",odd_sum);
     exit(0);
  }
  return 0;
}
 
