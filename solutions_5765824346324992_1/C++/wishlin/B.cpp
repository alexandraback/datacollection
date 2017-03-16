#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

void openfile(int val) {
    FILE *fin=0, *fout=0;
    if (val==0) {
        fin = freopen("in.txt", "r", stdin);
	    fout = freopen("o.txt", "w", stdout);
    }
    else if (val==1) {
        fin = freopen("B-small-attempt0.in", "r", stdin);
	    fout = freopen("s.txt", "w", stdout);
    }
    else if (val==2) {
        fin = freopen("B-large.in", "r", stdin);
	    fout = freopen("L.txt", "w", stdout);
    }
    if (!fin||!fout) exit(0);
}

long long gcdd(long long x, long long y) {
    if (x%y==0) return y;
    else return gcdd(y, x%y);
}

long long cas, len, arr[1024], arr2[1024], N, res, gcx, bar;
vector<long long> order;

long long find_bar() {
    long long minn=arr2[0], mid=0;

    for (long long i=0; i<len; ++i) {
        if (!arr2[i]) {arr2[i]+=arr[i]; return i;}
        if (arr2[i]<minn) {minn=arr2[i]; mid=i;}
    }
    for (long long i=0; i<len; ++i)
        if (arr2[i]!=minn) {arr2[mid]+=arr[mid]; return mid;}
    return -1;
}

int main() {
    openfile(2); cin>>cas;

    for (long long k=1; k<=cas; ++k) {
        cin>>len>>N; res=0;
        order.clear();
        for (long long i=0; i<len; ++i) {
            cin>>arr[i];
            if (!i) gcx=arr[i];
            else gcx=gcdd(gcx,arr[i]);
        }
        for (long long i=0; i<len; ++i) {
            arr[i]/=gcx; arr2[i]=0;
        }

        while (1) {
            bar=find_bar();
            if (bar>=0) order.push_back(bar);
            else break;
        }
        //for (int i=0; i<order.size(); ++i) cout<<order[i]<<" "; cout<<"\n";
        res = order[(N-1)%order.size()];
        cout<<"Case #"<<k<<": "<<res+1<<"\n";
    }
	return 0;
}
