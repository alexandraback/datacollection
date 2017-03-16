import java.util.*;
import java.io.*;
import static java.lang.Math.*;

class Tuple implements Comparable<Tuple> {
	char c;
	int rec;

	Tuple( char c, int rec ) {
		this.c = c;
		this.rec = rec;
	}

	public int compareTo( Tuple t ) {
		return rec - t.rec;
	}

	public String toString() {
		return String.format( "(%c, %d)", c, rec );
	}
}

class Main {

    public static void main( final String[] args ) {

		final Scanner stdin = new Scanner( System.in );
		final int T = stdin.nextInt();
		for ( int t = 1; t <= T; t++ ) {
			final int N = stdin.nextInt();
			List<List<Tuple>> lst = new ArrayList<List<Tuple>>();
			for ( int i = 0; i < N; i++ ) {
				final String input = stdin.next();
				lst.add( parse( input ) );
			}
			if ( hasSameSize( lst ) && hasSameCharacter( lst ) ) {
				int cost = 0;
				final int size = lst.get( 0 ).size();
				for ( int i = 0; i < size; i++ ) {
					ArrayList<Tuple> tmp = new ArrayList<Tuple>();
					for ( List<Tuple> l : lst ) {
						tmp.add( l.get( i ) );
					}
					Collections.sort( tmp );
					final int min = tmp.get( 0 ).rec;
					final int max = tmp.get( tmp.size() - 1 ).rec;
					int localCost = Integer.MAX_VALUE;
					for ( int j = min; j <= max; j++ ) {
						localCost = Math.min( localCost, eval( tmp, j ) );
					}
					cost += localCost;
				}
				System.out.printf( "Case #%d: %d\n", t, cost );
			} else {
				System.out.printf( "Case #%d: Fegla Won\n", t );
			}
		}		
    }
	
	static int eval( List<Tuple> l, int i ) {
		int accum = 0;
		for ( Tuple t : l ) {
			accum += Math.abs( t.rec - i );
		}
		return accum;
	}

	static boolean hasSameCharacter( List<List<Tuple>> lst ) {
		final int size = lst.get( 0 ).size();
		for ( int i = 0; i < size; i++ ) {
			final char ch = lst.get( 0 ).get( i ).c;
			for ( List<Tuple> l : lst ) {
				if ( ch != l.get( i ).c ) {
					return false;
				}
			}
		}
		return true;
	}
	
	static boolean hasSameSize( List<List<Tuple>> lst ) {
		final int size = lst.get( 0 ).size();
		for ( List<Tuple> l : lst ) {
			if ( l.size() != size ) {
				return false;
			}
		}
		return true;
	}			
	
	static List<Tuple> parse( final String input ) {
		List<Tuple> ans = new ArrayList<Tuple>();
		char before = input.charAt( 0 );
		int count = 0;
		for ( char ch : input.toCharArray() ) {
			if ( ch == before ) {
				count++;
			} else {
				ans.add( new Tuple( before, count ) );
				before = ch;
				count = 1;
			}
		}
		ans.add( new Tuple( before, count ) );
		return ans;
	}
}
