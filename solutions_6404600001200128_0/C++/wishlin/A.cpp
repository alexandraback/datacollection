#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

void openfile(int val) {
    FILE *fin=0, *fout=0;
    if (val==0) {
        fin = freopen("in.txt", "r", stdin);
	    fout = freopen("o.txt", "w", stdout);
    }
    else if (val==1) {
        fin = freopen("A-small-attempt0.in", "r", stdin);
	    fout = freopen("s.txt", "w", stdout);
    }
    else if (val==2) {
        fin = freopen("A-large.in", "r", stdin);
	    fout = freopen("L.txt", "w", stdout);
    }
    if (!fin||!fout) exit(0);
}

int main() {
    openfile(1);
    int cas; cin>>cas;
    int len, arr[1024], ans1, ans2, dif, maxx;

    for (int k=1; k<=cas; ++k) {
        cin>>len; ans1=ans2=dif=maxx=0;
        for (int i=0; i<len; ++i) {
            cin>>arr[i];
            if (i && arr[i-1]>arr[i]) {
                dif=arr[i-1]-arr[i];
                if (dif>maxx) maxx=dif;
                ans1+=dif;
            }
        }
        for (int i=1; i<len; ++i) {
            if (arr[i-1]<=maxx) {
                ans2+=arr[i-1];
            }
            else ans2+=maxx;
        }
        printf("Case #%d: %d %d\n", k, ans1, ans2);
    }
	return 0;
}
