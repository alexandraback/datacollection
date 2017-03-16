#include <bits/stdc++.h>

#define REP(i,x) for(int32 i = 0 ; i < (x) ; i++)

//#define DEBUG_MODE
#ifdef DEBUG_MODE
#define print(x) cout << #x << " = " << x << endl
#define debug(x) x
#else
#define print(x)
#define debug(x)
#endif

#define hash_map      unordered_map
#define hash_multimap unordered_multimap
#define hash_set      unordered_set
#define hash_multiset unordered_multiset

using namespace std;

typedef short int int16;
typedef unsigned short int uint16;
typedef int int32;
typedef unsigned int uint32;
typedef long long int64;
typedef unsigned long long uint64;

typedef pair <int, int> PII;
typedef pair <int32, int32> PUU;
typedef pair <int32, int> PUI;
typedef pair <int, int32> PIU;
typedef pair <int64, int64> PLL;
typedef pair <int64, int> PLI;
typedef pair <int, int64> PIL;
typedef pair <int, int32> PIS;
typedef pair <int32, int> PSI;

constexpr int UNDEF = -1;

class Application
{
public:
    inline void Run();
private:
    // Methods
    inline void LoadData();
    inline void Solve();
    inline void Clear();
    // Fields
    int TST;
    int n;
    priority_queue <PII> Q;
};

int main()
{
    ios_base::sync_with_stdio(false);
    Application app;
    app.Run();
}

inline void Application::LoadData()
{
    cin >> n;
    
    int occ;
    REP(i, n)
    {
        cin >> occ;
        Q.push(PII(occ, i));
    }
}

inline void Application::Solve()
{
    PII ev = PII(UNDEF, UNDEF);
    
    cout << "Case #" << TST + 1 <<": "; 
    while(!Q.empty())
    {
        PII it = Q.top();
        Q.pop();
        
        ev.first = it.second;
        --it.first;
        
        if(it.first > 0)
            Q.push(it);
        
        
        
        if(Q.top().first == 1 && Q.size() == 2)
        {
            cout << (char)(ev.first + 'A') << " ";
        }
        else
        {
            ev.second = Q.top().second;
            it = Q.top();
            
            Q.pop();
            --it.first;
            if(it.first > 0)
                Q.push(it);
            
             cout << (char)(ev.first + 'A') << (char)(ev.second + 'A') << " ";
        }

    }
            
        cout << "\n";
}

inline void Application::Clear()
{

}

inline void Application::Run()
{
    uint32 test_number;
    cin >> test_number;

    for(TST = 0; TST <test_number; ++TST)
    {
        LoadData();
        Solve();
        Clear();
    }
}