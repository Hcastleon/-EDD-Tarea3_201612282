#include <iostream>
#include"ABB.h"

using namespace std;

ABB* arbolito=new ABB();

void llenar(string dato){
    ABB *q=new ABB(dato);
    q->dato=dato;
    q->izquierdo=NULL;
    q->derecho=NULL;
    arbolito->_insertar(q);
}

int main()
{
		llenar("luigi");
		llenar("hammer");
		llenar("mario");
		llenar("peach");
		llenar("pow");
		llenar("fermin");
		arbolito->_eliminar("peach");
		llenar("shy_guy");
		llenar("edd");
		arbolito->_eliminar("pow");
		llenar("Boo");
		llenar("Kamek");
		llenar("star");
		llenar("Whomp");
		arbolito->_eliminar("shy_guy");
		arbolito->_eliminar("mario");
		arbolito->grafica();

    return 0;
}
