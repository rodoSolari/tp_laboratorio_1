#include "ArrayEmployees.h"
#include "funcionesParaTiposDeDatos.h"

static int contadorId = 1000;

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

void imprimirMenu(){
    printf(" __________________________\n");
    printf("|1.Cargar un empleados     |\n");
    printf("|2.Modificar un empleados  |\n");
    printf("|3.Eliminar un empleados   |\n");
    printf("|4.Ordenar empleados       |\n");
    printf("|5.SALIR                   |\n");
    printf("|__________________________|\n");
    printf("ELIJA UNA OPCION: ");
}

void iniciarMenu(Employee* listadoEmployees){
    int idEliminar;
    int idModificar;
    int orden;
    int employeeCargado = 0;
    int opcion;
    Employee newEmployee;
    do
    {
        imprimirMenu();
        scanf("%d",&opcion);
        switch(opcion){
            case 1:
                createNewEmployee(listadoEmployees,newEmployee,MAX_EMPLOYEES);
                employeeCargado++;
                break;
            case 2:
                if(employeeCargado>=1){
                    printEmployees(listadoEmployees,MAX_EMPLOYEES);
                    printf("Ingrese el id del empleado a modificar: ");
                    scanf("%d",&idModificar);
                    modificarEmpleado(listadoEmployees,idModificar,MAX_EMPLOYEES);
                }else{
                    printf("No hay empleados cargados en la lista, por favor ingrese primero la opcion 1");
                }
                break;
            case 3:
                if(employeeCargado>=1){
                    printEmployees(listadoEmployees,MAX_EMPLOYEES);
                    printf("Ingrese el id del empleado: ");
                    scanf("%d",&idEliminar);
                    if(removeEmployee(listadoEmployees,MAX_EMPLOYEES,idEliminar)==0){
                        printf("Eliminado con exito!\n");
                        employeeCargado--;
                    }
                }else{
                    printf("No hay empleados cargados en la lista, por favor ingrese primero la opcion 1");
                }
                break;
            case 4:
                if(employeeCargado>=1){
                    printf("ingrese el orden\n    1:ascendente    0:descendente\n");
                    scanf("%d",&orden);
                    if(sortEmployees(listadoEmployees,MAX_EMPLOYEES,orden)==0){
                        printf("ordenado con exito.\n");
                        informarPromedio(listadoEmployees,MAX_EMPLOYEES);
                    }

                }else{
                    printf("No hay empleados cargados en la lista, por favor ingrese primero la opcion 1");
                }
                break;
            default:
                if(opcion!=5){
                    printf("opcion incorrecta\n");
                }else{
                    printf("saliendo del programa...\n");
                }
                break;
            }
        system("pause");
        system("cls");
    }while(opcion!=5);
}

void createNewEmployee(Employee* list,Employee auxEmployee,int len){
    getString(auxEmployee.name,"Ingrese el nombre : ","Error : por favor ingreselo de nuevo\n");
    getString(auxEmployee.lastName,"Ingrese el Apellido : ","Error : por favor ingreselo de nuevo\n");
    getFloat(&auxEmployee.salary,"Ingrese el salario : ","Error : por favor ingreselo de nuevo\n");
    getInt(&auxEmployee.sector,"Ingrese el sector : ","Error : por favor ingreselo de nuevo\n");
    auxEmployee.id = employeeSearchFirstEmpty(list,len)+contadorId;
    if(addEmployee(list,len,auxEmployee.id,auxEmployee.name,auxEmployee.lastName,auxEmployee.salary,auxEmployee.sector)==0){
        printf("carga completada!\n");
        printEmployees(list,len);
    }else{
        printf("error!\n");
    }
}

int employeeSearchFirstEmpty(Employee* array,int tam){
	int respuesta = -1;
	int i;
	if(array != NULL && tam > 0){
        respuesta = 0;
		for(i=0;i<tam;i++){
			if(array[i].isEmpty == EMPTY){
				respuesta = i;
				break;
			}
		}
	}
	return respuesta;
}


int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector){
    int respuesta = -1;
    int indice = employeeSearchFirstEmpty(list,len);
	if(list != NULL && indice>=0){
        list[indice].id = id;
        strcpy(list[indice].name,name);
        strcpy(list[indice].lastName,lastName);
        list[indice].salary = salary;
        list[indice].sector = sector;
        list[indice].isEmpty = FULL;
        respuesta = 0;
    }
	return respuesta;
}



int findEmployeeById(Employee* list, int len,int id){
    int respuesta = -1;
	int i;
	if(list != NULL && len > 0 && id >= 0){
		respuesta = -1;
		for(i=0;i<len;i++){
			if(list[i].id == id){
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
	if(list != NULL && len > 0 && posicionId < len && posicionId >= 0 && list[posicionId].isEmpty == FULL){
		list[posicionId].isEmpty = EMPTY;
		respuesta = 0;
	}
	return respuesta;
}


void modificarEmpleado(Employee listado[],int id, int tam){
    Employee auxEmployee;
    int indice=findEmployeeById(listado, tam, id);
    int opcion;
    do{
        printf("1. Nombre:\n2.Apellido\n3.Salario\n4.Sector\n5.Salir\n");
        printf("Ingrese la opcion que quiera modificar del empleado: \n");
        scanf("%d",&opcion);
        switch(opcion){
            case 1:
                getString(auxEmployee.name,"Nombre : ","Error : por favor ingreselo de nuevo\n");
                strcpy(listado[indice].name,auxEmployee.name);
                break;
            case 2:
                getString(auxEmployee.lastName,"Apellido : ","Error : por favor ingreselo de nuevo\n");
                strcpy(listado[indice].lastName,auxEmployee.lastName);
                break;
            case 3:
                getFloat(&auxEmployee.salary,"Salario : ","Error : por favor ingreselo de nuevo\n");
                listado[indice].salary = auxEmployee.salary;
                break;
            case 4:
                getInt(&auxEmployee.sector,"Sector : ","Error : por favor ingreselo de nuevo\n");
                listado[indice].sector = auxEmployee.sector;
                break;
        }
    }while(opcion!=5);
    printf("Modificado con exito!\n");
    printEmployees(listado,MAX_EMPLOYEES);
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


int sortEmployees(Employee* list, int len, int order){
    int i;
    int j;
    Employee auxEmployee;
    int respuesta = -1;
    if(list != NULL && len>0){
        respuesta=0;
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
    }
    printf("LISTA ORDENADA : \n");
    printEmployees(list,len);
    return respuesta;
}

void printOneEmployee(Employee list){
    printf(" ID   :    NOMBRE    :     APELLIDO    :     SALARIO    :  SECTOR    \n");
    printf(" %1d %12s %14s   %16.2f  %10d\n",list.id,list.name,list.lastName,list.salary,list.sector);
    printf("\n");
}

int printEmployees(Employee* list, int len){
    int i;
    int respuesta = -1;
    if(list != NULL && len>0){
        respuesta=0;
        for(i=0;i<len;i++){
            if(list[i].isEmpty==FULL){
                printOneEmployee(list[i]);
            }
        }
    }
    return respuesta;
}
