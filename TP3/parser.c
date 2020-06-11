#include "parser.h"

int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int r,i=0;
    ll_clear(pArrayListEmployee); //Por si ya habia cargado datos desde otro archivo
    char var1[50],var2[50],var3[50],var4[50];
    Employee* auxEmployee;
    if(pFile == NULL){
        return -1;
    }
    do{
        if(i==0){
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4);
        }
        r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4);
        if(r==4){
            auxEmployee = employee_newParametros(var1,var2,var3,var4);
            ll_add(pArrayListEmployee,auxEmployee);
            i++;
        }
        else{
            break;
        }
    }while(!feof(pFile));
    //controller_ListEmployee(pArrayListEmployee);
    fclose(pFile);
    return 1;
}

int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int i=0;
    ll_clear(pArrayListEmployee); //Por si ya habia cargado datos desde otro archivo
    Employee* auxEmployee;

    if(pFile == NULL){
        return -1;
    }
    do{
        auxEmployee = employee_new();
        if(auxEmployee!=NULL){
            fread(auxEmployee,sizeof(Employee),1,pFile);
            ll_add(pArrayListEmployee,auxEmployee);
            i++;
        }
        else{
            break;
        }
    }while(!feof(pFile));
    //controller_ListEmployee(pArrayListEmployee);
    fclose(pFile);
    return 1;
}
