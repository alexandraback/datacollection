#include <iostream>
using namespace std;
long long arr[1050];
int B;
int judge(long long x,long long value)
{
	int i;
	long long count = 0;
	for(i=0;i<B;i++)
	{
		count+=x/arr[i]+1;
		//if(x!=0&&(x%arr[i]==0))
		//	count++;
	}
	if(count>=value) 
		return true;
	else
		return false;
}
int main()
{
	int T;
	long long N,i;
	int max;
	cin>>T;
	for(int t=1;t<=T;t++){
		cin>>B>>N;
		max = 0;
		for(i=0;i<B;i++)
		{
			cin>>arr[i];	
			if(arr[i]>max)
				max = arr[i];
		}	
		long long high,low,mid;
		high = N*max;
		low = -1;
		while(low<high-1)
		{
			mid = (low+high)/2;
	//		cout<<mid<<' '<<N<<endl;
			if(judge(mid,N))
				high = mid;
			else
				low = mid;
		}
	//	cout<<high<<endl;
		long long count=N;
		if(high!=0){
			for(i=0;i<B;i++){
				count-=high/arr[i]+1;
				if(high%arr[i]==0) count++;
			}
		}
		
		for(i=0;i<B;i++)
		{
			if(high%arr[i]==0) count--;
			if(count==0) break;
		}
		cout<<"Case #"<<t<<": "<<i+1<<endl;
				

	}
	return 0;
}
