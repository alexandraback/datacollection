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
#define READ  freopen("C:\\Users\\emotionless\\Desktop\\uva 13-01-15\\codejam\\B-large.in","r",stdin)
#define WRITE freopen("C:\\Users\\emotionless\\Desktop\\uva 13-01-15\\codejam\\output.txt","w",stdout)
#define use_cin  ios_base::sync_with_stdio(0); cin.tie(0);


#define s1(a) scanf("%d", &a)
#define s2(a, b) scanf("%d %d", &a, &b)
#define s3(a, b, c) scanf("%d %d %d", &a, &b, &c)
#define p1(a) printf("%d", a)
#define p2(a, b) printf("%d %d", a, b)
#define p3(a, b, c) printf("%d %d %d", a, b, c)


#define MOD 1000000007
#define MAX 200009



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

#define YES printf("GABRIEL\n")
#define NO printf("RICHARD\n")

LL B;
LL arr[1001];
LL n;
LL solve()
{
    LL st = 1ll, ed = 1000000000000000000ll, mid;
    LL res = ed;
    while(st <= ed)
    {

        mid = (st + ed)/2;
        LL sum = 0ll;
        for(int i = 1; i <= B; i++)
        {
            sum += mid/arr[i] + (mid%arr[i]?1:0);
        }
        if(sum >= n)
        {
            res = min(res, mid);
            ed = mid - 1;
        }
        else
            st = mid + 1;
    }
    return res;
}




int main()
{
    READ;
    WRITE;
    int i, j;
    int num;
    string tmp;
    int t,m,cases = 1;
    scanf("%d", &t);
    int x;
    string str;
    while(t--)
    {
        cin>>B>>n;
        for(i = 1; i <= B; i++)
            cin>>arr[i];
        LL res = solve();
        vector<int>V;
        V.clear();
//        cout<<res<<endl;
        for(i = 1; i <= B; i++)
        {
            if((res-1ll) % arr[i] == 0)
            {
                V.pb(i);
            }
        }
        res--;
        LL sum = 0ll;
        for(int i = 1; i <= B; i++)
        {
            sum += res/arr[i] + (res%arr[i]?1:0);
        }
        printf("Case #%d: %d\n",cases++, V[n-sum-1ll]);
    }



    return 0;
}

/*


3
2 4
10 5
3 12
7 7 7
3 8
4 2 1



*/
