#include<iostream>
#include<cstdio>
using namespace std;


int main() {
	ios_base::sync_with_stdio(0);
	int testy, r, c, n, wynik, nieuzyte, wolne2, wolne3, wolne4, pom1, pom2;
	
	cin >> testy;
	for(int i=1; i<=testy; i++)
	{
		cin >> r >> c >> n;
		
		if(n<=1) wynik = 0;
		else if(r*c == 1) wynik = 0;
		else if(r*c == 2) 
		{
			if(n <= 1) wynik = 0;
			else wynik = 1;
			}
		else if(r==1 || c==1) {
			if((r*c)%2 == 0) 
			{
				if(2*n <= (r*c)) wynik = 0;
				else wynik = 2*(n-(r*c/2))-1;
				}
			else {
				if(2*n+1 <= (r*c)) wynik = 0;
				else wynik = 2*(n-(r*c/2)-1);
				}
		}
		else if(r%2==1 && c%2==1)
		{
			if(2*n-1 <= r*c) wynik = 0;
			else 
			{
				pom1 = 0;
				nieuzyte = n - (r*c/2) - 1;
				wolne2 = 0;
				wolne3 = r+c-2;
				wolne4 = r*c/2 - wolne3;
				
				if(nieuzyte<=wolne3) {pom1 = pom1 + nieuzyte*3; nieuzyte = 0;}
				else 
				{
					pom1 = pom1 + wolne3*3;
					nieuzyte = nieuzyte - wolne3;
					wolne3 = 0;
					pom1 = pom1 + nieuzyte*4;
					nieuzyte = 0;
					}
					
				pom2 = 0;
				nieuzyte = n - r*c/2;
				wolne2 = 4;
				wolne3 = r+c-6;
				wolne4 = r*c/2 +1 - wolne2 - wolne3;
				if(nieuzyte<=wolne2) {pom2 = pom2 + nieuzyte*2; nieuzyte = 0;}
				else 
				{
					pom2 = pom2 + wolne2*2;
					nieuzyte = nieuzyte - wolne2;
					wolne2 = 0;
					if(nieuzyte<=wolne3) {pom2 = pom2 + nieuzyte*3; nieuzyte = 0;}
					else 
					{
						pom2 = pom2 + wolne3*3;
						nieuzyte = nieuzyte - wolne3;
						wolne3 = 0;
						pom2 = pom2 + nieuzyte*4;
						nieuzyte = 0;
						}
					}
				
				wynik = min(pom1, pom2);	
				}
			}
		else 
		{
			if(2*n <= r*c) wynik = 0; 
			else
			{
				wynik = 0;
				nieuzyte = n - r*c/2;
				wolne2 = 2;
				wolne3 = r+c-4;
				wolne4 = r*c/2 - wolne2 - wolne3;
				if(nieuzyte<=wolne2) {wynik = wynik + nieuzyte*2; nieuzyte = 0;}
				else 
				{
					wynik = wynik + wolne2*2;
					nieuzyte = nieuzyte - wolne2;
					wolne2 = 0;
					if(nieuzyte<=wolne3) {wynik = wynik + nieuzyte*3; nieuzyte = 0;}
					else 
					{
						wynik = wynik + wolne3*3;
						nieuzyte = nieuzyte - wolne3;
						wolne3 = 0;
						wynik = wynik + nieuzyte*4;
						nieuzyte = 0;
						}
					}
				}
			}
		
		cout << "Case #" << i << ": " << wynik << endl;
		}
		
	return 0;
}
