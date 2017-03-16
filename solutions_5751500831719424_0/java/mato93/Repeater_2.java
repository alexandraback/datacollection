package Round_1B;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;
import java.util.Scanner;

public class Repeater_2 
{
	public static int getPrefix(StringBuilder s, char c){
		int temp = 0;
		while(s.length() > 0 && s.charAt(0) == c){
			s.deleteCharAt(0);
			temp++;
		}
		
		return temp;
	}
	
	public static int play(StringBuilder[] s){
		int n = s.length;
		int[] prefix = new int[n];
		int count = 0;

		boolean finished = false;
		boolean success = false;
		do{
			boolean allFinished = true;
			for(int i=0; i<n; i++){
				if(s[i].length() == 0){
					finished = true;
				} else {
					allFinished = false;
				}
			}
			if(finished) 
			{
				if(allFinished){
					success = true;
				}
				break;
			}
			
			char c = s[0].charAt(0);
			
			for(int i=1; i<n; i++){
				if(s[i].charAt(0) != c){
					finished = true;
					break;
				}
			}
			if(finished) break;

			
			
			for(int i=0; i<n; i++){
				prefix[i] = getPrefix(s[i],c);
			}
			Arrays.sort(prefix);
			int min = prefix[0];
			int max = prefix[n-1];
			
			int best = Integer.MAX_VALUE;
			for(int i=min; i<=max; i++){
				int current = 0;
				for(int j=0; j<n; j++){
					current += Math.abs(prefix[j] - i);
				}
				
				if(current < best){
					best = current;
				}
			}
			
			count += best;
			
		} while(!finished);
		
		if(success){
			return count;
		} else {
			return -1;
		}
	}
	
	
	public static void main(String[] args) 
	{
		try{
			String readFrom = "1B/A-small-attempt0.in";
			Scanner sc = new Scanner(new File(readFrom));
			FileWriter out = new FileWriter(new File("1B/A-small-attemp0.out"));
			
			int testCases = sc.nextInt();
			//System.out.println(testCases);
			int n = 0;
			for(int k=1; k<=testCases; k++)
			{
				n = sc.nextInt();
				//System.out.println(n);

				StringBuilder[] s = new StringBuilder[n];
				for(int i=0; i<n; i++){
					s[i] = new StringBuilder(sc.next());
					//System.out.println(s[i]);
				}
				
				int result = play(s);
				String res = "Case #" + k + ": " + ((result == -1) ? "Fegla Won" : result);
				System.out.println(res);
				out.write(res + "\n");
			}

			out.close();
		}catch(IOException e)
		{
			System.out.println("IO error");
		}

	}

}
