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
static int contadorId = 0;

int initEmployees(Employee* list, int len){
    int respuesta = -1;
	int i;
	if(list != NULL && len > 0){
		respuesta = 0;
		for(i=0;i<len;i++){
			list[i].isEmpty = EMPTY;
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
void createNewEmployee(Employee* list,Employee auxEmployee,int len){
    int r;

    getString(auxEmployee.name,"Nombre : ","Error : por favor ingreselo de nuevo\n");
    getString(auxEmployee.lastName,"Apellido : ","Error : por favor ingreselo de nuevo\n");
   // getFloat(auxEmployee.salary,"Salario : ","Error : por favor ingreselo de nuevo\n");
    getInt(&auxEmployee.sector,"Sector : ","Error : por favor ingreselo de nuevo\n");
    printf("Salario: \n");
    scanf("%f",&auxEmployee.salary);
    auxEmployee.id = contadorId;
    printf("id que va a contener : %d\n",auxEmployee.id);
    contadorId++;
    r=addEmployee(list,len,auxEmployee.id,auxEmployee.name,auxEmployee.lastName,auxEmployee.salary,auxEmployee.sector);
    if(r==0){
        printf("carga completada!\n");
    }else{
        printf("error!\n");
    }

}


/** \brief
*
* \param array employee*
* \param tam int
* \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
*/
int employeeSearchFirstEmpty(Employee* array,int tam){
	int respuesta = -1;
	int i;
	if(array != NULL && tam > 0){
		for(i=0;i<tam;i++){
			if(array[i].isEmpty == EMPTY){
				respuesta = i;
				break;
			}
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
    int indice = employeeSearchFirstEmpty(list,len);
    printf("indice libre : %d\n", indice);
	if(list != NULL && indice>=0){
        list[indice].id = id;
        strcpy(list[indice].name,name);
        strcpy(list[indice].lastName,lastName);
        list[indice].salary = salary;
        list[indice].sector = sector;
        list[indice].isEmpty = FULL;
        respuesta = 0;
        indice++;
    }
	return respuesta;
}


/** \brief find an Employee by Id en returns the index position in array.
*
* \param list Employee*
* \param len int
* \param id int
* \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
*
*/

int findEmployeeById(Employee* list, int len,int id){
    int respuesta = -1;
	int i;
	if(list != NULL && len > 0 && id >= 0){
		respuesta = 0;
		for(i=0;i<len;i++){
			if(list[i].id == id){
				respuesta = i;
				break;
			}
		}
	}
    return respuesta;
}


/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
*
* \param list Employee*
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
*
*/
int removeEmployee(Employee* list, int len, int id){
    int respuesta = -1;
    int posicionId = findEmployeeById(list,len,id);
    printf("Encontre al id a buscar : %d\n",posicionId);
	if(list != NULL && len > 0 && posicionId < len && posicionId >= 0 && list[posicionId].isEmpty == FULL){
		list[posicionId].isEmpty = EMPTY;
		respuesta = 0;
	}
	return respuesta;
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


/** \brief Modifica el empleado que quiere el usuario ingresando el ID
*
* \param listado[] Employee
* \param id int
* \param int tam
* \return -
*
*/
void modificarEmpleado(Employee listado[],int id, int tam){
    Employee auxEmployee;
    int indice=employeeSearchId(listado, tam, id);
    int opcion;
    do{

        printf("1. Nombre:\n2.Apellido\n3.Salario\n4.Sector\n5.Salir");
        printf("Ingrese la opcion que quiera modificar del empleado: \n");
        switch(opcion){
            case 1:
                getString(auxEmployee.name,"Nombre : ","Error : por favor ingreselo de nuevo\n");
                strcpy(listado[indice].name,auxEmployee.name);
                break;
            case 2:
                getString(auxEmployee.lastName,"Apellido : ","Error : por favor ingreselo de nuevo\n");
                strcpy(listado[indice].name,auxEmployee.name);
                break;
            case 3:

                //listado[i].salary = auxEmployee.salary;
                break;
            case 4:
                getInt(&auxEmployee.sector,"Sector : ","Error : por favor ingreselo de nuevo\n");
                listado[indice].sector = auxEmployee.sector;
                break;
        }
    }while(opcion!=5);
}


void informarPromedio(Employee* list, int len){
    int totalSalario=0;
    int contadorEmpleados=0;
    int empleadosMayorPromedio=0;
    int totalPromedio;
    int i;
    for(i=0;i<len;i++){
        if(list[i].isEmpty==FULL){
            totalSalario+=list[i].salary;
            contadorEmpleados++;
        }
    }
    totalPromedio = totalSalario/contadorEmpleados;
    for(i=0;i<len;i++){
        if(list[i].isEmpty==FULL){
            if(totalPromedio<list[i].salary){
                empleadosMayorPromedio++;
            }
        }
    }
    printf("TOTAL DE SALARIOS A PAGAR : %d\n",totalSalario);
    printf("PROMEDIO DE SALARIOS : %d\n",totalPromedio);
    printf("CANTIDAD DE EMPLEADOS CON SALARIO MAYOR AL PROMEDIO : %d\n",empleadosMayorPromedio);

}



/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
*
* \param list Employee*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int sortEmployees(Employee* list, int len, int order){
    int i;
    int j;
    Employee auxEmployee;

    for(i=0; i<len-1; i++){
        for(j=i+1; j<len; j++){
            if(order==UP){
                if(stricmp(list[i].lastName,list[j].lastName)>0 || (stricmp(list[i].lastName,list[j].lastName)==0 && list[i].sector>list[j].sector)){
                    auxEmployee = list[i];
                    list[i] = list[j];
                    list[j] = auxEmployee;
                }
            }else if(order==DOWN){
                if(stricmp(list[i].lastName,list[j].lastName)<0 || (stricmp(list[i].lastName,list[j].lastName)==0 && list[i].sector<list[j].sector)){
                        auxEmployee = list[i];
                        list[i] = list[j];
                        list[j] = auxEmployee;
                }
            }
        }
    }
    printf("LISTA ORDENADA : \n");
    printEmployees(list,len);
    return 0;
}


/** \brief Imprime por pantalla un solo empleado
*
* \param list Employee
* \return -
*
*/
void printOneEmployee(Employee list){
    printf("id: %d\t nombre: %s\t Apellido: %s\t Salario: %.2f \t Sector: %d\n",list.id,list.name,
           list.lastName,
           list.salary,
           list.sector);
    printf("\n");
}


/** \brief Imprime todos los empleados de la lista recibida
*
* \param list Employee*
* \param lenght int
* \return -
*
*/
int printEmployees(Employee* list, int length){
    int i=0;
    for(i=0;i<length;i++){
        if(list[i].isEmpty==FULL){
            printOneEmployee(list[i]);
        }
    }
    return 0;
}
