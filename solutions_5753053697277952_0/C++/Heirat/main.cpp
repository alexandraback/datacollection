#include <iostream>
#include <fstream>
#include <istream>
#include <ostream>
bool senate(std::istream *in, std::ostream *out){
	int N;
	*in>>N;char o;
	int x=0;
	int *a=new int[N];
	for(int i=0;i<N;++i){
		*in>>a[i];
		x+=a[i];
	}
	while(x>0){
		int max=0;
		int sec=0;
		for(int i=0;i<N;++i){
			if(a[i]>a[max]){
				max=i;
			}
		}
		if(max==0){
			sec=1;
		}else{
			sec=0;
		}
		for(int i=0;i<N;++i){
			if(max!=i){
				if(a[i]>a[sec]){
					sec=i;
				}
			}
		}
		if(a[sec]<a[max]){
			while(a[sec]!=a[max]){
				if(a[sec]<a[max]-1){
					o=((char)65+(char)max);
					*out<<o;
					--a[max];
					--x;
				}o=(char)65+(char)max;
				*out<<o<<' ';
				--a[max];--x;
			}
		}bool sp=false;
		for(int i=0;i<N;++i){
			if(i!=sec&&i!=max){
				while(a[i]>0){
					o=(char)65+(char)i;
					*out<<o;
					if(sp){
						*out<<' ';
					}
					sp=!sp;
					--a[i];--x;
				}
			}
		}
		if(sp){
			*out<<' ';
		}
		for(int i=0;i<a[max];++i){
			o=((char)65+(char)max);
			*out<<o;
			o=((char)65+(char)sec);
			*out<<o<<' ';
		}
		a[max]=a[sec]=0;x=0;
	}
	return true;
}
bool runProg(std::istream *in, std::ostream *out){
	int T;
	*in>>T;
	for(int i=0;i<T;++i){
		*out<<"Case #"<<i+1<<": ";
		senate(in, out);
		*out<<'\n';
	}
	return true;
}
int main(int argc, char* argv[]){
	std::istream* iPut;
	std::ostream* oPut;
	std::ifstream iFile;
	std::ofstream oFile;
	
	iPut=&std::cin;
	oPut=&std::cout;
	if(argc==1){
		std::cout<<"This program requires arguments.  "<<argv[0]<<" ifile [0file]\nRunning in debug mode\n";
	}
	if(argc==2){
		iFile.open(argv[1],std::ios::in);
		iPut=&iFile;
	}
	if(argc==3){
		iFile.open(argv[1],std::ios::in);
		oFile.open(argv[2],std::ios::out);
		iPut=&iFile;
		oPut=&oFile;
	}
	if(argc>3){
		std::cerr<<"Too many arguments\n";
		return 1;

	}
	//actual program stuff happens in here
	runProg(iPut, oPut);
	//end program stuff
	if(argc>1){
		iFile.close();

	}
	if(argc>2){
		oFile.close();
	}
	return 0;
}
