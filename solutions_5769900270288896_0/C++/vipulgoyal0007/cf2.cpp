#include <vector>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <bitset>
#include <map>
#include <queue>
#include <climits>
#include <bitset>
#define LL long long
#define INFI 100000000000
#define D double
using namespace std;
#include <iomanip>

int main()
{
    LL tt;
    cin>>tt;
    
    for(LL t=1; t<=tt; t++)
    {
    	LL r,c,n;
    	cin>>r>>c>>n;
    	
    	string cc;
    	
    	for(LL i=0; i<n; i++)
    	{
    		cc+= '1';
    	}
    	for(LL i=n; i<r*c; i++)
    	{
    		cc+= '2';
    	}
    	
    	LL mn = INFI;
    	do{
    		LL ans=0;
    		for(LL i=0; i<cc.size(); i++)
    		{
    			if(cc[i] == '1')
    			{
    				LL x= i/c;
    				LL y= i%c;
    				
    				if(x+1 < r && cc[(x+1)*c + y] == '1')
    				{
    					ans++;
    				}
    				if(x>0  && cc[(x-1)*c + y] == '1')
    				{
    					ans++;
    				}
    				if(y+1 < c && cc[(x)*c + y+1] == '1')
    				{
    					ans++;
    				}
    				if(y > 0 && cc[(x)*c + y-1] == '1')
    				{
    					ans++;
    				}
    			}
    		}
    		
    		mn = min(mn,ans/2);
    	}
    	while(next_permutation(cc.begin(), cc.end()));
    		
    	
		cout<<"Case #"<<t<<": "<<mn<<endl;    	
	}
	return 0;
}