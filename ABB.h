#ifndef ABB_H
#define ABB_H
#include<string.h>
#include<iostream>

using namespace std;

class ABB
{
    public:

        ABB();
        ABB(string dato);

        string dato;
        ABB* izquierdo;
        ABB* derecho;

        ABB *raiz;

        void grafica();
        void _insertar(ABB*q);
        void _eliminar(string dato);

    private:
        int vacio( ABB*h );
        ABB* insertar(ABB *padre,ABB *nuevo);
        ABB* eliminar(ABB *padre, string dato);
        void print_dot_hijos(ABB* node, FILE* stream);
        void print_dot_raiz(ABB* tree, FILE* stream);
};

#endif // ABB_H
