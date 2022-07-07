#include "..\Grafo\Grafo.h"

void crearGrafo(Grafo* pg){
    *pg=NULL;
}

booleano añadirNodoHijo(Grafo* pg,void* elem,size_t tamElem){
    NodoG* nue = crearNodoG(elem,tamElem);
    if(!nue){
        return FALSO;
    }

    insertarEnListaFondo(&nue->hijos,nue,sizeof(NodoG));
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

    /*for(i=1;i<=largoLista(&(*pg)->hijos);i++){
        
        recorrerGrafoComoArbolOrd()

    }*/
}