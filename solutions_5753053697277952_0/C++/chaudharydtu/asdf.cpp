#include <iostream>
using namespace std;

int main() {
	int T,i,N,j,m1,m2,i1,i2,l;
	int A[27];
	char c,d;
	cin>>T;
	for(i=1;i<=T;i++)
	{
	    for(j=0;j<=26;j++)
	    A[j]=0;
	    cin>>N;
	    cin>>A[1];
	    cin>>A[2];
	    if(A[1]>A[2])
	    {m1=A[1];
	    m2=A[2];
	    i1=1;
	    i2=2;
	    }
	    else
	    {m2=A[1];
	    m1=A[2];
	    i2=1;
	    i1=2;
	    }
	    
	    for(j=3;j<=N;j++)
	    {
	        cin>>A[j];
	        if(A[j]>=m1)
	        {
	            m2=m1;
	            i2=i1;
	            m1=A[j];
	            i1=j;
	        }
	        
	    }
	    cout<<"Case #"<<i<<":";
	    l=m1-m2;
	    c=i1+64;
	    while(l)
	    {
	        cout<<" "<<c;
	        l--;
	    }
	    for(j=1;j<=N;j++)
	    {
	        if((j!=i1)&&(j!=i2))
	        {
	            c=j+64;
	            while(A[j]!=0)
	            {
	                cout<<" "<<c;
	                A[j]--;
	                
	            }
	            
	            
	        }
	        
	    }
	    c=i1+64;
	    d=i2+64;
	    while(m2)
	    {
	        cout<<" "<<c<<d;
	        m2--;
	        
	    }
	    cout<<"\n";
	    
	}
	
	
	
	
	return 0;
}
