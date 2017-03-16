#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std ;

int main(void)
{
	int tc ;
	scanf("%d", &tc) ;
	
	for(int c=1;c<=tc;c++)
	{
		int n ;
		long long k ;
		long long arr[1100] ;
		
		cin >> n >> k ;
		for(int i=0;i<n;i++)
			cin >> arr[i] ;
		
		long long t = 0 ;
		if(k>n)
		{
			long long a = 0, b = 1000000000000000LL ;
			
			while(a+1<b)
			{
				long long m = (a+b)/2 ;
				long long s = 0 ;
				
				for(int i=0;i<n;i++)
					s += m/arr[i]+1 ;
				
				if(s>=k)
					b = m ;
				else
					a = m ;
			}
			
			t = b ;
		}
		
		long long s = 0 ;
		vector<int> available ;
		for(int i=0;i<n;i++)
		{
			s += t/arr[i]+1 ;
			if(t%arr[i]==0)
			{
				s-- ;
				available.push_back(i+1) ;
			}
		}
		
		printf("Case #%d: %d\n", c, available[k-s-1]) ;
	}
	
	return 0 ;
}

