#include<bits/stdc++.h>
using namespace std;

priority_queue<pair<int,int> >Heap;
int n,sum,ntest,p;

main(){
    freopen("test.txt","w",stdout);
    cin>>ntest;
    for (int test=1;test<=ntest;test++) {
        cout<<"Case #"<<test<<": ";
        while(!Heap.empty()) Heap.pop();
        sum=0;
        cin>>n;
        for (int i='A';i-'A'<n;i++){
            cin>>p;
            Heap.push(make_pair(p,i));
            sum+=p;
        }
        Heap.push(make_pair(1,0));
        while(sum){
            pair<int,int> a=Heap.top(),b,c;
            Heap.pop();
            b=Heap.top();
            Heap.pop();
            if (a.first*2 > sum) cout<<"########";
            //printf("a:%d%c, b:%d%c, sum=%d\n",a.first,a.second,b.first,b.second,sum);

            sum-=2;
            if (a.first > b.first && (b.first*2<=sum||b.second==0)){
                cout<<(char)a.second<<(char)a.second<<" ";
                a.first-=2;
            } else{
                c=Heap.empty()?make_pair(0,0):Heap.top();
                if (c.second==0) c.first=0;
                if (b.second!=0 && c.first*2<=sum){
                    cout<<(char)a.second<<(char)b.second<<" ";
                    a.first--;
                    b.first--;
                } else {
                    cout<<(char)a.second<<" ";
                    a.first--;
                    sum++;
                }
            }
            if (a.first) Heap.push(a);
            if (b.first) Heap.push(b);
        }
        cout<<endl;
    }
}
