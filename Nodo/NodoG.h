#ifndef NODOG_H_INCLUDED
#define NODOG_H_INCLUDED
#define LISTA_IMP_DINAMICA

#include "..\TDA\Lista\Lista.h"

#include <stddef.h>

typedef struct{

    size_t tamElem;
    void* elem;
    Lista hijos;

}NodoG;

NodoG* crearNodoG(void* elem,size_t tamElem);
void destruirNodoG(NodoG* nae,void* elem,size_t tamElem);


#endif // NODOG_H_INCLUDED
