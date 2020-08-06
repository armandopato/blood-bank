// Pide los datos que se muestran a continuación al usuario, y los añade al final del archivo.
// Datos a guardar:
// - Nombre
// - Grupo Sanguineo
// - Factor
// - Direccion
// - Telefono

// Declaracion de funciones.
void nombre(Persona *x);
void gruposanguineo(Persona *x);
void factor(Persona *x);
void direccion(Persona *x);
void telefono(Persona *x);

// Esta funcion se encarga de registrar los datos que el usuario introduzca,
// Para así guardarlos en una estructura Persona y agregarlos al archivo .csv
void registro(void)
{
    Persona x;
    nombre(&x);
    system("cls");
    gruposanguineo(&x);
    system("cls");
    factor(&x);
    system("cls");
    direccion(&x);
    system("cls");
    telefono(&x);
    system("cls");
    FILE *ptr = fopen("bancoDeSangre.csv", "a");
    fputs(x.nombre, ptr);
    fputc(',', ptr);
    fputs(x.grupoSanguineo, ptr);
    fputc(',', ptr);
    fputs(x.factor, ptr);
    fputc(',', ptr);
    fputs(x.direccion, ptr);
    fputc(',', ptr);
    fputs(x.telefono, ptr);
    fputc('\n', ptr);
    fclose(ptr);
    printf("\nRegistrado con exito\n\n\n");
}

// Esta función guarda el nombre en la estructura Persona.
void nombre(Persona *x)
{
    printf("Nombre: ");
    char tmp[100];
    fflush(stdin);
    gets(tmp);
    printf("\n");
    if (strlen(tmp) < 43)
    {
        strcpy(x->nombre, tmp);
        return;
    }
    system("cls");
    printf("Por favor, digite un maximo de 44 caracteres.\n\n");
    nombre(x);
}


// Esta función guarda el grupo sanguineo en la estructura Persona.
void gruposanguineo(Persona *x)
{
    printf("Seleccione un grupo sanguineo:\n1. O\n2. A\n3. B\n4. AB\n");
    int tmp;
    scanf("%i", &tmp);
    printf("\n");
    switch (tmp)
    {
    case 1:
        strcpy(x->grupoSanguineo, "O");
        break;
    case 2:
        strcpy(x->grupoSanguineo, "A");
        break;
    case 3:
        strcpy(x->grupoSanguineo, "B");
        break;
    case 4:
        strcpy(x->grupoSanguineo, "AB");
        break;
    default:
        system("cls");
        printf("\nDigite un numero valido\n\n");
        gruposanguineo(x);
    }
}

// Esta función guarda el factor en la estructura Persona.
void factor(Persona *x)
{
    printf("Seleccione el factor:\n1. Positivo\n2. Negativo\n");
    int tmp;
    scanf("%i", &tmp);
    printf("\n");
    switch (tmp)
    {
    case 1:
        strcpy(x->factor, "Positivo");
        break;
    case 2:
        strcpy(x->factor, "Negativo");
        break;
    default:
        system("cls");
        printf("\nDigite un numero valido\n\n");
        factor(x);
    }
}

// Esta función guarda la direccion en la estructura Persona.
void direccion(Persona *x)
{
    printf("Direccion: ");
    char tmp[255];
    fflush(stdin);
    gets(tmp);
    printf("\n");
    if (strlen(tmp) < 85)
    {
        strcpy(x->direccion, tmp);
        return;
    }
    system("cls");
    printf("Por favor, digite un maximo de 84 caracteres.\n\n");
    direccion(x);
}

// Esta función guarda el telefono en la estructura Persona.
void telefono(Persona *x)
{
    printf("Telefono a 10 digitos: ");
    char tmp[100];
    fflush(stdin);
    scanf("%s", tmp);
    printf("\n");
    if (strlen(tmp) == 10)
    {
        strcpy(x->telefono, tmp);
        return;
    }
    system("cls");
    printf("Por favor, digite un numero valido.\n\n");
    telefono(x);
}
