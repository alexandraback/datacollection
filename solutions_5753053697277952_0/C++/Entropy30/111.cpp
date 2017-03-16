#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
#define pb push_back
#define all(a) a.begin(), a.end()
#define sqr(x) x*x
#define int long long

int inf = 1e11;
int m = 1000010;
using namespace std;


main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A.out", "w", stdout);
    ios::sync_with_stdio(0);
    

    int T;
    cin >> T;
	
    for(int q = 0; q < T; q++)
    {
		vector<int> senat(30, 0);
		int n;
		cin >> n;
		
		for(int j = 0; j < n; j++)
			cin >> senat[j];
		
		cout << "Case #" << (q + 1) << ": ";
		
		for(int w = 0; w < n * 10; w++)
		{
			int mx = *max_element(senat.begin(), senat.end());
			//cout << mx << endl;
			
			int max_pos[2] = {-1, -1};
			
			if(mx == 0)
				break;
				
			int cn = 0;
			for(int j = 0; j < n; j++)
				if((cn < 2) && (senat[j] == mx))
				{
					max_pos[cn] = j; 
					cn++;
				}
				else if((cn == 2) && (senat[j] == mx))
				{
					cn++;
					break;
				}
			
			if(cn == 1 || cn == 3)
			{
				cout << char('A' + max_pos[0]) << " ";
				senat[max_pos[0]]--;
				//cout << max_pos[0] << endl;
			}
			else if(cn == 2)
			{
				cout << char('A' + max_pos[0]) << char('A' + max_pos[1]) << " ";
				senat[max_pos[0]]--;
				senat[max_pos[1]]--;
				//cout << max_pos[0] << " " << max_pos[1] << endl;
			}
		}
		
		cout << '\n';
	}

    return 0;
}
