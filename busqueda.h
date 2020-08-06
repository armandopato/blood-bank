// Declaracion de funciones
char* pedirGrupo(void);
char* pedirFactor(void);
Persona *buscarTipo(char* grupoSanguineo, char* factor);
Persona *buscarNombre(char *nombre);
Persona *copiaPersona(Persona *trav1);



// Esta funcion permite elegir al usuario entre dos formas de busqueda:
// por nombre o por tipo de sangre.
// Se asegura de que los datos ingresados por el usuario sean correctos
// para continuar.
// Devuelve el puntero al primer elemento de la lista con las coincidencias
// Imprime la lista anterior.
// En caso de que no haya coincidencias, devuelve el valor NULL.

Persona *busqueda(void)
{
    Persona *coincidencias;
    int a;
    printf("\n\nEspecifique el parametro:\n1. Por nombre\n2. Por tipo de sangre\n");
    scanf("%i", &a);
    system("cls");
    if (a == 1)
    {
        while (true)
        {
            char nombre[255];
            printf("Por favor, digite el nombre de la persona: ");
            fflush(stdin);
            gets(nombre);
            system("cls");
            if (strlen(nombre) < 43)
            {
                coincidencias = buscarNombre(nombre);
                printf("\n\nCoincidencias:");
                mostrar(coincidencias);
                break;
            }
            printf("Digite un numero de caracteres menor a 43\n\n");
        }
    }
    else if (a == 2)
    {
        char *grupoSanguineo = pedirGrupo();
        system("cls");
        char *factor = pedirFactor();
        system("cls");
        coincidencias = buscarTipo(grupoSanguineo, factor);
        printf("\n\nCoincidencias:");
        mostrar(coincidencias);
    }
    else
    {
        system("cls");
        printf("\nDigite un numero valido.\n");
        return busqueda();
    }
    return coincidencias;

}


// Funcion auxiliar para que el usuario introduzca el grupo sanguineo a buscar.
char* pedirGrupo(void)
{
    printf("Seleccione un grupo sanguineo:\n1. O\n2. A\n3. B\n4. AB\n");
    int tmp;
    scanf("%i", &tmp);
    switch (tmp)
    {
    case 1:
        return "O";
    case 2:
        return "A";
    case 3:
        return "B";
    case 4:
        return "AB";
    default:
        system("cls");
        printf("Digite un numero valido\n");
        pedirGrupo();
    }
}

// Funcion auxiliar para que el usuario introduzca el factor a buscar.
char* pedirFactor(void)
{
    printf("Seleccione el factor:\n1. Positivo\n2. Negativo\n");
    int tmp;
    scanf("%i", &tmp);
    switch (tmp)
    {
    case 1:
        return "Positivo";
    case 2:
        return "Negativo";
    default:
        system("cls");
        printf("Digite un numero valido\n");
        pedirFactor();
    }
}

// Esta funcion devuelve el puntero al primer elemento de una lista ligada con
// los elementos que tengan el nomnbre especificado.
// En caso de no haber coincidencias, retorna NULL.
Persona *buscarNombre(char *nombre)
{
    Persona *listaOriginal = recuperarDatos();
    // Si no hay datos, devolver NULL.
    if (listaOriginal == NULL)
    {
        return NULL;
    }
    // Crear lista nueva y punteros auxiliares.
    Persona *listaNueva = NULL;
    Persona *trav1 = listaOriginal;
    Persona *trav2 = NULL;

    while(true)
    {
        // Buscar la primer coincidencia.
        if (strcmp(trav1->nombre, nombre) == 0 && listaNueva == NULL)
        {
            // Inicializar la lista nueva.
            listaNueva = copiaPersona(trav1);
            // Puntero auxiliar.
            trav2 = listaNueva;
        }
        // Buscar coincidencias restantes.
        else if (strcmp(trav1->nombre, nombre) == 0)
        {
            // Añadir el elemento coincidente a la lista nueva.
            trav2->siguiente = copiaPersona(trav1);
            // Ir al elemento agregado, es decir, el ultimo.
            trav2 = trav2->siguiente;
        }

        // Si ya no hay mas elementos en la lista, salir del loop.
        if (trav1->siguiente == NULL)
        {
            break;
        }
        // Ir al siguiente elemento de la lista.
        trav1 = trav1->siguiente;
    }

    return listaNueva;
}



// Esta funcion devuelve el puntero al primer elemento de una lista ligada con
// los elementos que tengan el grupo sanguineo y factor especificados.
// En caso de no haber coincidencias, retorna NULL.
Persona *buscarTipo(char* grupoSanguineo, char* factor)
{
    Persona *listaOriginal = recuperarDatos();
    // Si no hay datos, devolver NULL.
    if (listaOriginal == NULL)
    {
        return NULL;
    }
    // Crear lista nueva y punteros auxiliares.
    Persona *listaNueva = NULL;
    Persona *trav1 = listaOriginal;
    Persona *trav2 = NULL;

    while(true)
    {
        // Buscar la primer coincidencia.
        if (strcmp(trav1->grupoSanguineo, grupoSanguineo) == 0 && strcmp(trav1->factor, factor) == 0 && listaNueva == NULL)
        {
            // Inicializar la lista nueva.
            listaNueva = copiaPersona(trav1);
            // Puntero auxiliar.
            trav2 = listaNueva;
        }
        // Buscar coincidencias restantes.
        else if (strcmp(trav1->grupoSanguineo, grupoSanguineo) == 0 && strcmp(trav1->factor, factor) == 0)
        {
            // Añadir el elemento coincidente a la lista nueva.
            trav2->siguiente = copiaPersona(trav1);
            // Ir al elemento agregado, es decir, el ultimo.
            trav2 = trav2->siguiente;
        }

        // Si ya no hay mas elementos en la lista, salir del loop.
        if (trav1->siguiente == NULL)
        {
            break;
        }
        // Ir al siguiente elemento de la lista.
        trav1 = trav1->siguiente;
    }
    return listaNueva;
}


// Esta funcion crea una copia de una Persona, para así poder
// agregarla a la lista nueva.
Persona *copiaPersona(Persona *trav1)
{
    Persona *copia = malloc(sizeof(Persona));
    *copia = *trav1;
    copia->siguiente = NULL;
    return copia;
}
