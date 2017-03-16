#include <iostream>
#include <vector>
#include <queue>

using namespace std;

template <class T, class S, class C>
S& Container(priority_queue<T, S, C>& q) {
    struct HackedQueue : private priority_queue<T, S, C> {
        static S& Container(priority_queue<T, S, C>& q) {
            return q.*&HackedQueue::c;
        }
    };
    return HackedQueue::Container(q);
}

struct Barber
{
    int wait;
    int idx;

    bool operator<(const Barber &other) const
    {
        if(wait > other.wait)
            return true;
        else if(wait < other.wait)
            return false;
        return idx > other.idx;
    }
};

long long gcd(long long a, long long b)
{
    while(true)
    {
        if(a == 0) return b;
        b %= a;
        if(b == 0) return a;
        a %= b;
    }
}

long long lcm(long long a, long long b)
{
    long long denom = gcd(a,b);
    if(denom == 0) return 0;
    else
        return a/denom * b;
}

void doTest()
{
    int b, n;
    cin >> b >> n;
    vector<int> mk;

    for(int i=0; i<b; i++)
    {
        int tmp;
        cin >> tmp;
        mk.push_back(tmp);
    }

    int tick=0;
    priority_queue<Barber> waits;
    for(int i=0; i<b; i++)
    {
        Barber b;
        b.wait = 0;
        b.idx = i;
        waits.push(b);
    }

    long long totlcm = mk[0];
    for(int i=1; i<b; i++)
        totlcm = lcm(totlcm, mk[i]);

    int nchunk = 0;
    for(int i=0; i<b; i++)
        nchunk += totlcm/mk[i];

    n = 1 + ((n-1) % nchunk);

    int last = -1;

    while(n>0)
    {
        Barber next = waits.top();
        waits.pop();
        int wait = next.wait;
        tick += wait;
        vector<Barber> &inner = Container(waits);
        for(vector<Barber>::iterator it = inner.begin(); it != inner.end(); ++it)
            it->wait -= wait;
        next.wait = mk[next.idx];
        waits.push(next);
        last = next.idx;
        n--;
    }
    cout << last+1 << endl;
}


int main()
{
    int ncases;
    cin >> ncases;
    for(int i=0; i<ncases; i++)
    {
        std::cout << "Case #" << i+1 << ": ";
        doTest();
    }
}
