#include <iostream>
#include <vector>
using namespace std;

typedef struct 
{
    int n;
    char c;
} party;

void single(vector<party> &v)
{
    int max=0;
    for(int i=0; i<v.size(); i++)
    {
        if(v[i].n>v[max].n)
        {
            max = i;
        }
    }
    cout<< v[max].c << " ";
    v[max].n--;
    if(v[max].n==0)
    {
        v.erase(v.begin()+max);
    }
}

int main()
{
	int T;
	int N;
	int tmp;
	vector<party> v;
	cin >> T;
	for(int t=0; t<T; t++)
	{
	    v.clear();
	    cin >> N;
	    for(int n=0; n<N; n++)
	    {
	        cin>> tmp;
	        party p;
	        p.c = 'A'+n;
	        p.n = tmp;
	        v.push_back(p);
	    }
	    cout<< "Case #" << t+1 << ": ";
	    while(v.size()>2)
	    {
	        single(v);
	    }
	    while(v[0].n!=v[1].n)
	    {
	        single(v);
	    }
	    while(v[0].n>0)
	    {
	        cout<< v[0].c << v[1].c << " ";
	        v[0].n--;
	        v[1].n--;
	    }
	    cout<< endl;
	}
	return 0;
}
