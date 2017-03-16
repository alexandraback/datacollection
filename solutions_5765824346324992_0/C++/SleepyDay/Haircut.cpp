#include <vector>
#include <algorithm>
#include <fstream>
#include <stdlib.h> 
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stack>
#include <string.h>
#include <iomanip>
#include <sstream>
#include <map>
#include <set>

using namespace std;

#define ll long long
#define ull unsigned long long

ll gcd(ll a, ll b)
{
    if(a < 0) a = -a; if(b < 0) b = -b;
    return b ? gcd(b, a % b) : a;
}

int main()
{
	freopen("B-small-attempt5.in","r",stdin);
    freopen("B-small-attempt5.out","w",stdout);
	ll i, j, numCase, b, n;
	cin>>numCase;
	for(i=0; i<numCase; i++){		
		ll times[1001], curtimes[1001]={0}, cur=0, num, tot1=0;
		cin>>b>>n;
		for(j=1; j<=b; j++){
			cin>>times[j];
		}
		num=times[1];
		for(j=2; j<=b; j++){
			num=num*times[j]/gcd(num, times[j]);
		}
		for(j=1; j<=b; j++){
			tot1=tot1+num/times[j];
		}
		n=n%tot1;
		cout << "Case #" << (i+1) << ": ";
		if(b==1){
			cout<<1<<endl;
		}
		else if(n==0)
		{
			cout<<b<<endl;
		}
		else{
			ll count=1;
			ll minindex;
			while(count <= n){
				for(int k=2; k<=b; k++){
					if(curtimes[k] < curtimes[k-1]){
						minindex=k;
					}
				}
				curtimes[minindex]=curtimes[minindex]+times[minindex];
				count++;
			}
			cout<<minindex<<endl;
		}
	}	
	return 0;
}
