#include <bits/stdc++.h>

#define fi(a,b,c) for(int a=b; a<=c; a++)
#define fd(a,b,c) for(int a=b; a>=c; a--)
#define fii(a,b,c) for(int a=b; a<c; a++)
#define pb push_back
#define mp make_pair
#define ft first
#define sc second

using namespace std;

const int N = 10009;

struct node {int cnt, pos;} a[N];

int n;

int tcase;

bool cmp (node i, node j) {
    return i.cnt < j.cnt;
}

int main()
{
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    cin >> tcase;
    fi(t, 1, tcase) {
        printf("Case #%d: ", t);
        cin >> n;
        fi(i, 1, n) {
            cin >> a[i].cnt;
            a[i].pos = i;
        }
        sort (a+1, a+n + 1, cmp);
        if (n== 2) {
            fi(i, 1, a[1].cnt) cout <<"AB ";
            } else {
            fd(i, n, 2) {
                while (a[i].cnt > a[i-1].cnt) {
                    fi(j, i, n) {
                        cout <<(char)(a[j].pos + 'A' -1)<<' ';
                        a[j].cnt --;
                    }
                }
            }
            while (a[1].cnt > 1) {
                fi(j, 1, n) cout <<(char)(a[j].pos + 'A' -1) <<' ';
                a[1].cnt --;
            }
            fi(j, 3, n) cout <<(char)(a[j].pos+ 'A' -1) <<' ';
            cout <<(char)(a[1].pos + 'A' -1) <<(char)(a[2].pos + 'A' -1)<< ' ';


        }
        cout <<endl;
    }

}
