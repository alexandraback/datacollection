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

#define rep(i,n) for(int i = 0; i < (n); i++)

using namespace std;

void solve();
void runCase();

void runCase()
{
	int B,N;
	scanf("%d%d",&B,&N);
	vector<int> M(B),C(B,0);
	rep(i,B) scanf("%d",&M[i]);
	
	int y = 0;
	rep(i,N) {
		int mj = 0;
		rep(j,B) if(C[j] < C[mj]) mj = j;
		int t = C[mj];
		rep(j,B) C[j] -= t;
		
		int mx = 0;
		rep(j,B) if(C[j] > C[mx]) mx = j;
		if(C[mx]==0 && i!=0) {
			N %= i;
			break;
		}
		
		//rep(j,B) cout << C[j] << " "; cout << endl;
		C[mj] = M[mj];
		y = mj;
		//rep(j,B) cout << C[j] << " "; cout << endl;
	}
	rep(i,N) {
		int mj = 0;
		rep(j,B) if(C[j] < C[mj]) mj = j;
		int t = C[mj];
		rep(j,B) C[j] -= t;
		
		//rep(j,B) cout << C[j] << " "; cout << endl;
		C[mj] = M[mj];
		y = mj;
		//rep(j,B) cout << C[j] << " "; cout << endl;
	}
	printf("%d\n",y+1);
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
