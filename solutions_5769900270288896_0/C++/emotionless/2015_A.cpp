#include<bits/stdc++.h>

#define xx first
#define yy second
#define all(a) a.begin(), a.end()
#define vsort(v) sort(all(v))
#define UNIQUE(a)  sort(all(a)); a.erase(unique(all(a)), a.end())
#define clr(a,k) memset(a,k,sizeof a)
#define bclr(b) memset(b,false,sizeof b)
#define fr(i, a) for(i = 0; i < a; i++)
#define frr(i,a) for(i = a - 1; i >= 0, i--)
#define LL long long
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define vi vector<int>
#define vll vector<long long>
///***** bit *****///
#define check_bit(a, b) (a&(1<<b))
#define set_bit(a, b) (a|(1<<b))
#define total_bit(a) __builtin_popcount(a)
///***** Input / Output *****///
// IO
#define READ  freopen("C:\\Users\\back_bencher\\Desktop\\A-small-attempt0.IN","r",stdin)
#define WRITE freopen("C:\\Users\\back_bencher\\Desktop\\output.txt","w",stdout)
#define use_cin  ios_base::sync_with_stdio(0); cin.tie(0);


#define s1(a) scanf("%d", &a)
#define s2(a, b) scanf("%d %d", &a, &b)
#define s3(a, b, c) scanf("%d %d %d", &a, &b, &c)
#define p1(a) printf("%d", a)
#define p2(a, b) printf("%d %d", a, b)
#define p3(a, b, c) printf("%d %d %d", a, b, c)


#define MOD 1000000007
#define MAX 10000009



using namespace std;
///******* Template ********///


template <class T> inline T bigmod(T p,T e,T M)
{
    if(e==0)return 1;
    if(e%2==0)
    {
        T t=bigmod(p,e/2,M);
        return (t*t)%M;
    }
    return (bigmod(p,e-1,M)*p)%M;
}
template <class T> inline T gcd(T a,T b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}
template <class T> inline T modinverse(T a,T M)
{
    return bigmod(a,M-2,M);
}


///***** Template ends here *****///
///********************* Code starts here ****************************

int cost[MAX];
int N;
int rev(int a)
{
    stringstream ss;
    ss<<a;
    string str;
    ss>>str;
    int i = 0;
    for(i = 0; i < str.size(); i++)
    {
        if(str[i] != '0')
        {
            break;
        }
    }
    int num = 0;
    for(int j = str.length() - 1; j >= i; j--)
    {
        num = num * 10 + (str[j] - '0');
    }
    return num;
}

bool vis[MAX];

int BFS()
{
    clr(vis, 0);
    queue<pii>Q;
    Q.push(mp(1, 1));

    while(!Q.empty())
    {
        pii top = Q.front();
        Q.pop();

        int cn = top.xx;
        int cc = top.yy;

        if(vis[cn] || cn > 1000000) continue;
//        if(cn == N)
//        {
////            return cc;
//        }
        vis[cn] = 1;
        cost[cn] = cc;

//        cout<<cn<<" "<<cc<<endl;
        Q.push(mp(cn + 1, cc + 1));
        Q.push(mp(rev(cn), cc + 1));
    }



}





int main()
{
//    READ;
//    WRITE;
    int i, j, k;
    FILE *fp;
    fp = fopen("out.txt", "w");
    string str, inp;
    int t, n;
    int cases = 1;
    int num, m;
    int a, b, c;

    cin>>t;
    while(t--)
    {
        int tot = 0;
        cin>>n>>m>>N;
        fprintf(fp, "Case #%d: ", cases++);
        if(n * m == N)
        {
            fprintf(fp, "%d\n", (n - 1)*m + (m - 1)*n);
            continue;
        }
        else if(n * m - N == 1)
        {
            fprintf(fp, "%d\n", (n - 1)*m + (m - 1)*n - 4);
            continue;
        }
        if(m%2)
        {
            int a = m / 2 + 1;
            int b = a - 1;
            tot = a * ((n/2) + n%2) ;
            tot += b * (n/2);
        }
        else
        {
            int a = m/2;
            tot = a * n;
        }
//        cout<<tot<<endl;
        if(N <= tot)
        {
            fprintf(fp, "%d\n", 0);
            continue;
        }
        int rest = N - tot;

        fprintf(fp, "%d\n", rest * 3 - ((n*m)%2 == 0?min(2, rest):0) - 1);





    }










    return 0;
}

/*




*/
