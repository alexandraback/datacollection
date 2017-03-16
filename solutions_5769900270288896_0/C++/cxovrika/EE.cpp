#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

vector < int > q[200005];
int ans[200005][5],one,two,i,j,x,y,n,leaf,siz[200005],shv[200005];

void go(int z)
{
	 for (int j=0;j<q[z].size();j++)
	  {
	    go(q[z][j]);
	    siz[z]+=siz[q[z][j]];
	  } 
	  
	  if (q[z].size()==0)
	    {
	    	ans[z][1]=1;
	    	ans[z][2]=1;
	    	leaf++;
	    	siz[z]=1;
	    	return;
		}
		
	  one=1000000000;
	  two=0;
	 for (int j=0;j<q[z].size();j++)
	  {
	     one=min(one, ans[q[z][j]][2]  );
	     two+=ans[q[z][j]][1];
	  }	
	  ans[z][1]=one;
	  ans[z][2]=two;
		
}

void go1(int z)
{
	 for (int j=0;j<q[z].size();j++)
	  go1(q[z][j]);
	  
	  if (q[z].size()==0)
	    {
	    	ans[z][1]=1;
	    	ans[z][2]=1;
	    	return;
		}
		
	  one=000000;
	  two=0;
	 for (int j=0;j<q[z].size();j++)
	  {
	     one+= ans[q[z][j]][2]  ;
	     two=max(two, ans[q[z][j]][1] + siz[z]-siz[q[z][j]]);
	  }	
	  ans[z][1]=one-shv[z]+1;
	  ans[z][2]=two;
		
}


main()
{
   cin>>n;
    
	 for (i=1;i<n;i++)
	  {
	  	 cin>>x>>y;
	  	 shv[x]++;
	  	 q[x].push_back(y);
      }	
	
	 go(1);
	 cout<<leaf-ans[1][1]+1<<endl;
	
	 go1(1);
	 
	  cout<<leaf-ans[1][1]+1<<endl;
	
	
	
}
