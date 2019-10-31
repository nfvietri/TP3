#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Employee.h"



Employee* employee_new()
{
	return malloc(sizeof(Employee));
}

void employee_delete(Employee* this)
{
	free(this);
}

static int isValidId(int idCliente)
{
	return 1;
}

int employee_setId(Employee* this, int id)
{
	int retorno = -1;
	if(this!=NULL && isValidId(id))
	{
		this->id = id;
		retorno = 0;
	}
	return retorno;
}

int employee_getId(Employee* this, int* id)
{
	int retorno = -1;
	if(this!=NULL && id!=NULL)
	{
		*id = this->id;
		retorno = 0;
	}
	return retorno;
}

static int isValidNombre(char* nombre)
{
	return 1;
}

int employee_setNombre(Employee* this, char* nombre)
{
	int retorno = -1;
	if(this!=NULL && isValidNombre(nombre))
	{
		strcpy(this->nombre,nombre);
		retorno = 0;
	}
	return retorno;
}

int employee_getNombre(Employee* this, char* nombre)
{
	int retorno = -1;
	if(this!=NULL && nombre!=NULL)
	{
		strcpy(nombre, this->nombre);
		retorno = 0;
	}
	return retorno;
}

static int isValidHorasTrabajadas(int horasTrabajadas)
{
	return 1;
}

int employee_setHorasTrabajadas(Employee* this, int horasTrabajadas)
{
	int retorno = -1;
	if(this!=NULL && isValidHorasTrabajadas(horasTrabajadas))
	{
		this->horasTrabajadas = horasTrabajadas;
		retorno = 0;
	}
	return retorno;
}

int employee_getHorasTrabajadas(Employee* this, int* horasTrabajadas)
{
	int retorno = -1;
	if(this!=NULL && horasTrabajadas!=NULL)
	{
		*horasTrabajadas = this->horasTrabajadas;
		retorno = 0;
	}
	return retorno;
}


static int isValidSueldo(int sueldo)
{
	return 1;
}

int employee_setSueldo(Employee* this, int sueldo)
{
	int retorno = -1;
	if(this!=NULL && isValidSueldo(sueldo))
	{
		this->sueldo = sueldo;
		retorno = 0;
	}
	return retorno;
}

int employee_getSueldo(Employee* this, int* sueldo)
{
	int retorno = -1;
	if(this!=NULL && sueldo!=NULL)
	{
		*sueldo = this->horasTrabajadas;
		retorno = 0;
	}
	return retorno;
}

Employee* employee_newParametros(int idCliente,char* nombre, int horasTrabajadas, int sueldo)
{
	Employee* retorno = NULL;
	Employee* this;
	this = employee_new();
	if(this != NULL)
	{
		if(
				employee_setId(this,idCliente) == 0 &&
				employee_setNombre(this,nombre) == 0 &&
				employee_setHorasTrabajadas(this,horasTrabajadas) == 0 &&
				employee_setSueldo(this,sueldo) == 0
				)
		{
			retorno = this;
		}
		else
		{
			employee_delete(this);
		}

	}
	return retorno;
}

