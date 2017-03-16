#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
#include <sstream>
#include <math.h>
#include <stdlib.h>
#include <cstdlib>
#include <stdio.h>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <fstream>
#include <stack>
#include <queue>
#include <deque>
#include <list>
#include <vector>
#include <map>
#include <set>

using namespace std;
const unsigned long long O = 2e9;
const double E = 1e-9;
const double pi = 3.1415926536;
int DX[] = { 1, -1, 0, 0 };
int DY[] = { 0, 0, 1, -1 };

/*bool valid(int x, int y)
 {
 return ((x >= 0 && x<n) && (y >= 0 && y<n));
 }*/

int main() {
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("out.txt", "w", stdout);
	int t, X = 1;
	cin >> t;
	while (t--) {
		int n;
		cin>>n;
		int arr[26];
		for(int i=0;i<n;i++)
			cin>>arr[i];
		vector<string>v;
		int all=n;
		while(all!=2){
			int ind1=0,ind2=0,max1=0,max2=0;
		for(int i=0;i<n;i++)
		{
			if(arr[i]>max1)
				max1=arr[i],ind1=i;
		}
			v.push_back(string(1,ind1+'A'));
			arr[ind1]--;
		if(arr[ind1]==0)
			all--;
		}

		string rem="";
		int max1=0,max2=0,ind;
		for(int i=0;i<n;i++)
			if(arr[i]!=0 && max1==0)
				max1=i;
			else if(arr[i]!=0)
				max2=i;
		rem+=string(1,max1+'A')+string(1,max2+'A');
		for(int i=0;i<arr[max1];i++){
			v.push_back(rem);
		}
		cout<<"Case #"<<X++<<": "<<v[0];
		for(int i=1;i<v.size();i++)
			cout<<" "<<v[i];
		cout<<endl;
	}

}
