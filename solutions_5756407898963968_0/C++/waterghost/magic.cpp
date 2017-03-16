#include <iostream>
#include <fstream>
#include <set>
#include <string>

using namespace std;

int compare(set<int>, set<int>);
int main()
{
	ifstream fin("A-small-attempt0.in");
	ofstream fout("res.txt");
	string s;
	
	if(!fin.is_open())
	{	
		cout<<"open input file error.\n";
	}
	if(!fout.is_open())
	{
		cout<<"open output file error.\n";
	} 
	
	getline(fin, s);
	int num = atoi(s.c_str());
	//cout << num;
	for(int k = 0; k < num; k++){
		set<int> a,b;
		getline(fin, s);
		int num2 = atoi(s.c_str());
		int t;
		int i = 0;
		while(++i < num2)
		{
			getline(fin,s);
		}
		char ch[8];
		for(int j = 0; j < 4; j++)
		{
			fin >> ch;
			t = atoi(ch);
			a.insert(t);
		}
		getline(fin, s);
		i = 0;
		while(++i <= 4 - num2)
			getline(fin, s);

		getline(fin, s);
		num2 = atoi(s.c_str());
		i = 0;
		while(++i < num2)
		{
			getline(fin,s);
		}
		for(int j = 0; j < 4; j++)
		{
			fin >> ch;
			t = atoi(ch);
			b.insert(t);
		}
		getline(fin, s);
		i = 0;
		while(++i <= 4 - num2)
		{
			getline(fin, s);
		}

		int res = compare(a, b);
		switch(res)
		{
		case -1:
			fout << "Case #" << k+1 << ": "<<"Volunteer cheated!\n";
			break;
		case 0:
			fout << "Case #" << k+1 << ": "<<"Bad magician!\n";
			break;
		default:
			fout << "Case #" << k+1 << ": " << res << endl;;
		}
	}
	//system("pause");
	fin.close();
	fout.close();
	return 0;
}

int compare(set<int> a, set<int> b){
	bool flag = false;
	int temp = 0;
	if(a.empty() || b.empty())
		return -1;
	set<int>::iterator it = b.begin();
	set<int>::iterator re;
	for(; it != b.end();++it)
	{
		re = a.find(*it);
		if(re != a.end() && flag == false)
		{
			flag = true;
			temp = *it;
			continue;
		}
		if(re != a.end() && flag == true)
		{
			return 0;
		}
	}
	if(flag == false)
	{
		return -1;
	}
	else
	{
		return temp;
	}
}