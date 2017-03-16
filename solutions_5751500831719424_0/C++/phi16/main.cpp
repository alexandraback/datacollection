#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<queue>
#include<iomanip>
#include<cmath>

int main(){
  int probN;
  std::cin >> probN;
  for(int prob=1;prob<=probN;prob++){
    int n;
    std::cin >> n;
    std::vector<std::string> s(n);
    for(int i=0;i<n;i++)std::cin >> s[i];
    std::string p;
    for(int i=0;i<s[0].size();i++){
      if(p.empty() || s[0][i]!=p[p.size()-1])p+=s[0][i];
    }
    std::vector<std::vector<int> > ps;
    std::vector<int> mn(p.size(),-1),mx(p.size(),-1);
    bool fe=false;
    for(int i=0;i<n;i++){
      std::vector<int> y;
      char c;
      int m=0,r=0;
      for(int j=0;j<s[i].size();j++){
        if(m==0 || c!=s[i][j]){
          if(s[i][j]==p[m]){
            if(j!=0){          
              y.push_back(r);
              if(mx[m-1]==-1 || r>mx[m-1])mx[m-1]=r;
              if(mn[m-1]==-1 || r<mn[m-1])mn[m-1]=r;
            }
            c=s[i][j];
            m++;
            r=0;
          }else{
            fe=true;
            break;
          }
        }
        r++;
      }
      if(p.size()==m){
        y.push_back(r);
        if(mx[m-1]==-1 || r>mx[m-1])mx[m-1]=r;
        if(mn[m-1]==-1 || r<mn[m-1])mn[m-1]=r;
      }else fe=true;
      ps.push_back(y);
      if(fe)break;
    }
    std::cout << "Case #" << prob << ": ";
    if(fe){
      std::cout << "Fegla Won";
    }else{
      int score=0;
      for(int i=0;i<p.size();i++){
        int de=-1;
        for(int j=mn[i];j<=mx[i];j++){
          int pn=0;
          for(int k=0;k<n;k++){
            pn+=abs(ps[k][i]-j);
          }                         
          if(de==-1 || de>pn)de=pn;
        }
        score+=de;
      }
      std::cout << score;
    }
    std::cout << std::endl;
  }
  return 0;
}