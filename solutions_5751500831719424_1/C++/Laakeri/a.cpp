#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

int main(){
    freopen ("out.out","w",stdout);
    int tcs;
    cin>>tcs;
    for (int tc=1;tc<=tcs;tc++){
        int n;
        cin>>n;
        vector<char> cs[101];
        vector<int> ns[101];
        cout <<"Case #"<<tc<<": ";
        for (int i=0;i<n;i++){
            char nc=0;
            int nn=0;
            string s;
            cin>>s;
            for (char c:s){
                if (c!=nc){
                    if (nc!=0){
                        cs[i].push_back(nc);
                        ns[i].push_back(nn);
                        if (nn==0) cout <<"ERROR"<<endl;
                    }
                    nc=c;
                    nn=0;
                }
                nn++;
            }
            cs[i].push_back(nc);
            ns[i].push_back(nn);
        }
        int f=0;
        for (int i=1;i<n;i++){
            if (cs[i].size()!=cs[0].size()){
                f=1;
                break;
            }
            for (int ii=0;ii<cs[0].size();ii++){
                if (cs[i][ii]!=cs[0][ii]){
                    f=1;
                    break;
                }
            }
        }
        if (f) {
            cout <<"Fegla Won"<<endl;
            continue;
        }
        int v=0;
        for (int ii=0;ii<ns[0].size();ii++){
            int mic=99999;
            for (int p=1;p<=100;p++){
                int thc=0;
                for (int i=0;i<n;i++){
                    thc+=abs(ns[i][ii]-p);
                }
                mic=min(mic,thc);
            }
            v+=mic;
        }

        cout <<v<<endl;
    }
}
