#include<stdio.h>
#include<unistd.h>
int main()
{
    int i;
    printf("I am Demo file called by execvp() ");
    printf("\n");
    return 0;
}

//
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
        char *args[]={"./exec",NULL};
        execv(args[0],args);
        printf("Ending-----");
    return 0;
}

//Execvp.c

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
        char *args[]={"./3_6_demo",NULL};
        execvp(args[0],args);
        printf("Ending-----");
    return 0;
}
