package interview;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;

public class Solution_GJ {
	
	private Solution_GJ(){}
	
	public static void main(String[] args) throws IOException{
		String file = "C:/zfeng/A-small-attempt0.in";
		String output = "C:/zfeng/A-small-attempt0.out";
		//String file = "C:/zfeng/test1.txt";
		//String output = "C:/zfeng/output.txt";
		BufferedReader content =  new BufferedReader(new FileReader(file));	
		PrintWriter outputFile = new PrintWriter(new FileWriter(output));
		
		int num_cases = Integer.parseInt( content.readLine() );
		
		for( int i = 1; i<=num_cases; i++ ){
			int N = Integer.parseInt( content.readLine() );
			ArrayList<String> array = new ArrayList<String>();
			for ( int j=0; j<N; j++){		
				String dataRow = content.readLine();
				array.add(dataRow);
			}
			
			int num = isMatch( array );
			if( num ==-1 )
				outputFile.println("Case #"+i+": Fegla Won");
			else
				outputFile.println("Case #"+i+": "+num);
			
		}
		
		content.close();
		outputFile.close();		
	}
	
	public static int isMatch( ArrayList<String> array ){
		int step = 0;
		int N= array.size();
		int[] num_rep = new int[array.size()];
		int[] index = new int[array.size()];
		int valid = 0;
		for(int k=0; k<N; k++){
			if( index[k]<array.get(k).length())
				valid++;
		}
		if( valid<N && valid>0 )
			return -1;
		while( valid==N ){
			char ankor = array.get(0).charAt(index[0]);
			for( int i=0; i<array.size(); i++ ){
				String str = array.get(i);
				int id = index[i]+1;
				if( i>0 && ankor != str.charAt(index[i]))
					return -1;
				while( id<str.length()&&str.charAt(index[i]) == str.charAt(id)){
					id++;
				}
				num_rep[i] = id - index[i];
				index[i] = id;				
			}
			step += minStep( num_rep );
			
			valid = 0;
			for(int k=0; k<N; k++){
				if( index[k]<array.get(k).length())
					valid++;
			}
			if( valid<N && valid>0 )
				return -1;
		}
		
		
		return step;
	}
	
	public static int minStep( int[] copy ){
		Arrays.sort( copy );
		int old_sum = Integer.MAX_VALUE;
		
		for(int i=1; i<copy.length; i++){
			int sum = 0;
			for(int j=0; j<i; j++)
				sum -= copy[j];
			for(int j=i; j<copy.length;j++)
				sum += copy[j];
			int num_x = 2*i - copy.length;
			int x = num_x >0?copy[i-1]:copy[i];
			sum += num_x * x;
			if( sum< old_sum ){
				old_sum = sum;
			}
		}
				
		return old_sum;
	}
	
}
