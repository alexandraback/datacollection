#include<iostream>
#include<cstdio>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<iomanip>
#include<algorithm>
#include<cmath>
#include<string>





using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vi> wi;

struct p{
  int n;
  char a;
};

bool operator<(const p &a, const p &b){
  if (a.n<b.n)
    return 1;
  if (b.n<a.n)
    return 0;
  return (a.a<b.a);
}



using namespace std;


int main(){
  int T; cin>>T;
  for (int tc=1; tc<=T; ++tc){
    cout<<"Case #"<<tc<<": ";
    int n; cin>>n;
    vector<int> v(n,0);
    for (int i=0; i<n; ++i)
      cin>>v[i];
    priority_queue<p> q=priority_queue<p>();
    p pi;
    for (int i=0; i<n; ++i){
      pi.n=v[i];
      pi.a='A'+i;
      q.push(pi);
    }
    while(q.size()>0){
      pi=q.top();
      q.pop();
      
      if (q.size()==1){
	p pi2=q.top();
	q.pop();
	for (int i=0; i<pi.n; ++i)
	  cout<<pi.a<<pi2.a<<" ";
	break;
      }
      cout<<pi.a<<" ";
      pi.n-=1;
      if (pi.n>0)
	q.push(pi);
    }
    cout<<endl;






  }



  return 0;
}
