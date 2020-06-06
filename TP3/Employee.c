#include <stdlib.h>
#include "Employee.h"
#include <string.h>

Employee* employee_new()
{
    return (Employee*) malloc(sizeof(Employee));
}
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
    Employee* this = employee_new();
    int id = atoi(idStr);
    if(!employee_setId(this,id) && !employee_setNombre(this,nombreStr) && !employee_setHorasTrabajadas(this,atoi(horasTrabajadasStr))){

        return this;
    }
    //employee_delete(this)
    free(this);
    return NULL;
}

void employee_delete(){
    //free();
}

int employee_setNombre(Employee* this,char* nombre)
{
    return 1;
}

int employee_getNombre(Employee* this,char* nombre)
{
    int retorno = -1;
    if(this != NULL && nombre != NULL){
        retorno = 0;
        //strcpy()
    }
    return retorno;
}



int employee_setSueldo(Employee* this,int sueldo)
{
    return 1;
}
int employee_getSueldo(Employee* this,int* sueldo)
{
    return 1;

}

int employee_setId(Employee* this,int id)
{
    int retorno = -1;
    static int maximoId = -1;
    if(this!=NULL){
        retorno = 0;
        if(id<0){
            maximoId++;
            this->id = maximoId;
        }else{
            if(id>maximoId){
                maximoId = id;
            }
            this->id = id;
        }
    }
    return retorno;
}
int employee_getId(Employee* this,int* id)
{
    return 1;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int retorno = 0;
    if(this!=NULL){
        this->horasTrabajadas = horasTrabajadas;
        retorno = 1;
    }
    return retorno;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajdas)
{

    return 1;
}


int employee_CompareByName(Employee* e1, Employee* e2)
{

    return strcmp(e1->nombre, e2->nombre);
}

int employee_CompareById(Employee* e1, Employee* e2)
{

    if(e1->id > e2->id)
    {
        return 1;
    }
    else
    {
        if(e1->id < e2->id)
        {
            return -1;
        }
        else
        {
            return 0;
        }
    }
    return strcmp(e1->nombre, e2->nombre);
}



