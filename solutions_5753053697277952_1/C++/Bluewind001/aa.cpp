#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<map>
#include<bitset>
#include<sstream>
#include<queue>
#include<algorithm>
#include<string>
#include<cmath>
using namespace std;

int T,n,all,sum;

struct Node{
    int num;
    char id;
    Node(){num=0; id=' ';}
}a[30];

bool cmp(const Node &aa, const Node &bb){
    return aa.num > bb.num;
}

int main()
{
    freopen("in","r",stdin);
    freopen("outAB","w",stdout);

    cin >> T;
    for(int ii=1; ii<=T; ++ii){
        cin >> n;
        sum=0;
        for(int i=0; i<n; ++i){
            cin >> a[i].num;
            a[i].id= (char)(i+'A');
            sum+=a[i].num;
        }
        cout << "Case #" << ii<<":";
        while(sum>0){
            sort(a,a+n,cmp);
/*
            for(int i=0; i<n; ++i){
                cout << a[i].id <<a[i].num<<endl;
            }
*/
            if(sum==3){
                if(a[2].num!=0){
                    cout << " " << a[0].id ;
                    cout << " " << a[1].id <<a[2].id;
                    sum-=3;
                }
                else{
                    cout << " " << a[0].id;
                    cout << " " << a[0].id << a[1].id;
                    sum-=3;
                }
            }
            else{
                if(a[0].num == a[1].num){
                    cout << " " << a[0].id<<a[1].id;
                    a[0].num--;
                    a[1].num--;
                    sum-=2;
                }
                else{
                    cout<< " " << a[0].id <<a[0].id;
                    a[0].num-=2;
                    sum-=2;
                }
            }
        }
        cout << endl;
    }

    return 0;
}
