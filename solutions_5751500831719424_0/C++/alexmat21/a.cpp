// Created by alex_mat21. And it works!

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
#include <iomanip>
#include <cmath>
#include <utility>
 
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
string s[100];
int n;
int a[100];
int b[100];
for (int i111=0 ; i111<t111; i111++){
	cin >> n;
	FOR(i,n)
		cin >> s[i];
	int m=0;
	FOR(i,n)
		a[i]=0;
	int t=1;
	while (t==1){
		char c=s[0][a[0]];
		int mi=10000000;
		int ma=0;
		FOR(i,n){
			if (a[i]>=s[i].length() || s[i][a[i]]!=c){
				m=-1;
				t=0;
				break;
				}
			else{
				b[i]=0;
				while (a[i]<s[i].length() && s[i][a[i]]==c){
					a[i]++;
					b[i]++;
					}
				if (mi>b[i])
					mi=b[i];
				if (ma<b[i])
					ma=b[i];
				}
			}
		//cout << c << " " << mi << " " << ma <<  endl;
		int mm=1000000;
		if (m!=-1){
			for (int j=mi ; j<=ma; j++){
				int m1=0;
				FOR(i,n){
					m1+=abs(b[i]-j);
					}
				//cout << j << " !!! " << m1 <<endl;
				if (mm>m1)
					mm=m1;
				}
			m+=mm;
			}
		
		if (t==1 && a[0]>=s[0].length()){
			t=0;
			FOR(i,n){
				if (a[i]<s[i].length()){
					m=-1;
					break;
					}
				}
			}
		}

	if (m==-1)
		cout << "Case #"<< i111 +1 << ": Fegla Won"<< endl;
	else
		cout << "Case #"<< i111 +1 << ": " << m<< endl;
	}
return 0;
}
