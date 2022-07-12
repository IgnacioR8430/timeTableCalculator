#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include "..\Comun\Comun.h"
#define LISTA_IMP_DINAMICA
#include "..\TDA\Lista\Lista.h"


typedef struct{

    char nombre[21];
    int dia1;
    int dia2;
    int dia3;

}Horario;

void cargarHorariosEnListas(char* nombreArch,Lista* pl);
void generaArchivoHorario();
int comparaHorarios(const void* h1,const void* h2);
void imprimirHorario(Lista* pl);
void modificaMatrizNombres(const void* elem,char matrizDestino[][21]);
void resetColor();
void cyan();
void yellow();
void red();
void purple();

int main(){

    int i,j,k,a,w=1;

    generaArchivoHorario();

    Lista listaHorariosMaterias;
    crearLista(&listaHorariosMaterias);

    cargarHorariosEnListas("archivoHorarios.dat",&listaHorariosMaterias);

    int cantidadMaterias = largoLista(&listaHorariosMaterias);
    Lista listaAux;
    Lista listaResultado;
    crearLista(&listaResultado);
    Horario horarioAux;

    verElementoEnPos(&listaHorariosMaterias,&listaAux,sizeof(Lista),1); // listaAux == listaAM1
    for(i = 1;i<=largoLista(&listaAux);i++){
        verElementoEnPos(&listaAux,&horarioAux,sizeof(Horario),i);
        insertarEnListaFondo(&listaResultado,&horarioAux,sizeof(Horario));
        verElementoEnPos(&listaHorariosMaterias,&listaAux,sizeof(Lista),2); //listaAux == listaAGA
        for(j = 1;j<=largoLista(&listaAux);j++){
            verElementoEnPos(&listaAux,&horarioAux,sizeof(Horario),j);
            insertarEnListaFondo(&listaResultado,&horarioAux,sizeof(Horario));
            verElementoEnPos(&listaHorariosMaterias,&listaAux,sizeof(Lista),3); //listaAux == listaQuimica
            for(k = 1;k<=largoLista(&listaAux);k++){
                verElementoEnPos(&listaAux,&horarioAux,sizeof(Horario),k);
                insertarEnListaFondo(&listaResultado,&horarioAux,sizeof(Horario));
                verElementoEnPos(&listaHorariosMaterias,&listaAux,sizeof(Lista),4); //listaAux == listaDiscreta
                for(a = 1;a<=largoLista(&listaAux);a++){
                    verElementoEnPos(&listaAux,&horarioAux,sizeof(Horario),a);
                    insertarEnListaFondo(&listaResultado,&horarioAux,sizeof(Horario));
                    if(!hayDuplicados(&listaResultado,comparaHorarios)){
                        purple();
                        printf("OPCION: %d \n",w);
                        w++;
                        resetColor();
                        imprimirHorario(&listaResultado);
                    }
                    eliminarDeListaFondo(&listaResultado,NULL,0);
                }
                eliminarDeListaFondo(&listaResultado,NULL,0);
                verElementoEnPos(&listaHorariosMaterias,&listaAux,sizeof(Lista),3); //listaAux == listaQuimica
            }
            eliminarDeListaFondo(&listaResultado,NULL,0);
            verElementoEnPos(&listaHorariosMaterias,&listaAux,sizeof(Lista),2); //listaAux == listaAGA
        }
        eliminarDeListaFondo(&listaResultado,NULL,0);
        verElementoEnPos(&listaHorariosMaterias,&listaAux,sizeof(Lista),1); // listaAux == listaAM1
    }

    //printf("%s | %d | %d | %d",horarioAux.nombre,horarioAux.dia1,horarioAux.dia2,horarioAux.dia3);
    //getch();
    return 0;
}

void imprimirHorario(Lista* pl){

    char nombresMaterias[18][21]={};

    recorrerLista(pl,(Accion)modificaMatrizNombres,nombresMaterias);

    /*
    printf("|     Lunes     |     Martes     |   Miercoles   |     Jueves     |    Viernes    |     Sabado     |\n");
    printf("|---------------|----------------|---------------|----------------|---------------|----------------|\n");
    printf("|               |                |               |                |               |                |\n");
    printf("|%15s|%16s|%15s|%16s|%15s|%16s|\n",nombresMaterias[0],nombresMaterias[1],nombresMaterias[2],nombresMaterias[3],nombresMaterias[4],nombresMaterias[5]);
    printf("|               |                |               |                |               |                |\n");
    printf("|---------------|----------------|---------------|----------------|---------------|----------------|\n");
    printf("|               |                |               |                |               |                |\n");
    printf("|%15s|%16s|%15s|%16s|%15s|%16s|\n",nombresMaterias[6],nombresMaterias[7],nombresMaterias[8],nombresMaterias[9],nombresMaterias[10],nombresMaterias[11]);
    printf("|               |                |               |                |               |                |\n");
    printf("|---------------|----------------|---------------|----------------|---------------|----------------|\n");
    printf("|               |                |               |                |               |                |\n");
    printf("|%15s|%16s|%15s|%16s|%15s|%16s|\n",nombresMaterias[12],nombresMaterias[13],nombresMaterias[14],nombresMaterias[15],nombresMaterias[16],nombresMaterias[17]);
    printf("|               |                |               |                |               |                |\n");
    printf("|---------------|----------------|---------------|----------------|---------------|----------------|\n");
    printf("\n");*/

    printf("|     Lunes     |     Martes     |   Miercoles   |     Jueves     |    Viernes    |     Sabado     |\n");
    printf("|---------------|----------------|---------------|----------------|---------------|----------------|\n");
    printf("|               |                |               |                |               |                |\n");
    printf("|");
    cyan();
    printf("%15s",nombresMaterias[0]);
    resetColor();
    printf("|");
    cyan();
    printf("%16s",nombresMaterias[1]);
    resetColor();
    printf("|");
    cyan();
    printf("%15s",nombresMaterias[2]);
    resetColor();
    printf("|");
    cyan();
    printf("%16s",nombresMaterias[3]);
    resetColor();
    printf("|");
    cyan();
    printf("%15s",nombresMaterias[4]);
    resetColor();
    printf("|");
    cyan();
    printf("%16s",nombresMaterias[5]);
    resetColor();
    printf("|");
    printf("\n|               |                |               |                |               |                |\n");
    printf("|---------------|----------------|---------------|----------------|---------------|----------------|\n");
    printf("|               |                |               |                |               |                |\n");
    printf("|");
    yellow();
    printf("%15s",nombresMaterias[6]);
    resetColor();
    printf("|");
    yellow();
    printf("%16s",nombresMaterias[7]);
    resetColor();
    printf("|");
    yellow();
    printf("%15s",nombresMaterias[8]);
    resetColor();
    printf("|");
    yellow();
    printf("%16s",nombresMaterias[9]);
    resetColor();
    printf("|");
    yellow();
    printf("%15s",nombresMaterias[10]);
    resetColor();
    printf("|");
    yellow();
    printf("%16s",nombresMaterias[11]);
    resetColor();
    printf("|");
    printf("\n|               |                |               |                |               |                |\n");
    printf("|---------------|----------------|---------------|----------------|---------------|----------------|\n");
    printf("|               |                |               |                |               |                |\n");
    printf("|");
    red();
    printf("%15s",nombresMaterias[12]);
    resetColor();
    printf("|");
    red();
    printf("%16s",nombresMaterias[13]);
    resetColor();
    printf("|");
    red();
    printf("%15s",nombresMaterias[14]);
    resetColor();
    printf("|");
    red();
    printf("%16s",nombresMaterias[15]);
    resetColor();
    printf("|");
    red();
    printf("%15s",nombresMaterias[16]);
    resetColor();
    printf("|");
    red();
    printf("%16s",nombresMaterias[17]);
    resetColor();
    printf("|");
    printf("\n|               |                |               |                |               |                |\n");
    printf("|---------------|----------------|---------------|----------------|---------------|----------------|\n");
    printf("\n");

}

void modificaMatrizNombres(const void* elem,char matrizDestino[][21]){

    Horario* pH = (Horario*)elem;

    if(pH->dia1){
        strcpy(matrizDestino[pH->dia1-1],pH->nombre);
        if(pH->dia2){
            strcpy(matrizDestino[pH->dia2-1],pH->nombre);
            if(pH->dia3){
                strcpy(matrizDestino[pH->dia3-1],pH->nombre);
            }
        }

    }

}

int comparaHorarios(const void* h1,const void* h2){
    Horario* pH1 = (Horario*)h1;
    Horario* pH2 = (Horario*)h2;

    if( (pH1->dia1 != pH2->dia1) || !pH1->dia1 || !pH2->dia1 ){
        if((pH1->dia2 != pH2->dia2) || !pH1->dia2 || !pH2->dia2 ){
            if((pH1->dia3 != pH2->dia3) || !pH1->dia3 || !pH2->dia3){
                return 1;
            }
        }
    }
    return 0;
}

void generaArchivoHorario(){

    /*Horario horariosAM1[]={
        {"AM1",1,4,0},
        {"AM1",2,5,0},
        {"AM1",7,10,0}
    };

    Horario horariosAGA[]={
        {"AGA",2,5,0},
        {"AGA",3,5,0},
        {"AGA",8,10,0},
        {"AGA",1,5,0},
    };

    Horario horariosCompu[]={
        {"Computacion",6,0,0},
        {"Computacion",3,0,0},
    };*/

    Horario horariosAM1[]={
        {"AM1",1,3,0},
        {"AM1",2,4,0},
        {"AM1",9,11,0},
        {"AM1",7,10,0},
        {"AM1",13,15,0}
    };

    Horario horariosAGA[]={
        {"AGA",1,4,0},
        {"AGA",8,11,0},
        {"AGA",3,5,0},
        {"AGA",16,18,0},
    };

    Horario horariosQuimica[]={
        {"Quimica",2,5,0},
        {"Quimica",1,4,0},
        {"Quimica",7,9,0},
        {"Quimica",8,10,0},
    };

    Horario horariosDiscreta[]={
        {"Discreta",1,0,0},
        {"Discreta",3,0,0},
        {"Discreta",5,0,0},
        {"Discreta",7,0,0},
        {"Discreta",11,0,0},
        {"Discreta",4,0,0},
    };

    FILE* pf = fopen("archivoHorarios.dat","wb");

    fwrite(&horariosAM1,sizeof(Horario),5,pf);
    fwrite(&horariosAGA,sizeof(Horario),4,pf);
    fwrite(&horariosQuimica,sizeof(Horario),4,pf);
    fwrite(&horariosDiscreta,sizeof(Horario),6,pf);

    fclose(pf);
}

void cargarHorariosEnListas(char* nombreArch,Lista* pl){

    FILE* pf = fopen(nombreArch,"rb");
    Horario horarioLeido,horarioAnterior;
    Lista listaAux;
    crearLista(&listaAux);

    fread(&horarioLeido,sizeof(Horario),1,pf);
    horarioAnterior=horarioLeido;
    while(!feof(pf)){
        if(strcmp(horarioLeido.nombre,horarioAnterior.nombre)!=0){
            insertarEnListaFondo(pl,&listaAux,sizeof(Lista));
            crearLista(&listaAux);
        }

        horarioAnterior=horarioLeido;
        insertarEnListaFondo(&listaAux,&horarioLeido,sizeof(Horario));
        fread(&horarioLeido,sizeof(Horario),1,pf);

    }

    insertarEnListaFondo(pl,&listaAux,sizeof(Lista));

    fclose(pf);
}

void resetColor(){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole,7);
}

void cyan(){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole,3);
}

void yellow(){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole,6);
}

void red(){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole,4);
}

void purple(){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole,5);
}
