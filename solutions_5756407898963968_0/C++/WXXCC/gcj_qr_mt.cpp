#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
#include<set>
#include<map>
#include<stack>
#include<cstdlib>
#include<bitset>
using namespace std;

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int T;
    cin>>T;
    int cas = 1;
    while(T --){
        vector<bool> firrow(false,20);
        vector<vector<int> > cardsfirrow(4, vector<int>(0));
        vector<vector<int> > cardssecdrow(4, vector<int>(0));
        int cntsecdrow = 0, targ = 0;
        int firrownum = 0, secdrownum = 0;
        int inp;
        cin>>firrownum;
        for(int i = 0; i < 20; i ++)
            firrow[i] = false;
        for(int i = 0; i < 4; i ++){
            for(int j = 0; j < 4; j ++){
                cin>>inp;
                cardsfirrow[i].push_back(inp);;
            }
        }
        for(int i = 0; i < 4; i ++){
            firrow[cardsfirrow[firrownum - 1][i]] = true;
     //       cout<<cardsfirrow[firrownum - 1][i]<<" ";
        }
  //      cout<<endl;
   //     for(int i = 0; i < 20; i ++){
   //         if(firrow[i])
  //              cout<<i<<" ";
   //     }
   //     cout<<endl;
        cin>>secdrownum;
     //   cout<<secdrownum<<endl;
        for(int i = 0; i < 4; i ++){
            for(int j = 0; j < 4; j ++){
                cin>>inp;
                cardssecdrow[i].push_back(inp);
            }
        }
        for(int i = 0; i < 4; i ++){
        //    cout<<cardssecdrow[secdrownum - 1][i]<<" ";
            if(firrow[cardssecdrow[secdrownum - 1][i]] == true){
                cntsecdrow ++;
                targ = cardssecdrow[secdrownum - 1][i];
            }
        }
     //   cout<<endl;
   //     cout<<cntsecdrow<<endl;
        cout<<"Case #"<<cas<<": ";
        if(cntsecdrow == 1)
            cout<<targ<<endl;
        else if(cntsecdrow > 1)
            cout<<"Bad magician!"<<endl;
        else if(cntsecdrow == 0)
            cout<<"Volunteer cheated!"<<endl;
        cas ++;
    }
    return 0;
}
