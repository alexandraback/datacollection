#include<bits/stdc++.h>
#define ll   long long

#define md 1000000007
#define inf 1e18
using namespace std;
pair <int,char> a[100];
int main()
{
	ios_base::sync_with_stdio(0);
   #ifndef ONLINE_JUDGE
            freopen("input.txt","r",stdin);
            freopen("output.txt","w",stdout);    
    #endif
      int test;
      cin>>test;
      
     for(int tst=1;tst<=test;tst++){
     	cout<<"Case #"<<tst<<": ";
     		int n;
     		cin>>n;
     		int tot=0;
     		for(int i=0;i<n;i++){
     			int x;
     			cin>>x;
     			a[i]=make_pair(x,i+'A');
     			tot+=x;
     		}
     		while(tot!=0){
     			sort(a,a+n);
     			
     			int x=min(2,a[n-1].first);
     			if(tot-x-a[n-2].first>=a[n-2].first){
     			for(int i=0;i<x;i++)
     			cout<<a[n-1].second;
     			cout<<" ";
     			a[n-1].first-=x;
     			tot-=x;
     				
     			}
     			else{
     			cout<<a[n-1].second<<a[n-2].second<<" ";
     			a[n-1].first--;
     			a[n-2].first--;
     			tot-=2;
     			}
     		}
     		cout<<endl;
     	
        }
    
    return 0;  
}
