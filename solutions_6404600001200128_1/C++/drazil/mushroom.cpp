#include <stdio.h>
#include <algorithm>

using namespace std ;

int main(void)
{
	int tc ;
	scanf("%d", &tc) ;
	
	for(int c=1;c<=tc;c++)
	{
		int n ;
		int arr[11000] ;
		
		scanf("%d", &n) ;
		for(int i=0;i<n;i++)
			scanf("%d", &arr[i]) ;
			
		int ans1 = 0, rate = 0 ;
		for(int i=1;i<n;i++)
		{
			if(arr[i]<arr[i-1]) ans1 += arr[i-1]-arr[i] ;
			rate = max(rate, arr[i-1]-arr[i]) ;
		}
		
		int ans2 = 0 ;
		for(int i=1;i<n;i++)
			ans2 += min(rate, arr[i-1]) ;
		
		printf("Case #%d: %d %d\n", c, ans1, ans2) ;
	}
	
	return 0 ;
}

