#include<iostream>
#include<vector>

#define VECINT std::vector<int>
#define VV std::vector<VECINT >
#define VECSTR std::vector<std::string>

const int INF =10000009;

int abs_value(int x){
	if(x<0) return x*(-1);
	return x;
}

int main(){
	std::ios_base::sync_with_stdio(false);
	
	unsigned int T;
	std::cin>>T;
	
	for(unsigned int t=0;t<T;++t){
		unsigned int N;
		std::cin>>N;
		VECSTR Strings(N);
		VV Table(N, VECINT(100,0));
		std::string Pattern="",Pattern_temp="";
		for(unsigned int i=0;i<N;++i) std::cin>>Strings[i];
		bool correct=true;
		for(unsigned int i=0;i<N&&correct;++i){
			Pattern_temp+=Strings[i][0];
			Table[i][0]=1;
			for(unsigned int j=1;j<Strings[i].length();++j){
				if(Strings[i][j]!=Strings[i][j-1])
					Pattern_temp+=Strings[i][j];
					
				Table[i][Pattern_temp.size()-1]++;
			}
			if(Pattern!="") correct=(Pattern==Pattern_temp);
			else Pattern=Pattern_temp;
			Pattern_temp="";
		}
		
		if(correct){
			unsigned int R=0;
			for(unsigned int p=0;p<Pattern.size();++p){
				unsigned int r_local=INF;
				for(unsigned int k=1;k<=100;++k){
					unsigned int r=0;
					for(unsigned int i=0;i<N;++i)
						r+=abs_value(Table[i][p]-k);
							
					r_local=std::min(r,r_local);
				}
				R+=r_local;
			}
			
			std::cout<<"Case #"<<(t+1)<<": "<<R<<"\n";
		}
		else
			std::cout<<"Case #"<<(t+1)<<": "<<"Fegla Won"<<"\n";
	}
	
	return 0;
}
