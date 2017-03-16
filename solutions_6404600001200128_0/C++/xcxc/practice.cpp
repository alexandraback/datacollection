/*
ID: xiaoche4
PROG: skidesign
LANG: C++
*/
//#include "TC.cpp"
#include <iostream>
#include <sstream>
#include <fstream>
#include <cmath>
#include <ctime>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <bitset>
#include <utility>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;

int T,N;
int m[1000];
int main()
{
	freopen("A-small-attempt1.in","r",stdin);
	//freopen("Ans.out","w",stdout);
	//ifstream fin("dict.out");
	//ofstream fout("Ans.out");
	//FILE *fin=fopen("table.txt","r");
	FILE *fout=fopen("Ans.out","w");
	cin>>T;
	for(int k=1;k<=T;k++){
		cin>>N;
		for(int i=0;i<N;i++)
			cin>>m[i];
		int ans1=0,mm=0;
		for(int i=1;i<N;i++){
			if(m[i]<m[i-1]){
				ans1+=m[i-1]-m[i];
				mm=max(m[i-1]-m[i],mm);
			}
		}
		int ans2=0;
		for(int i=0;i<N-1;i++){
			if(mm>m[i]) ans2+=m[i];
			else ans2+=mm;
		}
		fprintf(fout,"Case #%d: %d %d\n",k,ans1,ans2);
	}

	return 0;
}