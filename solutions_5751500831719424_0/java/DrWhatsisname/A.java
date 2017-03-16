package round1B;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Scanner;


public class A {

	public static void main(String[] args) {
		
		Scanner in;
		PrintWriter out;
		try {
			in = new Scanner(new File("a-small-attempt2.in"));
			out = new PrintWriter("a2.out");
		} catch (FileNotFoundException e) {
			e.printStackTrace();
			System.exit(1);
			return;
		}
		
		int numCases = in.nextInt();
		
		for (int t = 1; t <= numCases; t++){
			
			
			int numStrings = in.nextInt();
			
			ArrayList<ArrayList<String>>  strings = new ArrayList<>();
			for (int i = 0; i<numStrings;i++){
				String s = in.next();
				strings.add(i, split(s));
			}
			
			System.err.println("Case #" + t);
			for (int i = 0; i< strings.size(); i++){
				System.err.println(strings.get(i).toString());
				System.err.println(strings.get(i).size());
			}
			
			int moves = solve(strings);
			
			if (moves == -1){
				out.println("Case #" + t + ": Fegla Won");
			}
			
			else out.println("Case #" + t + ": " + moves);
			
						
			
		}
		
		in.close();
		out.close();
		
	}
	
	private static int solve(ArrayList<ArrayList<String>> strings){
		for (int i = 1; i < strings.size(); i++){
			if (strings.get(i).size() != strings.get(0).size()){
				System.err.println("Not enough characters");
				return -1;
				
			}
			for (int j = 0; j < strings.get(0).size(); j++){
				if (strings.get(0).get(j).charAt(0) != strings.get(i).get(j).charAt(0)){
					System.err.println("Character mismatch");
					return -1;
				}
			}
		}
		int moves = 0;
		for (int j = 0; j < strings.get(0).size(); j++){
			int sum = 0;
			for (int i = 0; i < strings.size(); i++){
				sum+=strings.get(i).get(j).length();
			}
			int avg = (int)((double)sum/strings.size()+.5);
			System.err.print(avg + " ");
			for (int i = 0; i < strings.size(); i++){
				moves+=Math.abs(strings.get(i).get(j).length()-avg);
			}
		}
		System.err.println();
		System.err.println("Good: " + moves);
		return moves;
		
	}
	
	private static ArrayList<String> split(String s){
		ArrayList<String> result = new ArrayList<>();
		int i=0;
		while (i < s.length()){
			int j = i+1;
			while (j < s.length() && s.charAt(i)==s.charAt(j)) j++;
			result.add(s.substring(i,j));
			i=j;
		}
		return result;
	}

	
}
