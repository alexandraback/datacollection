#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#define mp(a,b) make_pair((a),(b))
#define ff first
#define ss second

using namespace std;

int main(){
  int i,j,k,l,m,n,p,r,s,t;
  int ok;
  char c;
  vector<vector<char> > slova;
  vector<pair<char,int> > rep,test;
  vector<vector<pair<char,int> > > kluc;
  
  scanf("%d",&t);
  
  for(l=1;l<=t;l++){
    scanf("%d",&n);
    
    slova.clear();
    slova.resize(n);
    kluc.resize(n);
    
    for(i=0;i<n;i++){
      c=getchar();
      while(c=='\n'){
	c=getchar();
      }
      while(c!='\n'){
	slova[i].push_back(c);
	c=getchar();
      }
    }
    
    rep.clear();
    p=1;
    for(j=1;j<slova[0].size();j++){
      if(slova[0][j]!=slova[0][j-1]){
	rep.push_back(mp(slova[0][j-1],p));
	p=1;
      }else{
	p++;
      }
    }
    rep.push_back(mp(slova[0][j-1],p));
    
    kluc[0]=rep;
    
    ok=1;
    for(i=1;i<n;i++){
      test.clear();
      p=1;
      for(j=1;j<slova[i].size();j++){
	if(slova[i][j]!=slova[i][j-1]){
	  test.push_back(mp(slova[i][j-1],p));
	  p=1;
	}else{
	  p++;
	}
      }
      test.push_back(mp(slova[i][j-1],p));
      if(test.size()!=rep.size()){
	ok=0;
	break;
      }
      for(j=0;j<rep.size();j++){
	if(test[j].ff!=rep[j].ff){
	  ok=0;
	  break;
	}
      }
      if(!ok){
	break;
      }
      kluc[i]=test;
    }
    
    if(!ok){
      printf("Case #%d: Fegla Won\n",l);
    }else{
      r=0;
      for(j=0;j<rep.size();j++){
	k=0;
	for(i=0;i<n;i++){
	  if(kluc[i][j].ss>k){
	    k=kluc[i][j].ss;
	  }
	}
	m=1234567890;
	for(p=0;p<=k;p++){
	  s=0;
	  for(i=0;i<n;i++){
	    s+=abs(kluc[i][j].ss-p);
	  }
	  if(s<m){
	    m=s;
	  }
	}
	r+=m;
      }
      printf("Case #%d: %d\n",l,r);
    }
    
  }
  
  return 0;
}
