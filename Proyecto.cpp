#include <stdio.h>
#include <stdbool.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 50

struct Paciente { 
	char nombre[50];
};
struct Cola {
    struct Paciente pacientes[MAX_SIZE];
    int frente;
    int final;
    int contador;
};

void inicializarCola(struct Cola *cola) {
    cola->frente = -1;
    cola->final = -1;
    cola->contador = 0;
}

bool estaVaciaCola(struct Cola *cola) {
    return cola->contador == 0 || cola->frente == -1;
}


bool estaLlena(struct Cola *cola) {
    return cola->contador == MAX_SIZE;
}

void meterCola(struct Cola *cola, struct Paciente paciente) {
    if (estaLlena(cola)) {
        printf("No hay cupo. No se puede agregar mas pacientes.\n");
        return;
    }

    if (estaVaciaCola(cola)) {
        cola->frente = 0;
    }
    cola->pacientes[++cola->final] = paciente;
    cola->contador++;
    printf("Paciente %s encolado. Posicion: %d.\n", paciente.nombre, cola->final + 1);
    printf("Tiempo de espera estimado: %d hora/s\n", cola->contador);
}

struct Paciente sacarCola(struct Cola *cola) {
	struct Paciente paciente;
    if (estaVaciaCola(cola)) {
        printf("Fin de atencion. La cola esta vacia.\n");
        strcpy(paciente.nombre, "");
        return paciente;
    }

    paciente = cola->pacientes[cola->frente];
    cola->frente++;
    cola->contador--;

    if (cola->frente > cola->final) {

        cola->frente = -1;
        cola->final = -1;
    }

    return paciente;
}


void mostrarPosicionFrenteFinal(struct Cola *cola) {
    printf("Posicion del frente: %d\n", cola->frente + 1);
    printf("Posicion del final: %d\n", cola->final + 1);
}

void atenderPacientes(struct Cola *cola, int maxPacientes) {
	if (estaVaciaCola(cola)) {
		printf("No hay pacientes que atender. Ingrese pacientes.\n");
	}
    printf("Inicio de atencion a pacientes!\n");
    printf("Maximo numero de pacientes: %d\n", maxPacientes);
    printf("=======================================\n");
    
    struct Paciente pacienteAtendido = sacarCola(cola);
    if (strcmp(pacienteAtendido.nombre, "") != 0) {
        printf("Atendiendo a %s. Ultimo paciente en espera: %s\n", pacienteAtendido.nombre, cola->pacientes[cola->final].nombre);
    }

}

struct Pila {
    int elementos[MAX_SIZE];
    int tope;
};

void inicializarPila(struct Pila *pila) {
    pila->tope = -1;
}

bool estaVaciaPila(struct Pila *pila) {
    return pila->tope == -1;
}

bool estaLlena(struct Pila *pila) {
    return pila->tope == MAX_SIZE - 1;
}

void push(struct Pila *pila, int valor) {
    if (estaLlena(pila)) {
        printf("La pila esta llena. No se puede insertar mas elementos.\n");
        return;
    }

    pila->elementos[++pila->tope] = valor;
    printf("Elemento %d insertado en la pila. Posicion del tope: %d\n", valor, pila->tope + 1);
}

int pop(struct Pila *pila) {
   	if (estaVaciaPila(pila)) {
        printf("La pila esta vacia. No se puede extraer ningun elemento.\n");
       return -1;
    }

    int valor = pila->elementos[pila->tope--];
    return valor;
}

void mostrarPila(struct Pila *pila) {
	
    if (estaVaciaPila(pila)) {
        printf("La pila esta vacia.\n");
        return;
    }

    printf("Tope: %d\n", pila->elementos[pila->tope]);
    printf("Elementos en la pila:\n");
    for (int i = pila->tope; i >= 0; i--) {
        printf("%d (Posicion: %d)\n", pila->elementos[i], i + 1);
    }
}

int realizarOperacion(struct Pila *pila, char (*operacion)[50], int *suma, int *resta, int *multiplicacion) {
    int num1 = pop(pila);
    int num2 = pop(pila);
    int resultado;
    	
    
    
    if (estaVaciaPila(pila)) {
        printf("La pila esta vacia. No se puede extraer ningun elemento.\n");
        return 0;	
    }
    
    if (num1 % 2 == 0 && num2 % 2 == 0) {
        resultado = num1 + num2;
        *suma += 1;
        strcpy(*operacion, "SUMA");
    } else if (num1 % 2 != 0 && num2 % 2 != 0) {
        resultado = num1 - num2;
        *resta += 1;
        strcpy(*operacion, "RESTA");
    } else {
        resultado = num1 * num2;
        *multiplicacion += 1;
        strcpy(*operacion, "MULTIPLICACION");
    }
	
    push(pila, resultado);
    
    if (pila->tope >= 1) {
        printf("Valor 1 = %d y Valor 2 = %d eliminados\n", num1, num2);
    }
    return resultado;
}


int main() {
    struct Cola cola;
    inicializarCola(&cola);

    struct Pila pila;
    inicializarPila(&pila);

    int opcion;
    while (true) {
    	system("cls");
        printf("\nMenu Principal:\n");
        printf("1. Pantalla de Presentacion\n");
        printf("2. Pila\n");
        printf("3. Cola\n");
        printf("4. Salir del programa\n");
        printf("Seleccione una opcion: \n\n");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                system("cls");
                printf("\t\t          UNIVERSIDAD TECNOLOGICA DE PANAMA\n");
				printf("\t\tFACULTAD DE INGENIERIA DE SISTEMAS COMPUTACIONALES\n");
				printf("\t\t   LIC. EN INGENIERIA DE SISTEMAS Y COMPUTACION\n");
				printf("\t\t\t    ESTRUCTURAS DE DATOS I\n");
				printf("\n\t\t\t\tPROYECTO N.2\n");
				printf("\t\t\t\tPILAS Y COLAS\n");
				printf("\t\t   FACILITADOR: ING. JACQUELINE S. DE CHING\n");
                printf("\t\t\t\tINTEGRANTES: \n");
                printf("\n");
                printf("\t\t\tJulio Lara\t8-997-2325\n");
                printf("\t\t\tJorge Gonzalez\t8-1002-2167\n");
                printf("\t\t\t\tGrupo : 1IL121\n\n");
                printf("\t\t\tFecha de Entrega : 17 de junio");
                printf("\n");
                getch();
                break;
            case 2: {
                system("cls");
                int suma = 0, resta = 0, multiplicacion = 0;
                char operacion[50];
                int opcionPila = 0;

                while (opcionPila != 6) {
                    printf("\n--- Menu de Opciones ---\n");
                    printf("1. Meter a la pila\n");
                    printf("2. Sacar de la pila\n");
                    printf("3. Mostrar operacion realizada y la pila\n");
                    printf("4. Cantidad de operaciones de suma, resta y multiplicacion\n");
                    printf("5. Mostrar pila final\n");
                    printf("6. Regresar al menu principal\n");
                    printf("Ingrese una opcion: \n\n");
                    scanf("%d", &opcionPila);

                    switch (opcionPila) {
                        case 1: {
                            printf("Ingrese 10 valores enteros para la pila:\n");
                            for (int i = 0; i < 10; i++) {
                                int valor;
                                scanf("%d", &valor);
                                push(&pila, valor);
                            }
                            break;
                        }
                        case 2:
                            realizarOperacion(&pila, &operacion, &suma, &resta, &multiplicacion);
                            break;
                        case 3:
                            printf("\nUltima operacion realizada:\n");
                            printf("Operacion: %s. ", operacion);
                            printf("\n");
                            printf("Pila : \n");
                            mostrarPila(&pila);
                            break;
                        case 4:
                            printf("\nTotal de operaciones realizadas:\n");
                            printf("Suma: %d\n", suma);
                            printf("Resta: %d\n", resta);
                            printf("Multiplicacion: %d\n", multiplicacion);
                            break;
                        case 5:
                            printf("\nPila final:\n");
                            mostrarPila(&pila);
                            break;
                        case 6:
                            printf("Volviendo al menu principal...\n");
                            break;
                        default:
                            printf("Opcion invalida. Por favor, ingrese una opcion valida.\n");
                            break;
                    }
                }
                break;
            }
            case 3: {
                system("cls");
                int maxPacientes;
                printf("Ingrese el maximo numero de pacientes que se pueden atender : ");
                printf("\n");
                scanf("%d", &maxPacientes);
                int opcionCola;
                bool salirCola = false;
                while (!salirCola) {

                    printf("\nMenu Cola:\n");
                    printf("1. Agregar pacientes\n");
                    printf("2. Atender Pacientes\n");
                    printf("3. Posicion del frente y final de la cola\n");
                    printf("4. Regresar al menu principal\n");
                    printf("Seleccione una opcion: \n\n");
                    scanf("%d", &opcionCola);

                    switch (opcionCola) {
                        case 1: {
                            if (cola.contador >= maxPacientes) {
                                printf("No hay cupo. No se puede agregar mas pacientes.\n");
                            } else {	
                                struct Paciente nuevoPaciente;
                            	printf("Ingrese el nombre del paciente: ");
                                scanf("%s", nuevoPaciente.nombre);
                                meterCola(&cola, nuevoPaciente);
                            }
                            break;
                        }
                        case 2: {
                            	atenderPacientes(&cola, maxPacientes);
	                            break;
                        }
                        case 3:
                            printf("Posicion del frente y final:\n");
                            mostrarPosicionFrenteFinal(&cola);
                            break;
                        case 4:
                            printf("Volviendo al menu principal...\n");
                            salirCola = true;
                            break;
                        default:
                            printf("Opcion invalida. Por favor, ingrese una opcion valida.\n");
                            break;
                    }
                }
                break;
            }
            case 4:
                printf("Saliendo del programa...\n");
                return 0;
            default:
                printf("Opcion invalida. Por favor, ingrese una opcion valida.\n");
                break;
        }
    }

    return 0;
}

