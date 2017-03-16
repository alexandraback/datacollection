
import java.util.Scanner;

public class Main {
	public static int findMax(Integer[] P){
		int index = 0;
		for(int i=1; i<P.length; i++){
			if(P[index] < P[i]){
				index = i;
			}
		}
		if(index == 0 && P[0] == 0){
			return -1;
		}
		
		return index;
	}
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int T = scanner.nextInt();
		for(int count=1; count<=T; count++){
			String output = "";
			int N = scanner.nextInt();
			Integer[] P = new Integer[N];
			char[] pNames = new char[N];
			for(int i=0; i<N; i++){
				P[i] = scanner.nextInt();
				pNames[i] = (char) ('A' + i);
			}
			int maxIndex = findMax(P);
			while(maxIndex > -1){
				
				P[maxIndex] -= 1;
				String str = ""+pNames[maxIndex];
				maxIndex = findMax(P);
				if(maxIndex > -1){
					str = str + pNames[maxIndex];
					P[maxIndex] -= 1;
				}
		
				output += str;
				maxIndex = findMax(P);
				if(maxIndex == -1){
					break;
				}else{
					output += " ";
				}
			}
			//we need to swap the last two in last we have only one
			String[] tokens = output.split(" ");
			if(tokens[tokens.length-1].length() == 1){
				//swap the last two with each other
				String temp = tokens[tokens.length-1];
				tokens[tokens.length-1] = tokens[tokens.length-2];
				tokens[tokens.length-2] = temp;
			}
			output="";
			for(String myStr : tokens){
				output = output+myStr+" ";
			}
			output = output.substring(0, output.length()-1);
			System.out.println("Case #"+count+": "+output);
		}
		scanner.close();
	}
}
