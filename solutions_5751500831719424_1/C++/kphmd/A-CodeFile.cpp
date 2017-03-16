#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <list>
#include <map>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <set>
#include <utility>
#include <stack>

#define rep(i,n) for(int i = 0; i < (int)(n); i++)

using namespace std;

void solve();
void runCase();


pair<string,vector<int> > tosi(string a) {
	string r1; vector<int> r2;
	int j = 0;
	r1 += a[0]; r2.push_back(1);
	for(int i = 1; i < a.length(); i++) {
		if(a[i]==r1[j]) r2[j]++;
		else {
			r1 += a[i];	r2.push_back(1); j++;
		}
	}
	return make_pair(r1,r2);
}

int getmin(vector<int> a) {
	int n = a.size();
	int avg = 0;
	rep(i,n) avg += a[i];
	avg /= n;
	int r1=0,r2=0;
	rep(i,n) {
		r1 += abs(avg-a[i]);
		r2 += abs(avg+1-a[i]);
	}
	return min(r1,r2);
}

void runCase()
{
	int N;
	cin>>N;
	vector<string> ss(N,"");
	rep(i,N) cin>>ss[i];
	
	vector< pair<string,vector<int> > > SS(N);
	
	rep(i,N) SS[i] = tosi(ss[i]);
	
	rep(i,N) {
		if(SS[i].first.length() != SS[0].first.length()) {
			printf("Fegla Won\n");return;
		}
	}
	
	int n = SS[0].first.length();
	rep(i,n) {
		rep(j,N) if(SS[j].first[i] != SS[0].first[i]) {
			printf("Fegla Won\n");return;
		}
	}
	
	int r = 0;
	rep(i,n) {
		vector<int> rs(N);
		rep(j,N) {
			rs[j] = SS[j].second[i];
		}
		r += getmin(rs);
	}
	cout << r << endl;
}

void runSample()
{
	string input;

	char buf[501] = {0};
	cin.getline(buf,501);

	input = buf;


	printf("%s\n",input.c_str());
}

void solve()
{
	int n;
	scanf("%d",&n);
	getchar();

	for(int i = 0; i < n; i++) {
		printf("Case #%d: ",i+1);
		runCase();
		//runSample();
	}
}

int main()
{
	solve();
	return 0;
}
