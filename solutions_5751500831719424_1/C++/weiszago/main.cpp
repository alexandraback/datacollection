#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int t;
int n;
string s[200];

int v[200][200];

int main()
{
    ifstream be("A-large.in");
    FILE *out = fopen("a.out", "w");
    be >> t;
    for (int ttt=1;ttt<=t;ttt++) {
        be >> n;
        for (int i=1;i<=n;i++) {
            be >> s[i];
        }

        s[0]="";
        s[0]+=s[1][0];
        for (int i=1;i<s[1].size();i++) {
            if (s[1][i]!=s[1][i-1]) s[0]+=s[1][i];
        }

        bool b=false;
        for (int j=2;j<=n;j++) {
            string st="";
            st+=s[j][0];
            for (int i=1;i<s[j].size();i++) {
                if (s[j][i]!=s[j][i-1]) st+=s[j][i];
            }
            if (st!=s[0]) {
                b=true;
            }
        }

        if (b) {
            fprintf(out, "Case #%d: Fegla Won\n", ttt);
        }
        else {
            for (int i=1;i<=n;i++) {
                int k=0;
                int l=0;
                while (k<s[i].size()) {
                    l++;
                    k++;
                    v[l][i]=1;
                    while (k<s[i].size() && s[i][k]==s[i][k-1]) {
                        k++;
                        v[l][i]++;
                    }
                }
            }

            for (int j=1;j<=s[0].size();j++) {
                sort(v[j]+1, v[j]+n+1);
            }

            int sum=0;

            for (int j=1;j<=s[0].size();j++) {
                for (int i=1;i<=n;i++) {
                    sum+=abs(v[j][i]-v[j][(n+1)/2]);
                }
            }
            fprintf(out, "Case #%d: %d\n", ttt, sum);
        }
    }
    fclose(out);
    return 0;
}
