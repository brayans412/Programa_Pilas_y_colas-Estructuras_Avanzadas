#include <iostream>
#include <conio.h>
#include <locale.h>
using namespace std;

// Colas
struct nodo
{
    int nro;
    struct nodo *sgte;
};

struct cola
{
    nodo *delante;
    nodo *atras;
};

struct cola q;

void encolar(int valor)
{
    struct nodo *aux = new (struct nodo);

    aux->nro = valor;
    aux->sgte = NULL;

    if (q.delante == NULL)
        q.delante = aux;
    else
        (q.atras)->sgte = aux;

    q.atras = aux;
}

int desencolar()
{
    int num;
    struct nodo *aux;

    aux = q.delante;
    num = aux->nro;
    q.delante = (q.delante)->sgte;
    delete (aux);

    return num;
}

void muestraCola()
{
    struct nodo *aux;

    aux = q.delante;

    while (aux != NULL)
    {
        cout << "   " << aux->nro;
        aux = aux->sgte;
    }
}

void vaciaCola()
{
    struct nodo *aux;

    while (q.delante != NULL)
    {
        aux = q.delante;
        q.delante = aux->sgte;
        delete (aux);
    }
    q.delante = NULL;
    q.atras = NULL;
}

void mostrarPrimerElemento()
{
    if (q.delante == NULL)
    {
        cout << "\nLa cola esta vacia." << endl;
    }
    else
    {
        cout << "\nEl primer elemento de la cola es el: " << q.delante->nro << endl;
    }
}

void mostrarUltimoElemento()
{
    if (q.delante == NULL)
    {
        cout << "\nLa cola esta vacia." << endl;
    }
    else
    {
        cout << "\nEl ultimo elemento de la cola es el: " << q.atras->nro << endl;
    }
}

int tamanoCola()
{
    int contador = 0;
    struct nodo *aux = q.delante;

    while (aux != NULL)
    {
        contador++;
        aux = aux->sgte;
    }

    return contador;
}

// Pilas
struct pilas
{
    int d;
    pilas *a;
} * c, *e;

void ingresar(void)
{

    if (!c)
    {
        c = new (pilas);
        cout << "\nIngrese elemento: ";
        cin >> c->d;

        c->a = NULL;
        return;
    }

    e = new (pilas);
    cout << "\nIngrese elemento: ";
    cin >> e->d;
    e->a = c;
    c = e;
}

void ultimo(void)
{
    if (c == NULL)
    {
        cout << "\nLa pila esta vacia";
    }
    else
    {
        e = c;
        while (e != NULL)
        {
            if (e->a == NULL)
            {
                cout << "El ultimo dato que sale es el: " << e->d << ", que a su vez fue el primero en ingresar a la pila!";
            }
            e = e->a;
            cout << endl;
        }
    }
}

void sacar(void)
{
    if (!c)
    {
        cout << "\n\nNo hay elementos!!";
        return;
    }

    e = new (pilas);
    e = c;
    cout << "\n\nElemento eliminado: " << e->d;
    c = e->a;
    delete (e);
    cout << endl;
}

void actualizar_pila(void)
{
    int y = 2, i, ca = 0;
    e = c;
    while (e)
    {
        ca++;
        e = e->a;
    }

    for (i = 0; i <= ca; i++)
    {
        cout << " ";
    }

    i = 0;
    e = c;
    while (e)
    {
        cout << "\n";
        cout << ++i << " - " << e->d;
        e = e->a;
    }
}

bool verifica(void)
{
    if (c == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int contarElementos(void)
{
    int contar = 0;
    pilas *temp = c;
    while (temp != NULL)
    {
        contar++;
        temp = temp->a;
    }
    return contar;
}

void vaciar(void)
{
    while (c != NULL)
    {
        pilas *temp = c;
        c = c->a;
        delete temp;
    }
    cout << endl;
    cout << "\nLa pila a sido borrada!!!";
}

void menuPilas(void)
{
    int opc;
    do
    {
    	system("color 02");
        system("cls");
        cout << "\n\tMENU DE PILAS\n\n";
        cout << ">----------------------------------------------<" << endl;
        cout << " 1. Ingresar datos a la pila" << endl;
        cout << " 2. Extraer datos de la pila" << endl;
        cout << " 3. Mostrar el ultimo dato que sale de la pila" << endl;
        cout << " 4. Verificar si la pila esta vacia" << endl;
        cout << " 5. Contar los datos de la pila" << endl;
        cout << " 6. Vaciar la pila" << endl;
        cout << " 0. Volver al menu principal" << endl;
        cout << ">----------------------------------------------<" << endl;
        cout << "\n\n INGRESE OPCION: ";
        cin >> opc;
        switch (opc)
        {
        case 1:
            ingresar();
            break;
        case 2:
            sacar();
            break;
        case 3:
            ultimo();
            break;
        case 4:
            if (verifica())
                cout << "\nLa pila esta vacia!!!\n";
            else
                cout << "\nLa pila NO esta vacia!\n";
            break;
        case 5:
            cout << "\nLa cantidad de elementos que hay en la pila es de: " << contarElementos() << endl;
            break;
        case 6:
            vaciar();
            break;
        case 0:
            break;
        default:
            cout << "\n Opcion no valida!!";
            break;
        }

        actualizar_pila();
        cout << "\n\nPresione para continuar...";
        getch();
    } while (opc != 0);
}

void menuColas()
{
    int dato;
    int op;
    int x;

    do
    {
    	system("color 09");
        system("cls");
        cout << "\n\tMENU DE COLAS\n\n";
        cout << ">----------------------------------------<" << endl;
        cout << " 1. Encolar" << endl;
        cout << " 2. Desencolar" << endl;
        cout << " 3. Mostrar la cola" << endl;
        cout << " 4. Vaciar la cola" << endl;
        cout << " 5. Mostrar el primer elemento de salida" << endl;
        cout << " 6. Mostrar el ultimo elemento de salida" << endl;
        cout << " 7. Mostrar el tamaño de la cola" << endl;
        cout << " 0. Volver al menu principal" << endl;
        cout << ">----------------------------------------<" << endl;

        cout << "\n INGRESE OPCION: ";
        cin >> op;

        switch (op)
        {
        case 1:
            cout << "\n Numero a encolar: ";
            cin >> dato;
            encolar(dato);
            cout << "\n\n\t\tNumero " << dato << " encolado...\n\n";
            break;

        case 2:
            x = desencolar();
            cout << "\n\n\t\tNumero " << x << " desencolado...\n\n";
            break;

        case 3:
            cout << "\n\n Mostrando Cola\n\n";
            if (q.delante != NULL)
                muestraCola();
            else
                cout << "\n\n\tCola vacia...!" << endl;
            break;

        case 4:
            vaciaCola();
            cout << "\n\n\t\tLa cola se a vaciado...\n\n";
            break;

        case 5:
            mostrarPrimerElemento();
            break;

        case 6:
            mostrarUltimoElemento();
            break;

        case 7:
            int tamano = tamanoCola();
            cout << "\nEl tamaño de la cola es de: " << tamano << " valor(es)!" << endl;
            break;
        }

        cout << "\n\nPresione para continuar...";
        getch();

    } while (op != 0);
}

void menu(void)
{
    int opc;
    do
    {
    	system("color 06");
        system("cls");
        cout << "\n\tMENU PRINCIPAL\n\n";
        cout << ">----------------------<" << endl;
        cout << " 1. Trabajar con pilas" << endl;
        cout << " 2. Trabajar con colas" << endl;
        cout << " 0. Salir" << endl;
        cout << ">----------------------<" << endl;
        cout << "\n\n Ingrese opcion: ";
        cin >> opc;
        switch (opc)
        {
        case 1:
            menuPilas();
            break;
        case 2:
            menuColas();
            break;
        case 0:
            break;
        default:
            cout << "\n Opcion no valida!!";
            break;
        }

        cout << "\n\nOprime una tecla para salir!!!";
        getch();
    } while (opc != 0);
}

int main()
{
	setlocale(LC_ALL, "");
    menu();
    return 0;
}

