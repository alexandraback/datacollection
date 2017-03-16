#include <fstream>
#include <ax/ax_core.h> //libax.googlecode.com

std::ifstream	inFile;
axFile			outFile;

axStatus	output( int caseId, int turn ) {
	axStringA_<256>	tmp;
	
	tmp.format("Case #{?}: ", caseId );
	
	if( turn < 0 ) {
		tmp.append("Fegla Won");
	}else{
		tmp.appendFormat("{?}", turn);
	}
	
	tmp.append("\n");
	
	outFile.writeString( tmp );
	ax_print( tmp );

	return 0;
}

struct K {
	K() {
		ch = 0;
		count = 0;
	}
	char ch;
	int	 count;
	
	axStatus onTake( K & src ) {
		ch = src.ch;
		count = src.count;
		return 0;
	}
	
	axStatus toStringFormat( axStringFormat & f ) const {
		return f.format("{?} {?}", ch, count);
	}
};

axStatus	doCase( int caseId ) {
	int n;
	inFile >> n;

	axArray< axArray<K,100>, 100 >	ss;

	std::string	tmp;

	int turn = 0;

	ss.resize(n);
	for( int i=0; i<n; i++ ) {
		inFile >> tmp;

		auto & s = ss[i];

		for( auto & ch : tmp ) {
			if( s.size() > 0 ) {
				if( s.last().ch == ch ) {
					s.last().count++;
					continue;
				}
			}
			
			K k;
			k.ch = ch;
			k.count = 1;
			s.append( k );
		}
	}
	
	auto & k0 = ss[0];

	for( int i=1; i<n; i++ ) {
		if( ss[i].size() != k0.size() ) return output( caseId, -1 );
	}

	for( axSize j=0; j<k0.size(); j++ ) {
		axArray< int, 100 >	sa;
		
		auto ch   = k0[j].ch;
		
		sa.append( k0[j].count );
	
		for( int i=1; i<n; i++ ) {
			auto & k = ss[i][j];
			if( k.ch != ch ) {
				return output( caseId, -1 );
			}
			sa.append( k.count );
		}

		int thisTurn = -1;
		
		for( int i=0; i<n; i++ ) {
			auto target = sa[i];
			
			int tryTurn = 0;
			
			for( int q=0; q<n; q++ ) {
				tryTurn += ax_abs(sa[q] - target);
			}
			
			if( thisTurn < 0 ) {
				thisTurn = tryTurn;
			}else{
				thisTurn = ax_min( thisTurn, tryTurn );
			}
		}
		
		turn += thisTurn;
	}
			
	output( caseId, turn );

	return 0;
}

axStatus	run() {
	axStatus	st;
		
	inFile.open("A-large.in");
	if( ! inFile.is_open() ) return -1;
	
	st = outFile.openWrite("out.txt", true, true);		if( !st ) return st;

	axStringA	buf;
	int C;
	inFile >> C;
	for( int c=0; c<C; c++ ) {
		st = doCase( c+1 );			if( !st ) return st;
	}
	return 0;
}


axStatus	changeDir() {
	axStatus st;
	axStringA path;
	st = axFilePath::dirName(path, __FILE__ );		if( !st ) return st;
	st = axFileSystem::setCurrentDir(path);				if( !st ) return st;
	return 0;
}


int main(int argc, const char * argv[]) {
	@autoreleasepool {
		changeDir();

		axStatus st = run();
		ax_log("===== end of program - return {?} =====", st );
	}
    return 0;
}

