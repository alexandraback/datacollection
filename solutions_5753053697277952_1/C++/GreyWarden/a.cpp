#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <string>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <fstream>

using namespace std;

int INF = 1E9;



int main() {
	freopen("A-large.in", "r", stdin);
	ofstream fout;
	fout.open("answer.out");

	int T;
	cin>>T;
	

	for(int Case = 1; Case <= T; Case++){
		fout<<"Case #"<<Case<<":";
		//fout<<endl;
		int cnt[26] = {0};
		int N;
		cin>>N;
		for(int i = 0; i < N; i++)
			cin>>cnt[i];
		int sum = 0;
		for(int i = 0; i < N; i++)
			sum += cnt[i];
		if(sum % 2){
			int at = 0, mx = 0;
			for(int i = 0; i < N; i++)
				if(cnt[i] > mx){
					mx = cnt[i];
					at = i;
				}
			fout<<" "<<char('A'+at);
			cnt[at]--;
		}
		bool change = true;
		while(change){
			change = false;
			int at1 = 0, mn1 = 0;
			int at2 = 0, mn2 = 0;
			for(int i = 0; i < N; i++){
				if(cnt[i] >= mn1){
					mn2 = mn1;
					at2 = at1;
					mn1 = cnt[i];
					at1 = i;
				}else if(cnt[i] > mn2){
					mn2 = cnt[i];
					at2 = i;
				}
			}
			if(cnt[at1] == 0) continue;
			cnt[at1]--; cnt[at2]--;
			fout<<" "<<char('A'+at1)<<char('A'+at2);
			change = true;
		}

		fout<<endl;
	}
	return 0;
}
