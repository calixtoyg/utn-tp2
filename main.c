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
        printf("| 1 - ALTA de empleado                                     |\n");
        printf("|                                                          |\n");
        printf("| 2 - MODIFICAR empleado                                   |\n");
        printf("|                                                          |\n");
        printf("| 3 - BAJA de empleado                                     |\n");
        printf("|                                                          |\n");
        printf("| 4 - INFORMAR empleado/s                                  |\n");
        printf("|                                                          |\n");
        printf("| 5 - SALIR                                                |\n");
        printf("------------------------------------------------------------\n");
        fflush(stdin);
        scanf("%d", &menu);
        if (!isValidMenu(menu, 1, 5)) {
            printf("El numero ingresado no es valido.\n");
            menu = 0;
        }
        switch (menu) {
            case 1:
                if (flag == 0) {
                    if (initEmployees(employee, SIZE) != -1) {
                        printf("No hay espacio libre.\n");
                    } else {
                        flag = 1;
                    }
                }
                if (getFreeSpace(employee, SIZE) != -1) {
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
                             0, pow(2, 1024), 3);
                    addEmployee(employee, SIZE, id, name, lastname, salary, sector);
                }
                break;
            case 2:
                if (isInit(flag)) {
                    int idToFind = getEntero(&idToFind, "Ingrese el ID del empleado que desea modificar\n",
                                             "ERROR: Solo numeros dentro de la cantidad maxima del array estan perimitidos\n",
                                             0, SIZE, 3);
                    int index = findEmployeeById(employee, SIZE, idToFind);
                    if (index != -1) {
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
                                 0, pow(2, 1024), 3);
                        addEmployee(employee, SIZE, index, name, lastname, salary, sector);
                    }
                }
                break;
            case 3:
                if (isInit(flag)) {
                    int idToFind = getEntero(&idToFind, "Ingrese el ID del empleado que desea eliminar\n",
                                             "ERROR: Solo numeros dentro de la cantidad maxima del array estan perimitidos\n",
                                             0, SIZE, 3);
                    removeEmployee(employee, id);


                }
                break;
            case 4:
                if (isInit(flag)) {
                    do {
                        system("cls");
                        fflush(stdin);
                        printf("--------------------------- Menu --------------------------------------------------\n");
                        printf("| 1 - Empleados/s ordenados alfabeticamente p/apellido                            |\n");
                        printf("|                                                                                 |\n");
                        printf("| 2 - Empleados/s Total, promedio de salarios y empleados que superan el promedio |\n");
                        printf("-----------------------------------------------------------------------------------\n");
                        scanf("%d", &menu);
                        if (!isValidMenu(menu, 1, 2)) {
                            printf("El numero ingresado no es valido.\n");
                            menu = 0;
                        }


                    } while (menu != 1 && menu != 2);
                    switch (menu){
                        case 1:
                            fflush(stdin);
                            int returnNum = getEntero(&order,
                                                      "Ingrese el orden de ordenamiento 1 para ascendente y 0 para descendente:  \n",
                                                      "ERROR: Solo numeros entre 0 y 1(inclusive) estan perimitidos.\n",
                                                      0, 1, 3);
                            if (returnNum != -1) {
                                toUpperLastNameAndName(employee, SIZE);
                                sortByLastnameAndName(employee, SIZE, order);
                                printEmployees(employee, SIZE);
                            }
                            break;
                        case 2:
                            break;
                    }


                }
                break;
            default:
                break;
        }

    } while (menu != EXIT);
    return 0;

}


