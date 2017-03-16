#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <map>
#include <list>
#include <set>
#include <numeric>
#include <queue>
#include <stack>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <climits>
#include <cfloat>
#include <ctime>
#include <complex>
#include <cassert>
#include <iomanip>
using namespace std;
typedef long long LL;
typedef pair<int,int> P;

int in[1000];
void run()
{
	int N;
	cin >> N;
	for(int i=0;i<N;i++){
		cin >> in[i];
	}
	int a=0;
	int m=0;
	for(int i=1;i<N;i++){
		if(in[i-1]>in[i]){
			a+=in[i-1]-in[i];
		}
		m=max(m,in[i-1]-in[i]);
	}
	int b=0;
	for(int i=1;i<N;i++){
		if(in[i-1]>m){
			b+=m;
		}
		else{
			b+=in[i-1];
		}
	}
	
	cout << a << " " << b << endl;

}


int main() {
	int TotalCase;
	cin >> TotalCase;
	for (int Case=1;Case<=TotalCase;Case++) {
		cout << "Case #" << Case << ": ";
		run();
	}
}
