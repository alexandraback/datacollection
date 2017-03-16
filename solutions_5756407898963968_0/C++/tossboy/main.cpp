#include <iostream>
#include <vector>
using namespace std;

#define M 10
int m=4, vis[100],row;

void getCard(){
    for(int i=1; i<=m; i++)
        for(int j=1; j<=m; j++){
            int v; cin>>v;
            if(i==row)
                vis[v]++;
        }
}

int main(int argc, const char * argv[])
{
    int nCase; cin>>nCase;
    for(int ca=1; ca<=nCase; ca++){
        memset(vis, 0, sizeof(vis));
        for(int i=0; i<2; i++){
            cin>>row;
            getCard();
        }
        vector<int> res;
        for(int i=1; i<=16; i++)
            if(vis[i]==2)
                res.push_back(i);
        
        cout<<"Case #"<<ca<<": ";
        if(res.size()==1)
            cout<<res[0];
        else if(res.size()>1)
            cout<<"Bad magician!";
        else
            cout<<"Volunteer cheated!";
        cout<<endl;
    }
    return 0;
}

