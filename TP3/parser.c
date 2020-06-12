#include "parser.h"

int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int r,i=0;
    int respuesta;
    ll_clear(pArrayListEmployee); //Por si ya habia cargado datos desde otro archivo
    char var1[50],var2[50],var3[50],var4[50];
    Employee* auxEmployee;
    if(pFile == NULL){
        respuesta = -1;
    }else{
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
        respuesta = 1;
    }
    fclose(pFile);
    return respuesta;
}

int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int i=0;
    int respuesta;
    ll_clear(pArrayListEmployee); //Por si ya habia cargado datos desde otro archivo
    Employee* auxEmployee;

    if(pFile == NULL){
        respuesta = -1;
    }
    do{
        if(feof(pFile)){
            break;
        }
        auxEmployee = employee_new();
        if(auxEmployee!=NULL){
            if(fread(auxEmployee,sizeof(Employee),1,pFile)==1){
                ll_add(pArrayListEmployee,auxEmployee);
                i++;
            }
        }else{
            break;
        }
        respuesta = 1;
    }while(!feof(pFile));
    fclose(pFile);
    return respuesta;
}
