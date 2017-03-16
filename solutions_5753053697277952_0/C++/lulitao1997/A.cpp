#include <bits/stdc++.h>
using namespace std;


int N;
int P[30];

pair<int,int> find_max() {
    int imax=-1,pos=0;
    for (int i=0;i<N;i++) {
        if (P[i]>imax) {
            imax=P[i];
            pos=i;
        }
    }
    return make_pair(imax,pos);
}

int main () {
    int casenum;
    cin>>casenum;
    for (int casen=1;casen<=casenum;casen++) {
        cin>>N;
        int sum=0;
        for (int i=0;i<N;i++) {
            cin>>P[i];
            sum+=P[i];
        }
        printf("Case #%d:",casen);
        while (sum) {
            auto t1=find_max();
            P[t1.second]--;sum--;
            putchar(' ');
            putchar('A'+t1.second);
            auto t2=find_max();
            P[t2.second]--;sum--;

            auto t3=find_max();
            if (t3.first*2>sum) {
                ++sum;
                ++P[t2.second];
            }
            else {
                putchar('A'+t2.second);
            }
        }
        putchar('\n');
    }


}
