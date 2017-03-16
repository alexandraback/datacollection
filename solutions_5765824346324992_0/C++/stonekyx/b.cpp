#include <iostream>
#include <set>

using namespace std;

class Barber {
public:
    int id;
    int endtime;
    bool operator<(const Barber &o) const {
        if(endtime == o.endtime) {
            return id < o.id;
        }
        return endtime < o.endtime;
    }
};

int gcd(int a, int b)
{
    return b==0?a:gcd(b, a%b);
}

int simulate(int B, int N, int cost[])
{
    int lcm=1;
    for(int i=0; i<B; i++) {
        lcm = lcm*cost[i]/gcd(lcm, cost[i]);
    }
    int lcmCus = 0;
    for(int i=0; i<B; i++) {
        lcmCus += lcm/cost[i];
    }
    N = (N-1)%lcmCus + 1;
    set<Barber> selector;
    for(int i=1; i<=B; i++) {
        Barber b;
        b.id = i;
        b.endtime = 0;
        selector.insert(b);
    }
    for(int i=1; i<=N; i++) {
        Barber b = *selector.begin();
        selector.erase(selector.begin());
        b.endtime += cost[b.id-1];
        selector.insert(b);
        if(i==N) return b.id;
    }
}

int main()
{
    int T, Tcnt=1;
    cin>>T;
    for(; T; T--, Tcnt++) {
        int B, N;
        cin>>B>>N;
        int *cost = new int[B];
        for(int i=0; i<B; i++) {
            cin>>cost[i];
        }
        cout<<"Case #"<<Tcnt<<": "<<simulate(B, N, cost)<<endl;
        delete[] cost;
    }
    return 0;
}

