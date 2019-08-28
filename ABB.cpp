#include "ABB.h"
#include<iostream>
#include<string.h>
#include<algorithm>

using namespace std;

ABB::ABB()
{
    raiz=NULL;
}

ABB::ABB(string dato)
{
    dato=dato;
}

int ABB::vacio( ABB*h ){
	int r=0;
	if( !h ) r=1;
	return r;
}

char easytolower(char in) {
  if(in <= 'Z' && in >= 'A')
    return in - ('Z' - 'z');
  return in;
}

ABB* ABB::insertar(ABB *padre,ABB *nuevo){
    string minusculas=nuevo->dato;
    transform(minusculas.begin(), minusculas.end(), minusculas.begin(), easytolower);
	if(padre==NULL) padre=nuevo;
	else{
		char nq[20];
		char np[20];
		strcpy(nq,minusculas.c_str());
		strcpy(np,padre->dato.c_str());
		if(strcmp(nq,np)<=0)
			padre->izquierdo=insertar(padre->izquierdo,nuevo);
		else
			padre->derecho=insertar(padre->derecho,nuevo);
	}
	return padre;
}



void ABB::_insertar(ABB*q){
	raiz=insertar(raiz,q);
}

 ABB *ABB::eliminar(ABB *padre, string dato){
	if(padre->dato==dato)
		{
		ABB *p, *p2;

		if( vacio(padre) )
			{
			free( padre);
			padre= NULL;
			return padre;
			}
		else if(padre->izquierdo==NULL )
			{
			p= padre->derecho;
			free( padre );
			return p;
			}
		else if( padre->derecho==NULL )
			{
			p= padre->izquierdo;
			free( padre);
			return p;
			}
		else
			{
			p= padre->derecho;
			p2= padre->derecho;
			while(p->izquierdo) p= p->izquierdo;
			p->izquierdo= padre->izquierdo;
			free( padre );
			return p2;
         }
		}
	else if(dato<padre->dato)
		 padre->izquierdo= eliminar( padre->izquierdo, dato );
	else
		 padre->derecho= eliminar(  padre->derecho ,dato );
	return padre;

}

void ABB::_eliminar(string dato){
	raiz=eliminar(raiz,dato);
}


void ABB::print_dot_hijos(ABB* node, FILE* stream)
{
     long int point = reinterpret_cast<long int>(node);
    if (node->izquierdo)
    {
        long int point2 = reinterpret_cast<long int>(node->izquierdo);
        fprintf(stream, "%ld[label=\"<C0>|%s|<C1>\"];\n", point, node->dato.c_str());
        fprintf(stream, "%ld[label=\"<C0>|%s|<C1>\"];\n", point2, node->izquierdo->dato.c_str());
        fprintf(stream, "    %ld:C0 -> %ld;\n", point, point2);
        print_dot_hijos(node->izquierdo, stream);
    }

    if (node->derecho)
    {
        long int point2 = reinterpret_cast<long int>(node->derecho);
        fprintf(stream, "%ld[label=\"<C0>|%s|<C1>\"];\n", point, node->dato.c_str());
        fprintf(stream, "%ld[label=\"<C0>|%s|<C1>\"];\n", point2, node->derecho->dato.c_str());
        fprintf(stream, "    %ld:C1 -> %ld;\n",point, point2);
        print_dot_hijos(node->derecho, stream);
    }

}

void ABB::print_dot_raiz(ABB* tree, FILE* stream)
{
    fprintf(stream, "digraph BINARIO {\n");
     fprintf(stream,"graph [nodesep=0.5]\n");
    fprintf(stream, "    node [shape = record,fontname=\"Arial\", color=\"#abebc6\", style=filled];\n");
    long int point = reinterpret_cast<long int>(tree);

    if (!tree)
        fprintf(stream, "\n");
    else if (!tree->derecho && !tree->izquierdo)
        fprintf(stream, "    %ld;\n", point);
    else
        print_dot_hijos(tree, stream);

    fprintf(stream, "}\n");
}

void ABB::grafica(){
	FILE *archivo;
	archivo=fopen("ABB_S.dot","w");
	print_dot_raiz(raiz,archivo);
	fclose(archivo);
	system("dot -Tjpg ABB_S.dot -o ABBCPP.jpg");
	system("eog ABBCPP.jpg");

}
