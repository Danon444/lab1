#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int isnumber(const char *str)
{
    if (str == NULL || *str == '\0')
    {
        return 1;
    }
    for (int i = 0; str[i] != '\0'; i++) 
    {
        if (!isdigit(str[i]) && !(i == 0 && str[i] == '-'))
        {
            return 1;
        }
    }
    return 0;
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
			printf("Деление на ноль!\n");
			exit(1);
		}
		return a%b;
	default:
		printf("Ошибка ввода знака операции!\n");
		exit(1);
	}
			
}
char *program(int argc,char *argv[])
{
	if (argc<6)
	{
		printf("Недостаточно введенных элементов!\n");
		exit(1);
	}
	if ((argc)%3!=0)
	{
		printf("Неверное количество введённых элементов!\n");
		exit(1);
	}
    int key=-1;
    for (unsigned r = 1; r < argc; r++)
    {
        if (argv[r][0] == '-') 
        {
            if (strcmp(argv[r], "-k") == 0)
            {
                key=r;
            }
        }
    }
    if (key==-1)
    {
        printf("Отсутсвует ключ!\n");
        exit(1);
    }
    if (key+1>=argc)
    {
        printf("Отсутствует значение ключа!\n");
        exit(1);
    }
    if (isnumber(argv[key+1])!=0)
    {
        printf("Ошибка ввода значения ключа!\n");
        exit(1);
    }
    int keyValue=atoi(argv[key+1]);
    int *resultmass = calloc((key-1)/3,sizeof(int));
    unsigned index = 0;
	for (unsigned i=1;i<argc-3;i+=3)
	{
		if (isnumber(argv[i])==0)
		{
                if (isnumber(argv[i+2])==0)
                {
			        int result = calc(atoi(argv[i]),atoi(argv[i+2]),*argv[i+1]);
			        printf("Ответ N %u: %d\n",((i)/3)+1,result);
                    resultmass[index]=result;
                    index++;
		        }
                else
                {
                    printf("Ошибка ввода правого операнда!\n");
                    exit(1);
                }
        }
        else
        {
            printf("Ошибка ввода левого операнда!\n");
            exit(1);
        }
	}
    char *resultstr=malloc((key-1)/3+1);
    for (unsigned j=0;j<((key-1)/3);j++)
    {
        resultstr[j]=(char)(resultmass[j]-keyValue);
    }
    resultstr[(key-1)/3+1]='\0';

    free(resultmass);
	return resultstr;
}

int main(int argc, char *argv[])
{
	char *resultstr=program(argc,argv);
    if (resultstr!=NULL)
    {
        printf("Результирующая строка: %s\n",resultstr);
        free(resultstr);
    }
    return 0;
}
