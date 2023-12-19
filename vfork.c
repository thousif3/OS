#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include <stdlib.h>

int main()
{
      printf(" Before fork");
      int fd1=open("kk.txt",O_RDONLY,742);  //kk.txt is a shared resource to parent and child process
      int a,b;   // a is shared  variable to parent and child process
      printf(" Process Id of parent %d \n",getpid());
	int rf=vfork();	
	if(rf==0)   // Upon successful execution fork() -->  Child process will execute below code in if block 
	{
	      printf("Inside child process \n");
	       printf(" Process Id of child pid= %d  rf=%d \n ",getpid(),rf);
	       scanf("%d",&b);
	       printf(" Inside child b value is b=%d",b);
	  
	}
	
	else if (rf> 0) // Upon successful execution fork() system call --> Parent process will exceute below code in elseif block
	{
	
	  printf("Inside parent process");
	  printf(" Process Id of parent pid=%d rf=%d \n",getpid(),rf);
	    scanf("%d",&a);
	    printf(" Inside parent a value is a=%d",a);
	}
	else{   // Upon uncusccessful execution  fork() system call Parent process will exceute below code in else block
                 printf(" Fork unsucessful \n Indide parent and Process Id of parent pid= %d  rf=%d \n  ",getpid(),rf);
         }
         printf("End of process %d\n", getpid());  
	return 0;
}
