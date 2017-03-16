#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

#define all(v) (v).begin(), (v).end()

int T, u, N;

int cmp(long long int x, long long int y = 0) {
    if(x<y) return -1;
    if(x==y) return 0;
    return 1;
}

struct point {
    long long int x, y;
    int id;
    point(long long int x = 0, long long int y = 0): x(x), y(y) {}
    point operator +(point q) { return point(x + q.x, y + q.y); }
    point operator -(point q) { return point(x - q.x, y - q.y); }
    double operator *(point q) { return x * q.x + y * q.y; }
    double operator %(point q) { return x * q.y - y * q.x; }
    int cmp(point q) const {
        if (int t = ::cmp(x, q.x)) return t;
        return ::cmp(y, q.y);
    }
    bool operator ==(point q) const { return cmp(q) == 0; }
    bool operator !=(point q) const { return cmp(q) != 0; }
    bool operator < (point q) const { return cmp(q) < 0; }
    static point pivot;
};
point point::pivot;
typedef vector<point> polygon;

int ccw(point p, point q, point r) {
    return cmp((p - r) % (q - r));
}

bool radial_lt(point p, point q) {
    point P = p - point::pivot, Q = q - point::pivot;
    double R = P % Q;
    if (cmp(R)) return R > 0;
    return cmp(P * P, Q * Q) < 0;
}

// Determina o fecho convexo de um conjunto de pontos no plano.
// Destrói a lista de pontos T.
polygon convex_hull(vector<point>& T) {
    int j = 0, k, n = T.size(); polygon U(n);
    point::pivot = *min_element(all(T));
    sort(all(T), radial_lt);
// Descomentar para manter pontos colineares
  for (k = n-2; k >= 0 && ccw(T[0], T[n-1], T[k]) == 0; k--);
  reverse((k+1) + all(T));
    for (int i = 0; i < n; i++) {
// troque o >= por > para manter pontos colineares
        while (j > 1 && ccw(U[j-1], U[j-2], T[i]) > 0) j--;
        U[j++] = T[i];
    }
    U.erase(j + all(U));
    return U;
}

point v[3010];
int resp[3010];
point w[3010];

void f(int pos, int size){
	//printf("%d %d\n", pos, size);
	if(pos == N){
		vector<point> aux;
		for(int i=0; i<size; i++) aux.push_back(w[i]);
		polygon temp;
		if(size >= 3) {
			temp = convex_hull(aux);
		}
		else {
			temp = aux;
		}
		for(int i=0; i<temp.size(); i++){
			if(resp[temp[i].id] > N-size){
				resp[temp[i].id] = N-size;
			}
		}
		return;
	}
	f(pos+1, size);
	w[size] = v[pos];
	f(pos+1, size+1);
}

int main(){
	scanf(" %d", &T);
	u=0;
	while(u<T){
		u++;
		scanf(" %d", &N);
		for(int i=0; i<N; i++){
			scanf(" %lld %lld", &v[i].x, &v[i].y);
			v[i].id = i;
			resp[i] = N;
		}

		f(0,0);

		printf("Case #%d:\n", u);
		for(int i=0; i<N; i++){
			printf("%d\n", resp[i]);
		}
	}
	return 0;
}
