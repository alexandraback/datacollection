#include<bits/stdc++.h>
using namespace std;
typedef long long int uli;
const int mx=30;
int p[mx];
int main(){
      freopen("a.in","r",stdin);
      freopen("a.out","w",stdout);
   int t,n;
   scanf("%d",&t);
   for(int tt=1;tt<=t;tt++){
      scanf("%d",&n);
      priority_queue<pair<int,int> >q;
      for(int i=0;i<n;i++){
         scanf("%d",p+i);
         q.push(make_pair(p[i],i));
      }
      vector<string>ans;
      while(q.size()>2){
         int cnt=q.top().first;
         int idx=q.top().second;
         q.pop();
         ans.push_back(string(1,idx+'A'));
         if(cnt-1>0)q.push(make_pair(cnt-1,idx));
      }
      int cnt1=q.top().first, idx1=q.top().second;
      q.pop();
      int cnt2=q.top().first, idx2=q.top().second;
      if(cnt1<cnt2) {
         swap(cnt1,cnt2);
         swap(idx1,idx2);
      }
      for(int i=0;i<cnt1-cnt2;i++){
         ans.push_back(string(1,idx1+'A'));
      }
      for(int i=0;i<cnt2;i++){
         ans.push_back(string(1,idx1+'A')+string(1,idx2+'A'));
      }
      printf("Case #%d:",tt);
      for(int i=0;i<int(ans.size());i++)printf(" %s",ans[i].c_str());
      printf("\n");
   }
   return 0;
}
