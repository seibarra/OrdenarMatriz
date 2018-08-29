#pragma warning(disable: 4996)
#include <stdlib.h>
#include <stdio.h>

#define SIZE 3

void IntercambiarValor(int matriz[][SIZE], int numeroAMover);
void OrdenarMatriz(int matriz[][SIZE]);

int main(void) {

	int matriz[SIZE][SIZE];
	int fila;
	int columna;
	int ordenado = 0;

	int numeroAIntercambiar1;
	int numeroAIntercambiar2;
	int numeroExistente = 0;
	
	for (fila = 0; fila < SIZE; fila++)
	{
		for (columna = 0; columna < SIZE; columna++)
		{
			printf("imprima el elemento %d de la fila %d\t", columna, fila);
			scanf("%d", &matriz[fila][columna]);
		}
	}

	OrdenarMatriz(matriz);

	printf("\n\n");

	for (fila = 0; fila < SIZE; fila++)
	{
		for (columna = 0; columna < SIZE; columna++)
		{
			printf("%d\t", matriz[fila][columna]);
		}
		printf("\n");
	}

	while (1) {
		for (int i = 1; i < 3; i++) {
			printf("imprima el numero %d que quiera intercambiar de posicion.\n imprima un numero inexistente para salir del programa.\n\n", i);
			if (i == 1)
				scanf("%d", &numeroAIntercambiar1);
			else
				scanf("%d", &numeroAIntercambiar2);
		}

		IntercambiarValor(matriz, numeroAIntercambiar1, numeroAIntercambiar2);

		printf("\n\n");

		for (fila = 0; fila < SIZE; fila++)
		{
			for (columna = 0; columna < SIZE; columna++)
			{
				printf("%d\t", matriz[fila][columna]);
			}
			printf("\n");
		}
	}

	


	system("pause");
	return 0;
}

void IntercambiarValor(int matriz[][SIZE], int numeroAIntercambiar1, int numeroAIntercambiar2) {
	int fila, columna;
	int aux = 0, auxFijado = 0;
	for (fila = 0; fila < SIZE; fila++) {
		for (columna = 0; columna < SIZE; columna++) {
			if (matriz[fila][columna] == numeroAIntercambiar1) {
				matriz[fila][columna] = numeroAIntercambiar2;
			}
			else if (matriz[fila][columna] == numeroAIntercambiar2) {
				matriz[fila][columna] = numeroAIntercambiar1;
			}
		}
	}
	


}

void OrdenarMatriz(int matriz[][SIZE]) {
	int fila;
	int columna;
	int ordenado = 0;

	while (ordenado == 0) {
		int auxordenado = 0;
		for (fila = 0; fila < SIZE; fila++)
		{
			for (columna = 0; columna < SIZE; columna++)
			{
				if (columna != SIZE - 1 || fila != SIZE - 1) {
					if (columna == SIZE - 1) {
						if (matriz[fila][columna] > matriz[fila + 1][0]) {
							int aux = matriz[fila][columna];
							matriz[fila][columna] = matriz[fila + 1][0];
							matriz[fila + 1][0] = aux;
							auxordenado = 0;
						}
						else auxordenado++;
					}
					else if (matriz[fila][columna] > matriz[fila][columna + 1]) {
						int aux = matriz[fila][columna];
						matriz[fila][columna] = matriz[fila][columna + 1];
						matriz[fila][columna + 1] = aux;
						auxordenado = 0;
					}
					else {
						auxordenado++;
					}
				}
			}
		}
		if (auxordenado >= SIZE * SIZE - 1)
			ordenado = 1;
	}
}
