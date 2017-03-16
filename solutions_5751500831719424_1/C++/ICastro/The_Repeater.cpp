#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compara (const int c1, const int c2) {
	return c1<c2;
}

int main(void){
	int T;
	cin >> T;
	for (int k = 0; k < T; ++k){
		int N;
		cin >> N;
		vector<string> vet(N);
		for (int i = 0; i < N; ++i){
			cin >> vet[i];
		}
		bool impossivel = false;
		int contTotal = 0;
		vector<int> cont(N);
		while (vet[0].size() > 0){
			//int j = vet[0].size()-1;
			char c = vet[0].back();
			vet[0].pop_back();
			cont[0] = 1;
			//j--;
			while (vet[0].back() == c){
				cont[0]++;
				vet[0].pop_back();
				//j--;
			}
			for (int i = 1; i < N; ++i){
				if (vet[i].size() == 0 || vet[i].back() != c){
					impossivel = true;
					break;
				}
				cont[i] = 0;
				while (vet[i].size() > 0 && vet[i].back() == c){
					cont[i]++;
					vet[i].pop_back();
				}
			}
			if (impossivel) break;
			sort(cont.begin(), cont.end(), compara);
			int media = cont[N/2];
			for (int i = 0; i < N; ++i){
				if (cont[i] < media){
					contTotal += media - cont[i];
				} else {
					contTotal += cont[i] - media;
				}
			}
		}
		for (int i = 0; i < N; ++i){
			if (vet[i].size() != 0){
				impossivel = true;
				break;
			}
		}

		if (impossivel){
			cout << "Case #" << k+1 << ": Fegla Won" << endl;
//			continue;
		} else {
			cout << "Case #" << k+1 << ": " << contTotal << endl;
		}
		/*for (int i = 0; i < N; ++i){
			cout << vet[i] << endl;
		}*/
	}
	return 0;
}
