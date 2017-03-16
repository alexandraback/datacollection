#include <algorithm>
#include <iostream>
#include <string>
#include <limits>
#include <vector>
using namespace std;

template<typename T>
T read(){
	T temp;
	cin >> temp;
	return temp;
}

struct Appartment{
	int r{ read<int>() };
	int c{ read<int>() };
	int n{ read<int>() };
	
	struct Rooms{
		vector<int> rooms;
		int r, c, n;
		
		Rooms( int r, int c, int n ) : rooms( r*c ), r(r), c(c), n(n) {
			for( auto& a : rooms )
				a = false;
		}
		
		bool tenant( int x, int y ){ return rooms[ x + y*r ]; }
		void setTenant( int x, int y, bool val ){ rooms[ x + y*r ] = val; }
		
		int unhappiness(){
			int amount = 0;
			
			for( unsigned iy=0; iy<c; iy++ )
				for( unsigned ix=0; ix<r-1; ix++ )
					if( tenant( ix, iy ) && tenant( ix+1, iy ) )
						amount++;
			
			for( unsigned iy=0; iy<c-1; iy++ )
				for( unsigned ix=0; ix<r; ix++ )
					if( tenant( ix, iy ) && tenant( ix, iy+1 ) )
						amount++;
			
			return amount;
		}
	
		int best( int x, int y, int tenants ){
			int best_val = numeric_limits<int>::max();
			if( tenants > n )
				return best_val;
			if( tenants == n )
				return unhappiness();
			
			for( int iy=y; iy<c; iy++ )
				for( int ix=(iy==y)?x:0; ix<r; ix++ ){
					Rooms rooms1( *this );
					rooms1.setTenant( ix, iy, true );
					
					auto result1 = rooms1.best( ix+1, iy, tenants+1 );
					best_val = min( result1, best_val );
				}
			
			return best_val;
		}
	};
	
	int result(){
		return Rooms( r, c, n ).best( 0,0,0 );
	};
};


int main(){
	auto amount = read<int>();
	
	for( int i=1; i<=amount; i++ )
		cout << "Case #" << i << ": " << Appartment().result() << endl;
	
	return 0;
}
