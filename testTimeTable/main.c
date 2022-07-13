#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "color.h"
#include "..\Comun\Comun.h"

#define LISTA_IMP_DINAMICA
#include "..\TDA\Lista\Lista.h"


typedef struct{

    char nombre[21];
    int dia1;
    int dia2;
    int dia3;

}Horario;

void generaArchivoHorario();

void cargarHorariosEnListas(char* nombreArch,Lista* pl);
int comparaHorarios(const void* h1,const void* h2);
void imprimirHorario(Lista* pl);
void modificaMatrizNombres(const void* elem,char matrizDestino[][21]);
int calculaPosibilidades(Lista* pl,int cantMaterias, Lista* plCantHor);
int calculaIndice(int materia,int iteracion, Lista* plCantHor, int cantMaterias);


int main(){

    int x,y,w=1;
    int indice;

    generaArchivoHorario();

    Lista listaHorariosMaterias;
    crearLista(&listaHorariosMaterias);

    Lista listaAux;
    crearLista(&listaAux);

    Lista listaCantHorarios;
    crearLista(&listaCantHorarios);

    Lista listaResultado;
    crearLista(&listaResultado);

    Horario horarioAux;

    cargarHorariosEnListas("archivoHorarios.dat",&listaHorariosMaterias);

    int cantidadMaterias = largoLista(&listaHorariosMaterias);

    int totalPosibilidades = calculaPosibilidades(&listaHorariosMaterias,cantidadMaterias,&listaCantHorarios);

    for(x=1;x<=totalPosibilidades;x++){
        for(y=cantidadMaterias;y>=1;y--){
            verElementoEnPos(&listaHorariosMaterias,&listaAux,sizeof(Lista),y); //carga la lista de horarios de la materia Y
            indice = calculaIndice(y,x,&listaCantHorarios,cantidadMaterias);    //calcula el indice correspondiente a la dupla iteracion-materia
            verElementoEnPos(&listaAux,&horarioAux,sizeof(Horario),indice);     //busca la opcion de horario segun el indice calculado
            insertarEnListaFrente(&listaResultado,&horarioAux,sizeof(Horario)); //
        }
        if(!hayDuplicados(&listaResultado,comparaHorarios)){
            purple();
            printf("OPCION: %d \n",w);
            w++;
            resetColor();
            imprimirHorario(&listaResultado);
        }
        vaciarLista(&listaResultado);
    }
    for(x=1;x<=cantidadMaterias;x++){
        verElementoEnPos(&listaHorariosMaterias,&listaAux,sizeof(Lista),x);
        vaciarLista(&listaAux);
    }
    vaciarLista(&listaHorariosMaterias);
    vaciarLista(&listaCantHorarios);
    getch();
    return 0;
}

int calculaIndice(int materia,int iteracion,Lista* plCantHor, int cantMaterias){

    int modul,div=1,i,cantAux;
    int res;


    if(materia == cantMaterias){
        verElementoEnPos(plCantHor,&modul,sizeof(int),materia);
        return ((iteracion-1)%modul)+1;
    }
    else{
        for(i=cantMaterias;i>materia;i--){
            verElementoEnPos(plCantHor,&cantAux,sizeof(int),i);
            div*=cantAux;
        }
        verElementoEnPos(plCantHor,&modul,sizeof(int),materia);

        res = ( ( ((iteracion-1)/div) + 1 )%modul );
        if(res==0){
            return modul;
        }
        return res;
    }

}

int calculaPosibilidades(Lista* pl,int cantMaterias, Lista* plCantHor){

    int i,res=1;
    int cantHorarios[cantMaterias];
    Lista listaAux;
    for(i=1;i<=cantMaterias;i++){
        verElementoEnPos(pl,&listaAux,sizeof(Lista),i);
        cantHorarios[i-1] = largoLista(&listaAux);
    }

    for(i=0;i<cantMaterias;i++){
        res*=cantHorarios[i];
        insertarEnListaFondo(plCantHor,&cantHorarios[i],sizeof(int));
    }

    return res;
}

void imprimirHorario(Lista* pl){

    char nombresMaterias[18][21]={};

    recorrerLista(pl,(Accion)modificaMatrizNombres,nombresMaterias);

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

    if( (pH1->dia1 != pH2->dia1 && pH1->dia1 != pH2->dia2 && pH1->dia1 != pH2->dia3) || !pH1->dia1 ){
        if( (pH1->dia2 != pH2->dia1 && pH1->dia2 != pH2->dia2 && pH1->dia2 != pH2->dia3) || !pH1->dia2 ){
            if((pH1->dia3 != pH2->dia1 && pH1->dia3 != pH2->dia2 && pH1->dia3 != pH2->dia3 ) || !pH1->dia3 ){
                return 1;
            }
        }
    }
    return 0;
}

void generaArchivoHorario(){



    Horario horariosAM1[]={
        {"AM1",1,3,0},
        {"AM1",2,4,0},
        {"AM1",9,11,0},
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
    };

    Horario horariosFisica[]={
        {"Fisica",2,5,0},
        {"Fisica",1,3,0},
        {"Fisica",3,6,0},
        {"Fisica",2,4,0},
        {"Fisica",13,15,0},
        {"Fisica",14,17,0},
    };

    FILE* pf = fopen("archivoHorarios.dat","wb");

    fwrite(&horariosAM1,sizeof(Horario),4,pf);
    fwrite(&horariosAGA,sizeof(Horario),4,pf);
    fwrite(&horariosQuimica,sizeof(Horario),4,pf);
    fwrite(&horariosDiscreta,sizeof(Horario),5,pf);
    fwrite(&horariosFisica,sizeof(Horario),6,pf);

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


