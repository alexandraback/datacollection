#include <iostream>

using namespace std;

int main() {
    int n, t;
    int ans1, ans2;
    int num[1002];
    int cnt = 0;
    int i, j;
    t = 1;
    cin>>n;
    int rate;
    int maxnum = -1;
    while (t<=n) {
        cin>>cnt;
        for (i=0; i<cnt; i++)
            cin>>num[i];
        ans1 = 0;
        for (i=1; i<cnt; i++) {
            if (num[i] < num[i-1]) ans1+=num[i-1]-num[i];
        }
        maxnum = -1;
        for (i=1; i<cnt; i++) {
            if (maxnum < (num[i-1]-num[i]))
                    maxnum = num[i-1]-num[i];
        }
        ans2 = 0;
        for (i=0; i<cnt-1; i++) {
            if (maxnum > num[i])
                ans2+=num[i];
            else
                ans2+=maxnum;
        }

        cout<<"Case #"<<t<<": "<<ans1<<" "<<ans2<<endl;
        t++;
    }
    return 0;
}
