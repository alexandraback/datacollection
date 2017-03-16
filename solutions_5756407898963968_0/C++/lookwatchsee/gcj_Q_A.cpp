#include <vector>
#include <iostream>
#include <string>
#include <queue>
#include <map>
#include <set>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
int first[4][4];
int second[4][4];
int x;
int y;
int main(int argc, char* argv[]) {
    int T;
    cin>>T;
    for (int t=1;t<=T;++t) {
        cout<<"Case #"<<t<<": ";
        cin>>x;
        x--;
        for (int i=0;i<4;++i) {
            for (int j=0;j<4;++j) {
                int a;
                cin>>a;
                first[i][j]=a;
            }
        }
        cin>>y;
        y--;
        for (int i=0;i<4;++i) {
            for (int j=0;j<4;++j) {
                int a;
                cin>>a;
                second[i][j]=a;
            }
        }
        //solve
        int cnt=0;
        int last=-1;
        for (int j=0;j<4;++j) {
            for (int k=0;k<4;++k) {
                if (first[x][j]==second[y][k]) {
                    last=first[x][j];
                    cnt++;
                }
            }
        }
        if (cnt==1) {
            cout<<last<<endl;
        } else if (cnt==0) {
            cout<<"Volunteer cheated!"<<endl;
        } else {
            cout<<"Bad magician!"<<endl;
        }
    }
    return 0;
}
