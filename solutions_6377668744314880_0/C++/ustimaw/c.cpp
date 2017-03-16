#include<iostream>
#include<utility>
#include<algorithm>
#include<vector>

using namespace std;

typedef pair<long long,long long> P;

P operator-(P a,const P &b){
  a.first-=b.first;
  a.second-=b.second;
  return a;
}

bool cmp_x(const P &a,const P &b){
  return a<b;
}

long long det(const P &a,const P &b){
  return a.first*b.second-a.second*b.first;
}

vector<P> convex_hull(vector<P> ps){
  int n=ps.size();
  sort(begin(ps),end(ps),cmp_x);
  int k=0;
  vector<P> qs(ps.size()*2);
  for(int i=0;i<n;i++){
    while(k>1&&det(qs[k-1]-qs[k-2],ps[i]-qs[k-1])<0)k--;
    qs[k++]=ps[i];
  }
  for(int i=n-2,t=k;i>=0;i--){
    while(k>t&&det(qs[k-1]-qs[k-2],ps[i]-qs[k-1])<0)k--;
    qs[k++]=ps[i];
  }
  qs.resize(k-1);
  return qs;
}

int main(){
  int T;
  cin>>T;
  for(int c=1;c<=T;c++){
    int N;
    cin>>N;
    P p[15];
    for(int i=0;i<N;i++){
      long long x,y;
      cin>>x>>y;
      p[i]=P(x,y);
    }
    int nt[15]={};
    for(int i=0;i<1<<N;i++){
      vector<P> v;
      for(int j=0;j<N;j++){
	if(i>>j&1){
	  v.push_back(p[j]);
	}
      }
      if(v.size()<=2){
	for(int j=0;j<N;j++){
	  if(i>>j&1){
	    nt[j]=max<int>(nt[j],v.size());
	  }
	}
      }else{
	auto qs=convex_hull(v);
	for(int j=0;j<N;j++){
	  if(find(begin(qs),end(qs),p[j])!=end(qs)){
	    nt[j]=max<int>(nt[j],v.size());
	  }
	}
      }
    }
    cout<<"Case #"<<c<<":"<<endl;
    for(int i=0;i<N;i++){
      cout<<N-nt[i]<<endl;
    }
  }
}

