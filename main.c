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
stNodo * borrarNodoPosi(stNodo * lista, int posi);

int main()
{
    //VARIABLES
    int validos;
    int posi;
    int loop = 0;

    //PUNTO 1 Crear una lista enlazada de n�meros enteros positivos al azar, la inserci�n se realiza por el �ltimo nodo.
    stNodo * lista = inicLista();
    lista = cargarListaRand(lista);
    printf("DE IZQUIERDA A DERECHA \n");
    mostrarLista(lista);


    //PUNTO 2
    printf("\nDE DERECHA A IZQUIERDA \n");
    mostrarListaRecursivo(lista);

    //PUNTO 3
    validos = contaNodos(lista);
    printf("\n\nCANTIDAD DE NODOS GENERADOS: %i\n", validos);

    //PUNTO 4
    while (loop == 0)
    {
        printf("\nINGRESE LA POSICION A ELIMINAR\n");
        scanf("%i", &posi);

        if (posi <= validos && posi != 0)
        {
            lista = borrarNodoPosi(lista, posi);
            loop = 1;
        }
        else
        {
            printf("\n\nPOSICION INVALIDA, INGRESE NUEVAMENTE \n\n");

        }
    }
    printf("LISTA CON DICHO NODO ELIMINADO\n");
    mostrarLista(lista);

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

    /*printf("CUANTOS NUMEROS DESEAN QUE SE CARGUE\n");
    scanf("%i", &aux1);*/

    srand(time(NULL));

    aux1 = (rand() % 10)+1;


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


stNodo * borrarNodoPosi(stNodo * lista, int posi)
{
    stNodo * aux;
    stNodo * ante;
    int i = 1;

    if (lista != NULL &&i == posi)
    {
        aux = lista;
        lista = lista->siguiente;
        free(aux);
    }
    else
    {
        aux = lista;
        while ((aux != NULL) && (i != posi))
        {
            ante = aux;
            aux = aux->siguiente;
            i++;
        }

        if (i == posi)
        {
            ante->siguiente = aux->siguiente;
            free(aux);
        }

    }

    return lista;
}
