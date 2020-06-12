
/** \brief Controlador para poder realizar la carga de un archivo de texto a una lista
 *  \param char* path Nombre del archivo
 *  \param LinkedList* pArrayListEmployee puntero a la lista en donde se cargaran los datos
 *  \return int Retorna  (-1) Error: si puntero a la lista es NULL o no existe el archivo
                         ( 0)        si no se realizo la carga del archivo a la lista
 *                       ( 1) Si se realizo con exito la carga del archivo a la lista
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);

/** \brief Controlador para poder realizar la carga de un archivo de formato binario a una lista
 *  \param char* path Nombre del archivo
 *  \param LinkedList* pArrayListEmployee puntero a la lista en donde se cargaran los datos
 *  \return int Retorna  (-1) Error: si puntero a la lista es NULL o no existe el archivo
                         ( 0)        si no se realizo la carga del archivo a la lista
 *                       ( 1) Si se realizo con exito la carga del archivo a la lista
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);

/** \brief Agrega un nuevo empleado a la lista ingresando sus datos
 *
 *  \param LinkedList* pArrayListEmployee puntero a la lista de trabajadores
 * \return int Retorna  (-1) Error: si puntero a la lista es NULL
 *                      ( 1) Si se realizo la carga del nuevo empleado al puntero a la lista
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee);

/** \brief Modifica los datos de un empleado ya existente en la lista
 *
 *  \param LinkedList* pArrayListEmployee puntero a la lista de trabajadores
 *  \return int Retorna  (-1) Error: si puntero a la lista es NULL
                         ( 0) Si el empleado a buscar, no existe en la lista
 *                       ( 1) Si se realizo con exito la modificacion del empleado
 */
int controller_editEmployee(LinkedList* pArrayListEmployee);

/** \brief Elimina un empleado de la lista
 *
 *  \param LinkedList* pArrayListEmployee puntero a la lista de trabajadores
 * \return int Retorna  (-1) Error: si puntero a la lista es NULL
                        ( 0) Si el empleado a buscar, no existe en la lista
 *                      ( 1) Si se pudo eliminar al empleado de la lista
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee);

/** \brief Imprime por pantalla la lista de los empleados
 *
 *  \param LinkedList* pArrayListEmployee puntero a la lista de trabajadores
 * \return int Retorna  ( 0) Error: si puntero a la lista es NULL o la lista esta vacia
 *                      ( 1) Si se realizo con exito mostrar el listado
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee);

/** \brief Ordena por criterio(por id,nombre,sueldo u horas trabajadas) la lista de empleados
 *
 *  \param LinkedList* pArrayListEmployee puntero a la lista de trabajadores
 * \return int Retorna  (-1) Error: si puntero a la lista es NULL
 *                      ( 1) Si se pudo realizar el ordenamiento
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee);

/** \brief guarda la lista en un archivo de texto
 *
 *  \param char* path nombre del archivo
 *  \param LinkedList* pArrayListEmployee puntero a la lista de trabajadores
 * \return int Retorna  (-1) Error: si puntero a la lista es NULL o no existe el archivo
 *                      ( 1) Si se pudo guardar los datos de la lista al archivo en formato texto
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);

/** \brief guarda la lista en un archivo de formato binario
 *
 *  \param char* path nombre del archivo
 *  \param LinkedList* pArrayListEmployee puntero a la lista de trabajadores
 * \return int Retorna  (-1) Error: si puntero a la lista es NULL o no existe el archivo
 *                      ( 1) Si se pudo guardar los datos de la lista al archivo en formato binario
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);


