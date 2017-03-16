#include <stdio.h>
#include <stdlib.h>
#include <string>

using namespace std;

struct TBloque {
    char c;
    int contador;
};

TBloque Bloque[100][100];
int numbloques[100];

int main(int argc, char* argv[])
{
	int T;
	#define NOMBRE_ARCHIVO "A-small-attempt0"
	string nombre = NOMBRE_ARCHIVO;
	nombre = nombre + ".in";
	FILE *entrada = fopen(nombre.c_str(), "rt");
	nombre = NOMBRE_ARCHIVO;
	nombre = nombre + ".out";
	FILE *salida = fopen(nombre.c_str(), "wt");
	fscanf(entrada,"%d", &T);
	for (int t=1;t<=T;t++) {
	    int N;
	    fscanf(entrada, "%d\n", &N);
        printf( "%d\n", N);
        char aux[1000];
        int total = 0;
        for (int i = 0; i < N; i++) {
            fscanf(entrada, "%s", aux);
            printf("%s\n", aux);
            numbloques[i]=1;
            Bloque[i][0].c = aux[0];
            Bloque[i][0].contador = 1;
            int p=1;
            while (aux[p]!=0) {
                if (aux[p]==aux[p-1]) {
                    Bloque[i][numbloques[i]-1].contador++;
                } else {
                    Bloque[i][numbloques[i]].contador=1;
                    Bloque[i][numbloques[i]].c = aux[p];
                    numbloques[i]++;
                }
                p++;
            }
            if (i>0) {
                if (numbloques[i]!=numbloques[i-1]) {
                    total=-1;
                }
            }
        }
        for (int i=0; (i<numbloques[0]) && (total>=0); i++) {
            int minb = Bloque[0][i].contador;
            int maxb = minb;
            for (int n=0;n<N;n++) {
                if (Bloque[n][i].c!=Bloque[0][i].c) {
                    total =-1;
                    break;
                }
                if (minb>Bloque[n][i].contador) {
                    minb=Bloque[n][i].contador;
                }
                if (maxb<Bloque[n][i].contador) {
                    maxb = Bloque[n][i].contador;
                }
            }
            if (total<0) {
                break;
            }
            int mejor = N*1000;
            for (int k=minb;k<=maxb;k++) {
                int actual=0;
                for (int n=0;n<N;n++) {
                    actual+=abs(k-Bloque[n][i].contador);
                }
                if (actual<mejor) {
                    mejor=actual;
                }
            }
            total+=mejor;
        }
        if (total<0) {
            fprintf(salida, "Case #%d: Fegla Won\n",t);
            printf("Case #%d: Fegla Won\n",t);
        } else {
            fprintf(salida, "Case #%d: %d\n",t, total);
            printf("Case #%d: %d\n",t, total);
        }
        fflush(salida);
		fflush(stdout);
	}
	fclose(salida);
	fclose(entrada);
	return 0;
}

