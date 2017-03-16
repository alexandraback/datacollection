#include<iostream>
#include<cstdio>
#include<fstream>

using namespace std;

int main()
{
    freopen("A-small-attempt1.in","r",stdin);
    freopen("output.txt","w",stdout);
    int t;
    cin >> t;
    for(int te=1;te<=t;te++) {
        int a1,a2,x1[4][4],x2[4][4];
        cin >> a1;
        for(int i=0;i<4;i++) for(int j=0;j<4;j++) cin >> x1[i][j];
        cin >> a2;
        for(int i=0;i<4;i++) for(int j=0;j<4;j++) cin >> x2[i][j];

        int ans = 0;
        int xx = 0;
        for(int i=0;i<4;i++)
            for(int j=0;j<4;j++)
                if(x1[a1-1][i] == x2[a2-1][j]) {
                    xx = x1[a1-1][i];
                    ans++;
                    break;
                }

        cout << "Case #" << te << ": ";
        if(ans == 1) cout << xx;
        else if(ans > 1) cout << "Bad magician!";
        else cout << "Volunteer cheated!";
        cout << endl;
    }
}
