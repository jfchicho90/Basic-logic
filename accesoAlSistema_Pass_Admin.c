#include <stdio.h>
#include <string.h>

typedef char txt[35];

int validarSistema(int passEntrada, txt adminEntrada, int pass, txt admin);
void leerCadena(txt admin_entrada, txt admin);
int leerEntero(txt msj);
int quiebre_intentos(int contador_intentos, int limite_intentos);

int main()
{   
    txt admin = "chicho";
    txt msj = "Bienvenido. Admin: ";
    txt msj2 = "Ingrese contraseña: ";
    txt admin_entrada;
    int pass = 3938;
    int contador_intentos = 1;
    int limite_intentos = 4;
    
    leerCadena(admin_entrada, admin);
    int pass_Entrada = leerEntero(msj2);
    
    while(!validarSistema(pass_Entrada, admin_entrada, pass, admin) && !quiebre_intentos(contador_intentos, limite_intentos))
    {
        contador_intentos++;
        printf("Error:\n");
        leerCadena(admin_entrada, admin);
        pass_Entrada = leerEntero(msj2);
    }
    
    if(quiebre_intentos(contador_intentos, limite_intentos) && !validarSistema(pass_Entrada, admin_entrada, pass, admin))
    {
        //si se consumen todos los intentos y aun no se introdujeron los datos correctos se niega el acceso
        printf("Denegado\n");
    }else if(quiebre_intentos(contador_intentos, limite_intentos) && validarSistema(pass_Entrada, admin_entrada, pass, admin))
    {
        //si se consumen todos los intentos pero en el ultimo funciona,  se concede el acceso
        printf("Concedido\n");
    }else if(!quiebre_intentos(contador_intentos, limite_intentos))
    {
        printf("Concedido");
    }
    return 0;
}

int leerEntero(txt msj)
{
    int n;
    printf("%s", msj);
    scanf("%d", &n);
    return n;
}

void leerCadena(txt admin_entrada, txt admin)
{
    printf("Ingrese admin: ");
    scanf("%s", admin_entrada);
    strcpy(admin_entrada, admin);
}

int validarSistema(int passEntrada, txt adminEntrada, int pass, txt admin)
{
    return passEntrada == pass && strcmp(adminEntrada, admin) == 0;
}

int quiebre_intentos(int contador_intentos, int limite_intentos)
{
    return contador_intentos == limite_intentos - 1;
}
