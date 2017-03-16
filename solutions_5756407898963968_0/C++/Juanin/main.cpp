#include <cstdio>
#include <iostream>

using namespace std;

int respuesta1;
int matrix1[4][4];

int respuesta2;
int matrix2[4][4];

int main() {
	int numero_casos;
	FILE *in;
	FILE *out;
	in = fopen("A-small-attempt0.in", "r");
	out = fopen("A-small-attempt0.out.txt", "w+");
	fscanf(in, "%d\n", &numero_casos);


	for ( int caseNum = 0; caseNum < numero_casos; caseNum++ ) {
		int resultado = 0;
		// leo los datos
		fscanf(in, "%d\n", &respuesta1);
		respuesta1--;
		for ( int y = 0; y < 4; y++ ) {
			fscanf(in, "%d %d %d %d\n", &matrix1[y][0], &matrix1[y][1], &matrix1[y][2], &matrix1[y][3] );
		}
		fscanf(in, "%d\n", &respuesta2);
		respuesta2--;
		for ( int y = 0; y < 4; y++ ) {
			fscanf(in, "%d %d %d %d\n", &matrix2[y][0], &matrix2[y][1], &matrix2[y][2], &matrix2[y][3] );
		}
		// calculo
		int posiblesSoluciones = 0;
		int numeroSolucion = 0;
		for ( int i = 0; i < 4; i++ ) {
			int numero_buscado = matrix2[respuesta2][i];
			for ( int j = 0; j < 4; j++ ) {
				if ( matrix1[respuesta1][j] == numero_buscado ) {
					posiblesSoluciones++;
					numeroSolucion = numero_buscado;
				}
			}
		}
		if ( posiblesSoluciones > 1 ) {
			resultado = -2;
		}
		else if ( posiblesSoluciones == 0 ) {
			resultado = -1;
		}
		else {
			resultado = numeroSolucion;
		}

		// imprimo el resultado
		fprintf(out, "Case #%d: ", caseNum+1 );
		if ( resultado == -1 ) {
			fprintf(out, "Volunteer cheated!");
		}
		else if ( resultado == -2 ) {
			fprintf(out, "Bad magician!");
		}
		else {
			fprintf(out, "%d", resultado);
		}
		fprintf(out, "\n");
	}

	fclose(in);
	fclose(out);

	return 0;
}

