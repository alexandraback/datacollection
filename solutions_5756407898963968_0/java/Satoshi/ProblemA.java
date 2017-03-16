package jp.gr.java_conf.satstnka.gcj2014.qualification;

import java.io.*;
import java.util.*;

public class ProblemA {

	/**
	 * main function
	 * @param args arguments
	 * @throws Exception exception
	 */
	public static void main(String[] args) throws Exception {
		// input
		BufferedReader reader
		= new BufferedReader( new InputStreamReader( System.in ) );
		
		String line = reader.readLine();
		int num = Integer.parseInt( line );
		
		// each test cases
		for( int i = 1; i <= num; i++ ) {
			// first time
			line = reader.readLine();
			int row0 = Integer.parseInt( line );		
			HashSet vals = new HashSet();
			for( int j = 1; j <= 4; j++ ) {
				line = reader.readLine();
				if( j == row0 ) {
					StringTokenizer st = new StringTokenizer( line );
					while( st.hasMoreTokens() ) {
						String tok = st.nextToken();
						vals.add( new Integer( tok ) );
					}
				}				
			}

			// second time
			line = reader.readLine();
			int row1 = Integer.parseInt( line );
			int cnt = 0;
			int val = -1;
			for( int j = 1; j <= 4; j++ ) {
				line = reader.readLine();
				if( j == row1 ) {
					StringTokenizer st = new StringTokenizer( line );
					while( st.hasMoreTokens() ) {
						Integer tmp = new Integer( st.nextToken() );
						if( vals.contains( tmp ) ) {
							cnt = cnt + 1;
							val = tmp.intValue();
						}
					}
				}				
			}
			
			// output
			if( val > 0 && cnt == 1 ) {
				System.out.println( "Case #" + i + ": " + val );
			}
			else if( cnt > 1 ) {
				System.out.println( "Case #" + i + ": Bad magician!" );
			}
			else {
				System.out.println( "Case #" + i + ": Volunteer cheated!" );
			}
		}
		
		reader.close();
	}
}
