#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int main() {
    freopen("A-small-attempt0.in","r",stdin);
    freopen("output1.txt","w",stdout);
    long totcase;
    cin >> totcase;
    for (long nowcase=0;nowcase<totcase;nowcase++) {
        long n, mush[1000];
        cin >> n;
        long ans1=0,ans2=0,max=0;
        for (long i=0;i<n;i++) {
            cin >> mush[i];
            if (i>0) {
                if (mush[i]<mush[i-1]) {
                    long c=mush[i-1]-mush[i];
                    ans1+=c;
                    if (c>max) max=c;
                }
            }
            
        }
        for (long i=0;i<n-1;i++) {
            if (mush[i]>max) ans2+=max; else ans2+=mush[i];
        }
        cout << "Case #"<<nowcase+1<<": " << ans1 <<" "<<ans2 << endl;
    }
    
}