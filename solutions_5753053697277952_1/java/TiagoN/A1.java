package iC;

import java.util.Scanner;

public class A1 {

	public static String[] letter = {"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};
	
	public static String work(int[] partie){
		String result = "";
		int max;
		int count = countParties(partie);
		
		while(count>0){
			max = getMax(partie);
			result += letter[max];
			partie[max]--;
			count = countParties(partie);
			if(count>0 && !(countNum(partie)==2 && count==2)){
				max = getMax(partie);
				result += letter[max];
				partie[max]--;
			}
			if(count>0)
				result+=" ";
			count = countParties(partie);
		}
		
		return result;
	}
	
	public static int getMax(int[] partie){
		int pos=0;
		int max=0;
		for(int i=0; i<partie.length; i++){
			if(partie[i]>max){
				max = partie[i];
				pos=i;
			}
		}
		return pos;
	}
	
	public static int countNum(int[] partie){
		int count=0;
		for(int i=0; i<partie.length; i++){
			if(partie[i]>0)
				count++;
		}
		return count;
	}
	
	public static int countParties(int[] partie){
		int count=0;
		for(int i=0; i<partie.length; i++){
			count+=partie[i];
		}
		return count;
	}
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int t = in.nextInt();
		
		for (int i = 1; i <= t; ++i) {
			int n = in.nextInt();
			int[] partie = new int[n];
			for(int j=0; j<n; j++){
				partie[j] = in.nextInt();
			}
			System.out.println("Case #" + i + ": " + work(partie));
			
		}

	}

}
