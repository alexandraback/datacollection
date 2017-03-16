import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class CJ2015_1A_A {

	public CJ2015_1A_A(){}
	public static void main( String[] asArguments ){
		doProblem();
	}
	
	static void doProblem(){
		String sDirectory = "R:\\dev\\codejam\\20151A\\A\\";
//		String sFileName = "A-example";
		String sFileName = "A-small-attempt0";
//		String sFileName = "A-small-attempt1";
//		String sFileName = "A-large";
		StringBuffer sbError = new StringBuffer();
		StringBuffer sbAnswer = new StringBuffer();
		String sAbsolutePath_input  = sDirectory + sFileName + ".in";
		String sAbsolutePath_output = sDirectory + sFileName + ".out";
		ArrayList<String> listLines = zLoadLines( sAbsolutePath_input, 50000, sbError );
		int ctTestCases = 0;
		int xLine = 0;
		try {
			ctTestCases = Integer.parseInt( listLines.get( xLine ) );
			System.out.println( "test case count: " + ctTestCases ); 
		} catch( Throwable t ) {
			System.err.println( "count test cases: " + t );
			System.exit( -1 );
		}
		for( int xTestCase = 1; xTestCase <= ctTestCases; xTestCase++ ){
			int ctObservations = Integer.parseInt( listLines.get( ++xLine ) );
			int[] pieces = splitInteger( listLines.get( ++xLine ) );
			int iAnswer_1 = 0;
			int min_per_10 = 0;
			for( int xPiece = 2; xPiece <= ctObservations; xPiece++ ){
				if( pieces[ xPiece ] < pieces[ xPiece - 1 ] ){
					int eaten = pieces[ xPiece - 1 ] - pieces[ xPiece ];
					if( eaten > min_per_10 ) min_per_10 = eaten;
					iAnswer_1 += eaten;
				}
			}
			int iAnswer_2 = 0;
			for( int xPiece = 1; xPiece < ctObservations; xPiece++ ){
				if( pieces[ xPiece ] > min_per_10 ){
					iAnswer_2 += min_per_10;
				} else {
					iAnswer_2 += pieces[ xPiece ];
				}
			}

			// write output
//			if( xTestCase % 100 == 0 ) System.out.println( "Case #" + xTestCase + ": " + ctFairAndSquareNumbers );
			sbAnswer.append( "Case #" + xTestCase + ": " + iAnswer_1 + " " + iAnswer_2 + "\n" );
		}
		fileSave( sAbsolutePath_output, sbAnswer.toString(), sbError );
		System.out.println( "wrote " + ctTestCases + " cases" );
	}

	/** values[0] = the number of items, any amount of whitespace can be between values */
	public static int[] splitInteger( String s ){
		if( s == null ) return null;
		boolean zWriting = false;
		boolean zInValue = false;
		int ctItems = 0;
		int pos = 0;
		int len = s.length();
		StringBuffer sb = new StringBuffer( );
		int[] values = null;
		while( true ){
			if( pos >= len ){
				if( zInValue ){
					ctItems++;
					if( zWriting ){
						try {
							values[ ctItems ] = Integer.parseInt( sb.toString() );
							sb.setLength( 0 );
						} catch( Throwable t ) {
							return null; // not an integer
						}
					}
				}
				if( zWriting ) break;
				values = new int[ ctItems + 1 ];
				values[ 0 ] = ctItems;
				pos = 0;
				zWriting = true;
				ctItems = 0;
				continue;
			}
			char c = s.charAt( pos );
			if( zInValue ){
				if( Character.isWhitespace( c ) ){
					ctItems++;
					if( zWriting ){
						try {
							values[ ctItems ] = Integer.parseInt( sb.toString() );
							sb.setLength( 0 );
						} catch( Throwable t ) {
							return null; // not an integer
						}
					}
				} else {
					if( zWriting ) sb.append( c );
				}
			} else {
				if( ! Character.isWhitespace( c ) ){
					zInValue = true;
				}
			}
			pos++;
		}
		return values;
	}

	// loads lines in a file into an array list of lines
	// content can include newlines if in quotation marks
	// End of Line:
	//   PC - carriage return plus line feed
	//   Macintosh - carriage return
	//   UNIX - line feed (usually called "new line" in UNIX parlance)
	// ASCII code in decimal: LF = 10; CR = 13
	public static ArrayList<String> zLoadLines( String sAbsolutePath, int iEstimatedSize, StringBuffer sbError){
		if( sAbsolutePath == null ){ sbError.append("path missing"); return null; }
		StringBuffer sbContent = new StringBuffer(iEstimatedSize);
		if( !fileLoadIntoBuffer( sAbsolutePath, sbContent, sbError ) ){
			sbError.insert(0, "error loading file (" + sAbsolutePath + "): ");
			return null;
		}
		return zLoadLines( sbContent, sbError );
	}
	
	public static ArrayList<String> zLoadLines( StringBuffer sbContent, StringBuffer sbError ){
		return zLoadLines( sbContent.toString(), sbError );
	}
		
	public static ArrayList<String> zLoadLines( String sContent, StringBuffer sbError ){ 
		int lenContent = sContent.length();
		ArrayList<String> listLines = new ArrayList<String>();
		StringBuffer sbLine = new StringBuffer(120);
		int pos = 0;
		int eState = 1;
		while( pos < lenContent ){
			char c = sContent.charAt(pos);
			switch( eState ){
				case( 1 ): // in line
					if( c == 13 ){
						eState = 2; // after CR
					} else if( c == 10 ){ // end of UNIX line
						listLines.add(sbLine.toString());
						sbLine.setLength(0);
					} else {
						sbLine.append(c);
					}
					pos++;
					break;
				case( 2 ): // after CR
					if( c == 10 ){ // reached end of PC line
						listLines.add(sbLine.toString());
						sbLine.setLength(0);
						pos++;
						eState = 1;
					} else if( c == 13 ){ // two mac lines in a row (stay in CR state)
						listLines.add(sbLine.toString());
						sbLine.setLength(0);
						pos++;
					} else { // single mac line
						listLines.add(sbLine.toString());
						sbLine.setLength(0);
						eState = 1;
					}
			}
		}
		if( sbLine.length() > 0 ) listLines.add(sbLine.toString()); // add any unterminated lines at end
		return listLines;
	}
	
	public static boolean fileLoadIntoBuffer( String sAbsolutePath, StringBuffer sbResource, StringBuffer sbError){
		File file = new File(sAbsolutePath);
		if( !file.exists() ){
			sbError.append("file not found");
			return false;
		}
		java.io.InputStream inputstreamResource = null;
		try {
			inputstreamResource = new FileInputStream(file);
		} catch(Exception ex) {
			sbError.append("unable to open file: " + ex);
			return false;
		}
		return zLoadString( inputstreamResource, sbResource, sbError );
	}
	
	public static boolean zLoadString( java.io.InputStream inputstreamResource, StringBuffer sbResource, StringBuffer sbError){
		if( inputstreamResource == null ){
			sbError.append("resource input stream does not exist");
			return false;
		}
		BufferedReader brFileToBeLoaded = null;
		try {
			int iFileCharacter;
			brFileToBeLoaded = new BufferedReader(new InputStreamReader(inputstreamResource));
			while(true) {
				iFileCharacter = brFileToBeLoaded.read();
				if(iFileCharacter==-1) break;
				sbResource.append((char)iFileCharacter);
			}
		} catch(Exception ex) {
			sbError.append("Failed to read resource: " + ex);
			return false;
		} finally {
			try {
				if(brFileToBeLoaded!=null) brFileToBeLoaded.close();
			} catch(Exception ex) {
				sbError.append("Failed to close resource: " + ex);
				return false;
			}
		}
		return true;
	}
		public static boolean fileSave( String sAbsolutePath, String sContent, StringBuffer sbError){
		File file = new File(sAbsolutePath);
		return fileSave( file, sContent, sbError );
	}

	public static boolean fileSave(  File file, String sContent, StringBuffer sbError ){

		// if file does not exist, create it
		try {
			if( ! file.exists() ){
				file.createNewFile();
			}
		} catch( Exception ex ) {
			sbError.append("failed to create file " + file + ": " + ex );
			return false;
		}


		// open file
		java.io.FileOutputStream fos = null;
		try {
		    fos = new java.io.FileOutputStream(file);
		} catch(Exception ex) {
			sbError.append("failed to open file for writing: " + ex);
			return false;
		}

		// save to file
		try {
			fos.write( sContent.getBytes() );
		} catch(Exception ex) {
			System.err.println("write failure (" + sContent.length() + " bytes): " + ex);
			return false;
		} finally {
			try {
				if( fos!=null ) fos.close();
			} catch(Exception ex) {}
		}
		return true;
	}

	public static String[] split( String s, char c ){
		if( s == null ) return null;
		int ctChar = getOccurrenceCount(s, c);
		int ctSegments = ctChar + 1;
		String[] asSegments = new String[ctSegments];
		if( ctChar == 0 ){ // minimal case
			asSegments[0] = s;
			return asSegments;
		}
		int len = s.length();
		int xSegment = 0;
		int posStartOfSegment = 0;
		for(int pos = 0; pos < len; pos++){
			if( s.charAt(pos) == c ){
				asSegments[xSegment] = s.substring(posStartOfSegment, pos);
				posStartOfSegment = pos + 1; // skip delimiter
				xSegment++;
			}
		}
		asSegments[xSegment] = s.substring(posStartOfSegment, len);
		return asSegments;
	}

	public static int getOccurrenceCount(String s, char c){
		if( s == null ) return 0;
		int len = s.length();
		if( len == 0 ) return 0;
		int iCount = 0;
		for(int pos = 0; pos < len; pos++){
			if( s.charAt(pos) == c ) iCount++;
		}
		return iCount;
	}
	
}