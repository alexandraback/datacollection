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
#define MAX 1010
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

string s[MAX];

bool igual(int n){
	int i;
	for(i = 1; i < n; i++)
		if(s[i] != s[0])
			return false;
	return true;
}

int solve(int n){
	int i, j, indice, cont = 0, suma = 0, cuenta, toca, aux, dp[MAX];
	for(indice = 0; indice < s[0].size() && !igual(n); ){
		char c = s[0][indice];
//		cout << "INDICE = "<<indice << " " << c << endl;
		memset(dp, 0, sizeof(dp));
		for(i = 0; i < n; i++){
			for(j = indice; j < s[i].size() && c == s[i][j]; j++, dp[i]++);
			if(j == indice)
				return INT_MAX;
//			cout << "dp["<<i << "]="<<dp[i] << endl;
		}
		for(i = 0, cuenta = INT_MAX, toca = -1; i < n; i++){
			for(j = aux = 0; j < n; j++){
				aux += dp[i]>dp[j] ? dp[i]-dp[j] : dp[j]-dp[i];
			}
			if(aux < cuenta){
				cuenta = aux;
				toca = i;
			}
		}
		string t="1";
		t[0] = c;
//		cout << "es la letra " << c <<" toca "<<toca<<" cuenta "<<cuenta<< endl;
		for(i = 0; i < n; i++){
//			cout << "turno = " << i <<" "<<dp[i]<<" "<<dp[toca]<< endl;
			while(dp[i] < dp[toca]){
				s[i] = s[i].substr(0, indice)+t+s[i].substr(indice);
				dp[i]++;
//				cout << s[i] <<" "<<dp[i]<< endl;

			}
			while(dp[toca] < dp[i]){
				s[i] = s[i].substr(0, indice)+s[i].substr(indice+1);
				dp[i]--;
//				cout << s[i] <<" "<<dp[i]<< endl;
			}
//			cout << "i = "<<i<<" "<<s[i] << endl;
		}
//		cout << "fin" << endl;
		indice = indice+dp[toca];
		suma += cuenta;
//		cout <<"indice = " << indice << " " << suma << endl;
	}
	if(indice >= s[0].size() && !igual(n)){
		return INT_MAX;
	}
	return suma;
}

int main(){
	int i, j, n, k, casos, minimo;
	scanf("%d", &casos);
	for(i = 0; i < casos; i++){
		scanf("%d", &n);
		for(j = 0; j < n; j++){
			cin >> s[j];
		}
		minimo = solve(n);
		if(minimo == INT_MAX){
			printf("Case #%d: Fegla Won\n", i+1);
		}
		else
			printf("Case #%d: %d\n", i+1, minimo);
	}
	return 0;
}
