// codejam2.cpp : Defines the entry point for the console application.
//

#define _CRT_SECURE_NO_WARNINGS
#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <vector>
#include <list>
#include <numeric>
#include <set>
#include <regex>
#include <map>
#include <algorithm>
#include <string>
#include <cstring>
#include <sstream>
#include <cmath>
#include <stack>
#include <cctype>
#include <queue>
#include <functional>
#include <bitset>
#define INF 2000000000
#define endl "\n"
#define gcd(x,y) __gcd((x),(y))
#define	all(c)	(c).begin(), (c).end()
#define rep(i,a,n) for (int i=a;i<n;i++)
const long long mod = 1000000007;

using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<pair<int, int>> vii;
typedef long long ll;
typedef unsigned long long ull;
template <typename T> using min_heap = priority_queue<T, vector<T>, greater<T> >;

template<typename T> void print2DArray(const vector<vector<T>>& p, string delim = " "){ for (int i = 0; i < p.size(); i++){ for (int j = 0; j < p[0].size(); j++){ cout << p[i][j]; if (j != p[0].size() - 1) cout << delim; }cout << endl; } }

int main(){
	int nbCases;
	scanf("%d", &nbCases);
	for (int caseNb = 1; caseNb <= nbCases; caseNb++){
		int R, C, N;
		scanf("%d%d%d", &R, &C, &N);
		vector<vector<bool>> veld;
		if (C < R)
			swap(C, R);
		veld.resize(R);
		for (int i = 0; i < R; i++){
			veld[i].resize(C, 0);
		}

		int best = INF;
		for (unsigned int i = 0; i < 1 << (R*C); i++){
			if (__popcnt(i) != N)
				continue;

			for (int j = 0; j < R*C; j++){
				veld[j/C][j%C] = (i & (1 << j));
			}

			int happy = 0;
			for (int k = 0; k < R; k++){
				for (int l = 0; l < C; l++){
					if (veld[k][l]){
						if (k + 1 < R && veld[k + 1][l]){
							happy++;
						}
						if (l + 1 < C && veld[k][l + 1]){
							happy++;
						}
					}
				}
			}
			best = min(best, happy);
		}


		printf("Case #%d: %d\n", caseNb, best);
	}
	return 0;
}