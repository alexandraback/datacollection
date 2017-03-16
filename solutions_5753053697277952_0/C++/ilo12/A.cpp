#include <iostream>


using namespace std;


int n;
int T;
int tab[30];

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);

	cin>>T;
	for(int t=0; t<T; ++t){
		cout<<"Case #"<<t+1<<": ";
		cin>>n;
		for (int i = 0; i < n; ++i)
		{
			cin>>tab[i];
		}
		int lowest_size = 10001;
		//get lowest
		for (int i=0; i<n; ++i){
			lowest_size = min(lowest_size,tab[i]);
		}
		int bigger = 0;
		for (int i = 0; i < n; ++i)
		{
			if(tab[i]>lowest_size)
				++bigger;
		}
		while(bigger > 0){
			int biggest_size = 0;
			int biggest = -1;
			for (int i = 0; i < n; ++i)
			{
				if(tab[i]>biggest_size){
					biggest_size = tab[i];
					biggest = i;
				}

			}

			cout<<(char)('A'+biggest)<<" ";
			tab[biggest]--;
			bigger = 0;
			for (int i = 0; i < n; ++i)
			{
				if(tab[i]>lowest_size)
					++bigger;
			}
		}

		int nonZero = 0;
		for (int i = 0; i < n; ++i)
		{
			if(tab[i]>0)
				++nonZero;
		}

		int i = 0;
		while(nonZero > 2){
			if(tab[i]>0){
				for(int j = 0; j<lowest_size/2; ++j)
					cout<<(char)('A'+i)<<(char)('A'+i)<<" ";
				if(lowest_size%2)
					cout<<(char)('A'+i)<<" ";	
				nonZero--;
				tab[i]=0;
			}

			i++;
		}

		int a = -1, b = -1;
		for (int i = 0; i < n; ++i)
		{
			if(tab[i]>0)
				if(a==-1)
					a=i;
				else
					b=i;
		}
		for(int j = 0; j<lowest_size; ++j)
			cout<<(char)('A'+a)<<(char)('A'+b)<<" ";
			
		cout<<"\n";


	}

	return 0;
}