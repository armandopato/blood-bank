// Driver
// Sistema de registro del banco de sangre.
// Este documento contiene a la funcion main, en él se incluyen
// los  5 módulos necesarios para la ejecucion del programa, los cuales se muestran a cotinuacion.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "recuperarDatos.h"
#include "mostrar.h"
#include "registro.h"
#include "busqueda.h"
#include "eliminar.h"



int main(void)
{
    // Abre archivo para comprobar que existe, en caso contrario se crea auntomaticamente.
    FILE *tabla = fopen("bancoDeSangre.csv", "a");
    fclose(tabla);

    // Menu
    printf("\nSISTEMA DE REGISTRO DEL BANCO DE SANGRE\n\nPor favor, elija una opcion.\n\n");
    printf("1. Registrar un nuevo elemento.\n2. Realizar una busqueda.\n3. Eliminar registros por busqueda.\n4. Mostrar todos los registros.\n5. Eliminar todos los registros.\n6. Salir\n");
    int a;
    scanf("%i", &a);
    Persona *x;
    switch(a)
    {
    case 1:
        system("cls");
        registro();
        break;
    case 2:
        system("cls");
        x = busqueda();
        liberarMemoria(x);
        break;
    case 3:
        system("cls");
        eliminar();
        break;
    case 4:
        system("cls");
        mostrarTodo();
        break;
    case 5:
        system("cls");
        eliminarTodo();
        break;
    case 6:
        return 0;
    default:
        system("cls");
        printf("\nDigite una opcion valida.\n\n");
    }
    main();
}
