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

void runCase()
{
	int N;
	cin>>N;
	string a,b;
	cin >> a >> b;
	pair<string,vector<int> > A,B;
	A = tosi(a);
	B = tosi(b);
	if(A.first.length() != B.first.length()) printf("Fegla Won\n");
	else {
		int r = 0;
		rep(i,A.first.length()) {
			if(A.first[i] != B.first[i]) {printf("Fegla Won\n");return;}
			else r += abs(A.second[i]-B.second[i]);
		}
		cout << r << endl;
	}
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
