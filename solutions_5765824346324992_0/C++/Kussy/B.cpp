#include<iostream>
#include<queue>
using namespace std;

int M[1000+7];
int t;

unsigned int nwd(int x, int y)
{
    if (x == 0)
        return y;
    if (y == 0)
        return x;

    int k=0;
    while(!((x | y) & 1))
    {
        x>>=1; y>>=1;
        k++;
    }

    while (!(x & 1))
    x>>=1;
    do {
        while (!(y & 1))
        y>>=1;
        if (x > y)
            swap(x, y);
        y=y-x;
    } while (y != 0);
    return (x<<k);
}

struct B{
    int n;
    int f;
};

bool operator<(B a, B b) {
    if(a.f != b.f)
        return a.f > b.f;
    else
        return a.n > b. n;
}

priority_queue<B> Q;

int main() {
    ios_base::sync_with_stdio(0);
    int T;
    cin>>T;

    for(int tt = 1; tt<=T; tt++) {
        int b, n, o;
        cin>>b>>n;

        B barber;

        for(int i = 1; i<=b; i++)
        {
            cin>>M[i];
            barber.n = i;
            barber.f = 0;
            Q.push(barber);
        }

        int a = 1;
        long long ab;
        for(int i = 1; i<=b; i++)
        {
            ab = a * M[i];
            ab /= nwd( min(a, M[i]), max(a, M[i]) );
          //  cout<<" "<<ab<<" "<<nwd( min(a, M[i]), max(a, M[i]) )<<endl;
            a = ab;
        }
        long long il = 0;
        for(int i = 1; i<=b; i++)
            il += ab/M[i];

        n%=il;
        if(n==0)
            n+=il;
       // cout<<ab<<" "<<il<<" "<<n<<endl;
        int c = 0;
        while(c < n) {
            c++;
            barber = Q.top();
            if(c == n)
                o=barber.n;
            Q.pop();
            //cout<<" "<<c<<" "<<barber.n<<" "<<barber.f<<" "<<M[ barber.n ]<<endl;
            barber.f += M[ barber.n ];

           // cout<<" "<<Q.top().f<<endl;
            Q.push(barber);
        }
        while(!Q.empty())
            Q.pop();

        cout<<"Case #"<<tt<<": "<<o<<endl;
    }
    return 0;
}
