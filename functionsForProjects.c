
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "functionsForProjects.h"

static int getI(int *pBuffer) {

    return scanf("%d", pBuffer);

}

static char getC(char *pBuffer) {
    fflush(stdin);

    return scanf("%c", pBuffer);


}

static float getF(float *pBuffer) {

    return scanf("%f", pBuffer);

}

void toUpperLastNameAndName(eEmployee employee[], int cant) {
    int i;
    int j;
    for (i = 0; i < cant; i++) {
        for (j = 0; j < strlen(employee[i].lastName); ++j) {
            employee[i].lastName[j] = toupper(employee[i].lastName[j]);
        }
    }
    for (i = 0; i < cant; i++) {
        for (j = 0; j < strlen(employee[i].name); ++j) {
            employee[i].name[j] = toupper(employee[i].name[j]);
        }
    }
}

void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// A function to implement bubble sort
void bubbleSort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++)

        // Last i elements are already in place
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
}

/* Function to print an array */
void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int getEntero(int *pInt, char msg[], char msgError[], int min, int max, int reintentos) {
    int returnNum = -1;
    int bufferInt = 0;
    if (pInt != NULL && msg != NULL && msgError != NULL && min <= max && reintentos >= 0) {
        do {
            reintentos--;
            printf("%s", msg);
            fflush(stdin);
            if (getI(&bufferInt) && bufferInt >= min && bufferInt <= max) {
                *pInt = bufferInt;
                returnNum = 0;
                break;

            } else {
                printf("%s", msgError);

            }


        } while (reintentos > 0);

    }
    return returnNum;


}

int getFloat(float *pFloat, char msg[], char msgError[], float min, float max, int reintentos) {
    int returnNum = -1;
    float bufferFloat = 0;
    if (pFloat != NULL && msg != NULL && msgError != NULL && min <= max && reintentos >= 0) {
        do {
            reintentos--;
            printf("%s", msg);
            fflush(stdin);
            if (getF(&bufferFloat) && bufferFloat >= min && bufferFloat <= max) {

                *pFloat = bufferFloat;
                returnNum = 0;
                break;

            } else {
                printf("%s", msgError);

            }


        } while (reintentos > 0);

    }
    return returnNum;


}

int getChar(char *pChar, char msg[], char msgError[], char minChar, char maxChar, int reintentos) {
    int returnNum = -1;
    char bufferChar;
    if (pChar != NULL && msg != NULL && msgError != NULL && minChar <= maxChar && reintentos >= 0) {
        do {
            reintentos--;
            printf("%s", msg);
            fflush(stdin);
            if (getC(&bufferChar) && bufferChar >= minChar && bufferChar <= maxChar) {

                *pChar = bufferChar;
                returnNum = 0;
                break;

            } else {
                printf("%s", msgError);

            }


        } while (reintentos > 0);

    }
    return returnNum;


}

int isLetter(char c[]) {
    int i = 0;
    if (c[i] == ' ' || c[i] == '\r')
        return 0;
    while (c[i] != '\0') {
        if ((c[i] != ' ') && (c[i] < 'a' || c[i] > 'z') && (c[i] < 'A' || c[i] > 'Z') && (c[i] == '\r'))
            return 0;
        i++;
    }
    return 1;
}

/**
 *
 * @param mensaje
 * @param input
 */
void getString(char input[], char msg[]) {
    fflush(stdin);
    printf("%s", msg);
    fgets(input, 200, stdin);
    input[strcspn(input, "\n")] = 0;
}

/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo letras
 */
int getStringLettersOnly(char *input, char *mensaje, int cant, int intentos) {
    char aux[cant];
    do {
        getString(aux, mensaje);
        if (isLetter(aux)) {
            strcpy(input, aux);
            return 1;
        } else {
            intentos--;
            printf("Error nombre deben ser solo letras y no puede estar vacio!.\n");
        }

    } while (intentos >= 0);
    return 0;
}

int getFreeSpace(eEmployee Per[], int cant) {

    int i;
    for (i = 0; i < cant; i++) {
        if (Per[i].isEmpty == 1) {
            return i;
        }
    }
    printf("No hay espacio en el array para agregar mas empleados.\n");
    return -1;

}


int isRepeated(eEmployee Per[], int buffer, int cant) {
    int retorno = -1, i;
    for (i = 0; i < cant; i++) {
        if (Per[i].id == buffer) {
            printf("Legajo repetido.");
            retorno = i;
            break;
        }

    }
//TODO terminar
    return retorno;
}

int initEmployees(eEmployee *Per, int cant) {
    int i;
    for (i = 0; i < cant; i++) {
        Per[i].isEmpty = 1;
    }
    return -1;

}

int addEmployee(eEmployee *list, int len, int id, char name[], char lastName[], float salary, int sector) {
    int i;
    i = getFreeSpace(list, len);
    if (i != -1) {
        list[i].isEmpty = 0;
        list[i].id = id;
        strcpy(list[i].name, name);
        strcpy(list[i].lastName, lastName);
        list[i].salary = salary;
        list[i].sector = sector;
        return 0;
    }
    return -1;
}

int findEmployeeById(eEmployee employee[], int elements, int id) {
    int i;
    for (i = 0; i < elements; i++) {
        if (id == employee[i].id) {
            return i;

        }
    }
    printf("No hay empleados con el ID:%d en el array.\n", id);
    return -1;
}

int isOneDigitNumber(int n) {
    if (n > 0 && n < 9) {
        return 1;
    } else
        return 0;
}

int isValidMenu(int n, int min, int max) {
    if (n >= min && n <= max) {
        return 1;
    } else
        return 0;
}

int isInit(int flag) {
    if (flag == 1) {
        return 1;
    } else {
        printf("No se puede realizar esta operacion sin inicializar la carga de empleados.\n");
        return 0;
    }
}

void printEmployees(eEmployee per[], int cant) {
    int i;
    system("cls");
    for (i = 0; i < cant; i++) {
        if (per[i].isEmpty == 0) {
            printf("------------------------------------------------------------\n");
            printf("| ID        |    %d\n", per[i].id);
            printf("| Nombre    |    %s\n", per[i].name);
            printf("| Apellido  |    %s\n", per[i].lastName);
            printf("| Salario   |    %f\n", per[i].salary);
            printf("| Sector    |    %d\n", per[i].sector);
            printf("------------------------------------------------------------\n");
        }
    }


}

void sortBySectorLastnameAndName(eEmployee *employee, int cant, int order) {
    int i;
    int j;
    eEmployee auxEmployee;

    if (order == 1) {
        for (i = 0; i < cant - 1; i++) {
            for (j = i; j < cant; ++j) {
                if (employee[i].sector > employee[j].sector) {
                    auxEmployee = employee[i];
                    employee[i] = employee[j];
                    employee[j] = auxEmployee;
                }

            }

        }
        for (i = 0; i < cant - 1; i++) {
            for (j = i; j < cant; ++j) {
                if (strcmp(employee[i].lastName, employee[j].lastName) > 0 && i == j) {
                    auxEmployee = employee[i];
                    employee[i] = employee[j];
                    employee[j] = auxEmployee;
                } else if (strcmp(employee[i].lastName, employee[j].lastName) == 0 && i == j) {
                    if (strcmp(employee[i].name, employee[j].name) > 0) {
                        auxEmployee = employee[i];
                        employee[i] = employee[j];
                        employee[j] = auxEmployee;
                    }

                }

            }

        }
    }
    if (order == 0) {
        for (i = 0; i < cant - 1; i++) {
            for (j = i; j < cant; ++j) {
                if (employee[i].sector < employee[j].sector) {
                    auxEmployee = employee[i];
                    employee[i] = employee[j];
                    employee[j] = auxEmployee;
                }

            }

        }
        for (i = 0; i < cant - 1; i++) {
            for (j = i; j < cant; ++j) {
                if (strcmp(employee[i].lastName, employee[j].lastName) < 0 && i == j) {
                    auxEmployee = employee[i];
                    employee[i] = employee[j];
                    employee[j] = auxEmployee;
                } else if (strcmp(employee[i].lastName, employee[j].lastName) == 0 && i == j) {
                    if (strcmp(employee[i].name, employee[j].name) < 0) {
                        auxEmployee = employee[i];
                        employee[i] = employee[j];
                        employee[j] = auxEmployee;
                    }

                }

            }

        }
    }


}

int removeEmployee(eEmployee *list, int range, int id) {
    char tempChar;
    int i, returnNum = -1;
    printf("Esta seguro que desea eliminar el registro (Y/N): \n");
    getC(&tempChar);
    tempChar = toupper(tempChar);
    if (tempChar == 'Y') {
        for (i = 0; i < range; i++) {
            if (id == list[i].id) {
                list[i].isEmpty = 1;
                returnNum = 1;
                return returnNum;
            }
            returnNum = -1;
        }
        if (returnNum != 0) {
            printf("Registro no encontrado");
            returnNum = 0;
            return returnNum;
        }
    } else {
        system("cls");
        printf("Operacion cancelada-\n");
        return returnNum;
    }

}

int totalSalaries(eEmployee *list, int range) {
    int i, totalSalaries = 0;
    for (i = 0; i < range; i++) {
        if (list->isEmpty == 0)
            totalSalaries += list[i].salary;
    }
    return totalSalaries;


}

int averageSalaries(eEmployee *list, int range) {
    int i, averageSalaries = 0, rangeOfNotEmptyEmployees = 0;
    for (i = 0; i < range; i++) {
        if (list[i].isEmpty == 0) {
            averageSalaries += list[i].salary;
            rangeOfNotEmptyEmployees++;
        }
    }
    return averageSalaries / rangeOfNotEmptyEmployees;
}

int employeesAboveAverage(eEmployee *list, int range) {
    int getAverageSalary = averageSalaries(list, range);
    int i, employessAboveAverage = 0;
    for (i = 0; i < range; i++) {
        if (list[i].isEmpty == 0 && list[i].salary > getAverageSalary) {
            employessAboveAverage++;

        }
    }
    return employessAboveAverage;


}