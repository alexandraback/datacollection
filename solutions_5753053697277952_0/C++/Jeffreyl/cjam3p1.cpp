#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
#define pii pair<int, int>
using namespace std;
int T, N, s; vector<pii> list;

int main() {
	cin>>T;
	for (int t=1; t<=T; t++) {
		cin>>N;
		list.clear();
		for (int i=0; i<N; i++) {
			cin>>s;
			list.push_back(make_pair(s, i));
		} cout<<"Case #"<<t<<": ";
		while (true) {
			sort(list.begin(), list.end());
			if (list[N-1].first<=0) break;
			if (list[N-1].first>0&&list[N-2].first==list[N-1].first&&list[N-3].first==0) {
				list[N-1]=make_pair(list[N-1].first-1, list[N-1].second);
				list[N-2]=make_pair(list[N-2].first-1, list[N-2].second);
				cout<<char(list[N-1].second+'A')<<char(list[N-2].second+'A')<<" ";
				continue;
			}
			list[N-1]=make_pair(list[N-1].first-1, list[N-1].second);
			cout<<char(list[N-1].second+'A')<<" ";
		}
		cout<<endl;
	}
	return 0;
}
