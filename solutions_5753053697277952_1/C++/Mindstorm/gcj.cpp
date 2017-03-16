#include <bits/stdc++.h>
using namespace std;

vector< pair< int, int > > s;

int n, sum, tab[100010];
bool blad;


void czysc()
{

}
void czytaj()
{
	freopen( "A-large (2).in", "r", stdin );
	freopen( "wyj.txt", "w", stdout );
}
void wypisz( int x )
{
	cerr<<"Case #"<<x<<endl;
//	cerr<<r<<" "<<c<<" "<<w<<endl;
}
int main()
{
	czytaj();
	int ttt;
	cin>>ttt;
	for( int iii = 1; iii <= ttt; iii++ )
	{
		cin>>n;
		for( int a = 1; a <= n; a++ )
		{
			cin>>tab[a];
			sum += tab[a];
		}
		cout<<"Case #"<<iii<<": ";
		while( sum > 0 )
		{
			sum = 0;
			blad = 0;
			s.clear();
			for( int a = 1; a <= n; a++ )
			{
				if( tab[a] )s.push_back( make_pair( -tab[a], a ) );
			}
			sort( s.begin(), s.end() );
			cout<<char( 'A' + s[0].second - 1 );
			tab[ s[0].second ]--;
			tab[ s[1].second ]--;
			for( int a = 1; a <= n; a++ )sum += tab[a];
			for( int a = 1; a <= n; a++ )
			{
				if( 2 * tab[a] > sum )blad = 1;
			}
			if( blad )
			{
				tab[ s[1].second ]++;
				sum++;
			}
			else cout<<char( 'A' + s[1].second - 1 );
			cout<<" ";	
		}
		
		
		
		cout<<endl;
		wypisz( iii );
		czysc();
	} 
	return 0;
}
