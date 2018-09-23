#include <stdio.h>
#include <stdlib.h>

#define CANT 5
#define ID 0
#define EXIT 5

#include "functionsForProjects.h"


int main() {
    int flag = 0, id = 0, sector;
    float salary;
    int menu;
    char name[20];//BORERAR TODO
    char lastname[20];//BORERAR TODO
    eEmployee employee[CANT];

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
                if (initEmployees(employee, CANT) != -1) {
                    printf("No hay espacio libre.\n");
                } else {
                    flag = 1;
                }
            }
            //TODO esta todo medio hardcordeado.
            if (getFreeSpace(employee, CANT) != -1)
                id++;
            printf("------------------------------------------------------------\n");
            getString(name,"|               Ingrese el nombre:                         |\n");
            printf("------------------------------------------------------------\n");
            system("cls");
            printf("------------------------------------------------------------\n");
getString(lastname,"|               Ingrese el apellido:                      |\n");
            printf("------------------------------------------------------------\n");
            system("cls");
            printf("------------------------------------------------------------\n");
            getEntero(&sector, "|               Ingrese el sector:                        |\n","ERROR: Solo numeros\n",0,300,0);
            printf("------------------------------------------------------------\n");
            system("cls");
            printf("------------------------------------------------------------\n");
            getFloat(&salary, "|               Ingrese el salario:                       |\n","ERROR: Solo numeros\n",0,450000.0,0);
            printf("------------------------------------------------------------\n");
            system("cls");
            addEmployee(employee, CANT, id, name,lastname, salary, sector);

        }

        if (menu == 2) {
            if (isInit(flag)) {

            } else {

            }

        }
        if (menu == 3) {
            if (isInit(flag)) {


            }

        }

        if (menu == 4) {
            if (isInit(flag)) {
                printf("\nEl primer legajo es:\n   Nombre:%s\n   Apellido:%s\n   Salario:%f\n   Sector:%d\n", employee[0].id,
                       employee[0].name, employee[0].lastName,employee[0].salary, employee[0].sector);

            }


        }
    } while (menu != EXIT);
    return 0;
//    eEmployee Per[CANT];
//    initEmployees(Per, CANT);
//    alta(Per, CANT);
//    //alta(Per, CANT);
//    //alta(Per, CANT);
//    printf("\nEl primer legajo es:\n   Nombre:%s\n   Legajo:%d\n   Salario:%f",Per[0].nombre,Per[0].legajo,Per[0].salario);
//    printf("EL TAMA�O DEL ARRAY ES : %d", sizeof(Per)/sizeof(Per[0]));
//    alta(Per, CANT);
//    //alta(Per, CANT);
//    //alta(Per, CANT);
//    printf("-----------------------------------------------------------------------------------------------------------");
//    printf("\nEl primer legajo es:\n   Nombre:%s\n   Legajo:%d\n   Salario:%f",Per[0].nombre,Per[0].legajo,Per[0].salario);
//    printf("EL TAMA�O DEL ARRAY ES : %d", sizeof(Per)/sizeof(Per[0]));
//    getchar();

}


