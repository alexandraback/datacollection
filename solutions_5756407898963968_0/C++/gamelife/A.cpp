/*
 * A.cpp
 *
 *  Created on: 2014/4/12
 *      Author: gamelife
 */

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <stack>
#include <sstream>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
#define SZ(x) (int)(x.size())
#define STRLEN(x) (int)(strlen(x))
#define F0(i,n) for(i=0;i<n;i++)
#define F1(i,n) for(i=1;i<=n;i++)
ll gcd(ll x, ll y) { return y ? gcd(y, x%y) : x; }

const int maxn = 1000 ;
char line[maxn] ;
int cnt ;
int i,j,k,m,n,x,y,z;
int tt, tn;

void main2(){
	int q1 ,  q2 ;
	int a1[4][4] , a2[4][4];

	map<int,int> possible;

	scanf("%d\n" , &q1) ;
//	printf("%d \n" , q1) ;
	F0(i,4){
		F0(j,4){
			scanf("%d " , &a1[i][j]) ;
			if(i == q1-1){
				possible[a1[i][j]] = 1 ;
			}
//			printf("%d " , a1[i][j]) ;
		}
//		cout<<endl;
	}

	int ans = -1 , count = 0 ;

	scanf("%d\n" , &q2) ;
//	printf("%d \n" , q2) ;
	F0(i,4){
		F0(j,4){
			scanf("%d " , &a2[i][j]) ;
			if(i==q2-1){
				if(possible.find(a2[i][j]) != possible.end()){
					count ++ ;
					ans = a2[i][j];
				}

			}
//			printf("%d " , a2[i][j]) ;
		}
//		cout<<endl;
	}

	if(count > 1)
		cout << "Bad magician!" << endl;
	if(count == 1)
		cout << ans << endl ;
	if(ans == -1)
		cout << "Volunteer cheated!" << endl;

}

int main() {
//	    freopen("test.in", "r", stdin);

	    freopen("A-small-attempt0.in", "r", stdin);
	    freopen("A-small.out", "w", stdout);

//	    freopen("C-large-practice.in", "r", stdin);
//	    freopen("C-large.out", "w", stdout);

	    scanf("%d\n" , &tn) ;

	    F1(tt,tn) {
	    	printf("Case #%d: ", tt);
	    	main2();

	    }

	return 0;
}


