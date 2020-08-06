bool seRepite(Persona* coincidencias, Persona *elemento);
void eliminar(void);

// Funcion que borra todo el contenido del archivo.
void eliminarTodo(void)
{
    FILE *ptr = fopen("bancoDeSangre.csv", "w+");
    fclose(ptr);
    printf("\nSe eliminaron todos los registros.\n\n");
}

// Función que elimina los elementos especificados por el usuario,
// en caso de existir.
void eliminar(void)
{
    // Lista de coincidencias.
    Persona *coincidencias = busqueda();
    // Si no hay, salir.
    if (coincidencias == NULL)
    {
        return;
    }
    Persona *listaOriginal = recuperarDatos();
    Persona *trav = listaOriginal;

    printf("\n\nLista original:");
    mostrar(listaOriginal);

    FILE *ptr = fopen("bancoDeSangre.csv", "w+");

    while (true)
    {
        // Si el elemento de la listaOriginal no es el especificado por
        // el usuario, escribirlo en el documento.
        if(!seRepite(coincidencias, trav))
        {
            fputs(trav->nombre, ptr);
            fputc(',', ptr);
            fputs(trav->grupoSanguineo, ptr);
            fputc(',', ptr);
            fputs(trav->factor, ptr);
            fputc(',', ptr);
            fputs(trav->direccion, ptr);
            fputc(',', ptr);
            fputs(trav->telefono, ptr);
            fputc('\n', ptr);
        }

        if (trav->siguiente == NULL)
        {
            break;
        }
        trav = trav->siguiente;
    }
    fclose(ptr);

    printf("\n\nLista nueva:");
    Persona *listaNueva = recuperarDatos();
    mostrar(listaNueva);
    liberarMemoria(listaOriginal);
    liberarMemoria(coincidencias);
    liberarMemoria(listaNueva);
}

// Función auxiliar que devuelve el valor true si el elemento
// deseado se encuentra en la lista. Si no se encuentra
// devuelve el valor false.
bool seRepite(Persona* coincidencias, Persona *elemento)
{
    Persona *trav = coincidencias;
    while(trav != NULL)
    {
        if (strcmp(trav->nombre, elemento->nombre) == 0)
        {
            return true;
        }
        trav = trav->siguiente;
    }
    return false;
}
