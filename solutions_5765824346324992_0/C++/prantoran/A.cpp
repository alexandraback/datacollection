#include<bits/stdc++.h>
#define ll long long
#define sz 1111
using namespace std;

ll gcd(ll a,ll b){
    if(!a)return b;
    return gcd(b%a,a);
}


struct item{
    ll id,time;
    bool operator<( const item& aa ) const {
        if(time == aa.time ) {
            return id > aa.id;
        }
        return time > aa.time;
    }
}tmp;

ll t,n,b,a[sz],ans1,ans2,lcm,mxm,counter,bb[11111111],oni,lau;
priority_queue<item> q;
bool f1,check[sz];


int main(){
    #ifndef ONLINE_JUDGE
        freopen("B-small-attempt1.in","r",stdin);
    #endif // ONLINE_JUDGE
    ofstream fout ("output.txt");

    cin>>t;
    //cout<<"t:"<<t<<endl;
    for( ll ca = 1; ca <= t; ca++ ) {

        q = priority_queue<item>();


        cin>>b>>n;
        lcm=1;

        for( ll i = 0; i < b; i++ ) {

            tmp.id=i;
            tmp.time=0;
            q.push(tmp);

            cin>>a[i];
            lau=lcm*a[i];
            lau/=gcd(lcm,a[i]);
            lcm=lau;

        }

        //cout<<"lau:"<<lau<<endl;




        ans1=0;
        f1=true;
        counter=0;

        while(f1){
            tmp = q.top();
            q.pop();

            ans1 = tmp.id;
            bb[counter]=ans1;

            if(tmp.time>=lcm){
                f1=false;
                continue;
            }




            tmp.time += a[ ans1 ];
            q.push(tmp);

            counter++;
        }

        //cout<<"counter:"<<counter<<"\tn:"<<n<<endl;

        if(n>counter){
            n-=((n-1)/counter)*counter;
        }
        //cout<<"n:"<<n<<endl;

        ans1=bb[n-1];
        fout<<"Case #"<<ca<<": "<<ans1+1<<"\n";


    }

    return 0;
}
