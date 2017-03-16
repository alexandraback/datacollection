#include <iostream>
using namespace std;


int main()
{
	int powtorzenia;
	cin >> powtorzenia;
	for(int x=1; x<=powtorzenia; x++)
	{
		int n;
		cin >> n;
		
		int wynik1, wynik2, roznica1, roznica2;
		int tab [2005];
		tab[0]=0;
		wynik1=wynik2=roznica1=roznica2=0;
		
		for (int i=1; i<=n; i++)
		{
			cin >> tab[i];
			if (tab[i-1] > tab[i])
			{
				roznica1=tab[i-1]-tab[i];
				wynik1+=roznica1;
				roznica2=max(roznica1, roznica2);
			}
		}
		
		for (int i=1; i<n; i++)
		{
			if (tab[i]<roznica2)
			{
				wynik2+=tab[i];
			}
			else 
			{
				wynik2+=roznica2;
			}
		}
		
		cout << "Case #" << x << ": " << wynik1 << " " << wynik2 << endl;
	}	
	
}	
