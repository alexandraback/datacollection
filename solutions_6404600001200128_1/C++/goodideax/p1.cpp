#include <iostream>
using namespace std;
int main()
{
	int T;
	cin>>T;
	int N,i;
	int arr[10020];
	int min1,min2;
	for(int t=1; t<=T;t++)
	{
		cin>>N;
		for(i=0;i<N;i++) cin>>arr[i];
		min1=0;
		for(i=0;i<N-1;i++)
			if(arr[i]>arr[i+1]) 
				min1+=arr[i]-arr[i+1];
		min2=0;
		for(i=0;i<N-1;i++)
			if(arr[i]-arr[i+1]>min2) 
				min2=arr[i]-arr[i+1];
		int sum=0;
		for(i=0;i<N-1;i++)
			if(arr[i]>min2)
				sum+=min2;
			else
				sum+=arr[i];
		cout<<"Case #"<<t<<": "<<min1<<' '<<sum<<endl;	
	}
	return 0;

}
