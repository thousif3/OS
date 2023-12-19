#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
  printf("Before fork\n");

  // Open the file after fork() to avoid sharing the file descriptor
  int fd1;

  printf("Process Id of parent %d\n", getpid());

  int rf = fork();

  if (rf == 0) {  // Child process
    printf("Inside child process\n");
    printf("Process Id of child pid= %d rf=%d\n", getpid(), rf);

    int a;  // Declare a for child process
    printf("Child process: to execute the prime number Program\n");
    printf("Enter a number: ");
    scanf("%d", &a);

    // Prime number check logic
    int flag = 0;
    for (int i = 2; i <= a / 2; i++) {
      if (a % i == 0) {
        flag = 1;
        break;
      }
    }
    if (flag == 0) {
      printf("Given number %d is a prime number\n", a);
    } else {
      printf("Given number %d is not a prime number\n", a);
    }

  } else if (rf > 0) {  // Parent process
    printf("Inside parent process\n");
    printf("Process Id of parent pid=%d rf=%d\n", getpid(), rf);

    int a;  // Declare a for parent process
    printf("Parent process: to execute the factorial of a number\n");
    printf("Enter a number: ");
    scanf("%d", &a);

    // Factorial calculation logic
    int total = 1;
    for (int i = 1; i <= a; i++) {
      total *= i;
    }
    printf("Factorial value is: %d\n", total);

  } else {  // Fork failed
    printf("Fork unsuccessful\nInside parent and Process Id of parent pid= %d rf=%d\n", getpid(), rf);
    exit(1);  // Exit with an error code
  }

  // Open the file here in both parent and child processes
  fd1 = open("kk.txt", O_RDONLY, 742);

  printf("End of process %d\n", getpid());
  return 0;
}
