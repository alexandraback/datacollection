#include <iostream>
#define F first
#define S second
#include <algorithm>
#include <vector>
using namespace std;

long long T,TT,n,i,sul;
pair < long long , long long > a[50];
vector < string > ans;
string tmp;

main(){
	
	freopen ("A-small-attempt2.in","r",stdin);
	freopen ("output.txt","w",stdout);
	
	
	cin>>T; TT=T;
	 
	 while (T--){
	 	ans.clear();
	 	sul=0;
	 	
	 	cin>>n;
	 	
	 	for (i=1;i<=n; i++){
			cin>>a[i].F;
			sul += a[i].F;
			a[i].S = i-1;
	 	}
	 	
		 sort(a+1,a+n+1);
	 	
	 	while (true){
	 			
	 		i=n;
	 		if (i==0) break;
	 		
			tmp= "";
			if (i == 1){
				if (a[i].F>1) { sul -= 2; tmp += (char)('A' + a[i].S) ; tmp += (char)('A' + a[i].S); }	else
				 		  	  { sul -= 1; tmp += (char)('A' + a[i].S) ; }
				
				ans.push_back(tmp);
				a[i].F-=2;
				if (a[i].F<0) a[i].F=0; 	
			} else
			if (max(a[i].F-1, a[i-1].F)*2 <= sul-1)
			{
				sul--;
				tmp += (char)('A' + a[i].S);
				ans.push_back(tmp);
				a[i].F--;
			} else
			if (max(a[i].F-2, a[i-1].F)*2 <= sul-2 && a[i].F>1)
			{
				sul-=2;
				tmp += (char)('A' + a[i].S);
				tmp += (char)('A' + a[i].S);
				ans.push_back(tmp);
				a[i].F -= 2;
			} else
			{
				sul-=2;
				tmp += (char)('A' + a[i].S);
				tmp += (char)('A' + a[i-1].S);
				ans.push_back(tmp);
				a[i].F--;
				a[i-1].F--;
			}
			
			while (n>0 && a[n].F == 0) n--;
			
			if (n>0) sort(a+1,a+n+1);
		}
	 	
	 	cout<<"Case #"<<TT-T<<": ";
	 	for (i=0; i<ans.size(); i++)
	 		cout<<ans[i]<<" ";
	 		cout<<endl;
	 	
	 }
	
}
