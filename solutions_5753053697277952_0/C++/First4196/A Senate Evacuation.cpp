#include   <bits/stdc++.h>
#define    sf               scanf
#define    pf               printf
#define    eof              feof(stdin)
#define    gl(a)            getline(cin,a)
#define    f(a,b,c)         for(intt a=b;a<=c;a++)
#define    r(a,b,c)         for(intt a=b;a>=c;a--)
#define    it(a,b)          for(intt a=0;a<b.size();a++)
#define    s(a)             sf(inttScan,&a);
#define    s2(a,b)          s(a) s(b)
#define    s3(a,b,c)        s(a) s2(b,c)
#define    s4(a,b,c,d)      s(a) s3(b,c,d)
#define    s5(a,b,c,d,e)    s(a) s4(b,c,d,e)
#define    p(a)             pf(inttPrint,a);
#define    p2(a,b)          p(a) p(b)
#define    p3(a,b,c)        p(a) p2(b,c)
#define    p4(a,b,c,d)      p(a) p3(b,c,d)
#define    p5(a,b,c,d,e)    p(a) p4(b,c,d,e)
#define    c(a)             cerr << "{ " << #a << "=" << a << " }";
#define    c2(a,b)          c(a) c(b)
#define    c3(a,b,d)        c(a) c2(b,d)
#define    c4(a,b,d,e)      c(a) c3(b,d,e)
#define    c5(a,b,d,e,f)    c(a) c4(b,d,e,f)
#define    el               pf("\n");
#define    cel              cerr << "\n";
#define    cline            cerr << "--------------------\n";
#define    ll               long long
#define    db               double
#define    ld               long double
#define    mset(a,b)        memset(a,b,sizeof(a));
#define    allocArr(a,b)    a=(intt*)calloc(b,sizeof(intt));
#define    allocMat(a,b,c)  a=(intt**)calloc(b,sizeof(intt*));f(i,0,b-1){allocArr(a[i],c)}
#define    bo               bool operator
#define    mp               make_pair
#define    pii              pair<intt,intt>
#define    pushb            push_back
#define    pushf            push_front
#define    popb             pop_back()
#define    popf             pop_front()
#define    lowb             lower_bound
#define    upb              upper_bound
#define    fi               first
#define    se               second
#define    seed             srand(time(NULL));
#define    randl            ((ll)rand()*32768ll+(ll)rand())
#define    maxpq(T)         priority_queue<T>
#define    minpq(T)         priority_queue<T,vector<T>,greater<T>>
#define    read(a)          freopen(a,"r",stdin);
#define    write(a)         freopen(a,"w",stdout);
#define    base             257ll
#define    mod              1000000007ll
#define    mod2             1000000009ll
#define    inf              2000000000ll
#define    pi               3.141592653589793
template<typename A, typename B> inline bool mins(A &x,B y){return (x>y)?(x=y,1):0;}
template<typename A, typename B> inline bool maxs(A &x,B y){return (x<y)?(x=y,1):0;}
using namespace std;

#define usell   0

#if usell
    #define     intt        long long
    #define     inttScan    "%lld"
    #define     inttPrint   "%lld "
#else
    #define     intt        int
    #define     inttScan    "%d"
    #define     inttPrint   "%d "
#endif

void clrmem();
void prep();

intt n;
struct party{
    int id,n;
    bo < (party z)const{
        return n>z.n;
    }
}p[30];

void solve(){
    s(n)
    f(i,0,n-1){
        s(p[i].n)
        p[i].id=i;
    }
    sort(p,p+n);
    while(p[0].n>p[1].n){
        pf("%c ",p[0].id+'A');
        p[0].n--;
    }
    f(i,2,n-1){
        while(p[i].n>0){
            pf("%c ",p[i].id+'A');
            p[i].n--;
        }
    }
    while(p[0].n>0){
        pf("%c%c ",p[0].id+'A',p[1].id+'A');
        p[0].n--;
        p[1].n--;
    }
    el
    return;
}

void clrmem(){

    return;
}

void prep(){

    return;
}

int main(){
    #define mode 1
    if(mode==1){
        read("A-small-attempt0.in")
        write("A-small-attempt0.out")
    }
    else if(mode==2){
        read("A-large.in")
        write("A-large.out")
    }
    prep();
    intt testN;
    s(testN)
    for(int testC=1;testC<=testN;testC++){
        cerr << "\n>>>>> Test " << testC << " <<<<<\n";
        pf("Case #%d: ",testC);
        clrmem();
        solve();
        clrmem();
    }
    return 0;
}
