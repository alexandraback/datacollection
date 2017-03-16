#include<bits/stdc++.h>
long long int read_int(){
	char r;
	bool start=false,neg=false;
	long long int ret=0;
	while(true){
		r=getchar();
		if((r-'0'<0 || r-'0'>9) && r!='-' && !start){
			continue;
		}
		if((r-'0'<0 || r-'0'>9) && r!='-' && start){
			break;
		}
		if(start)ret*=10;
		start=true;
		if(r=='-')neg=true;
		else ret+=r-'0';
	}
	if(!neg)
		return ret;
	else
		return -ret;
}
using namespace std;
struct bolol {
    long long tuu,ii;
    bolol() {}
    bolol(long long _tuu,long long _ii) {
        tuu=_tuu,ii=_ii;
    }
    bool operator<(const bolol&p)const {
        return (tuu>p.tuu || (tuu==p.tuu && ii>p.ii));
    }
};
int main() {
    freopen("abc.txt","r",stdin);
    freopen("ans.txt","w",stdout);
    long  long int t;
    t=read_int();
    for(int z=1; z<=t; z++) {
        int b,n,x,y=-1,maxi=1,gcd;
        b=read_int();
        n=read_int();
        priority_queue<bolol>q;
        long long int m[b+1];
        vector<int>v;
        for(int i=0; i<b; i++) {
            cin>>x;
            q.push(bolol(x,i+1));
            v.push_back(i+1);
            m[i+1]=x;
            maxi=(maxi*x)/(__gcd(maxi,x));
        }
        int ii=0;
        while(ii<=maxi) {
            bolol w=q.top();
            //cout<<w.ii<<endl;
            q.pop();
            v.push_back(w.ii);
            w.tuu+=m[w.ii];
            q.push(w);
            ii=w.tuu;//-m[w.ii];
            /*while(q.top().tuu==maxi) {
                //cout<<"ok\n";
                v.push_back(q.top().ii);
                bolol r=q.top();
                q.pop();
                r.tuu+=m[r.ii];
                q.push(r);
            }*/
        }
        v.pop_back();
        int sz=v.size();
        /*cout<<sz<<endl;
        for(int i=0;i<sz;i++){
            cout<<v[i]<<" ";
        }cout<<endl;*/
        n--;
        n%=sz;
        cout<<"Case #"<<z<<": "<<v[n]<<"\n";
    }
    return 0;
}
