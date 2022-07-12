#include "..\Grafo\Grafo.h"

void crearGrafo(Grafo* pg){
    *pg=NULL;
}

booleano añadirNodoHijo(Grafo* pg,void* elem,size_t tamElem){
    NodoG* nue = crearNodoG(elem,tamElem);
    if(!nue){
        return FALSO;
    }

    insertarEnListaFondo(&(*pg)->hijos,nue,sizeof(NodoG));
    return VERDADERO;
}

void eliminarNodoHijo(Grafo* pg, void* elem, size_t tamElem){

}

void verElemento(Grafo* pg,void* elem,size_t tamElem){
    if(!*pg){
        return;
    }
    memcpy(elem,(*pg)->elem,MIN(tamElem,(*pg)->tamElem));
}

void recorrerGrafoComoArbolOrd(Grafo* pg,Accion acc,void* datosAccion){
    int i;

    if(!(*pg)->hijos){
        acc((*pg)->elem,datosAccion);
        return;
    }

    for(i=1;i<=largoLista(&(*pg)->hijos);i++){
        
        recorrerGrafoComoArbolOrd(dirElementoDeListaPos(&(*pg)->hijos,i),acc,datosAccion);

    }

    acc((*pg)->elem,datosAccion);

}

void insertarListaEnHijo(Grafo* pg,Lista* pl){
    (*pg)->hijos=*pl;
}