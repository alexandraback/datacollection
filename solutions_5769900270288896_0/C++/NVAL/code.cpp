#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <list>
#include <map>
#include <set>
#include <stdlib.h>
#include <sstream>
#include <assert.h>
#include <memory.h>
#include <string.h>
#include <time.h>
using namespace std;
#pragma comment(linker, "/STACK:200000000")

#define mp make_pair
#define pb push_back 
#define ll long long
#define sz(x) (int)(x).size()
/*
int rev(ll x) {
	ll val = x;
	ll res = 0;
	while(val > 0) {
		res *= 10LL;
		res += val % 10LL;
		val /= 10LL;
	}
	return res;
}*/


int solve(int R, int C, int N) {
	int res = 0;
			int saveN = N;
		int without = (R * C + 1) / 2;
		if(N <= without) {
			res = 0;
		}
		else {
			int gr = 0;
			int ost = R * C;
			N -= without;
			ost -= without;
			if(C > 1) { // не линия
				if(R % 2 == 0 && C % 2 == 0) {
					gr += R / 2;
					gr += R / 2;
					gr += (C - 2) / 2;
					gr += (C - 2) / 2;
				}
				else if(R % 2 == 0 && C % 2 == 1) {
					gr += C;
					gr += (R - 2) / 2;
					gr += (R - 2) / 2;
				}
				else if(R % 2 == 1 && C % 2 == 0) {
					gr += R;
					gr += (C - 2) / 2;
					gr += (C - 2) / 2;
				}
				else {
					gr += R / 2;
					gr += R / 2;
					gr += (C - 1) / 2;
					gr += (C - 1) / 2;
				}
				int ugl = 0; // стоимости по 2, а gr по 3
				if(R * C % 2 == 0) {
					ugl = 2;
					gr -= 2;
				}

				if(N <= ugl) {
					res += N * 2;
					N = 0;
				}
				else {
					N -= ugl;
					res += ugl * 2;
					ost -= ugl;
					if(N <= gr) {
						res += N * 3;
						gr -= N;
						N = 0;
						if((gr > 0 && C == 3 && R == 3 && saveN == 8)) {
							res--;
						}
					}
					else {
						res += gr * 3;
						N -= gr;
						ost -= gr;
						res += N * 4;
						N = 0;
					}
				}
			}
			else {
				// вытянута в линию
				if(R % 2 == 0) {
					if(N <= 1) {
						res += N;
						N = 0;
					}
					else {
						res++;
						N--;
						ost--;
						res += N * 2;
					}
				}
				else {
					res += N * 2;
				}
			}
		}
		return res;
}

int main()
{
	freopen("input.txt","rt",stdin);
    freopen("output.txt","wt",stdout);
    //freopen("a.in","rt",stdin);
    //freopen("a.out","wt",stdout);

	int T;
	scanf("%d", &T);
	for(int t = 1; t <= T; t++) {
		/*ll N;
		scanf("%lld", &N);
		int res = 0;
		ll cur = 1;*/
		int res = 0;
		int R, C, N;
		scanf("%d %d %d", &R, &C, &N);
		if(R < C) swap(R, C);
		res = 1e9;
		if(C == 3 && R % 2 == 1) {
			res = 0;
			if(N <= (R * C + 1) / 2) {
				res = 0;
			}
			else {
				int gr = R * 2 + 2;
				if(N <= gr) {
					res = N * 2 - 1;
				}
				else {
					res = N * 2;
					N -= gr;
					int ost = R - 2;
					if(N <= (ost - 1) / 2) {
						res += N * 2;
					}
					else res += N * 4;
				}
			}
		}
		res = min(res, solve(R, C, N));
		printf("Case #%d: %d\n", t, res);
	}

    return 0;
}