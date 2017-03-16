#include <iostream>
#include <string>
using namespace std;

typedef pair<int,int> pii;

template<typename t1, typename t2>
 std::ostream& operator<<(std::ostream& os, const std::pair<t1, t2>& pair)
 {
     return os << pair.first << " " << pair.second;
 }

int m[1010],N;
pii calc()
{
	cin>>N;
	for(int i=0;i<N;i++)cin>>m[i];
	int mr=0;
	for(int i=0;i<N-1;i++)
		mr=max(mr,m[i]-m[i+1]);
	//cerr<<"mr::"<<mr<<endl;
	
	int first=0,second=0;
	
	for(int i=0;i<N-1;i++)
	{
		int curr=m[i],next=m[i+1];
		if(next<curr)first+=curr-next;
		if(curr<mr)
		{
			//cerr<<"curr<mr"<<curr<<" sec+="<<curr<<endl;
			second+=curr;
		}
		else
		{
			//cerr<<"curr>=mr"<<curr<<" sec+="<<mr<<endl;
			second+=mr;
		}
	}
	//second+=m[N-1];
	return pii(first,second);
}

int main()
{
	//cout<<calc();
	//return 0;
	
	int N;cin>>N;
	for(int i=0;i<N;i++)
		cout<<"Case #"<<(i+1)<<": "<<calc()<<endl;
	return 0;
}