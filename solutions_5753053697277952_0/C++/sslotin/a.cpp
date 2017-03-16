#include <bits/stdc++.h>
using namespace std;

int main(){
	int T;
	cin >> T;

	for(int t = 0; t < T; t++){
		cout << "Case #" << t+1 << ": ";
		int n;
		cin >> n;
		set< pair<int, int> > p;
		for(int i = 0; i < n; i++){
			int c;
			cin >> c;
			p.insert({-c, i});
		}
		while(!p.empty()){
			if( (int) p.size() >= 2 ){
				auto it = p.begin();
				auto it2 = it;
				++it2;
				if(it->first == it2->first && (it->first != -1 || (int) p.size() != 3)){
					cout << char('A' + it->second) << char('A' + it2->second) << " ";
					if(it->first != -1)
						p.insert({it->first+1, it->second});
					p.erase(it);
					if(it2->first != -1)
						p.insert({it2->first+1, it2->second});
					p.erase(it2);
					continue;
				}
			}
			auto it = p.begin();
			cout << char('A' + it->second) << " ";
			if(it->first != -1)
				p.insert({it->first+1, it->second});
			p.erase(it);
		}
		cout << endl;
	}

	return 0;
}
