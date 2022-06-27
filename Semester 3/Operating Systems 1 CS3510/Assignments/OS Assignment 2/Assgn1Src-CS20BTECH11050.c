#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
  printf("This program gives the collatz sequence of a given number using multiple processes\n\n");

  int Num;
  printf("Enter the Number: ");
  scanf("%d",&Num); // Taking an input integer from user 

  /*collatz conjecture cannot be performed on non positive integers
            giving an error message for non positive integers*/ 
  if(Num <= 0) 
  {
    printf("Error! Non positive integers not allowed\n");
    return -1; 
  }
  
  else
  {
    pid_t pid;    // Taking a variable pid of type pid_t
    pid = fork(); // forking for child process
    
    if (pid < 0) // Output a stderr file with an error message and exit if fork gives an error
    {
      fprintf(stderr, "Fork Failed");
      return 1;
    }

    else if (pid == 0) // For a newly created child process pid = 0
    {
       printf("Child process of pid %d, whose parent pid is %d has started\n\n",getpid(),getppid());
       printf("{%d,",Num);
       while(Num!=1)
      {
         if(Num % 2 == 0)
            Num = Num/2;
         
         else
            Num = 3*Num + 1;

           printf("%d,",Num);
          
      }
        printf("\b}\n"); // \b removes the extra comma
    }

    else // Parent process (pid > 0) fork returns pid of child to the parent process
    { 
      printf("\nParent process of pid %d, will wait for child process of pid %d\n",getpid(),pid);
      wait(NULL);
      printf("The collatz sequence of %d is obtained above\n",Num);
      printf("\nChild process of pid %d Completed\n",pid);
      printf("Parent process of pid %d Completed\n",getpid());
    }
  }

  return 0;
}