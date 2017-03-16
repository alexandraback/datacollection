#include <bits/stdc++.h>
using namespace std;
typedef long long int LL;
multiset< pair<int, char> > S;
pair<char, bool> f() {
	auto tmpA = S.end();
	tmpA--;
	auto par = *tmpA;
	S.erase(tmpA);
	par.first--;
	S.insert(par);
	int sum = 0, limite;
	for(auto val: S) {
		sum += val.first;
	}
	limite = sum / 2 + 1;
	for(auto val: S) {
		if( val.first >= limite ) return make_pair(par.second, false);
	}
	return make_pair(par.second, true);
}
int main() {
	int T, n, data;
	scanf("%d", &T);
	for(int caso=1 ; caso<=T ; caso++) {
		scanf("%d", &n);
		S.clear();
		for(int i=0, c = 'A'; i<n ; i++, c++) {
			scanf("%d", &data);
			S.insert(make_pair(data, c));
		}
		printf("Case #%d:", caso);		
		while( true ) {
			auto ans = f();
			if( ans.second == false ) {
				auto ansTmp = f();
				if( ansTmp.second == false ) {
					cout<<"ERROR";
				} else cout<<" "<<ans.first<<ansTmp.first;
			} else cout<<" "<<ans.first;
			int suma = 0;
			for(auto data: S) suma += data.first;
			if( suma == 0 ) break;
		}
		cout<<endl;
	}
	return 0;
} 
