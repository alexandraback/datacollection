import java.io.*;
import java.util.*;
import java.math.*;

//         java -jar cj.jar test.txt
//         java -jar cj.jar A-small.practice.in.txt > as.txt
//         java -jar cj.jar A-large.practice.in.txt > al.txt

public class Main {
	
	public static void main(String[] args){
		assert(args.length == 1);
		parseTXT(args[0]);
	}
	
	private static void parseTXT(String file){
 		try{
			BufferedReader infile = new BufferedReader(new FileReader(file));
			int T = Integer.parseInt(infile.readLine()); // number of test cases
			for(int i = 0; i < T; i++){
				//parse test case to get input data for getReult function
				int r1, r2;
				Set<Integer> set1 = new HashSet<Integer>();
				Set<Integer> set2 = new HashSet<Integer>();
				
				r1 = Integer.parseInt(infile.readLine()) - 1;
				for(int k = 0; k < 4; k++){
					if(k != r1){
						infile.readLine();
					}else{
						String[] s = infile.readLine().split("\\s+");
						for(int j = 0; j < 4; j++) set1.add(Integer.parseInt(s[j]));
					}
				}
				r2 = Integer.parseInt(infile.readLine()) - 1;
				for(int k = 0; k < 4; k++){
					if(k != r2){
						infile.readLine();
					}else{
						String[] s = infile.readLine().split("\\s+");
						for(int j = 0; j < 4; j++) set2.add(Integer.parseInt(s[j]));
					}
				}
				set1.retainAll(set2);
				String res;
				if(set1.size() == 1) res = "" + set1.iterator().next();
				else if(set1.size() == 0) res = "Volunteer cheated!";
				else res = "Bad magician!";
				
				// print result
				int id = i+1;
				System.out.println("Case #" + id + ": " + res);
				
			}
			infile.close();
		}catch(IOException e){
			System.err.println("check input file " + file );
		}
	}
}








