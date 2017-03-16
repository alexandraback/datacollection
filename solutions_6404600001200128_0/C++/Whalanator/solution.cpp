#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

ll T,N,c1,S,M,cas,i,j,S2;
vector<int> as;

int main() {
	cin >> T;
	for (cas=1;cas<=T;cas++) {
		cin >> N;
		S=0;
		M=0;
		cin >> i;
		as.clear();
		as.push_back(i);
		for (c1=1;c1<N;c1++) {
			cin >> j;
			as.push_back(j);
			S+=max((int)(i-j),0);
			M=max((int)(i-j),(int)M);
			i=j;
		}
		S2=0;
		for (c1=1;c1<N;c1++) {
			S2+=min(as[c1-1],(int)M);
		}
		cout << "Case #" << cas << ": " << S << ' ' << S2 << endl;
	}
	return 0;
}
