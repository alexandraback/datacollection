#include <iostream>
using namespace std; 


char alpha[30]={"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};

	int choose_max(int a[],int n)
	{
		int max =a[0],max_i =0;
		
		for(int i=1; i<n; i++)
		{
			if(a[i]>max)
			{
				max_i=i;
				max=a[i];
			}
		}
		return max_i;
	}



int main() {
  int t, n, m , a[30] ,total;
  cin >> t; 
  
  
  for (int i = 1; i <= t; ++i) {
  
  
  
    cin >> n;
    total = 0 ;
	
	
	for(int j=0; j<n; j++)
	{
		cin>>a[j];
		total += a[j] ;
	}
	cout << "Case #" << i << ": ";
	while(total>0)
	{
	
		if(total==2)
		{
			for(int j=0; j<n; j++)
			{
				if(a[j]>0)	{
					cout<<alpha[j];
				}
			}
			total-=2;
			break;
		}
		
		if(total%2==0)
		{
		
		 int p = choose_max(a,n);
	     a[p]--;
	     total--;
		cout<<alpha[p];
		 p = choose_max(a,n);
		 a[p]--;
		 total--;
		 cout<<alpha[p]<<" ";
		 
		}
		else
		{
		
		 int p = choose_max(a,n);
		 a[p]--;
		 total--;
		 cout<<alpha[p]<<" ";
		 
		}
				
	}
	  cout<< endl;
    
  
  
  }
  
  return 0;
}
