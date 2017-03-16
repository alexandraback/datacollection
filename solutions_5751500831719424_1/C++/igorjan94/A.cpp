#include <bits/stdc++.h>

#define pb push_back
#define ll long long
#define forit(it, r) for (auto it = r.begin(); it != r.end(); it++)
#define forn(i, n) for (int i = 0; i < n; i++)
#define forn1(i, n) for (int i = 1; i < n; i++)
#define fori(n) for (int i = 0; i < n; i++)
#define forj(n) for (int j = 0; j < n; j++)
#define vi vector<int>
#define vll vector<long long>
#define pii pair<int, int>
#ifndef ONLINE_JUDGE
#define lld I64d
#endif
#define FILENAME "input"
#define INF 1000000007

using namespace std;

template <class Head, class... Tail> void writeln(Head head, Tail... tail);
template <class Head, class... Tail> void readln(Head& head, Tail&... tail);
void writeln(){printf("\n");}void readln(){}
struct graph{vector<vector<int>> edges;int n;graph(int);graph(int, int);graph();void createGraph(int);void add_edge(int, int);void add_or_edge(int, int);void writelnMatrix();void writeln();};

///----------------------------------------------------------------------------------------------------------------------------

int n, m, k, ans;
vector<string> s;

void readInput()
{
    ans = 0;
    readln(n);
    s.clear();
    s.resize(n);
    readln(s);
}

void writeOutput()
{
    if (ans == -1)
        writeln("Fegla Won");
    else
        writeln(ans);
}

void solve()
{
    vi cur(n, 0);
    char c;
    for(; cur[0] < s[0].size();)
    {
        c = s[0][cur[0]];
        vi a(n, 0);
        forj(n)
            while (cur[j] < s[j].size() && s[j][cur[j]] == c)
                cur[j]++,
                a[j]++;
        if (*min_element(a.begin(), a.end()) == 0 && *max_element(a.begin(), a.end()) != 0)
        {
            ans = -1;
            return;
        }
        int mn = INF;
        forn1(q, 101)
        {
            int sum = 0;
            forn(z, n)
                sum += abs(a[z] - q);
            mn = min(mn, sum);
        }
        ans += mn;
    }
    fori(n)
        if (cur[i] < s[i].size())
        {
            ans = -1;
            return;
        }
}

void run()
{
    readInput();
    solve();
    writeOutput();
}

int main()
{
    freopen(FILENAME".in", "r", stdin);
    freopen(FILENAME".out", "w", stdout);
    int T;
    readln(T);
    forn(q, T)
        printf("Case #%d: ", q + 1),
        run();
    return 0;
}

























graph::graph(int n){this->n = n;edges.resize(n);int t;fori(n){edges[i].resize(n);forj(n)readln(t),edges[i][j] = t == '1';}}graph::graph(int n, int m){this->n = n;edges.resize(n);int u, v;fori(m)readln(u, v),add_edge(u - 1, v - 1);}void graph::add_edge(int u, int v){edges[u].pb(v);}void graph::add_or_edge(int u, int v){edges[u].pb(v);edges[v].pb(u);}graph::graph(){};void graph::createGraph(int n){edges.resize(n);}void graph::writeln(){fori(n)forj(edges[i].size())::writeln(i, edges[i][j]);}void graph::writelnMatrix(){::writeln(edges);}
void print(double a){printf("%f ", a);}
void print(int a){printf("%d ", a);}
void print(string a){printf("%s ", a.c_str());}
void print(long long a){printf("%lld ", a);}
void print(unsigned long a){printf("%ld ", a);}
void print(char a){printf("%c ", a);}
template<class Type>
void print(vector<Type>& a){for(int i = 0; i < a.size(); ++i)print(a[i]);}
template<class Type>
void print(vector<vector<Type>>& a){for(int i = 0; i < a.size(); ++i)writeln(a[i]);}
void read(double &a){scanf("%lf", &a);}
void read(int &a){scanf("%d", &a);}
void read(string &a){cin>>a;}
void read(long long &a){scanf("%lld", &a);}
void read(char &a){scanf("%c", &a);}
template<class Type>
void read(vector<Type> &a){if (a.size() == 0){int n; read(n); a.resize(n);}for(int i = 0; i < a.size(); ++i)read(a[i]);}
template<class Type>
void read(vector<vector<Type>> &a){for(int i = 0; i < a.size(); ++i)readln(a[i]);}
template <class Head, class... Tail>
void writeln(Head head, Tail... tail){print(head);writeln(tail...);}
template <class Head, class... Tail>
void readln(Head& head, Tail&... tail){read(head);readln(tail...);}
