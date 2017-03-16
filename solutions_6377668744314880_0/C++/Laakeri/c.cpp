#include <bits/stdc++.h>
#define X first
#define Y second
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> po;

ll cp(po o, po p1, po p2){
    return (p1.X-o.X)*(p2.Y-o.Y)-(p2.X-o.X)*(p1.Y-o.Y);
}

int main(){
    int tcs;
    cin>>tcs;
    for (int tc=1;tc<=tcs;tc++){
        cout<<"Case #"<<tc<<": ";
        cout<<endl;
        int n;
        cin>>n;
        vector<po> ps(n);
        vector<po> pss(n);
        for (int i=0;i<n;i++){
            cin>>ps[i].X>>ps[i].Y;
            pss[i]=ps[i];
        }
        /*
        sort(ps.begin(), ps.end());
        vector<po> hu;
        for (int i=0;i<n;i++){
            while (hu.size()>=2&&cp(hu[hu.size()-2], hu[hu.size()-1], ps[i])>=0){
                hu.pop_back();
            }
            hu.push_back(ps[i]);
        }
        int t=hu.size()+1;
        for (int i=n-2;i>=0;i--){
            while ((int)hu.size()>=t&&cp(hu[hu.size()-2], hu[hu.size()-1], ps[i])>=0){
                hu.pop_back();
            }
            hu.push_back(ps[i]);
        }
        int hs=hu.size();
        map<po, int> ohu;
        for (auto p:hu){
            ohu[p]=1;
            //cout<<p.X<<" "<<p.Y<<endl;
        }
        */
        for (int i=0;i<n;i++){
            int mi=n-1;
            for (int ii=0;ii<n;ii++){
                if (i!=ii){
                    int f=0;
                    for (int iii=0;iii<n;iii++){
                        if (i!=iii&&ii!=iii){
                            if (cp(pss[ii], pss[i], pss[iii])>0) f++;
                        }
                    }
                    //cout<<i<<" "<<ii<<" "<<f<<endl;
                    mi=min(f, mi);
                }
            }
            cout<<mi<<endl;
        }
    }
}
