package codejam2014.round1b;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.Reader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;


public class P1 {
	
	public String solve(String[] strArr){
		List<Integer> freq;
		int count = 0;
		try{
			while((freq = getFreq(strArr)).size() > 0){
				Collections.sort(freq);
				int size = freq.size();
				if(size %2 == 0){
					int mid = size/2;
					
					int count1 = getDiffCount(freq, freq.get(mid));
					int count2 = getDiffCount(freq, mid-1);
					count+= Math.min(count1, count2);
				}else{
					int mid = size/2;
					count += getDiffCount(freq, freq.get(mid));
				}
			}
		}
		catch (Exception e) {
			return "Fregla Won";
		}
		
		return ""+count;
	}
	
	private int getDiffCount(List<Integer> list, int num){
		int count = 0;
		for(int i=0; i < list.size() ; i++){
			count += Math.abs((list.get(i) -num));
		}
		return count;
	}
	private List<Integer> getFreq(String[] strArr) throws Exception{
		List<Integer> list = new ArrayList<Integer>();
		
		if(strArr[0].length() > 0)
		{
			char character = strArr[0].charAt(0);
			
			for(int i=0; i < strArr.length; i++){
				int count =0;
				for(int j=0; j < strArr[i].length(); j++)
				{
					if(strArr[i].charAt(j) == character){
						count++;
					}else{
						break;
					}
				}
				
				if(count == 0){
					throw new Exception("Not possible");
				}
				list.add(count);
				if(strArr[i].length() ==count){
					strArr[i] = "";
				}
				else{
					strArr[i] = strArr[i].substring(count);
				}
			}
		}else{
			for(int i=0; i < strArr.length; i++){
				if(strArr[i].length() > 0){
					throw new Exception("Not possible");
				}
			}
		}
		return list;
		
	}
	public static void main(String[] argv) {
		try {
			long startTime = System.currentTimeMillis();
			Reader reader = new FileReader("C:\\Users\\AvinashS\\Desktop\\google\\mid\\small.in");
			BufferedReader bufReader = new BufferedReader(reader);
			String x = bufReader.readLine();
			int numOfTestCases = Integer.parseInt(x);
			int count = 0;
	
			File file = new File("C:\\Users\\AvinashS\\Desktop\\google\\mid\\small.out");
			FileWriter writer = new FileWriter(file);
			for(count =1; count<= numOfTestCases; count++) {
				int numberOfLines = Integer.parseInt(bufReader.readLine());
				String[] strArr = new String[numberOfLines];
				for(int i=0; i < numberOfLines; i++){
					strArr[i] = bufReader.readLine();
				}
				String res = new P1().solve(strArr);
				writer.write("Case #" + count + ": "+res+"\n");
				System.out.println("Case #" + count + ": "+res );
			}
			writer.close();
			System.out.println("Total time = " + (System.currentTimeMillis() - startTime));
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
	
	private static ArrayList<Integer> getIntegerList(String s) {
		ArrayList<Integer> intList = new ArrayList<Integer>();
		String[] strArr = s.split(" ");
		for (String str : strArr) {
			intList.add(Integer.parseInt(str.trim()));
		}
		return intList;
	}
}
