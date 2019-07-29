#include "Laboratorio9.h"

int main()
{

    char *nombre_archivo;
    nombre_archivo = (char *)malloc(sizeof(char)*20);
    int tamanio_tabla,maximo,minimo,promedio;

    printf("Ingrese el nombre de archivo: ");
    scanf("%s",nombre_archivo);

    printf("\nIngrese el tamanio de la tabla hash: ");
    scanf("%d",&tamanio_tabla);

    Nodo *TablaHash[tamanio_tabla];
    creartablahash(TablaHash,nombre_archivo,tamanio_tabla);

    maximo_palabras(TablaHash,tamanio_tabla);
    minimo_palabras(TablaHash,tamanio_tabla);
    promedio_palabras(TablaHash,tamanio_tabla);
    escribir_archivo(TablaHash,tamanio_tabla);

    char *palabra;
    int continuar = 1,encriptado,h;

    while(continuar){
      palabra = (char *)malloc(sizeof(char)*20);
      printf("\nIngrese una palabra para buscar en la tabla: ");
      scanf("%s", palabra);
      encriptado = radix(palabra);
      h = string_hash(palabra,tamanio_tabla);
      //printf("encriptado: %d -- h: %d\n",encriptado,h);
      buscar_palabra(palabra,TablaHash,tamanio_tabla);

      printf("Desea continuar?\n1: Si\n0: No\n\nSeleccione opcion: ");
      scanf("%d",&continuar);
      free(palabra);
    }

    borrar_tabla_hash(TablaHash,tamanio_tabla);

    free(nombre_archivo);

    return 0;
}
