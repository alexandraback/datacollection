#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std ;

long long arr[3100][2] ;
int cur ;

bool cmp(const int a, const int b)
{
	long long va[2], vb[2] ;
	va[0] = arr[a][0]-arr[cur][0] ;
	va[1] = arr[a][1]-arr[cur][1] ;
	vb[0] = arr[b][0]-arr[cur][0] ;
	vb[1] = arr[b][1]-arr[cur][1] ;
	
	return (atan2(va[1],va[0]) < atan2(vb[1],vb[0])) ;
}

int main(void)
{
	int tc ;
	scanf("%d", &tc) ;
	
	for(int c=1;c<=tc;c++)
	{
		int n ;
		
		cin >> n ;
		for(int i=0;i<n;i++)
			cin >> arr[i][0] >> arr[i][1] ;
		
		printf("Case #%d:\n", c) ;
		for(cur=0;cur<n;cur++)
		{
			int ps[6100] ;
			for(int i=0;i<n-1;i++)
				ps[i] = i<cur?i:i+1 ;
			sort(ps, ps+n-1, cmp) ;
			for(int i=n-1;i<2*(n-1);i++)
				ps[i] = ps[i-n+1] ;
				
			int ans = n-1 ;
			int ed = 1 ;
			for(int st=0;st<n-1;st++)
			{
				long long vs[2], vt[2] ;
				vs[0] = arr[ps[st]][0]-arr[cur][0] ;
				vs[1] = arr[ps[st]][1]-arr[cur][1] ;
				
				for(;ed<st+n-1;ed++)
				{
					vt[0] = arr[ps[ed]][0]-arr[cur][0] ;
					vt[1] = arr[ps[ed]][1]-arr[cur][1] ;
					
					if(vs[0]*vt[1]-vs[1]*vt[0]<0)
						break ;
				}
				
				ans = min(n-(ed-st+1), ans) ;
			}
			cout << ans << endl ;
		}
	}
	
	return 0 ;
}

