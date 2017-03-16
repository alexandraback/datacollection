#include <iostream>
#include <set>

using namespace std;

class Barber {
public:
    int id;
    int cost;
    long long endtime;
    bool operator<(const Barber &o) const {
        if(endtime-cost == o.endtime-o.cost) {
            return id > o.id;
        }
        return endtime-cost > o.endtime-o.cost;
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

long long canFinish(long long endtime, int B, int cost[])
{
    long long allCus=0;
    for(int i=0; i<B; i++) {
        allCus += (endtime+cost[i])/cost[i];
    }
    return allCus;
}

long long endtime(int B, long long N, int cost[])
{
    long long right = cost[0]*N;
    long long left = 0;
    while(left < right-1) {
        long long mid = (left+right)/2;
        if(canFinish(mid, B, cost)>=N) {
            right = mid;
        } else {
            left = mid;
        }
    }
    return right;
}

int simulateFast(int B, int N, int cost[])
{
    long long right = endtime(B, N, cost);
    long long finish = canFinish(right, B, cost);
    for(int i=B; i>=1; i--) {
        if(right%cost[i-1]==0) {
            if(finish == N) {
                return i;
            }
            finish --;
        }
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
        cout<<"Case #"<<Tcnt<<": "<<simulateFast(B, N, cost)<<endl;
        delete[] cost;
    }
    return 0;
}

