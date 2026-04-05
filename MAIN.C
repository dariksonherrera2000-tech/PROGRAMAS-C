#include <stdio.h>
#include <string.h>

int main()
{
    char ID[10] = "N/A";      
    char nombre[20] = "N/A";
    int stock = 0;
    float precio = 0.0;
    float gananciasTotales = 0.0; 
    
    int opc = 0, opc2 = 0;
    int len, aux, cantidad;

    do {
        printf("\n--- MENU DE GESTION ---\n");
        printf("1. Registrar producto\n");
        printf("2. Vender producto\n");
        printf("3. Reabastecer producto\n");
        printf("4. Informacion producto\n");
        printf("5. Ganancias totales\n");
        printf("6. Salir\n");
        
        do {
            printf(">> ");
            aux = scanf("%d", &opc);
            if (aux != 1 || opc < 1 || opc > 6) {
                printf("Ingrese una opcion valida (1-6)\n");
                while(getchar() != '\n');
            }
        } while (aux != 1 || opc < 1 || opc > 6);

        switch (opc) {
            case 1:
                printf("Ingresar el ID del producto: ");
                scanf("%s", ID);
                printf("Ingresar el nombre del producto: ");
                getchar(); 
                fgets(nombre, 20, stdin);
                len = strlen(nombre) - 1;
                if (nombre[len] == '\n') nombre[len] = '\0'; 
                
                printf("Ingresar el stock inicial: ");
                scanf("%d", &stock);
                printf("Ingresar el precio unitario: ");
                scanf("%f", &precio);
                printf("¡Producto registrado con exito!\n");
                break;

            case 2:
                if (stock <= 0) {
                    printf("Error: No hay stock disponible para vender.\n");
                } else {
                    printf("Cantidad a vender: ");
                    scanf("%d", &cantidad);
                    if (cantidad <= stock && cantidad > 0) {
                        stock -= cantidad; 
                        gananciasTotales += (cantidad * precio); 
                        printf("Venta realizada. Total: $%.2f\n", cantidad * precio);
                    } else {
                        printf("Error: Stock insuficiente o cantidad no valida.\n");
                    }
                }
                break;

            case 3:
                printf("Cantidad de unidades a añadir al stock: ");
                scanf("%d", &cantidad);
                if (cantidad > 0) {
                    stock += cantidad;
                    printf("Stock actualizado. Nuevo stock: %d\n", stock);
                } else {
                    printf("Cantidad no valida.\n");
                }
                break;

            case 4:
                printf("\nINFORMACION DEL PRODUCTO\n");
                printf("ID: %s\n", ID);
                printf("Nombre: %s\n", nombre);
                printf("Stock actual: %d\n", stock);
                printf("Precio unitario: $%.2f\n", precio);
                break;

            case 5:
                printf("\nGanancias totales acumuladas: $%.2f\n", gananciasTotales);
                break;
                
            case 6:
                printf("Saliendo del programa...\n");
                return 0;
        }
        printf("\n¿Desea realizar otra operacion? (1.Si / 2.No): ");
        scanf("%d", &opc2);

    } while (opc2 == 1);

    printf("Gracias por usar el sistema.\n");
    return 0;
}