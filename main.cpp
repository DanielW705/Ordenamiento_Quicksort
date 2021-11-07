/******Descripcion del tema*********
 * Uso del metodo quicksort o arboles binarios
**************/
/*********Librerias******/
#include <iostream>
#include <conio.h>
#include <ctime>
#include <cstdlib>
#include <cmath>
/*********Usings************/
using namespace std;
/**********Prototipos****************/
void randomNumbers();
void QuickSort(int *, int, int);
void imprimir();
int *redimencionar(int *, int);
/********Variables globales**********/
const int length = 10000;
int *numeros = new int[0];
/*************Funcion Main**********/
int main(int argc, char const *argv[])
{
    /****Variables locales****/
    randomNumbers();
    QuickSort(numeros, 0, length);
    imprimir();
    cout << "Tiempo de ejecucion: " << clock() << "ms" << endl;
    getch();
    return 0;
}
/****************Metodos o funciones************/
void randomNumbers()
{
    // Rand es un metodo de cstdlib (en c++), y stdlib.h (en c), se divide entre 100 para que de un numero entre 0 y 100, y se le suma para que de entre 1 y 100.
    // length = rand() % 1000 + 1;
    *&numeros = new int[length];
    cout << "Arreglo desordenado: ";
    for (int i = 0; i < length; i++)
    {
        *&numeros[i] = rand() % 1000;
        cout << *&numeros[i] << ",";
    }
    cout << endl;
}
int particion(int *vector, int inicio, int final)
{
    int pivote = *&vector[inicio];
    int i = inicio + 1;
    for (int j = i; j < final; j++)
    {
        if (*&vector[j] < pivote)
        {
            swap(*&vector[i], *&vector[j]);
            i++;
        }
    }
    swap(*&vector[inicio], *&vector[i - 1]);
    return i - 1;
}
void QuickSort(int *vector, int inicio, int fin)
{
    if (inicio < fin)
    {
        int pivote = particion(vector, inicio, fin);
        QuickSort(vector, inicio, pivote - 1);
        QuickSort(vector, pivote + 1, fin);
    }
    // if (tamano > 1)
    // {

    //     int puntoMedio = *&vector[0], indicePuntoMedio = 0, conMe = 0, conMa = 0;
    //     int *menor = new int[0], *mayor = new int[0];
    //     cout << "El punto medio es: " << puntoMedio << endl;
    //     for (int i = 0; i < tamano; i++)
    //     {
    //         int ramaBinaria = *&vector[i];
    //         if (puntoMedio < ramaBinaria)
    //         {
    //             // swap(vector[indicePuntoMedio], vector[i]);
    //             // indicePuntoMedio = i;
    //             // // cout << "El numero es: " << puntoMedio << " < " << ramaBinaria << endl;
    //             mayor = redimencionar(mayor, ++conMa);
    //             *&mayor[conMa - 1] = ramaBinaria;
    //             // cout << "El contador de mayores es de " << conMa << endl;
    //         }
    //         if (puntoMedio > ramaBinaria)
    //         {
    //             // swap(vector[indicePuntoMedio], vector[i]);
    //             // indicePuntoMedio = i;
    //             // cout << "El numero es: " << puntoMedio << " > " << ramaBinaria << endl;
    //             menor = redimencionar(menor, ++conMe);
    //             *&menor[conMe - 1] = ramaBinaria;
    //             // cout << "El contador de menores es de " << conMe << endl;
    //         }
    //     }
    //     cout << "Los menores son: ";
    //     for (int i = 0; i < conMe; i++)
    //     {
    //         cout << *&menor[i] << " ";
    //     }
    //     cout << endl;
    //     cout << "Los mayores son: ";
    //     for (int i = 0; i < conMa; i++)
    //     {
    //         cout << *&mayor[i] << " ";
    //     }
    //     cout << endl;
    //     QuickSort(menor, conMe);
    //     QuickSort(mayor, conMa);
    // }
}
int *redimencionar(int *arreglo, int tamano)
{
    int *newArreglo = new int[tamano];
    for (int i = 0; i < tamano; i++)
    {
        if (i >= tamano - 1)
        {
            *&newArreglo[i] = 0;
        }
        else
        {
            *&newArreglo[i] = *&arreglo[i];
        }
    }
    delete[] arreglo;
    return newArreglo;
}
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
void imprimir()
{
    cout << "Arreglo ordenado: ";
    for (int i = 0; i < length; i++)
    {
        cout << *&numeros[i] << ",";
    }
    cout << endl;
}