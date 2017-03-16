#include <iostream>
using namespace std;

int main() {
    int t;
    cin>>t;
    
    int ans[2];
    int cards[2][4][4];
    for(int ti = 1; ti <= t; ++ti) {
        cout<<"Case #"<<ti<<": ";
        for(int i = 0; i < 2; ++i)
        {
            cin>>ans[i];
            for(int j = 0; j < 4; ++j)
            {
                for(int k = 0; k < 4; ++k)
                {
                    cin>>cards[i][j][k];
                    //cout<<cards[i][j][k]<<" ";
                }
                //cout<<endl;
            }
        }
        int found = 0, num=-1;
        for(int i = 0; i < 4; ++i)
        {
            for(int j = 0; j < 4; ++j)
            {
                if(cards[0][ans[0]-1][i] == cards[1][ans[1]-1][j]) {
                    if(found > 0) {
                        cout<<"Bad magician!";
                        j=4;
                        i=4;
                        num = -1;
                    }
                    else {
                        ++found;
                        num = cards[0][ans[0]-1][i];
                    }
                }
            }
        }
        if(found == 0) {
            cout<<"Volunteer cheated!";
        }
        else if(num >= 0) {
            cout<<num;
        }
        cout<<endl;
    }
}
