#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <functional>
#include <string>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <cmath>
#include <cstdio>
#include <map>

using namespace std;
int m[1010];
int main()
{
	int T;
	cin>>T;
	for(int t = 1; t <= T; ++t) {
		int N;
		cin>>N;
		for(int i = 0; i < N; ++i) {
			cin>>m[i];
		}
		long long sol1=0, sol2=0;
		int tmp = 0;
		int tmpm = m[0];
		while(tmp<N) {
			if(m[tmp] > tmpm) {
				tmpm = m[tmp];
			} else {
				sol1+= (tmpm - m[tmp]);
				tmpm = m[tmp];
			}
			tmp++;
		}
		int mlargest = 0;
		for(int i = 0; i < N-1; ++i) {
			if((m[i] - m[i+1]) > mlargest) {
				mlargest = m[i] - m[i+1];
			}
		}
		if(mlargest > 0) {
			for(int i = 0; i < N-1; ++i) {
				if(m[i] < mlargest) {
					sol2+=m[i];
				} else {
					sol2 += mlargest;
				}
			}
		}
		cout<<"Case #"<<t<<": "<<sol1<<' '<<sol2<<endl;
	}
}
