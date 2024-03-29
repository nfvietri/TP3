#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int r,i=0;
	char id[4096];
	char nombre[4096];
	char horasTrabajadas[4096];
	char sueldo[4096];
	while(!feof(pFile))
	{
		r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",
						id,
						nombre,
						horasTrabajadas,
						sueldo);
		if(r==4)
		{
			Employee* empAux = employee_new();
			employee_setId(empAux,atoi(id));
			employee_setNombre(empAux,nombre);
			employee_setHorasTrabajadas(empAux,atoi(horasTrabajadas));
			employee_setSueldo(empAux,atoi(sueldo));
			ll_add(pArrayListEmployee,empAux);

		}

	}
    return 1;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{

    return 1;
}
