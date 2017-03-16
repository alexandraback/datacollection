#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include<cmath>
#include<complex>
#include<vector>
using namespace std;

typedef long long ty ;
typedef complex<ty> pt;

/*
Utile : 
pt(a,b) 
pt.norm -> le carre de la norme
pt.abs -> la norme (attention aux types)
pt p =  conj(a)*b;
p.real() -> le produit scalaire (a.x*b.x - (-a.y)*b.y == a.x*b.x + a.y+b.y)
p.imag() -> le produit vectoriel (a.x*b.y+(-a.y)*b.y == a.x*b.y-a.y*b.x)
atan2(p.imag(),p.real()) -> angle entre a et b
*/


struct sort_pts
{
  bool operator() ( const pt & a,const pt & b ) const
  {
    if(a.real() != b.real() )
      return a.real()<b.real() ;
    return a.imag()<b.imag() ;
  }  
};

double angle(pt a, pt b) { // angle between vectors Oa and Ob
  const pt p = conj(a)*b;
  return atan2(p.imag(),p.real());
}

int n;
pt pts[3000];
vector<double> a;
	    
int main()
{
    int nb_cas;
    scanf("%d", &nb_cas);
    for(int cas = 1; cas <= nb_cas; cas++)
    {
	printf("Case #%d:\n",cas);
	//enter code here
        scanf("%d",&n);
	for(int i=0;i<n;i++)
	  {
	    int a,b;
	    scanf("%d%d",&a,&b);
	    pts[i]=pt(a,b);
	  }
        for(int ref=0;ref<n;ref++)
	  {
	    a.clear();
	    a.push_back(-M_PI);
	    for(int i=0;i<n;i++)
	      if(i!=ref)
		{
		  double v = angle(pts[i]-pts[ref],pt(0,1));
		  a.push_back(v);
		  if(v<0)
		    a.push_back(v+2*M_PI);
		}
	    a.push_back(2*M_PI);
	    sort(a.begin(),a.end());
	    //fprintf(stderr,"%d\n",a.size());
	    // for(int i=0;i<a.size();i++)
	    //   printf("%f ",a[i]);
	    // printf("\n");
	    int ia=0;
	    int ib=0;
	    double mypi = M_PI - 1E-10;
	    int min_half = n;
	    while(ib < a.size())
	      {
		while(ib < a.size() && a[ib+1]-a[ia] < mypi)
		  ib++;
		//printf("%d %d\n",ia,ib);
		min_half=min(min_half,ib-ia);
		ia++;
	      }
	    printf("%d\n",min_half);
	  }
    }
    return 0;
}
