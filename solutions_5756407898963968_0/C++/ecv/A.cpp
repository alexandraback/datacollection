// CF.cpp: define el punto de entrada de la aplicaci?n de consola.
//
#pragma warning ( disable: 4996 )
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <map>
#include <iostream>

typedef std::pair<int,int> ii;
typedef long long int Int;
typedef unsigned long long int uInt;
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;
typedef std::vector<std::string> vs;
typedef std::vector<ii> vii;
#define sz(X) int((X).size())
#define REP(i,n) for(int i = 0; i < n; ++i)
#define FOR(i,v) for(int i = 0; i < int(v.size()); ++i)
#define ALL(v) v.begin(),v.end()
using namespace std;


int main(){
    FILE *f = freopen("A.txt","r",stdin);
	FILE *g = freopen("out.txt","w",stdout);
	int ntsts;
	scanf("%d", &ntsts);
	for(int ntst = 1; ntst <= ntsts; ++ntst){
		int B[4][4],C[4][4], b, c;
		scanf("%d",&b);
		for(int i = 0; i<4; ++i){
			for(int j = 0; j<4; ++j){
				scanf("%d",&B[i][j]);
			}
		}
		scanf("%d",&c);
		for(int i = 0; i<4; ++i){
			for(int j = 0; j<4; ++j){
				scanf("%d",&C[i][j]);
			}
		}
		vi is(17);
		for(int i = 0; i<4; ++i) is[B[b-1][i]]++, is[C[c-1][i]]++;
		vi resp;
		for(int i = 1; i<=16; ++i){
			if(is[i]==2)
				resp.push_back(i);
		}

		fail:
		printf("Case #%d: ",ntst);
		switch(resp.size()){
		case 0: printf("Volunteer cheated!"); break;
		case 1: printf("%d",resp[0]); break;
		default: printf("Bad magician!"); break;
		}
		printf("\n");
	}

	//printf("%I64d\n", nr);
	return 0;
}
