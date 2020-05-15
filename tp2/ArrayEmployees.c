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
/*Employee createNewEmployee(){
    Employee hola;
    char nombre[51];
    if(utn_getNombre(nombre,NAME_LEN,"\nNombre?\n","\nERROR\n",2) == 0)
        utn_getNombre(auxEmployee.lastName,LASTNAME_LEN,"\nApellido?\n","\nERROR\n",2) == 0 &&
        utn_getNumero(&auxEmployee.sector,"\nSector?\n","\nERROR\n",2) == 0 &&
        utn_getNumeroFlotante(&auxEmployee.salary,"\nSalario?\n","\nERROR\n",2) == 0){
        printf("\nID: ");
        scanf("%d",&auxEmployee.id);
        printf("Nombre: ");
        scanf("%s",auxEmployee.name);
        printf("\nApellido: ");
        scanf("%s",auxEmployee.lastName);
        printf("\nSector: ");
        scanf("%d",&auxEmployee.sector);
        printf("\nSalario: ");
        scanf("%f",&auxEmployee.salary);

        }

    return hola;
}*/

int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector){
    int respuesta = -1;
    //int indice = employeeSearchFirstEmpty(list,len);
	if(list != NULL){
        if(utn_getNumero(&sector,"\nSector?\n","\nERROR\n",2) == 0 &&
        utn_getNumeroFlotante(&salary,"\nSalario?\n","\nERROR\n",0,20000,2) == 0){
            respuesta = 0;
            list[0].id = id;
            strcpy(list[0].name,name);
            strcpy(list[0].lastName,lastName);
            list[0].salary = salary;
            list[0].sector = sector;
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
    int posicionId = findEmployeeById(list,len,id);
	if(list != NULL && len > 0 && posicionId < len && posicionId >= 0 && list[posicionId].isEmpty == 0)
	{
		list[posicionId].isEmpty = 1;
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
    int i;
    int j;
    Employee auxEmployee;

    for(i=0; i<len-1; i++){
        for(j=i+1; j<len; j++){
            if(strcpy(list[i].lastName,list[j].lastName)>0){
                auxEmployee = list[i];
                list[i] = list[j];
                list[j] = auxEmployee;
            }
            else{
                if(list[i].sector>list[j].sector){
                        auxEmployee = list[i];
                        list[i] = list[j];
                        list[j] = auxEmployee;
                }
            }
        }
    }
    return 0;
}

void printOneEmployee(Employee list){
    printf("id: %d\t nombre: %s\t Apellido: %s\t Salario: %.2f \t Sector: %d\n",list.id,list.name,
           list.lastName,
           list.salary,
           list.sector);
    printf("\n");
}

int printEmployees(Employee* list, int length){
    int i=0;
    for(i=0;i<length;i++){
        printOneEmployee(list[i]);
    }
    return 0;
}
