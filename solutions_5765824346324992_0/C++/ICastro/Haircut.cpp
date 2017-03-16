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
		int B, N;
		cin >> B >> N;
		vector<int> vet(B);
		double cortPM = 0;
		for (int i = 0; i < B; ++i){
			cin >> vet[i];
			cortPM += 1.0/vet[i];
		//cout << "cortPM " << cortPM << endl;
		}
		if (N <= B){
			cout << "Case #" << t+1 << ": " << N << endl;
			continue;
		}
		//cout << N - 2*B << endl;
		//cout << (N - 2*B)/cortPM << endl;
		lint tempo = N - 2*B > 0 ? (N - 2*B)/cortPM : 0;

		//cout << tempo << endl;
		vector<int> aux(B);
		lint num = B;
		for (int i = 0; i < B; ++i){
			aux[i] = vet[i] - (tempo % vet[i]);
			num += tempo / vet[i];
		//cout << "tempo / vet[i] " << tempo / vet[i] << endl;
		}

		int resp = -1;
		//int contmaster = 0;
		//cout << num << endl;
		while(num < N){
			//if (contmaster++ > 15) break;
			int min = aux[0];
			for (int i = 1; i < B; ++i){
				if (aux[i] < min){
					min = aux[i];
				}
			}
			//cout << "min " << min << endl;
			for (int i = 0; i < B; ++i){
				aux[i] -= min;
			//cout << "aux[i] " << aux[i] << endl;
				if (aux[i] == 0){
		//cout << 'i' << i << endl;
					aux[i] = vet[i];
					num++;
					if (num == N){
						resp = i;
					}
				}
			}
		}

		cout << "Case #" << t+1 << ": " << resp + 1 << endl;
	}
	return 0;
}
