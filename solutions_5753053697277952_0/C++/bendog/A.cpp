#include<iostream>
#include<set>
#include<queue>
#include<cstdio>
using namespace std;
int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("Aout.txt","w",stdout);
    int cas,n,tmp,tot;
    cin>>cas;

for(int q=1;q<=cas;q++ ){
        cin>>n;
        tot = 0;
        priority_queue< pair<int,char> > pq;
    for(int i = 0 ;i<n;i++){
        cin>>tmp;
        tot+=tmp;
        pq.push(make_pair(tmp,i+'A'));
    }
     cout<<"Case #"<<q<<":";
    while(pq.size()){
            pair<int,char> p1,p2;
        p1 = pq.top(); pq.pop();
        p2 = pq.top(); pq.pop();
        if(p1.first > p2.first){
            cout<<' '<<p1.second;
            p1.first--;tot--;
            if(p1.first)pq.push(p1);
            pq.push(p2);
        }
        else{
            if(pq.size()){
                cout<<' '<<p1.second;
                p1.first--;
                if(p1.first)pq.push(p1);
                pq.push(p2);
            }
            else{
                cout<<' '<<p1.second<<p2.second;
                p1.first--;p2.first--;tot-=2;
                if(p1.first)pq.push(p1);
                if(p2.first)pq.push(p2);
            }
        }
    }
    cout<<endl;

}
    return 0;
}
