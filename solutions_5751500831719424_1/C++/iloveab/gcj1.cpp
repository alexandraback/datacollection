#include <bits/stdc++.h>
using namespace std;


pair<vector<char>,vector<int> > vec(string s)
{
	int l1=s.length();
	int i=0;
	vector<char>t1,t2;
	  vector<int> c1,c2;
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
	  return make_pair(t1,c1);
}
int main()
{
  freopen("in.in","r",stdin);
  freopen("out.out","w",stdout);
  
  int TC;
  cin>>TC;
  for(int test_case=1;test_case<=TC;test_case++){
	 
	  int n;
	  cin>>n;
	  string s[n];
	  for(int i=0;i<n;i++) cin>>s[i];
	  
	  printf("Case #%d: ",test_case);;
	  int f=0;
	  vector<char> o=vec(s[0]).first;
	  for(int i=1;i<n;i++)
	  {
		  if(vec(s[i]).first!=o)
		  {
			  f=1;
			  break;
		  }
	  }
	  if(f==1)
	  {
		  cout<<"Fegla Won"<<endl;
		  continue;
	  }
	  else
	  {
		  vector<int> t[n];
		  for(int i=0;i<n;i++)
		  {
			  t[i]=vec(s[i]).second;
		  }
		  long long  ans=0;
		  for(int i=0;i<o.size();i++)
		  {
			  long long  minc=INT_MAX;
			  for(int j=0;j<=100;j++)
			  {
				  long long  c=0;
				  for(int k=0;k<n;k++)
				  {
					  c+=abs(j-t[k][i]);
				  }
				  minc = min(minc,c);
			  }
			  ans+=minc;
			  
			  
		  }
		  cout<<ans<<endl;
	  }
	  
	 }	
  return 0;
}
