#include <bits/stdc++.h>
using namespace std;

int main()
{
  freopen("in.in","r",stdin);
  freopen("out.out","w",stdout);
  
  int TC;
  cin>>TC;
  for(int test_case=1;test_case<=TC;test_case++){
	 
	  int n;
	  cin>>n;
	  string s,t;
	  cin>>s>>t;
	  int l1=s.length();
	  int l2=t.length();
	  
	  vector<char>t1,t2;
	  vector<int> c1,c2;
	  int i=0;
	  while(i<l1)
	  {
		  char p=s[i];
		  int j=i+1;
		  int c=1;
		  while(j<l1 && s[j]==p)
		  {
			  c++;
			  j++;
		  }  
		  
			  t1.push_back(p);
			  c1.push_back(c);
			 
		  i=j;
	      
			  
	  }
	  i=0;
	  while(i<l2)
	  {
		  char p=t[i];
		  int j=i+1;
		  int c=1;
		  while(j<l2 && t[j]==p)
		  {
			  c++;
			  j++;
		  }  
		  
			  t2.push_back(p);
			  c2.push_back(c);
			 
		  i=j;
	      
			  
	  }
	  
	  printf("Case #%d: ",test_case);;
	  if(t1!=t2)
	  {
		  cout<<"Fegla Won"<<endl;
		  continue;
	  }
	  else
	  {
		  int ans=0;
		  for(int i=0;i<t1.size();i++)
		  {
			  ans+= abs(c1[i]-c2[i]);
		  }
		  cout<<ans<<endl;
	  }
	  
	 }	
  return 0;
}
