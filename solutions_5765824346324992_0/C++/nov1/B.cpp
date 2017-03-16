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
long long M[1010];
long long B,N;
long long bt[1010];

int main()
{
	int T;
	cin>>T;
	for(int t = 1; t <= T; ++t) {
		cin>>B>>N;
		long long tm = 1;
		long long nm = 0;
		for(int i = 1; i <=B; ++i) {
			cin>>M[i];
			tm *= M[i];
		}
		if(B == 1) {
			cout<<"Case #"<<t<<": "<<1<<endl;
			continue;
		}

		for(int i = 1; i <=B; ++i) {
			nm += tm/M[i];
		}

		long long con = (N-1)%nm;

		if(con < B) {
			cout<<"Case #"<<t<<": "<<con+1<<endl;
			continue;
		}
		memset(bt, 0, sizeof(bt));
		int tmp = 1;
		bool flag = false;
		for(int i = 1; i <= tm;++i) {
			for(int j = 1; j <= B; ++j) {
				if(bt[j] == 0) {
					if(tmp == con+1) {
					cout<<"Case #"<<t<<": "<<j<<endl;
					flag = true;
					break;
					}
					//cout<<i<<' '<<j<<' '<<tmp<<endl;
					bt[j] = M[j]-1; 
					tmp++;
				} else {
					bt[j]--;
				}
			}
			if(flag) break;
		}
	}
}
