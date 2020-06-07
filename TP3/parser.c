#include "parser.h"

int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int r,i=0;
    char var1[50],var3[50],var2[50],var4[50];
    pFile = fopen("data.csv","r");
    if(pFile == NULL)
    {
        return -1;
    }
    do{
        r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4);
        if(r==4)
        {
            /*pArrayListEmployee[i].id = atoi(var1);
            strncpy(arrayEmployees[i].nombre,var2,sizeof(arrayEmployees[i].nombre));
            strncpy(arrayEmployees[i].horasTrabajadas,var3,sizeof(arrayEmployees[i].horasTrabajadas));
            arrayEmployees[i].sueldo = atof(sueldo);*/
            i++;
        }
        else{
            break;
        }
    }while(!feof(pFile));
    fclose(pFile);
    return i;
}

int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{

    return 1;
}
