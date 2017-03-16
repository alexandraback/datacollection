package contest2014;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class ProblemA {
	
	private static ArrayList<String> inputList = new ArrayList<>();
	private static ArrayList<String> outputList = new ArrayList<>();
	private static String input = "A-small-attempt3.in"; 
	private static String output = "outputA.out";
	private static BufferedWriter buffer;
	
	public static void main( String args[] ){
		
		inputList = readFile( input );
		int trys = Integer.parseInt( inputList.remove( 0 ) );
		for( int i = 0; i < trys; i++ ){
			
				outputList.add("Case #" + ( i + 1 ) + ": " + question() );
			
		}
		writeFile( output , outputList );
	}
	
	public static String question(){
		int row;
		ArrayList<Integer> cards1 = new ArrayList<>();
		ArrayList<Integer> cards2 = new ArrayList<>();
		row = Integer.parseInt( inputList.remove( 0 ) );
		
		for( int i = 0; i < 4; i++ ){
			if( i + 1 == row ){
				int start = 0;
				int number = 0;
				for( int j = 0; j < inputList.get(0).length(); j++ ){
					
					if( inputList.get(0).charAt( j ) == ' ' ){
					
						number = Integer.parseInt( inputList.get(0).substring( start, j ) );
						start = j + 1;
						cards1.add( number );
							
					}
					if( j == inputList.get(0).length() - 1 ){
						
						number = Integer.parseInt( inputList.get(0).substring( start ) );
						cards1.add( number );
						
					}
		
				}
			}
			inputList.remove( 0 );
		}
		
		row = Integer.parseInt( inputList.remove( 0 ) );
	
		for( int i = 0; i < 4; i++ ){
			if( i + 1 == row ){
				int start = 0;
				int number = 0;
				for( int j = 0; j < inputList.get(0).length(); j++ ){
					
					if( inputList.get(0).charAt( j ) == ' ' ){
					
						number = Integer.parseInt( inputList.get(0).substring( start, j ) );
						start = j + 1;
						cards2.add( number );
							
					}
					if( j == inputList.get(0).length() - 1 ){
						
						number = Integer.parseInt( inputList.get(0).substring( start ) );
						cards2.add( number );
						
					}
		
				}
			}
			inputList.remove( 0 );
		}
		
		int choseNumber = 0;
		int count = 0;
		
		for( int i = 0; i < cards1.size(); i++){
			for( int j = 0; j < cards2.size(); j++ ){
				if( cards1.get(i) == cards2.get(j) ){
					count++;
					choseNumber = cards1.get(i);
				}
				if( count > 1 ){
					return "Bad magician!";
				}
			}
		}
		if( count == 1 ){
			return choseNumber + "";
		}
		if( count == 0 )
		return "Volunteer cheated!";
		return "";
	}
	
	
	
	public static ArrayList<String> readFile( String fileName ){
		File file = new File( fileName );
		FileReader fileReader = null;
		try{
			fileReader = new FileReader( file );
		} 
		catch( FileNotFoundException e ){
			System.err.println( "The File Doesn't Exist(error 1)." );
			e.printStackTrace();
			return null;
		}
		BufferedReader buffer = new BufferedReader( fileReader );
		String line = null;
		ArrayList<String> list = new ArrayList<String>();
		try{
			while( ( line = buffer.readLine() ) != null ){
				list.add( line );
			}
		}
		catch( IOException e ){
			System.err.println( "Buffer Can't read the line(error 2)." );
			e.printStackTrace();
			return null;
		}
		try{
			buffer.close();
		}catch( IOException e ){
			System.err.println( "Buffer Can´t close(error 3)." );
			e.printStackTrace();
			return null;
		}
		return list;
	}
	
	public static boolean writeFile(String fileName, ArrayList <String> lines){
		File file=new File(fileName);
		FileWriter fileWriter=null;
		try {
			fileWriter=new FileWriter(file);
		} catch (IOException e) {
			System.err.println("The File Doesn't Exist(error 4).");
			e.printStackTrace();
		}
		buffer = new BufferedWriter(fileWriter);
		for(String line : lines){
			try {
				buffer.write(line);
				buffer.newLine();
			} catch (IOException e) {
				System.err.println("Buffer Can't Read The Line(error 5).");
				e.printStackTrace();
				return false;
			}	
		}
		try {
			buffer.close();
		} catch (IOException e) {
			System.out.println("Buffer Can't Close(error 6).");
			e.printStackTrace();
		}
		return true;
	}
}
