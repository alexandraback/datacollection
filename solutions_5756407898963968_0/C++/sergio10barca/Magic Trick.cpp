#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <set>
#include <stack>
#include <deque>
#include <queue>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <cstring>
#include <iomanip>
#include <climits>
#include <cfloat>
#include <cstdio>
#define x first
#define y second
#define IN(x, n) (0 <= (x) && (x) < n)
#define MAX 4
#define MOD 1000000007
using namespace std;

typedef long long int entero;
typedef pair<int, int> Point;

int vec8[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};// signo x+
int vec4[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};//signo +

string int_to_string(int n, int base = 10){
	string s = "";
	do{
		s += char((n%base)+'0');
		n /= base;
	}while(n > 0);
	reverse(s.begin(), s.end());
	return s;
}

int gcd(int uno, int dos)/*calculo el maximo comun divisor*/
{
	if(dos == 0)
		return uno;
	return gcd(dos, uno%dos);/*si este es uno los numeros solo tienen a 1 como maximo comun divisor*/
}

int mcm(int x, int y)/*minimo comun multiplo*/
{
   return (x/gcd(x,y))*y;/*es mejor primero dividir para no desbordar*/
}

int Orientacion(Point p, Point q, Point r){
	//devuelve negativo si la orientacion es en el sentido de las manecillas del reloj es decir negativa
    return (q.x*r.y + r.x*p.y + p.x*q.y) - (q.x*p.y + r.x*q.y + p.x*r.y);
}

int v[MAX][MAX], u[MAX][MAX];

void imprime(int m[MAX][MAX]){
	int i, j;
	for(i = 0; i < MAX; i++)
		for(j = 0; j < MAX; j++)
			printf("%d%c", m[i][j], j == 3 ? '\n': ' ');
	return;
}

void lee(int m[MAX][MAX]){
	int i, j;
	for(i = 0; i < MAX; i++){
		for(j = 0; j < MAX; j++)
			scanf("%d", &m[i][j]);
		sort(m[i], m[i]+4);
	}
	return;
}


int main(){
	int i, j, n, k, casos, index[2], valor, cont;
	scanf("%d", &casos);
	for(k = 1; k <= casos; k++){
		scanf("%d", &index[0]);
		index[0]--;
		lee(u);
		scanf("%d", &index[1]);
		index[1]--;
		lee(v);
		for(i = 0, cont = valor = 0; i < 4; i++){
			if(binary_search(v[index[1]], v[index[1]]+4, u[index[0]][i])){
				cont++;
				valor = u[index[0]][i];
			}
		}
//		printf("%d\n", cont);
		if(cont == 0){
			printf("Case #%d: Volunteer cheated!\n", k);
		}
		else if(cont == 1){
			printf("Case #%d: %d\n", k, valor);
		}
		else{
			printf("Case #%d: Bad magician!\n", k);
		}
	}
	return 0;

}
