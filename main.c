#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int isnumber(int number, char snumber)
{
    if ((number!=0) || (snumber=='0'))
    {
        return 0;
    }
    else
    {
        printf("error: operand isn't number");
        exit(1);
    }
}

int calc(int a, int b, char operator)
{
	switch (operator)
	{
	case '+':
		return a+b;
	case '-':
		return a-b;
	case '*':
		return a*b;
	case '%':
		if (b==0)
		{
			printf("error delenie na null\n");
			exit(1);
		}
		return a%b;
	default:
		printf("Error input operator\n");
		exit(1);
	}
			
}
void program(int argc,char *argv[])
{
	if (argc<6)
	{
		printf("Error input\n few elements\n");
		exit(1);
	}
	if (argc%3!=0)
	{
		printf("Error input \n Incorrect number of elements elements \n");
		exit(1);
	}
	//for (unsigned i=0;i)
	for (unsigned i=1;i<argc-3;i+=3)
	{
		if (isnumber(atoi(argv[i]),*argv[i])==0 && isnumber(atoi(argv[i+2]),*argv[i+2])==0)
		{
			int result = calc(atoi(argv[i]),atoi(argv[i+2]),*argv[i+1]);
			printf("Ответ N %u: %d\n",((i)/3)+1,result);	
		}
	}
	//return 0;
}
void print(int argc, char *mass[])
{
	for (unsigned i=1;i<argc;i++)
	{
		printf("%s\n",(mass[i]));
	}
}

int main(int argc, char *argv[])
{
	program(argc,argv);
	//print(argc,argv);
	return 0;
}
