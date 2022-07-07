#ifndef GRAFO_H_INCLUDED
#define GRAFO_H_INCLUDED

#include "..\..\Comun\Comun.h"
#include "..\Grafo_Imp_Dinamica\Grafo_Imp_Dinamica.h"

void crearGrafo(Grafo* pg);
booleano añadirNodoHijo(Grafo* pg,void* elem,size_t tamElem);
void eliminarNodoHijo(Grafo* pg, void* elem, size_t tamElem);
void verElemento(Grafo* pg,void* elem,size_t tamElem);
void recorrerGrafoComoArbolOrd(Grafo* pg,Accion acc,void* datosAccion);


#endif // GRAFO_H_INCLUDED
