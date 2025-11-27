#include <stdio.h>
#include <stdlib.h>
#include "func.h"

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
