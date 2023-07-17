 #include <stdio.h>
 
typedef char txt[45];

int leerEnteroEntre(txt cad2, int num_inicial, int num_final);
int validarRango(int n, int num_inicial, int num_final);
int leerEntero(txt cad1);

int main()
{
    
   txt cad1 = "Ingrese dimension: ";
   txt cad2 = "Ingrese el entero: ";
   int lim_inferior = 3;
   int lim_superior = 21;
   int valor;
   int contadorGrupos = 0;
   int contadorEnteros = 0;
   int grupoGanador;
   float promedio_maximo = -99.9;
   float promedio_parcial;
   int acum_valores = 0;
   int i = 0;
   int LIM = leerEnteroEntre(cad1, lim_inferior, lim_superior);
   
   do
   {
       valor = leerEntero(cad2);     
       if(valor != 0 && i != LIM - 1)
       {
            contadorEnteros++; //cuenta los elementos que se ingresan
            acum_valores += valor; //acumula en una suma los elementos
       }else
       {
           promedio_parcial = acum_valores*1.0/contadorEnteros; //calcula un promedio parcial
           printf("Cierre del grupo\nEnteros ingresados es %d\nPromedio parcial: %f\n", contadorEnteros, promedio_parcial);
           
           contadorEnteros = 0;
           contadorGrupos++;
           acum_valores = 0;
           if(promedio_maximo < promedio_parcial)
            {
                promedio_maximo = promedio_parcial;
                grupoGanador = contadorGrupos;
            }//Compara para encontrar el maximo promedio y su grupo correspondiente
       }
       i++;
   }while(i < LIM);
    printf("El promedio maximo es de %f\nGrupo: %d", promedio_maximo, grupoGanador);
    return 0;
}

int leerEntero(txt cad1)
{
    printf("%s", cad1);
    int n;
    scanf("%d", &n);
    fflush(stdin);
    while(n < 0)
    {
        printf("Error ");
        scanf("%d", &n);
        fflush(stdin);
    }
    return n;
}

int leerEnteroEntre(txt cad2, int num_inicial, int num_final)
{
    printf("%s", cad2);
    int dim;
    scanf("%d", &dim);
    fflush(stdin);
    while(!validarRango(dim, num_inicial, num_final))
    {
        printf("Error. Dimension debe ser mayor a %d y menor a %d ", num_inicial, num_final);
        scanf("%d", &dim);
        fflush(stdin);
    }
    return dim;
}

int validarRango(int n, int num_inicial, int num_final)
{
    return n >= num_inicial && n <= num_final;
}
