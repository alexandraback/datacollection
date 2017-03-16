#include <iostream>
#include <utility>
#include <functional>
#include <algorithm>

using namespace std;

#define endl '\n'
#define ll long long int

int main(){
	//ios_base::sync_with_stdio(false);
	//cin.tie(0);
	int T;
	cin >> T;
	for (int Case = 1; Case <= T; Case++){
		vector<pair<int, char> > v;
		int N;
		cin >> N;
		for (char i = 'A'; i < 'A'+N; i++){
			int temp;
			cin >> temp;
			v.push_back(make_pair(temp, i));
		}

		sort(v.begin(), v.end(), greater<pair<int, char> >());
		cout << "Case #" << Case << ": ";
		while (v[0].first){
			int cnt = 0;
			for (int i = 0; i < v.size(); i++){
				cnt += v[i].first;
			}
			if (cnt == 3){
				int i;
				for (i = 0; i < v.size()-1; i++){
					if (v[i].first > v[i+1].first){
						cout << v[i].second;
						v[i].first--;
						break;
					}
				}
				if (i == v.size()-1){
					cout << v[i].second;
					v[i].first--;
				}
				cout << ' ';
				continue;
			}
			int i;
			for (i = 0; i < v.size()-1; i++){
				if (v[i].first > v[i+1].first){
					cout << v[i].second;
					v[i].first--;
					break;
				}
			}
			if (i == v.size()-1){
				cout << v[i].second;
				v[i].first--;
			}
			if (v[0].first == 0) break;
			for (i = 0; i < v.size()-1; i++){
				if (v[i].first > v[i+1].first){
					cout << v[i].second;
					v[i].first--;
					break;
				}
			}
			if (i == v.size()-1){
				cout << v[i].second;
				v[i].first--;
			}
			cout << ' ';
		}
		cout << endl;
	}

}