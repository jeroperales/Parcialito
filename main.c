#include <stdio.h>
#include <stdlib.h>


//ESTRUCTURAS NODOS

typedef struct stNodo
{
    int num;
    struct stNodo * siguiente;

} stNodo;

typedef struct stNodoDoble
{
    int num;
    struct stNodoDoble * siguiente;
    struct stNodoDoble * anterior;
} stNodoDoble;




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
stNodo * borraNodosMayores (stNodo * lista, int limite);
/*
stNodoDoble * crearNodoDoble(int num);
stNodoDoble * agregarPrincipioDoble (stNodoDoble * lista, stNodoDoble * nuevo);
stNodoDoble * pasarEnOrden(stNodoDoble * listaDoble, stNodo * lista);
void mostrarListaDoble(stNodoDoble * lista);
*/

int main()
{
    //VARIABLES
    int validos;
    int posi;
    int limite;
    int loop = 0;
    int opc;



    //PUNTO 1 Crear una lista enlazada de numeros enteros positivos al azar, la insercion se realiza por el ultimo nodo.
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


    printf("\n\n");
    printf("================MENU================\n");
    printf(" 1- Eliminar segun POSICION\n");
    printf(" 2- Eliminar todo numero MAYOR a numero ingresado\n");
    printf(" 3- Pasar de lista SIMPLE a lista DOBLE\n");
    printf("====================================");
    fflush(stdin);
    printf("\nIngrese una opcion: \n");
    scanf("%i", &opc);

    switch(opc)
    {

    case 1:

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
        break;

    case 2:
        printf("INGRESE A PARTIR DE QUE NUMERO DESEA BORRAR\n");
        scanf("%i", &limite);
        lista = borraNodosMayores(lista, limite);
        mostrarLista(lista);
        break;

    case 3:
        /*listaDoble = pasarEnOrden(listaDoble, lista);
        mostrarListaDoble (listaDoble);*/
        break;


    }
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


stNodo * borraNodosMayores (stNodo * lista, int limite)
{
    stNodo * aux = lista;
    stNodo * ante =NULL;

    while (aux != NULL)
    {
        if (aux->num <= limite)
        {
            ante = aux;
            aux=aux->siguiente;
        }
        else
        {
            if (ante == NULL)
            {
                lista = aux->siguiente;
                free(aux);
                aux = lista;
            }
            else
            {
                ante->siguiente = aux->siguiente;
                free(aux);
                aux = ante->siguiente;
            }


        }
    }

    return lista;
}

/*
stNodoDoble* crearNodoDoble(int num)
{
    stNodoDoble* aux = (stNodoDoble*)malloc(sizeof(stNodoDoble));
    aux->num = num;
    aux->anterior = NULL;
    aux->siguiente = NULL;

    return aux;
}

stNodoDoble * agregarPrincipioDoble (stNodoDoble * lista, stNodoDoble * nuevo) {
    nuevo->siguiente = lista;
    if(lista != NULL)
       lista->anterior=nuevo;

    return nuevo;
}



stNodoDoble* pasarEnOrden(stNodoDoble * listaDoble, stNodo * lista)
{
    stNodoDoble * auxDoble = listaDoble;
    stNodoDoble * nuevoNodo;
    stNodo * aux = lista;




        if(aux->num <= auxDoble->num)
        {

            nuevoNodo = crearNodoDoble (aux->num);
            auxDoble = agregarPrincipioDoble(auxDoble, nuevoNodo);

        }
        else
        {
            printf("B");
            auxDoble->siguiente = aux;
            aux = aux->siguiente;

        }
    printf("HOLA");
        return auxDoble;


}

void mostrarListaDoble(stNodoDoble * lista)
{
    stNodoDoble * aux = lista;
    while (aux !=NULL)
    {
        printf("| %i | ", aux->num);
        aux=aux->siguiente;
    }
}
*/

