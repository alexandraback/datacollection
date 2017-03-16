#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <queue>
#include <cmath>
#include <stack>

#pragma comment(linker, "/STACK:1024000000");
#define EPS (1e-6)
#define LL long long
#define ULL unsigned long long int
#define _LL __int64
#define INF 0x3f3f3f3f
#define Mod 1000000007

using namespace std;

int num[1100];

int main()
{
   // freopen("A-large.in","r",stdin);
    //freopen("A-large.out","w",stdout);
    freopen("B-small-attempt0.in","r",stdin);
    freopen("B-small-attempt0.out","w",stdout);
    int T,icase = 1;

    scanf("%d",&T);

    while(T--)
    {
        int n,i,k;

        scanf("%d %d",&n,&k);

        for(i = 1;i <= n; ++i)
            scanf("%d",&num[i]);

        int lcm = num[1];

        for(i = 1;i <= n; ++i)
            lcm = lcm/__gcd(lcm,num[i])*num[i];

        int ans = 0;

        for(i = 1;i <= n; ++i)
            ans += lcm/num[i];

        k = (k%ans == 0 ? ans : k%ans);

        int t = 0,anw = -1;
        while(k)
        {
            for(i = 1;i <= n; ++i)
            {
                if(t%num[i] == 0)
                {
                    k--;
                    if(k == 0)
                    {
                        anw = i;
                        break;
                    }
                }
            }
            t++;
        }
        printf("Case #%d: %d\n",icase++,anw);
    }

    return 0;
}

/*
const int MAXN = 100100;

struct N
{
    int v,next;
} edge[MAXN*2];

int head[MAXN];

int Top;

void Link(int u,int v)
{
    edge[Top].v = v , edge[Top].next = head[u] , head[u] = Top++;
}

int Top_E;

int siz[MAXN],fa[MAXN],son[MAXN],dot_site[MAXN],dep[MAXN],top[MAXN],seg[MAXN];

int que[MAXN];

void dfs1(int s)
{
    int L = 0 ,R = 0,p,now,v;
    fa[s] = -1,dep[s] = 1,siz[s] = 1,son[s] = -1;
    que[R++] = s;

    while(L <= R)
    {
        now = que[L++];
        for(p = head[now]; p != -1; p = edge[p].next)
        {
            v = edge[p].v;
            if(v != fa[now])
                fa[v] = now,dep[v] = dep[now]+1,siz[v] = 1,son[v] = -1,que[R++] = v;
        }
    }

    for(L = R-1; L >= 0; --L)
    {
        now = que[L];
        v = fa[now];
        if(son[v] == -1 || siz[son[v]] < siz[now])
            son[v] = now;
        siz[v] = max(siz[v],siz[now] + 1);
    }
}

void dfs2(int s,int pre,int T)
{
    top[s] = T , dot_site[s] = ++Top_E , seg[Top_E] = s ;

    if(son[s] == -1)
        return ;

    dfs2(son[s],s,T);

    for(int p = head[s] ; p != -1; p = edge[p].next)
        if(edge[p].v != son[s] && edge[p].v != pre)
            dfs2(edge[p].v,s,edge[p].v);
}

struct E
{
    int u,v,w;
} input[MAXN];

int val[MAXN];

struct ST
{
    int Max,Min,flag;
} st[MAXN*4];

void Init(int site,int l,int r)
{
    if(l == r)
    {
        st[site].Max = val[l];
        st[site].Min = val[l];
        st[site].flag = 0;
        return ;
    }
    int mid = (l+r)>>1;
    Init(site<<1,l,mid);
    Init(site<<1|1,mid+1,r);
    st[site].Max = max(st[site<<1].Max,st[site<<1|1].Max);
    st[site].Min = min(st[site<<1].Min,st[site<<1|1].Min);
    st[site].flag = 0;
}

void Update2(int site,int L,int R,int l,int r)
{
 //   cout<<"*"<<" site = "<<site<<" L = "<<L<<" R = "<<R<<" l = "<<l<<" r = "<<r<<endl;
    if(L == l && R == r)
    {
        st[site].flag ^= 1;
        swap(st[site].Max,st[site].Min);
        st[site].Max *= (-1);
        st[site].Min *= (-1);
        return ;
    }

    int mid = (L+R)>>1;

    if(st[site].flag)
    {
        st[site].flag = 0;
        Update2(site<<1,L,mid,L,mid);
        Update2(site<<1|1,mid+1,R,mid+1,R);
    }

    if(r <= mid)
        Update2(site<<1,L,mid,l,r);
    else if(mid < l)
        Update2(site<<1|1,mid+1,R,l,r);
    else
    {
        Update2(site<<1,L,mid,l,mid);
        Update2(site<<1|1,mid+1,R,mid+1,r);
    }

    st[site].Max = max(st[site<<1].Max,st[site<<1|1].Max);
    st[site].Min = min(st[site<<1].Min,st[site<<1|1].Min);
}

int Query(int site,int L,int R,int l,int r)
{
  //  cout<<"site = "<<site<<" L = "<<L<<" R = "<<R<<" l = "<<l<<" r = "<<r<<endl;
    if(L == l && R == r)
        return st[site].Max;
    int mid = (L+R)>>1;
    if(st[site].flag)
    {
        st[site].flag = 0;
        Update2(site<<1,L,mid,L,mid);
        Update2(site<<1|1,mid+1,R,mid+1,R);
    }
    if(r <= mid)
        return Query(site<<1,L,mid,l,r);
    if(mid < l)
        return Query(site<<1|1,mid+1,R,l,r);
    return max(Query(site<<1,L,mid,l,mid),Query(site<<1|1,mid+1,R,mid+1,r));
}

void Update1(int site,int l,int r,int x,int data)
{
    //cout<<"l = "<<l<<" r = "<<r<<" x = "<<x<<" data = "<<data<<endl;
    if(l == r)
    {
        st[site].Max = data;
        st[site].Min = data;
        st[site].flag = 0;
        return ;
    }

    int mid = (l+r)>>1;
    if(st[site].flag)
    {
        st[site].flag = 0;
        Update2(site<<1,l,mid,l,mid);
        Update2(site<<1|1,mid+1,r,mid+1,r);
    }

    if(x <= mid)
        Update1(site<<1,l,mid,x,data);
    else
        Update1(site<<1|1,mid+1,r,x,data);

    st[site].Max = max(st[site<<1].Max,st[site<<1|1].Max);
    st[site].Min = min(st[site<<1].Min,st[site<<1|1].Min);
}

int main()
{
    char s[20];
    int n,i;
    int u,v,w;
    int T;

    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        memset(head,-1,sizeof(int)*(n+2));
        Top = 0;

        for(i = 1; i < n; ++i)
        {
            scanf("%d %d %d",&u,&v,&w);
            Link(u,v);
            Link(v,u);
            input[i].u = u;
            input[i].v = v;
            input[i].w = w;
        }

        dfs1(1);
        Top_E = 0;
        dfs2(1,-1,1);

        for(i = 1; i < n; ++i)
        {
            if(fa[input[i].u] == input[i].v)
                val[input[i].u] = input[i].w;
            else
                val[input[i].v] = input[i].w;
        }

        Init(1,1,Top_E);

        while(scanf("%s",s) && s[0] != 'D')
        {
            if(s[0] == 'Q')
            {
                scanf("%d %d",&u,&v);
                int fu = top[u],fv = top[v];
                int anw = -INF;

                while(fu != fv)
                {
                    if(dep[fu] < dep[fv])
                        swap(fu,fv),swap(u,v);
                    anw = max(anw,Query(1,1,Top_E,dot_site[fu],dot_site[u]));
                    u = fa[fu];
                    fu = top[u];
                }
                if(u != v)
                {
                    if(dep[u] < dep[v])
                        swap(u,v);
                    anw = max(anw,Query(1,1,Top_E,dot_site[v]+1,dot_site[u]));
                }
                printf("%d\n",anw);
            }
            else if(s[0] == 'C')
            {
                scanf("%d %d",&i,&v);
                if(fa[input[i].u] == input[i].v)
                    Update1(1,1,Top_E,dot_site[input[i].u],v);
                else
                    Update1(1,1,Top_E,dot_site[input[i].v],v);
            }
            else
            {
                scanf("%d %d",&u,&v);
                int fu = top[u],fv = top[v];
                while(fu != fv)
                {
                    if(dep[fu] < dep[fv])
                        swap(fu,fv),swap(u,v);
                    Update2(1,1,Top_E,dot_site[fu],dot_site[u]);
                    u = fa[fu];
                    fu = top[u];
                }
                if(u != v)
                {
                    if(dep[u] < dep[v])
                        swap(u,v);
                    Update2(1,1,Top_E,dot_site[v]+1,dot_site[u]);
                }
            }
        }
    }
    return 0;
}
*/
