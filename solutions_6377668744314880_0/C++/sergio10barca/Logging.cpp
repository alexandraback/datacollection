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

typedef pair<long long int, long long int> Point;

double Orientacion(Point p, Point q, Point r){
	//devuelve negativo si la orientacion es en el sentido de las manecillas del reloj es decir negativa
    return (q.x*r.y + r.x*p.y + p.x*q.y) - (q.x*p.y + r.x*q.y + p.x*r.y);
}

vector<Point > Graham(vector<Point > P){
    vector<Point> resp;
    vector<Point> Lupper;
    vector<Point> Llower;
    int i, k, n = P.size();
    //Ordenar los puntos por su coordenada en x
    sort(P.begin(), P.end());
    for(i = 1; i < P.size(); i++)
		if(P[i].x == P[i-1].x && P[i].y == P[i-1].y){
			P.erase(P.begin()+i);
			i--;
		}
	n = P.size();
//	printf("tam = %d\n", n);

    for(i = 0; i < n; i++){
        Lupper.push_back(P[i]);
        //Mientras haya mas de 2 puntos en Lupper y haya una orientacion positiva entre los tres ultimos puntos
        while((k = Lupper.size())>2 && Orientacion(Lupper[k-3], Lupper[k-2], Lupper[k-1])>0)
            Lupper.erase(Lupper.begin()+(k-2));//quiere decir que el punto de en medio de los ultimos tres (k-1) no es parte del cerco
    }

    for(i = n-1; i >= 0; i--){
        Llower.push_back(P[i]);
        //Mientras haya mas de 2 puntos en Lupper y haya una orientacion positiva entre los tres ultimos puntos
        while((k = Llower.size())>2 && Orientacion(Llower[k-3], Llower[k-2], Llower[k-1])>0)
            Llower.erase(Llower.begin()+(k-2));//quiere decir que el punto de en medio de los ultimos tres (k-1) no es parte del cerco
    }

    if(Llower.size() > 0)
        Llower.erase(Llower.begin()+(Llower.size()-1));
    if(Llower.size() > 0)
        Llower.erase(Llower.begin());

    for(i = 0; i < Lupper.size(); i++)
        resp.push_back(Lupper[i]);
    for(k = 0; k < Llower.size(); k++, i++)
        resp.push_back(Llower[k]);

	for(i = 0, k = resp.size()-1; i < k; i++, k--)
		swap(resp[i], resp[k]);
    sort(resp.begin(), resp.end());
    int j;
    bool entra;
    for(int i = 0; i < resp.size(); i++){
        entra = false;
        for(j = i+1; j < resp.size(); j++)
            if(resp[i] == resp[j]){
                entra = true;
                resp.erase(resp.begin()+j);
                break;
            }
        if(entra)
            i = -1;
    }
    return resp;
}

void imprime(vector<Point> resp){
    printf("cubierta %d\n", resp.size());
    for(int i = 0; i<  resp.size(); i++){
        printf("%lld %lld\n", resp[i].first, resp[i].second);
    }
    printf("----\n");
    return;
}

int solve(int n, vector<Point> p){
    vector<Point> resp = Graham(p);
    int a, b, k, index, lim = 1 << n;
//    imprime(resp);
    for(index = 0; index < n; index++){
        int j;
        for(j = 0; j < resp.size(); j++){
            if(resp[j] == p[index]){
                printf("0\n");
                break;
            }
        }
        if(j == resp.size()){
            vector<Point> r;
            int maximo = 0, v[20] = {0};
            for(k = 1; k < lim; k++){
                v[index] = 0;
                r.clear();
                for(a = k, b = 0; a > 0; a>>=1, b++){
                    if(a&1){
                        r.push_back(p[b]);
                    }
                    v[b] = a&1;
                }
                if(v[index]){
                    r = Graham(r);
                    for(a = 0; a < r.size(); a++){
                        if(r[a] == p[index])
                            break;
                    }
                    if(a < r.size())
                        maximo = max(maximo, (int)r.size());
                }
                r.clear();
            }
            if(n == maximo){
                cout << "error";
                exit(0);
            }
            printf("%d\n", n-maximo);
        }
    }
    return -1;
}

int main(){
	int n, casos;
	long long int a, b;
    vector<Point> p;
	scanf("%d", &casos);
	for(int i = 1; i <= casos; i++){
        scanf("%d", &n);
        for(int j = 0; j < n; j++){
            scanf("%lld%lld", &a, &b);
            p.push_back(make_pair(a, b));
        }
        printf("Case #%d:\n", i);
        solve(n, p);
        p.clear();
	}
	return 0;
}
