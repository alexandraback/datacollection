#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <map>
#include <stack>
  
#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define FORR(i, n) FOR(i, 0, n)
#define sz(e) (int)e.size()
#define all(e) e.begin(), e.end()
#define pb push_back
#define CLR(x, a) memset(x, a, sizeof(x))
  
#define ll long long
#define ull unsigned ll
#define ii pair<int, int>
#define vi vector<int>
  
using namespace std;

int main (){
	int T;
	scanf (" %d", &T);
	FORR (c, T){
		int X;
		scanf (" %d", &X);
		vector<int> possible;
		FORR (i, 4){
			FORR (j, 4){
				int Y;
				scanf (" %d", &Y);
				if (i==X-1) possible.pb (Y);
			}
		}
		scanf (" %d", &X);
		int cont = 0, res = -1;
		FORR (i, 4){
			FORR (j, 4){
				int Y;
				scanf (" %d", &Y);
				if (i==X-1){
					FORR (k, sz(possible)) 
						if (possible[k]==Y) res = Y, cont++;
				}
			}
		}
		printf ("Case #%d: ", c+1);
		if (cont==0){
			printf ("Volunteer cheated!\n");
		} else if (cont>1){
			printf ("Bad magician!\n");
		} else {
			printf ("%d\n", res);
		}
	}
}

