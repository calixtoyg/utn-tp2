#include <stdio.h>
#include <stdlib.h>

#define SIZE 5
#define EXIT 5
#define CHARSIZE 50

#include "functionsForProjects.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int flag = 0, id = 0, sector, menu, order;
    float salary;
    char name[CHARSIZE];
    char lastname[CHARSIZE];
    eEmployee employee[SIZE];

    do {
        printf("--------------------------- Menu ---------------------------\n");
        printf("|1- ALTA de empleado                                       |\n");
        printf("|                                                          |\n");
        printf("|2- MODIFICAR empleado                                     |\n");
        printf("|                                                          |\n");
        printf("|3- BAJA de empleado                                       |\n");
        printf("|                                                          |\n");
        printf("|4- INFORMAR empleado/s                                    |\n");
        printf("|                                                          |\n");
        printf("|5- SALIR                                                  |\n");
        printf("------------------------------------------------------------\n");
        fflush(stdin);
        scanf("%d", &menu);
        if (!isValidMenu(menu)) {
            printf("El numero ingresado no es valido.\n");
            menu = 0;
        }

        if (menu == 1) {
            if (flag == 0) {
                if (initEmployees(employee, SIZE) != -1) {
                    printf("No hay espacio libre.\n");
                } else {
                    flag = 1;
                }
            }
            
            if (getFreeSpace(employee, SIZE) != -1)
                id++;
            printf("------------------------------------------------------------\n");
            getStringLettersOnly(name, "Ingrese el nombre:\n", CHARSIZE, 3);
            printf("------------------------------------------------------------\n");
            getStringLettersOnly(lastname, "Ingrese el apellido:\n", CHARSIZE, 3);

            printf("------------------------------------------------------------\n");
            getEntero(&sector, "Ingrese el sector:\n", "ERROR: Solo numeros entre 0 y 300\n",
                      0, 300, 3);
            printf("------------------------------------------------------------\n");
            getFloat(&salary, "Ingrese el salario:\n", "ERROR: Un salario no puede ser negativo.\n",
                     0, pow(2,1024), 3);
            addEmployee(employee, SIZE, id, name, lastname, salary, sector);

        }

        if (menu == 2) {
            if (isInit(flag)) {

            }
        }
        if (menu == 3) {
            if (isInit(flag)) {


            }

        }

        if (menu == 4) {
            if (isInit(flag)) {


                fflush(stdin);
                system("cls");
                int returnNum = getEntero(&order, "Ingrese el orden de ordenamiento(1 ascendente/0 descendente):  \n",
                                          "ERROR: Solo 1 o 0 estan perimitidos como orden.\n",
                                          0, 1, 3);
                if (returnNum != -1) {
                    toUpperLastNameAndName(employee, SIZE);
                    sortByLastname(employee, SIZE, order);
                    printStructArray(employee, SIZE);
                }

            }


        }
    } while (menu != EXIT);
    return 0;

}


