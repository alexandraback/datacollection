package googleJamR1B;

import java.util.*;
import java.io.*;

public class TheRepeater {
	private static Scanner reader = new Scanner(System.in);
	private static String inputFolder;

	public static void main(String[] args) throws Exception {
		inputFolder = reader.nextLine();
		
		BufferedReader br = new BufferedReader(new FileReader(inputFolder
				+ "\\input.txt"));
		BufferedWriter bw = new BufferedWriter(new FileWriter(inputFolder
				+ "\\output.txt"));

		int howManyRounds = Integer.parseInt(br.readLine());
		String currLine;
		int N;
		String[] strings;
		int result;

		for (int i = 1; i <= howManyRounds; i++) {
			currLine = br.readLine();
			N = Integer.parseInt(currLine);
			strings = new String[N];
			for (int j=0 ; j<strings.length ; j++){
				strings[j] = br.readLine();
			}
			result = returnResults(N,strings);
			if (result == -1){
				bw.write("Case #"+i+": Fegla Won\n");
			}
			else{
				bw.write("Case #"+i+": "+result+"\n");
			}
			
		}
		
		
		br.close();
		bw.close();
	}
	
	public static int returnResults(int N, String[] strings){
		int result = 0;
		String order = ""+strings[0].charAt(0);
		for(int i=1 ; i<strings[0].length(); i++){
			if(strings[0].charAt(i) != order.charAt(order.length()-1)){
				order += strings[0].charAt(i);
			}	
		}
		
		for(int i=1 ; i<strings.length ; i++){
			if (!checkOrder(order,strings[i])){
				return -1;
			}
		}
		int N2 = order.length();
		for(int i=0 ; i<N2 ; i++){
			result += costForNext(strings,order.charAt(i));
		}
		
		return result;
	}
	
	public static boolean checkOrder(String order, String toCheck){
		int place=0;
		boolean beenThisPlace = false;
		for(int i=0 ; i<toCheck.length();i++){
			if(toCheck.charAt(i) == order.charAt(place)){
				beenThisPlace = true;
				continue;
			}
			else if (place == order.length()-1)
				return false;
			else if (beenThisPlace && toCheck.charAt(i) == order.charAt(place + 1)){
				place +=1;
				beenThisPlace = true;
				continue;
			}
			else {
				return false;
			}
		}
		
		if (place == order.length()-1 && beenThisPlace == true)
			return true;
		else
			return false;
	}
	
	public static int costForNext(String[] strings, char c){
		int[] lengths = new int[strings.length];
		for (int i=0 ; i<lengths.length ; i++){
			lengths[i] = 0;
			while (strings[i].length()>0 && strings[i].charAt(0) == c){
				lengths[i] += 1;
				strings[i] = strings[i].substring(1);
			}
		}
		int dist;
		int maxDist = Integer.MAX_VALUE;
		for (int i=1 ; i<=100 ; i++){
			dist = 0;
			for (int j=0 ; j<lengths.length ; j++){
				dist += Math.abs(i-lengths[j]); //add to dist how many letters we have to change in j-th string
			}
			if (dist < maxDist)
				maxDist = dist;
		}
		
		return maxDist;
		
	}
}
