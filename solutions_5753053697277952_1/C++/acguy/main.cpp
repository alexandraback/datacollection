#include<iostream>
#include<queue>
using namespace std;
int P[27];
int main(void){
  int T;
  cin>>T;
  for(int Ti=1;Ti<=T;Ti++){
    cout<<"Case #"<<Ti<<": ";
    priority_queue< pair<int,char> > pq;
    int N;
    cin>>N;
    for(int i = 0;i<N;i++){
      int tmp;
      cin>>tmp;
      pq.push(make_pair(tmp,(char)('A'+i)));
    }

    while(pq.top().first>0){
      priority_queue<pair<int,char> > tmp = pq;
      /*      cout<<endl;
      while(!tmp.empty()){
          cout<<tmp.top().second<<" = "<<tmp.top().first<<endl;
          tmp.pop();
          }*/


      pair<int,char> a,b,c,d;
      a = pq.top();
      pq.pop();

      b = pq.top();
      pq.pop();

      if(!pq.empty()){
        c = pq.top();
        pq.pop();

      }else{
        c = make_pair(0,'a');
      }
      if(!pq.empty()){
        d = pq.top();
        pq.pop();

      }else{
        d = make_pair(0,'a');
      }
      if((a.first+b.first+c.first) == 3 && d.first<=0){
        a.first--;
        pq.push(a);
        pq.push(b);
        pq.push(c);
        pq.push(d);
        cout<<a.second<<" ";
      }else{
        a.first--;
        pq.push(a);
        b.first--;
        pq.push(b);
        pq.push(c);
        pq.push(d);
        cout<<a.second<<b.second<<" ";
      }
        
    }
    cout<<endl;
      
    
    
  }
  return 0;
}
