#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<vector>
#include<set>
#include<math.h>
#include<map>
#include<algorithm>
#include<queue>
#include<cstring>
#include<stack>
using namespace std;
typedef pair<int,int> ii;
int main()
{
  freopen("inp.txt","r",stdin);
  freopen("out.txt","w",stdout);
  int t;
   cin>>t;
    int id=1;
    while(t--)
    {
    	 int n;
    	string str[109];
    	vector<ii>V[109];
		 cin>>n;
		  for(int i=0;i<n;i++)
		  {
		   cin>>str[i];
		     int k=str[i].length();
		       char ch=str[i][0];
		       int l=1;
		       for(int j=1;j<k;j++)
		       {
		       	if(ch==str[i][j])
		       	 l++;
		       	 else
		       	 {
		       	 	V[i].push_back(ii(ch,l));
		       	 	l=1;
		       	 	 ch=str[i][j];
		       	 }
		       }
		       if(l>0)
		       	V[i].push_back(ii(ch,l));
	       }
	       
	       
	       int tot=0;
	       
	      
	     
		for(int i=1;i<n;i++)
		{
			int fl=0;
		
			if(V[i].size()==V[0].size())
			{
				
			  for(int j=0;j<V[i].size();j++)
			  {
			  	 if(V[i][j].first==V[0][j].first)
			  	  {
			  	  	continue;			  	  	 
			  	  }
			  
			      else
			      {
			  	    fl=1;
			  	    break;
			      }	
			 }
	       }
			else
			 fl=1;
			 
			 if(fl==1)
			 {
			 //	cout<<i;
			 	cout<<"Case #"<<id<<": Fegla Won\n";
			 	goto S;
			 }
			 
			 
		}
	
	
		for(int i=0;i<V[0].size();i++)
		{
				vector<int>V1;
			int mi=10999,mm=-1;
			for(int j=0;j<n;j++)
			{
			 V1.push_back(V[j][i].second);
			  mi=min(V[j][i].second,mi);
			  	  	  mm=max(V[j][i].second,mm);
		    }
		    
		    int mmi=10999;
		  //  cout<<mi<<" "<<mm;
			 for(int kk=mi;kk<=mm;kk++)
			 {
			 	int ll=0;
			 	for(int kl=0;kl<V1.size();kl++)
			 	 ll+=abs(kk-V1[kl]);
			 //	 cout<<ll;
			 	 mmi=min(mmi,ll);
			 }
			 tot+=mmi;
		}
	cout<<"Case #"<<id<<": "<<tot<<endl;
		S:;
		id++;
		  
    }
  
  return 0;
}
