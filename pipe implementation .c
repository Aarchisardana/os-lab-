#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
int main()
{
    char arr[100] , str[100] ; 
     int fd[2] , nbw,  nbr ;
    pid_t pid ;
    pipe(fd);                    //  create a pipe 
    // without  this how it wil write so printing wroing ans
      pid = fork();
       if(pid == 0 ){
            printf("enter the string: ");
            gets(str);
            nbw = write(fd[1], str, strlen(str));
            printf(" no of  bytes write is %d\n" , nbw);
            exit(0);
       }
        else{
             nbr = read(fd[0], arr, sizeof(arr));
             arr[nbr] ='\0';
           printf(" parent has read %d bytes : %s" , nbr , arr);
                                 //   i had use %s  for printing arr so careful
        }
    return 0;
}
