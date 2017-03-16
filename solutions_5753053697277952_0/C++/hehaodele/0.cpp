#include "iostream"
#include "cstdio"
#include "cstdlib"
#include "cstring"
#include "cmath"
#include "algorithm"
#include "set"
#include "map"
#include "queue"
#include "vector"
using namespace std;
#define rep(i,n) for(int i=0; i<n; ++i)
#define repp(i,a,b) for(int i=a; i<a+b; ++i)
#define sz size()
#define X first
#define Y second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int,int> pii;

void run(){
	int n;
	int a[26];
	cin >> n;
	int N = 0;
	rep(i,n){
		cin >> a[i];
		N += a[i];
	}
	if(n==2){
		rep(i,a[0]) printf("AB%c", i<a[0]-1? ' ':'\n');
	}else{
		rep(nn,N-2){
			int j = 0;
			rep(i,n){
				if(a[i] > a[j]) j = i;
			}
			printf("%c ", 'A' + j);
			a[j]--;
		}
		std::vector<char> v;
		v.clear();
		rep(i,n) if(a[i]) v.pb('A' + i);
		printf("%c%c\n", v[0], v[1]);
	}
}

int main(int argc, char const *argv[])
{
	int cas;
	cin >> cas;
	rep(ca,cas){
		printf("Case #%d: ", ca+1);
		run();
	}
	return 0;
}