#include <bits/stdc++.h>

using namespace std;

#define p_b(a,b) a.push_back(b)
#define all(a) (a.begin(),a.end())
#define m_p(a,b) make_pair(a,b)

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

void solve(){
  int n;
  cin>>n;
  vector<int> st[n];
  vi to_sort;
  vector<char> chk[n];
  string s;
  int sol=0,mc=0;
  for(int i=0;i<n;i++){
    cin>>s;
    int l = s.length();
    for(int j=0;j<l;){
      int ct=0;
      int g=j;
      p_b(chk[i],s[j]);
      while(j<l && s[g]==s[j])
	ct++,j++;
      p_b(st[i],ct);
    }
  }

    int ok=1;
    for(int i=1;i<n;i++)
      ok &= chk[i]==chk[0];
    if(!ok){
      cout<<"Fegla Won"<<endl;
      return;
    }

    int ll=st[0].size();
    for(int i=0;i<ll;i++){
      to_sort.clear();
      for(int j=0;j<n;j++)
	p_b(to_sort,st[j][i]);
     // cout<<endl;
      
      sort(to_sort.begin(),to_sort.end());
      if(0)for(int i=0;i<n;i++)
	cout<<to_sort[i]<<endl;
      //cout<<endl;
      for(int i=0;i<n/2;i++)
	sol += to_sort[n/2]-to_sort[i];
      for(int i=n/2+1;i<n;i++)
	sol += to_sort[i]-to_sort[n/2];
    }
  cout<<sol<<endl;
}

int main(){
  int t,prob=1;
  cin>>t;
  while(t--){
    cout<<"Case #"<<prob++<<": ";
    solve();
  }
}
