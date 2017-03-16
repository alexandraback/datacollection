#include <bits/stdc++.h>

using namespace std;

#define EPS 1e-7
double ABS(double a){
    if(a>0)
        return a;
    return -a;
}

int main() {
    freopen("/home/mars/Documents/in.in","r",stdin);
    freopen("/home/mars/Documents/A.out","w",stdout);
    int T; scanf("%d", &T);
    for(int z=1;z<T+1;++z) {
        int n;
        cin >> n;
        vector<int> v(n);
        vector<pair<double,char> > per(n);
        int tot=0;
        for(int i=0;i<n;++i){
            cin >> v[i];
            tot+=v[i];
        }
        for(int i=0;i<n;++i){
            per[i].first=v[i]*1.0/tot;
            per[i].second='A'+i;
        }
        cout << "Case #" << z << ":";
        int ind=n-1;
        while(tot){
            sort(per.rbegin(),per.rend());
            /*
            cout << endl;
            cout << ind << endl;
            for(int i=0;i<n;++i){
                cout << per[i].first << " ";
            }
            cout << endl;
            for(int i=0;i<n;++i){
                cout << v[i] << " ";
            }
            cout << endl;
            */
            if(tot==3 && ind==2){
                cout << " " << per[0].second << " " << per[1].second << per[2].second;
                tot-=3;
                break;
            }
            //cout << tot << endl;
            if(ABS(per[0].first-per[1].first)<EPS){
                v[per[0].second-'A']--;
                v[per[1].second-'A']--;
                tot-=2;
                for(int i=0;i<n;++i){
                    per[i].first=v[per[i].second-'A']*1.0/tot;
                    if(v[i]==0){
                        ind--;
                    }
                }
                cout <<  " " << per[0].second << per[1].second;
            }else{

                v[per[0].second-'A']-=2;
                tot-=2;
                for(int i=0;i<n;++i){
                    per[i].first=v[per[i].second-'A']*1.0/tot;
                    if(v[i]==0){
                        ind--;
                    }
                }
                cout <<  " " << per[0].second << per[0].second;
            }
        }
        cout << '\n';

    }
}
