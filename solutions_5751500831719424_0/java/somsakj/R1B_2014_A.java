import java.util.*;
import java.io.*;
import static java.lang.Math.*;

public class R1B_2014_A {
	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new FileReader("A-small-attempt0.in"));
		FileWriter fw = new FileWriter("A-small-attempt0.out");
		int T = new Integer(in.readLine());
		for (int cases = 1; cases <= T; cases++) {
			int N = new Integer(in.readLine());
			int y = 0;
			String[] input = new String[N];
			for(int i=0; i<N; i++){
				input[i] = in.readLine();
			}
			//small-case
			if(N==2){
				if(input[0].equals(input[1])){
					fw.write("Case #" + cases + ": 0\n");
					continue;
				}
				
				ArrayList iChar0 = new ArrayList();
				ArrayList<Integer> iNum0 = new ArrayList<Integer>();
				ArrayList iChar1 = new ArrayList();
				ArrayList<Integer> iNum1 = new ArrayList<Integer>();
				//count
				char[] iChar = input[0].toCharArray();
				char lastChar = iChar[0];
				int lastCharCount = 1;
				for(int j=1; j<iChar.length; j++){
					char curChar = iChar[j];
					if(curChar == lastChar){
						lastCharCount++;
					}
					else{
						iChar0.add(lastChar);
						iNum0.add(lastCharCount);
						lastCharCount = 1;
						lastChar = curChar;
					}
				}
				iChar0.add(lastChar);
				iNum0.add(lastCharCount);

				//count2
				iChar = input[1].toCharArray();
				lastChar = iChar[0];
				lastCharCount = 1;
				for(int j=1; j<iChar.length; j++){
					char curChar = iChar[j];
					if(curChar == lastChar){
						lastCharCount++;
					}
					else{
						iChar1.add(lastChar);
						iNum1.add(lastCharCount);
						lastCharCount = 1;
						lastChar = curChar;
					}
				}
				iChar1.add(lastChar);
				iNum1.add(lastCharCount);

				
				

				if(sameCharList(iChar0, iChar1)){ //possible
					//sum step
					y = 0;
					for(int k=0; k< iChar0.size(); k++){
						y += Math.abs(iNum0.get(k) - iNum1.get(k));
					}
					
					
					fw.write("Case #" + cases + ": " + y + "\n");
				}
				else{  //not possible
					fw.write("Case #" + cases + ": Fegla Won\n");
					
				}
				
				
			}
			
			
		}
		fw.flush();
		fw.close();
		
		System.out.println("Done!");
	}

	private static boolean sameCharList(ArrayList a1, ArrayList a2){
		if(a1.size() != a2.size())
			return false;
		
		for(int i=0; i< a1.size(); i++){
			if(a1.get(i) != a2.get(i)){
				return false;
			}
		}
		
		return true;
	}
}

