#include <stdio.h>
#include <stdlib.h>
#define CANT 5
#include ".\\functions-in-C\\functionsBiblo\\functionsForProjects.h"

typedef struct {
    int legajo;
    char nombre[50];
    float salario;
    int isEmpty;

}ePersona;


int getFreeSpace(ePersona[],int);
int init(ePersona[], int);
int alta(ePersona[], int);
int isRepeated(ePersona[], int,int);


int getFreeSpace(ePersona Per[],int cant ) {

    int i;
    for (i=0;i<cant;i++){
            printf("ENTRO \n");
        if(Per[i].isEmpty==1){
            return i;
        }
    }
    return -1;

}


isRepeated(ePersona Per[],int buffer,int cant){
    int retorno=0,i;
    for(i=0;i<cant;i++) {
            if(Per[i].legajo==buffer) {
                printf("Legajo repetido.");
                retorno=1;
            }

    }
    //TODO terminar
    return retorno;
}
int init(ePersona Per[], int cant){
    int i;
    for (i=0;i<cant;i++){
        Per[i].isEmpty=1;
    }
    return 0;

}
int alta(ePersona Per[],int cant){

    //TODO seguir
    int i,buffer;
    //getFreeSpace(Per)
    i=getFreeSpace(Per,cant);
        if(i!=-1){
            Per[i].isEmpty=0;

            printf("Ingrese el nombre: \n");
            gets(&Per[i].nombre);
            getEntero(&buffer,"Ingrese un legajo","Legajo invalido",0,2147483647,2);

            if(!isRepeated(Per,buffer,CANT)){
                    Per[i].legajo=buffer;

            };

            getFloat(&Per[i].salario,"Ingrese salario","Salario invalido",0,2147483647,2);

            return 0;


        }

    return -1;

}
int main()
{
    ePersona Per[CANT];
    init(Per, CANT);
    alta(Per, CANT);
    printf("\nEl primer legajo es:\n   Nombre:%s\n   Legajo:%d\n   Salario:%f",Per[0].nombre,Per[0].legajo,Per[0].salario);
    printf("EL TAMAÑO DEL ARRAY ES : %d", sizeof(Per)/sizeof(Per[0]));
    return 0;
}
