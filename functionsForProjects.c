
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "functionsForProjects.h"

static int getI(int *pBuffer) {

    return scanf("%d", pBuffer);

}

static char getC(char *pBuffer) {

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
    while (c[i] != '\0') {
        if ((c[i] != ' ') && (c[i] < 'a' || c[i] > 'z') && (c[i] < 'A' || c[i] > 'Z'))
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
        }
    } while (intentos >= 0);
    return 0;
}
//    if(pChar != NULL && msg != NULL && msgError != NULL && minChar<=maxChar && reintentos>=0) {
//        do{
//            reintentos--;
//            printf("%s", msg);
//            fflush(stdin);
//            if(getC(&bufferChar)&& bufferChar>=minChar && bufferChar<=maxChar){
//
//                *pChar = bufferChar;
//                returnNum = 0;
//                break;
//
//            }else{
//                printf("%s", msgError);
//
//            }
//
//
//        }while(reintentos>0);

//    }
int getFreeSpace(eEmployee Per[], int cant) {

    int i;
    for (i = 0; i < cant; i++) {
        if (Per[i].isEmpty == 1) {
            return i;
        }
    }
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


int isOneDigitNumber(int n) {
    if (n > 0 && n < 9) {
        return 1;
    } else
        return 0;
}

int isValidMenu(int n) {
    if (!(n > 0 && n <= 5)) {
        return 0;
    } else
        return 1;
}

int isInit(int flag) {
    if (flag == 1) {
        return 1;
    } else {
        printf("No se puede realizar esta operacion sin inicializar la carga de empleados.\n");
        return 0;
    }
}

void printStructArray(eEmployee per[], int cant) {
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

void sortByLastname(eEmployee employee[], int cant, int order) {
    int i;
    int j;
    eEmployee auxEmployee;

    if (order == 1) {
        for (i = 0; i < cant - 1; i++) {
            for (j = i; j < cant; ++j) {
                if (strcmp(employee[i].lastName, employee[j].lastName) > 0) {
                    auxEmployee = employee[i];
                    employee[i] = employee[j];
                    employee[j] = auxEmployee;
                } else if (strcmp(employee[i].lastName, employee[j].lastName) == 0) {
                    if (strcmp(employee[i].name, employee[j].name) > 0) {
                        auxEmployee = employee[i];
                        employee[i] = employee[j];
                        employee[j] = auxEmployee;
                    }

                }

            }

        }
    }
    if(order == 0){
        for (i = 0; i < cant - 1; i++) {
            for (j = i; j < cant; ++j) {
                if (strcmp(employee[i].lastName, employee[j].lastName) < 0) {
                    auxEmployee = employee[i];
                    employee[i] = employee[j];
                    employee[j] = auxEmployee;
                } else if (strcmp(employee[i].lastName, employee[j].lastName) == 0) {
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