#include "parser.h"

int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int r,i=0;
    int tamLinkedList = ll_len(pArrayListEmployee);
    char var1[50],var2[50],var3[50],var4[50];
    Employee* auxEmployee;
    pFile = fopen("data.csv","r");
    if(pFile == NULL)
    {
        return -1;
    }
    do{
        r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4);
        if(r==4)
        {
            auxEmployee = employee_new();
            if(auxEmployee!=NULL){
                auxEmployee->id=atoi(var1);
                strncpy(auxEmployee->nombre,var2,50);
                auxEmployee->horasTrabajadas=atoi(var3);
                auxEmployee->sueldo=atoi(var4);
                ll_add(pArrayListEmployee,auxEmployee);
                i++;
            }
        }
        else{
            break;
        }
    }while(!feof(pFile) && i<tamLinkedList);
    fclose(pFile);
    return i;
}

int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int i=0;
    int tamLinkedList = ll_len(pArrayListEmployee);
    char var1[50],var2[50],var3[50],var4[50];
    Employee* auxEmployee;
    pFile = fopen("data.csv","rb");

    if(pFile == NULL)
    {
        return -1;
    }
    do{
        auxEmployee = employee_new();
        if(auxEmployee!=NULL){
            fread(auxEmployee,sizeof(auxEmployee),1,pFile);
            auxEmployee->id=atoi(var1);
            strncpy(auxEmployee->nombre,var2,50);
            auxEmployee->horasTrabajadas=atoi(var3);
            auxEmployee->sueldo=atoi(var4);
            ll_add(pArrayListEmployee,auxEmployee);
            i++;
        }
        else{
            break;
        }
    }while(!feof(pFile) && i<tamLinkedList);
    fclose(pFile);
    return i;
}
