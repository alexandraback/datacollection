#include<cstdlib>
#include<iostream>
#include<vector>
#include<string>
#include<cmath>
using namespace std;

bool intsort(int* n,int size){
    int i, j, temp;
    for (i = size - 1; i > 0; i--)
    {
        for (j = 0; j <= i - 1; j++)
        {
            if (n[j] < n[j + 1])
            {
                temp = n[j];
                n[j] = n[j + 1];
                n[j + 1] = temp;
            }
        }
    }
}

class gamestring{
public:
	gamestring(){
		cin>>_s;
		char char_t = '\0'; int num_t = 0;
		for(int i=0;i<_s.size();i++){
			if(_s[i]!=char_t){
				if(char_t!='\0'){
					_ele.push_back(char_t);
					_num.push_back(num_t);
				}
				char_t = _s[i]; num_t = 1;
			}
			else{
				num_t++;
			}
		}_ele.push_back(char_t); _num.push_back(num_t);
	}
	
	string _s;
	vector<char> _ele;
	vector<int> _num;
};
class solution{
public:
	solution(void){
		cin>>_num; _flag = true;
		for(int i=0;i<_num;i++){
			_v.push_back(new gamestring());
		}
		for(int i=1;i<_v.size();i++){
			if(_v[i]->_ele!=_v[0]->_ele){
				cout<<"Fegla Won\n";
				_flag = false;
				break;
			}
		}
		if(_flag){
			int n[_num],sum=0;
			for(int i=0;i<_v[0]->_num.size();i++){
				for(int j=0;j<_num;j++){
					n[j]=_v[j]->_num[i];
				}
				intsort(n,_num);
				int mi = n[_num/2];
				for(int j=0;j<_num;j++)sum+=abs(n[j]-mi);
			}
			cout<<sum<<endl;
		}
	}
	
	vector<gamestring*> _v;
	int _num;
	bool _flag;
};

int main(){
	int time;
	cin>>time;
	for(int t=0;t<time;t++){
		cout<<"Case #"<<t+1<<": ";
		solution* k = new solution();
	}
}
