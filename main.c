#include <stdio.h>

#define MAX_EST 50
#define MAX_MAT 10

int main() {
    int estudiantes = 0, materias = 0, opc, opc2 = 0;
    int aux, aux1;
    float calificaciones[MAX_EST][MAX_MAT][3]; 
    
    float suma_notas, prom_est, prom_asig;
    float nota_max, nota_min;
    int aprobados;

    do {
    printf("\n--- INGRESO DE CALIFICACIONES ---\n");
    printf("1. Registrar calificaciones\n");
    printf("2. Reporte de Promedios por Estudiante\n");
    printf("3. Estadisticas por Asignatura (Max/Min/Aprobados)\n");
    printf("4. Salir\n");
    printf("Seleccione una opcion: ");
    scanf("%i", &opc);
 switch (opc) {
case 1:
 printf("\n--- Registro de Datos ---\n");
    do {
printf("Ingrese el numero de estudiantes: ");
aux = scanf("%i", &estudiantes);
if (aux == 0) {
printf("Error: Ingrese un numero valido\n");
while (getchar() != '\n');
}
} while (estudiantes <= 0 || aux != 1);

do {
printf("Ingrese el numero de materias: ");
aux1 = scanf("%i", &materias);
if (aux1 == 0) {
printf("Error: Ingrese un numero valido\n");
while (getchar() != '\n');
}
} while (materias <= 0 || aux1 != 1);
for (int i = 0; i < estudiantes; i++) {
 printf("\nEstudiante %d:\n", i + 1);
for (int j = 0; j < materias; j++) {
for (int k = 0; k < 3; k++) {
printf("  Asignatura %d - Nota %d: ", j + 1, k + 1);
scanf("%f", &calificaciones[i][j][k]);
}
}
}
break;

case 2:
printf("\n--PROMEDIOS POR ESTUDIANTE ---\n");
for (int i = 0; i < estudiantes; i++) {
suma_notas = 0;
int total_notas = materias * 3;
for (int j = 0; j < materias; j++) {
for (int k = 0; k < 3; k++) {
suma_notas += calificaciones[i][j][k];
}
}
prom_est = suma_notas / total_notas;
printf("Estudiante %d: Promedio General = %.2f\n", i + 1, prom_est);
}
break;

case 3:
printf("\n--- ESTADISTICAS POR ASIGNATURA ---\n");
for (int j = 0; j < materias; j++) {
float suma_asig = 0;
aprobados = 0;
nota_max = 0;
nota_min = 10;
for (int i = 0; i < estudiantes; i++) {
float prom_individual = (calificaciones[i][j][0] + calificaciones[i][j][1] + calificaciones[i][j][2]) / 3;
suma_asig += prom_individual;

if (prom_individual >= 6.0) {
     aprobados++;
    }

if (prom_individual > nota_max) nota_max = prom_individual;
if (prom_individual < nota_min) nota_min = prom_individual;
}

printf("\nAsignatura %d:\n", j + 1);
printf("  - Promedio Grupal: %.2f\n", suma_asig / estudiantes);
printf("  - Promedio mas alto: %.2f\n", nota_max);
printf("  - Promedio mas bajo: %.2f\n", nota_min);
printf("  - Estudiantes que aprobaron: %d\n", aprobados);
}
break;

            case 4:
                printf("Saliendo...\n");
                return 0;
                break; }
if (opc != 4) {
    printf("\n¿Desea realizar otra operacion? (1. Si / 2. No): ");
    scanf("%i", &opc2);
    } else {
    opc2 = 2;
    }

    } while (opc2 == 1);

    return 0;
}