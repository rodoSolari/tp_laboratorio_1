#include "ArrayEmployees.h"
#include "funcionesParaTiposDeDatos.h"

/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE in all
* position of the array
* \param list Employee* Pointer to array of employees
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int initEmployees(Employee* list, int len){
int respuesta = -1;
	int i;
	if(list != NULL && len > 0){
		respuesta = 0;
		for(i=0;i<len;i++){
			list[i].isEmpty = 1;
		}
	}
	return respuesta;
}


/** \brief add in a existing list of employees the values received as parameters
* in the first empty position
* \param list employee*
* \param len int
* \param id int
* \param name[] char
* \param lastName[] char
* \param salary float
* \param sector int
* \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
*/
int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector){
    int respuesta = -1;
	Employee bufferEmployee;
    int indice = employeeSearchFirstEmpty(list,len);
	if(list != NULL && len > 0 && indice < len && indice >= 0 && id != 0){
		if(	utn_getNombre(bufferEmployee.name,NAME_LEN,"\nNombre?\n","\nERROR\n",2) == 0 &&
			utn_getNumero(&bufferEmployee.sector,"\nSector?\n","\nERROR\n",2) == 0 &&
			utn_getNumeroFlotante(&bufferEmployee.salary,"\nLast Name?\n","\nERROR\n",0,5,2) == 0 &&
			utn_getNombre(bufferEmployee.name,NAME_LEN,"\nNombre?\n","\nERROR\n",2) == 0){

			respuesta = 0;
			bufferEmployee.id = id;
			bufferEmployee.isEmpty = 0;
			list[indice] = bufferEmployee;
			id++;
		}
	}
	return respuesta;
}

int findEmployeeById(Employee* list, int len,int id){
    int respuesta = -1;
	int i;
	if(list != NULL && len > 0 && id >= 0)
	{
		respuesta = 0;
		for(i=0;i<len;i++)
		{
			if(list[i].id == id)
			{
				respuesta = i;
				break;
			}
		}
	}
    return respuesta;
}

int removeEmployee(Employee* list, int len, int id){
    int respuesta = -1;
	if(list != NULL && limite > 0 && indice < limite && indice >= 0 && list[indice].isEmpty == 0)
	{
		list[indice].isEmpty = 1;
		respuesta = 0;
	}
	return respuesta;
    return 0;
}

int employeeSearchId(Employee list[], int limite, int valorBuscado){
	int respuesta = -1;
	int i;
	if(list != NULL && limite > 0 && valorBuscado >= 0){
		respuesta = 0;
		for(i=0;i<limite;i++){
			if(list[i].id == valorBuscado){
				respuesta = i;
				break;
			}
		}
	}
	return respuesta;
}

int sortEmployees(Employee* list, int len, int order){
    return 0;
}

int printEmployees(Employee* list, int length){
    return 0;
}
