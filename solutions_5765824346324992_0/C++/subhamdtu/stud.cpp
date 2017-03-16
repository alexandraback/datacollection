#include<bits/stdc++.h>
#define s(n) scanf("%d",&n)
#define sl(n) scanf("%lld",&n)
#define p(n) printf("%d\n",n)
#define ll long long

#define pb push_back
#define mp make_pair
#define mod1 1000000007
#define NN 100002
#define LN 21
using namespace std;
struct tree
{
 ll a;
 ll d;
 int f;
}node[4*NN];
ll ar[NN];
ll lim=1e10;
void build_tree(int id,int l,int r)
{
 if(l==r)
 {
 node[id].f=1;
 node[id].a=ar[l];
 node[id].d=lim;
 }
 else
 {
  int mid=(l+r)/2;
  build_tree(2*id+1,l,mid);
  build_tree(2*id+2,mid+1,r);
  if(node[2*id+1].f==1 && node[2*id+2].f==1)
  {
    if(r-l==1)
    {
     node[id].f=1;
     node[id].a=node[2*id+1].a;
     node[id].d=ar[r]-ar[l];
    }
    else if(r-l==2)
    {
         if(ar[mid+1]-ar[mid]==node[2*id+1].d)
         {
          node[id].f=1;
          node[id].a=node[2*id+1].a;
          node[id].d=node[2*id+1].d;
         }
         else
         {
           node[id].f=0;
            node[id].a=node[id].d=lim;
         }
    }
    else
    {
            if((node[2*id+1].d==node[2*id+2].d) && (ar[mid+1]-ar[mid]==node[2*id+1].d))
            {
            node[id].f=1;
            node[id].a=node[2*id+1].a;
            node[id].d=node[2*id+1].d;
            }
            else
            {
            node[id].f=0;
            node[id].a=node[id].d=lim;
            }
    }
  }
  else
  {
  node[id].f=0;
  node[id].a=node[id].d=lim;
  }
 }
}
void update(int id,int l,int r,int qid,ll val)
{
 if(qid<l||qid>r||l>r)
 return;
 else if(l==r)
 {
  ar[l]=val;
  node[id].f=1;
  node[id].a=ar[l];
  node[id].d=lim;
 }
 else
 {
    int mid=(l+r)/2;
    update(2*id+1,l,mid,qid,val);
    update(2*id+2,mid+1,r,qid,val);
    if(node[2*id+1].f==1 && node[2*id+2].f==1)
     {
        if(r-l==1)
        {
        node[id].f=1;
        node[id].a=node[2*id+1].a;
        node[id].d=ar[r]-ar[l];
        }
        else if(r-l==2)
        {
         if(ar[mid+1]-ar[mid]==node[2*id+1].d)
         {
          node[id].f=1;
          node[id].a=node[2*id+1].a;
          node[id].d=node[2*id+1].d;
         }
         else
         {
           node[id].f=0;
            node[id].a=node[id].d=lim;
         }
        }
        else
        {
            if((node[2*id+1].d==node[2*id+2].d) && (ar[mid+1]-ar[mid]==node[2*id+1].d))
            {
            node[id].f=1;
            node[id].a=node[2*id+1].a;
            node[id].d=node[2*id+1].d;
            }
            else
            {
            node[id].f=0;
            node[id].a=node[id].d=lim;
            }
        }
    }
    else
    {
    node[id].f=0;
    node[id].a=node[id].d=lim;
    }
 }
}
pair<ll,int> query(int id,int l,int r,int ql,int qr)
{
  if(ql>r||qr<l||l>r)
  return mp(lim,-1);
  else if(ql<=l && qr>=r)
  return mp(node[id].d,node[id].f);
  else
  {
   int mid=(l+r)/2;
   pair<ll,int> v1=query(2*id+1,l,mid,ql,qr);
   pair<ll,int> v2=query(2*id+2,mid+1,r,ql,qr);
   //cout<<l<<" "<<r<<" "<<v1.first<<" "<<v1.second<<" "<<v2.first<<" "<<v2.second<<endl;
   if(v1.second==1 && v2.second==1)
   {
    if(r-l==1)
    return mp(ar[r]-ar[l],1);
    else if(r-l==2)
    {
     if(v1.first==lim)
     return mp(ar[mid+1]-ar[mid],1);
     else if(ar[mid+1]-ar[mid]==v1.first)
     return mp(v1.first,1);
     else
     return mp(lim,0);
    }
    else
    {
     if(v1.first==lim && v2.first==lim)
     return mp(ar[mid+1]-ar[mid],1);
     else if(v1.first==lim)
     {
      if(ar[mid+1]-ar[mid]==v1.second)
      return mp(v1.second,1);
      else
      return mp(lim,0);
     }
     else if(v2.first==lim)
     {
      if(ar[mid+1]-ar[mid]==v1.first)
      return mp(v1.first,1);
      else
      return mp(lim,0);
     }
     else if(v1.first==v2.first && (ar[mid+1]-ar[mid]==v1.first))
     return mp(v1.first,1);
     else
     return mp(lim,0);
    }
   }
   else if(v1.second==-1 && v2.second==1)
   return mp(v2.first,1);
   else if(v1.second==1 && v2.second==-1)
   return mp(v1.first,1);
   else
   return mp(lim,0);
  }
}
int main()
{
 priority_queue<pair<int,int> >pq;
  int t,n,p,i,j,b;
  int mi[1002];
  cin>>t;
  for(p=1;p<=t;++p)
  {
   while(!pq.empty())
   pq.pop();
     s(b);
     s(n);

     for(i=0;i<b;++i)
     cin>>mi[i];
     int lcm=1;
     for(i=0;i<b;++i)
     {
       int va=lcm*mi[i];
       int gc=__gcd(lcm,mi[i]);
       lcm=va/gc;
     }

   // cout<<lcm<<endl;
     int pe=0;
     for(i=0;i<b;++i)
     pe+=lcm/mi[i];

     int req=n%pe;
     if(req==0)req+=pe;
   //  cout<<pe<<" "<<req<<endl;

     printf("Case #%d: ",p);
     if(req<=b)
     cout<<req<<endl;
     else
     {
      req-=b;
      for(i=0;i<b;++i)
      pq.push(mp(-mi[i],-i-1));
      i=1;
      int va;
      while(1)
      {
        pair<int,int> p=pq.top();
        pq.pop();
        if(i==req)
        {
         va=p.second*-1;
         break;
        }
        i++;
       // cout<<p.first<<" "<<p.second<<endl;
        p.first=p.first-mi[abs(p.second)-1];

        pq.push(p);
      }
      cout<<va<<endl;
     }
  }
}
