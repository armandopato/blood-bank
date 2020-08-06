void mostrarTodo(void);

// Muestra la lista especificada.
// Imprime espacios para alinear el texto.
void mostrar(Persona *lista)
{
    int i;
    if (lista == NULL)
    {
        printf("\nNo hay registros.\n\n\n");
        return;
    }
    Persona *trav = lista;
    printf("\n\nNOMBRE");
    for (i = 0; i < 43 - strlen("NOMBRE"); i++)
    {
        printf(" ");
    }
    printf("GRUPO SANGUINEO   ");
    printf("FACTOR     ");
    printf("DIRECCION");
    for (i = 0; i < 85 - strlen("DIRECCION"); i++)
    {
        printf(" ");
    }
    printf("TELEFONO\n\n");


    while(true)
    {
        printf("%s", trav->nombre);
        for (i = 0; i < (43-strlen(trav->nombre)); i++)
        {
            printf(" ");
        }
        printf("%s", trav->grupoSanguineo);
        for (i = 0; i < 18-strlen(trav->grupoSanguineo); i++)
        {
            printf(" ");
        }
        printf("%s", trav->factor);
        printf("   ");
        printf("%s", trav->direccion);
        for (i = 0; i < (85-strlen(trav->direccion)); i++)
        {
            printf(" ");
        }
        printf("%s\n\n", trav->telefono);
        // Si ya no hay elementos, salir.
        if (trav->siguiente == NULL)
        {
            break;
        }
        // Ir al siguiente elemento.
        trav = trav->siguiente;
    }
    printf("\n");
}

// Muestra la lista completa.
void mostrarTodo(void)
{
    Persona *lista = recuperarDatos();
    mostrar(lista);
    liberarMemoria(lista);
}
