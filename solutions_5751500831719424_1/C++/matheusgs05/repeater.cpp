#include<iostream>
#include<vector>
#include<map>
#include<cmath>
#include<algorithm>

using namespace std;

int main()
{
	int casos, flag, inst = 1, i, j, cont, mediana, n, k;
	string s1, s2;	
	vector<string> v;
	vector<vector<int> > v2;
	vector<int> med;
	map<string, int> m;
	char aux, ant;
	int fim[220];
	
	cin >> casos;
	
	while(casos--)
	{
		cin >> n;
		flag = 0;
		for(i=0; i<n; i++)
		{
		
			fim[i] = 0;
			cin >> s1;
			s2.push_back(s1[0]);
			ant = s1[0];
			for(j=1; j<s1.size(); j++)
			{
				if(s1[j] == ant)
					continue;
				else
				{
					s2.push_back(s1[j]);
					ant = s1[j];
				}
			}
			m[s2]++;
			if(m.size() > 1)
				flag = 1;
			
			s2.clear();
			v.push_back(s1);
			v2.push_back(vector<int>());
		}
		if(flag == 1)
		{
			cout << "Case #" << inst++ << ": Fegla Won" << endl; 
		}
		else
		{

		
			for(i=0; i<n; i++)
			{
				for(j=0; j<30; j++)
					v2[i].push_back(0);
			}
	

			/*
			for(i=0; i<n; i++)
			{
				for(j=0; j<v[i].size(); j++)
				{
					v2[i][v[i][j]-'a']++;
				}
			}
			*/

			cont = 0;
			ant = '-';
			for(i=0; i<v[0].size(); i++)
			{
				aux = v[0][i];
				if(aux == ant)
					continue;
					
				for(j=0; j<n; j++)
				{
					v2[j][aux-'a'] = 0;
					for(k=fim[j]; k<v[j].size(); k++)
					{
						if(v[j][k] == aux)
						{
							v2[j][aux-'a']++;
						}
						else
							break;
					}
					fim[j] = k;
				}
					
			
				ant = aux;
	
				for(j=0; j<n; j++)
					med.push_back(v2[j][aux-'a']);
				sort(med.begin(), med.end());
		
				if(n%2 == 1)
					mediana = med[n/2];
				else
					mediana = (med[n/2] + med[(n/2) -1]) / 2;
			
		
				for(j=0; j<n; j++)
				{
					cont += abs(mediana - v2[j][aux-'a']);
				}
				med.clear();
			}
	
			cout << "Case #" << inst++ << ": " << cont << endl;
		}
		m.clear();
		v.clear();
		v2.clear();
		
	}
	
	return 0;
}
		
		
		
	
