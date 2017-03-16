#include <iostream>
#include <vector>
#include <queue>

template<class T>
T gcd(T a, T b)
{
    while(b)
        std::swap(a%=b,b);
    return a;
}
template<class T>
T lcm(T a, T b)
{
    return a/gcd(a,b)*b;
}

static auto solve = []()
{
    int B,N; std::cin >> B >> N;
    std::vector<int> M(B);
    for(auto&v:M) std::cin >> v;
    int g=M[0];
    for(int i=1; i<B; ++i) g=lcm(g,M[i]);
    int t=0;
    for(auto v:M) t+= g/v;
    N=std::min(N,N%t+t);
    typedef std::pair<int,int> T;
    std::priority_queue<T,std::vector<T>,std::greater<T>> q;
    for(int i=0; i<B; ++i) q.emplace(0,i);
    int k=0;
    for(int _=0; _<N; ++_)
    {
        int t; std::tie(t,k) = q.top(); q.pop();
        q.emplace(t+M[k],k);
    }
    return k+1;
};

int main()
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);
    int T; std::cin >> T;
    for (int i=1; i<=T; ++i)
        std::cout << "Case #" << i << ": " << solve() << '\n';
}
