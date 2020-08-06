// Definicion de estructura Persona
// Nótese que contiene el atributo siguiente, el cual es un pointer
// a la siguiente estructura Persona, para así poder crear una lista ligada.
struct persona
{
    char nombre[100];
    char grupoSanguineo[3];
    char factor[20];
    char direccion[255];
    char telefono[20];
    struct persona *siguiente;
};
typedef struct persona Persona;

// Declaracion de funciones.
Persona leerPersona(char *linea);
Persona *nuevaPersona(char *linea1);
void liberarMemoria(Persona *lista);

// Esta funcion se encarga de recuperar los datos ya existentes en el documento.
// Crea una lista ligada de estructuras Persona.
// Devuelve el pointer a la primera estructura de la lista ligada.
// En caso de no haber datos, retorna el valor NULL.
Persona *recuperarDatos(void)
{
    FILE *ptr = fopen("bancoDeSangre.csv", "r");
    char linea[1000];

    // Leer primera linea, en caso de que el documento esté vacío,
    // devuelve el valor NULL, de lo contrario guarda la estructura
    // de la línea leída.
    int x = fgets(linea, 1000, ptr);

    if (x == 0  || ferror( ptr ) || feof( ptr))
    {
        return NULL;
    }
    // Guardar pointer al primer elemento de la lista.
    Persona *primero = nuevaPersona(linea);
    // Hacer una copia del pointer anterior, para no perder
    // el inicio de la lista.
    Persona *trav = primero;

    // Leer las siguientes lineas y guardarlas.
    while(true)
    {
        x = fgets(linea, 1000, ptr);
        // En caso de que lleguemos al fin del documento, salir del loop.
        if (x == 0  || ferror( ptr ) || feof( ptr))
        {
            // Asegurarnos de que el valor SIGUIENTE de la estructura actual
            // es igual a NULL, es decir, es el final de la lista.
            trav->siguiente = NULL;
            break;
        }
        // Asignar el valor SIGUIENTE de la Persona actual a una nuevaPersona.
        trav->siguiente = nuevaPersona(linea);
        // Moverse a la Persona creada.
        trav = trav->siguiente;
    }
    fclose(ptr);
    return primero;
}


// Esta función se encarga de leer una linea con los datos de una Persona
// y guardarlos en una estructura Persona
// Devuelve una estructura Persona con los datos correspondientes.
Persona leerPersona(char *linea1)
{
    // Copia de la linea
    char *linea = linea1;
    Persona elemento;
    // Separador
    const char s[2] = ",";
    // Elementos
    char *tokens[5];
    int i;
    // Encontrar primer elemento.
    tokens[0] = strtok(linea, s);

    // Encontrar elementos restantes.
    for (i = 1; i < 5; i++)
    {
        tokens[i] = strtok(NULL, s);
    }
    // Asegurarnos de que el ultimo caracter del ultimo elemento
    // no sea una secuencia de escape \n
    tokens[4][10] = '\0';
    // Guardar los datos obtenidos en la Persona
    strcpy(elemento.nombre, tokens[0]);
    strcpy(elemento.grupoSanguineo, tokens[1]);
    strcpy(elemento.factor, tokens[2]);
    strcpy(elemento.direccion, tokens[3]);
    strcpy(elemento.telefono, tokens[4]);
    elemento.siguiente = NULL;
    return elemento;
}

// Esta funcion crea una estructura Persona, utilizando malloc para
// guardarla dinámicamente en la memoria.
// Devuelve el puntero a la estructura Persona.
Persona *nuevaPersona(char *linea1)
{
    Persona per = leerPersona(linea1);
    Persona *ptr = malloc(sizeof(Persona));
    *ptr = per;
    return ptr;
}

// Esta funcion se encarga de liberar la memoria utilizada
// por la lista ligada, ya que alojamos dinámicamente
// las estructuras.
void liberarMemoria(Persona *lista)
{
    Persona *tmp;
    while (lista != NULL)
    {
       tmp = lista;
       lista = lista->siguiente;
       free(tmp);
    }
}
