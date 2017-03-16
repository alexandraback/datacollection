#include <iostream>
using namespace std;


struct party {
	int n;
	char c;
};

bool operator< ( const party& a , const party& b )
{
	return a.n<b.n;
}

party a[30];

int main()
{

	freopen("input.txt","r",stdin);
	freopen ( "output.txt","w",stdout );

	int w;
	cin>>w;
	int sum=0;
	for ( int v=1; v<=w; v++ ) {
		int n;
		cin>>n;
		for ( int i=1; i<=n; i++ ) {
			cin>>a[i].n;
			a[i].c = 'A'-1+i;
			sum+=a[i].n;
		}

		cout<<"Case #"<<v<<": ";

		while ( true ) {
			sort ( a+1,a+1+n );

			if ( a[n].n==0 )
				break;

			if (a[n-1].n>0 &&  a[n-1].n > ( sum-1 ) /2 ) {
				cout<<a[n].c<<a[n-1].c<<" ";
				a[n].n--;
				a[n-1].n--;
				sum-=2;
			} else {
				cout<<a[n].c<<" ";
				a[n].n--;
				sum--;
			}
		}

		cout<<endl;
	}
	return 0;
}
