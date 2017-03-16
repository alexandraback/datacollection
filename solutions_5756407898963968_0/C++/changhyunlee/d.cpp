#include <vector>
#include <iostream>
using namespace std;

int main() {
    int t;
    int ans[2];
    int d[4][4];
    int table[16];

    FILE *fp = fopen("A-small-attempt1.in", "r");
    FILE *out = fopen("out.txt", "w");
    fscanf(fp, "%d", &t);
//    cin >> t;
    for (int l=1; l<=t; l++) {
        fill(table, table+16, 0);
        for (int i=0; i<2; i++) {
            fscanf(fp, "%d", &ans[i]);
//            cin >> ans[i];
            ans[i]--;
            for (int j=0; j<4; j++) {
                for (int k=0; k<4; k++) {
                    fscanf(fp, "%d", &d[j][k]);
//                    cin >> d[j][k];
                }
            }
            for (int k=0; k<4; k++) {
                table[d[ans[i]][k]-1]++;
            }
        }
        int res, cnt;
        res = cnt = 0;
        for (int i=0; i<16; i++) {
            if (table[i]==2) {
                res = i+1;
                cnt++;
            }
        }
//        cout << "Case #" << l << ": ";
        fprintf(out, "Case #%d: ", l);
        if (cnt==0)
            fprintf(out, "Volunteer cheated!\n");
//            cout << "Volunteer cheated!" << endl;
        else if (cnt==1)
            fprintf(out, "%d\n", res);
//            cout << res << endl;
        else if (cnt>=2)
            fprintf(out, "Bad magician!\n");
//            cout << "Bad magician!" << endl;
    }
    return 0;
}
