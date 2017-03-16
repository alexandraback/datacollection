#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <climits>

using namespace std;

int minMov(vector< int > &cantidad){
	int max = 0;
	int min ;
	int acum;
	for (int i = 0; i < cantidad.size(); ++i)
	{
		if(cantidad[i] > max){max = cantidad[i];}
	}
	//cout << "max: " << max << endl;
	acum = 0;
		for (int j = 0; j < cantidad.size(); ++j)
		{
			if(cantidad[j] > 1){
				acum += cantidad[j] - 1;
			}
			else{acum -= cantidad[j] - 1;} 
		}
	min = acum;

	for (int i = 2; i <= max; ++i)
	{	
		acum = 0;
		for (int j = 0; j < cantidad.size(); ++j)
		{
			if(cantidad[j] > i){
				acum += cantidad[j] - i;
			}
			else{acum -= cantidad[j] - i;} 
		}
		if(acum < min){min = acum;}
	}
	//cout << min << endl;
	return min;
}


int main(){
	int t, mov, n;
	char letra;
	bool posible;
	string aux;
	cin >> t;
	for(int i = 1; i <= t; ++i){
		cout << "Case #" << i << ": ";
		cin >> n  ;
		posible = true;
		mov = 0;
		vector < string > palabras(n);
		vector < int > iteradores(n,0);
		vector < int > cantidad(n,0);
		for (int i = 0; i < n; ++i)
		{
			cin >> palabras[i];
		}
		while(iteradores[0] < palabras[0].size()){
			letra = palabras[0][iteradores[0]];
			for (int i = 0; i < n; ++i)
			{
				cantidad[i] = 0;
				while(iteradores[i] < palabras[i].size() && palabras[i][iteradores[i]] == letra){
					++iteradores[i];
					++cantidad[i];
				}
				if(cantidad[i] == 0){posible = false; break;}
			}
			if(!posible){break;}
			mov += minMov(cantidad);
			/*if(cantidad[0] > cantidad[1]){mov += cantidad[0] - cantidad[1];}
			else{mov -= cantidad[0] - cantidad[1];}*/
		}
		for (int i = 0; i < n; ++i)
		{
			if(iteradores[i] != palabras[i].size()){posible = false; break;}
		}
		if(!posible){cout << "Fegla Won" << endl;}
		else {cout << mov << endl;}
		
	}




	return 0;
}

