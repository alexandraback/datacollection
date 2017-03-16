#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;



int main() {
	int t, n, r, c;
	cin.sync_with_stdio(false);
	cin >> t;
	
	
	
	for(int TCASE = 0; TCASE < t; TCASE++) {
		cin >> r >> c >> n;
		
		if(r > c)
			swap(r, c);
		
		cout << "Case #" << TCASE + 1 << ": ";
		
		
		
		if(n <= max(r*c / 2, r*c - r*c/2) )
			cout << "0\n";
		else {
			
			vector<int> evenadd, oddadd;
			int neven = 0, nodd = 0;
			
			for(int i=0;i<r;i++)
				for(int j=0;j<c;j++) {
					int cadd = (int)(i > 0) + (i < r-1) + (j > 0) + (j < c-1);
					
					if((i+j) % 2 == 0)
						evenadd.push_back(cadd), neven ++;
					else
						oddadd.push_back(cadd), nodd++;
				}
			
			
			sort(evenadd.begin(), evenadd.end() );
			sort(oddadd.begin(), oddadd.end() );
			
			
			int result = 1000000000;
			
			//Finally try out
			
			int cres = 0;
			
			for(int i=0;i<n - neven;i++)
				cres += oddadd[i];
			
			result = min(result, cres);
			
			cres = 0;
			
			for(int i=0;i<n-nodd;i++)
				cres += evenadd[i];
			
			result = min(result, cres);
			
			
			cout << result << '\n';
		}
	}
	
	return 0;
}





