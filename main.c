#include <stdio.h>
#include <stdlib.h>


typedef struct stNodo
{
    int num;
    struct stNodo * siguiente;

} stNodo;


//PROTOTIPADO
stNodo * inicLista();
stNodo * crearNodo(int num);
stNodo * cargarListaRand(stNodo * lista);
stNodo * agregarUltimo (stNodo * lista, stNodo * nuevoNodo);
stNodo * buscarUltimo(stNodo * lista);
void mostrarLista(stNodo * lista);
void mostrarListaRecursivo(stNodo * lista);
int contaNodos(stNodo * lista);


int main()
{
    //VARIABLES
    int i;

    //PUNTO 1 Crear una lista enlazada de números enteros positivos al azar, la inserción se realiza por el último nodo.
    stNodo * lista = inicLista();
    lista = cargarListaRand(lista);
    printf("DE IZQUIERDA A DERECHA \n");
    mostrarLista(lista);


    //PUNTO 2
    printf("\nDE DERECHA A IZQUIERDA \n");
    mostrarListaRecursivo(lista);

    //PUNTO 3
    i = contaNodos(lista);
    printf("\n\nCantidad de nodos en lista: %i\n", i);

    return 0;
}

stNodo * inicLista()
{
    return NULL;
}

stNodo * crearNodo(int num)
{
    stNodo * aux = (stNodo*)malloc(sizeof(stNodo));
    aux->num = num;
    aux->siguiente = NULL;
    return aux;
}



stNodo * cargarListaRand(stNodo * lista)
{
    stNodo * aux = lista;
    stNodo * nuevoNodo;
    int aux1, aux2, i;

    printf("CUANTOS NUMEROS DESEAN QUE SE CARGUE\n");
    scanf("%i", &aux1);

    srand(time(NULL));


    for (i=0; i<aux1; i++)
    {
        aux2 = rand() % 100;
        nuevoNodo = crearNodo(aux2);
        aux = agregarUltimo(aux, nuevoNodo);

    }

    return aux;
}

stNodo * agregarUltimo (stNodo * lista, stNodo * nuevoNodo)
{
    stNodo * aux = lista;
    stNodo * ultimo;

    if(lista != NULL)
    {
        ultimo = buscarUltimo(aux);
        ultimo->siguiente = nuevoNodo;
    }
    else
    {
        aux = nuevoNodo;
    }

    return aux;
}

stNodo * buscarUltimo(stNodo * lista)
{
    stNodo * seg = lista;
    if(seg != NULL)
        while(seg->siguiente != NULL)
        {
            seg = seg->siguiente;
        }
    return seg;
}


void mostrarLista(stNodo * lista)
{
    stNodo * aux = lista;
    while (aux !=NULL)
    {
        printf("| %i | ", aux->num);
        aux=aux->siguiente;
    }
}

void mostrarListaRecursivo(stNodo * lista)
{
    stNodo * aux = lista;

    if (aux != NULL)
    {
        mostrarListaRecursivo(aux->siguiente);
        printf("| %i | ", aux->num);

    }

}

int contaNodos(stNodo * lista)
{
    stNodo * aux = lista;
    int i=0;

    while (aux !=NULL)
    {

        i++;
        aux = aux->siguiente;

    }
    return i;
}
