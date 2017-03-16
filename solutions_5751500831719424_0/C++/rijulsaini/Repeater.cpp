#include<iostream>
#include<algorithm>
#include<cstring>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

pair<char,int> p[105][105]; char s[105][105]; int l[105]; int v[105]; int a[105];

int main(){
  ios_base::sync_with_stdio(false);
  int n,i,t,ii,u,j,k,ans,flag,g,h,temp; char temp1;
  cin>>t;
  for(ii=1;ii<=t;ii++){
    cout<<"Case #"<<ii<<": ";
    cin>>n;
    for(i=0;i<n;i++){
      cin>>s[i];
    }
    if(n==1){
      cout<<0<<'\n';
      continue;
    }
    for(i=0;i<n;i++){
      l[i] = strlen(s[i]);
      u = 0;
      for(j=0;j<l[i];j++){
	temp1 = s[i][j];
	k = 0;
	while(j<l[i] && s[i][j] == temp1){
	  j++; k++;
	}
	p[i][u] = mp(temp1,k);
	j--; u++;
      }
      v[i] = u;
    }
    ans = 0;
    temp = v[0]; flag =1;
    for(i=0;i<n && flag;i++){
      if(v[i]!=temp){
	flag = 0; continue;
      }
      for(j=0;j<temp && flag;j++){
	if(p[i][j].ff != p[0][j].ff){
	  flag = 0;
	}
      }
    }
    if(flag == 0){
      cout<<"Fegla Won\n";
      continue;
    }
    for(j=0;j<temp;j++){
      for(i=0;i<n;i++){
	a[i] = p[i][j].ss;
      }
      sort(a, a+n);
      g = a[n/2]; 
      for(i=0;i<n;i++){
	ans += max(g-a[i],a[i]-g);
      }
    }
    cout<<ans<<'\n';
  }
  return 0;
}