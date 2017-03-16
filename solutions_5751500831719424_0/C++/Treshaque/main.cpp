#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <deque>
#include <iomanip>
#include <stdio.h>

using namespace std ;

int solveA( ifstream &inp ){
    int N ; inp >> N ;
        vector< string > lines( N ) ;
        for ( int i = 0 ; i < N ; ++i ){
            inp >> lines[ i ] ;
        }
        vector< char > pattern ;
        vector< vector< int > > nums( 1, vector< int >( 1, 1 ) ) ;
        pattern.push_back( lines[ 0 ][ 0 ] ) ;
        for ( int i = 1, iMax = ( int )lines[ 0 ].size() ; i < iMax ; ++i ){
            if ( lines[ 0 ][ i ] != pattern.back() ){
                    pattern.push_back( lines[ 0 ][ i ] ) ;
                nums.back().push_back( 1 ) ;
            } else {
                nums.back().back() += 1 ;
            }
        }
        for ( int row = 1 ; row < N ; ++row ){
            nums.push_back( vector< int >( 1, 0 ) ) ;
            int pos = 0 ;
            for ( int i = 0, iMax = ( int )lines[ row ].size() ; i < iMax ; ++i ){
                    char c = lines[ row ][ i ] ;
                if ( c == pattern[ pos ] ){
                        nums.back().back() += 1 ;
                } else if ( i > 0 && pos < ( int )pattern.size() - 1 && c == pattern[ pos + 1 ] ){
                    pos += 1 ;
                    nums.back().push_back( 1 ) ;
                } else {
                    return -1 ;
                }
            }
            if ( pos + 1 != ( int ) pattern.size() ){
                    return -1 ;
            }
        }
        int res = 0 ;
        for ( int col = 0, colMax = ( int )pattern.size() ; col < colMax ; ++col ){
            vector< int > column( N ) ;
            for ( int row = 0 ; row < N ; ++row ){
                    column[ row ] = nums[ row ][ col ] ;
            }
            sort( column.begin(), column.end() ) ;
            int median = column[ column.size() / 2 ] ;
            for ( int row = 0 ; row < N ; ++row ){
                    res += abs( nums[ row ][ col ] - median ) ;
            }
        }
        return res ;
}

int main(){
    ifstream inp( "C:/data/jam14b/inputAs.txt", ios::in ) ;
    ofstream out( "C:/data/jam14b/outputAs.txt", ios::out ) ;
    int tasks ; inp >> tasks ;
    for ( int task = 0 ; task < tasks ; ++task ){
            int res = solveA( inp ) ;
            out << "Case #" << task + 1 << ": " ;
            if ( res >= 0 ){
                    out << res ;
            } else {
                    out << "Fegla Won" ;
            }
            out << endl ;
    }








}







