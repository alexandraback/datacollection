#include <iostream>
#include <ios>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	for(int i=1; i<=t; ++i) {
		int N;
		cin >> N;
		cout << "Case #" << i << ":";
		int partit[26];
		// for(j=0;j<N;++j) cin >> partit[j];
		copy_n(istream_iterator<int>(cin),N,partit);
		int totalpartit=accumulate(partit,partit+N,0);
		while(totalpartit) {
			string evac=" ";
			int *proximo=max_element(partit,partit+N);
			// cerr << proximo << ' ' << partit << ' ' << proximo-partit << ' ' << (char)('A'+(proximo-partit)) << endl;
			evac+=(char)('A'+(proximo-partit));
			--(*proximo);
			--totalpartit;
			int *otro;
			if(*(otro=max_element(partit,partit+N))>(totalpartit>>1)) {
				evac+=(char)('A'+(otro-partit));
				--(*otro);
				--totalpartit;
			}
			cout << evac;
		}
		cout << endl;
	}
	return 0;
}