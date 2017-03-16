#include <bits/stdc++.h>
using namespace std;

#define size(v) int(v.size())
#define MOD 1000003
#define INF 1e9
#define ulint unsigned long long int
#define lint long long int
#define mp make_pair
#define pb push_back
#define pop pop_back
#define st first
#define nd second
#define all(X) (X).begin(),(X).end()
#define E12 1000000000000

struct min_heap_comparator{
	bool operator()(const long& a,const long& b) const{
		return a>b;
	}
};
#define mh_min(X) make_heap(all(X), min_heap_comparator());
#define poph_min(X) {pop_heap(all(X), min_heap_comparator()); (X).pop();}
#define pushh_min(X, Y) {(X).pb(Y); push_heap(all(X), min_heap_comparator());}
#define sorth_min(X) sort_heap(all(X), min_heap_comparator());

#define mh_max(X) make_heap(all(X));
#define poph_max(X) {pop_heap(all(X)); (X).pop();}
#define pushh_max(X, Y) {(X).pb(Y); push_heap(all(X));}
#define sorth_max(X) sort_heap(all(X));

int main(void){
	int T;
	cin >> T;
	for (int t = 0; t < T; ++t){
		int N;
		cin >> N;
		vector<int> vet(N);
		for (int i = 0; i < N; ++i){
			cin >> vet[i];
		}
		int A = 0;
		int maxDif = 0;
		for (int i = 1; i < N; ++i){
			if (vet[i] < vet[i-1]){
				A += vet[i-1] - vet[i];
				if (vet[i-1] - vet[i] >= maxDif){
					maxDif = vet[i-1] - vet[i];
				}
			}
		}
		//int atual = vet[0];
		int B = 0;
		for (int i = 0; i < N-1; ++i){
			if (vet[i] > maxDif){
				//vet[i] -= maxDif;
				B += maxDif;
			} else {
				B += vet[i];
				//vet[i] = 0;
			}
			//atual += vet[i];
		}
		cout << "Case #" << t+1 << ": " << A << " " << B << endl;
	}
	return 0;
}
