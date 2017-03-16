#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <sstream>
#include <stdio.h>
#include <math.h>
#include <bitset>
#include <string> 
#include <iomanip> // za setprecision() !!
#include <cmath> // za abs()
 
#define FOR(i,n) for(int i=0,_n=n;i<_n;i++)
#define FORR(i,s,n) for(int i=s,_n=n;i<_n;i++)
#define mp make_pair
#define vi vector<int>
#define fs first
#define sec second
#define pii pair<int,int>

using namespace std;

int main (){
int t111;
cin >> t111;
int a[16];
int n,k;
for (int i111=0 ; i111<t111; i111++){
	memset(a,0,sizeof(a));
	for (int l=0; l<2; l++){
	cin >> n;
	for (int i=0 ; i<4 ; i++)
		for (int j=0; j<4 ; j++){
			cin >> k;
			if (i+1!=n)
				a[k-1]=1;
			}}
	int t=0;
	int t1;
	for (int i=0; i<16 ;i++){
		//cout << a[i] << endl;
		if (a[i]==0){
			t+=1;
			t1=i+1;
			}
		}
	cout << "Case #"<< i111 +1 << ": ";
	if (t==0)
		cout << "Volunteer cheated!";
	else if (t>1)
		cout << "Bad magician!";
	else
		cout << t1;
		
	cout << endl;
	}
return 0;
}
