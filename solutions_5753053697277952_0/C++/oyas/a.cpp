#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

#define rep(i,n) for(int i=0; i<(n); i++)
#define rrep(i,n) for(int i=(n)-1; i>=0; i--)
#define all(X) (X).begin(),(X).end()

using namespace std;
typedef long long int ll;
typedef pair<int,int> P;

template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

template<class A, size_t N, class T> void Fill(A (&a)[N], const T &v){ fill( (T*)a, (T*)(a+N), v ); }

const int INF = 0x3fffffff;


int main(){
	int T;

	cin >> T;
	for(int caseNum=1; caseNum <= T; caseNum++){

		int N, p[30];
		P top={}, sec={};
		cin >> N;
		rep(i,N){
			cin >> p[i];
			if( top < P(p[i], i) ){
				sec = top;
				top = P(p[i], i);
			}else if( sec < P(p[i], i) ){
				sec = P(p[i], i);
			}
		}

		printf("Case #%d: ", caseNum);
		rep(i, top.first - sec.first){
			cout << (char)('A'+top.second) << " ";
		}
		rep(i,N){
			if( i != top.second && i != sec.second ){
				rep(j, p[i]){
					cout << (char)('A'+i) << " ";
				}
			}
		}
		rep(i, sec.first){
			cout << (char)('A'+top.second) << (char)('A'+sec.second) << " ";
		}
		printf("\n");

	}

	return 0;
}
