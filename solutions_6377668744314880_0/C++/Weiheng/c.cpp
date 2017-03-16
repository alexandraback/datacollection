#include <iostream>

using namespace std;
double point[20][2];
int countnum[20][20][2];
int cnt;

int getside(int i, int j, int k) {
    double x1 = point[i][0] - point[j][0];
    double y1 = point[i][1] - point[j][1];
    double x2 = point[k][0] - point[j][0];
    double y2 = point[k][1] - point[j][1];
    double num = x1*y2-x2*y1;
    if (num>-0.000000000001 && num<=0.000000001)
        return 0;
    if (num > 0)
        return 1;
    else 
        return -1;
}

int main() {
    int n, t;
    t = 1;
    cin>>n;
    int i, j, k;
    while (t<=n) {
        cin >> cnt;
        for (i=0; i<cnt; i++) {
            cin>>point[i][0]>>point[i][1];
        }
        for (i=0; i<cnt; i++) {
            for (j=0; j<cnt; j++) {
                if (j == i)continue;
                countnum[i][j][0] = 0;
                countnum[i][j][1] = 0;
                for (k=0; k<cnt; k++) {
                    if (k==i || k==j) continue;
                    int tmp = getside(i, j, k);
                    if (tmp== -1)
                        countnum[i][j][0]++;
                    else if(tmp == 1) 
                        countnum[i][j][1]++;
                }
            }
        }
        cout<<"Case #"<<t<<":"<<endl;
        for (i=0; i<cnt; i++) {
            int minnum = 1000000;
            for (j=0; j<cnt; j++) {
                if (i==j)continue;
                if (countnum[i][j][0] < minnum)
                    minnum = countnum[i][j][0];
                if (countnum[i][j][1] < minnum)
                    minnum = countnum[i][j][1];
            }
            cout<<minnum<<endl;
        }
        t++;
    }
    return 0;
}
