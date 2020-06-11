#include "Employee.h"


Employee* employee_new()
{
    return (Employee*) malloc(sizeof(Employee));
}
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
    Employee* this = employee_new();
    int id;
    int horasTrabajadas;
    int sueldo;

    if(this!=NULL){
        id = atoi(idStr);
        horasTrabajadas = atoi(horasTrabajadasStr);
        sueldo = atoi(sueldoStr);
        employee_setId(this,id);
        employee_setNombre(this,nombreStr);
        employee_setHorasTrabajadas(this,horasTrabajadas);
        employee_setSueldo(this,sueldo);
    }else{
        employee_delete(this);
    }
    return this;
}

void employee_delete(Employee* this){
    free(this);
}

int employee_setNombre(Employee* this,char* nombre)
{
    int retorno = 1;
	if(this != NULL && nombre != NULL)
	{
		if(isValidNombre(nombre,50))
		{
			retorno = 0;
			strncpy(this->nombre,nombre,50);
		}
	}
	return retorno;
}

int employee_getNombre(Employee* this,char* nombre)
{
    int retorno = 1;
	if(this != NULL && nombre != NULL)
	{
		retorno = 0;
		strncpy(nombre,this->nombre,50);
	}
	return retorno;
}



int employee_setSueldo(Employee* this,int sueldo)
{
    int retorno = 1;
	if(this != NULL && sueldo >= 0)
	{
		retorno = 0;
		this->sueldo = sueldo;
	}
	return retorno;
}
int employee_getSueldo(Employee* this,int* sueldo)
{
    int retorno = 1;
	if(this != NULL && sueldo != NULL)
	{
		retorno = 0;
		*sueldo = this->sueldo;
	}
	return retorno;
}

int employee_setId(Employee* this,int id)
{
    int retorno = 1;
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
    int retorno = 1;
	if(this != NULL && id != NULL)
	{
		retorno = 0;
		*id = this->id;
	}
	return retorno;
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
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int retorno = 1;
	if(this != NULL && horasTrabajadas != NULL)
	{
		retorno = 0;
		*horasTrabajadas = this->horasTrabajadas;
	}
	return retorno;
}


int employee_CompareByName(void* e1, void* e2)
{
    char nombrePrimerEmployee[50];
    char nombreSegundoEmployee[50];
    employee_getNombre(e1,nombrePrimerEmployee);
    employee_getNombre(e2,nombreSegundoEmployee);
    if(strcmp(nombrePrimerEmployee, nombreSegundoEmployee)>0){
        return 1;
    }
    return 0;
}

int employee_CompareById(void* e1, void* e2)
{
    int idPrimerEmployee, idSegundoEmployee;
    employee_getId(e1,&idPrimerEmployee);
    employee_getId(e2,&idSegundoEmployee);

    if(idPrimerEmployee > idSegundoEmployee)
    {
        return 1;
    }
    else
    {
        if(idPrimerEmployee < idSegundoEmployee)
        {
            return -1;
        }
        else
        {
            return 0;
        }
    }
}

void printEmployee(Employee* employee){
   // printf("    ID      Nombre      Horas trabajadas     Sueldo  \n");
    printf("    %d      %s                %d              %d    \n",employee->id,
                                                   employee->nombre,
                                                   employee->horasTrabajadas,
                                                   employee->sueldo);
}

int getIndexOfEmployeeById(LinkedList* LinkedList, int id){
    int tam = ll_len(LinkedList);
    int i;
    int indice = -1;
    Employee* employee;
    for(i=0;i<tam;i++){
        employee = ll_get(LinkedList,i);
        if(employee->id==id){
            indice = id;
        }
    }
    return indice;
}
