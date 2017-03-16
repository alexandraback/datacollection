package gcj14;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;
import java.util.Set;

public class TheRepeater {

	private String getAnswer(String[] words) {
		List<List<String>> lists = new ArrayList<List<String>>();
		
		boolean ok = true;
		int prevSize = -1;
		for(int i = 0; i < words.length; i++) {
			List<String> curList = new ArrayList<String>();
			lists.add(curList);
			
			String cur = words[i];
			
			char curChar = cur.charAt(0);
			StringBuilder sb = new StringBuilder();
			sb.append(curChar);
			
			for(int j = 1; j < cur.length(); j++) {
				if (curChar != cur.charAt(j)) {
					curList.add(sb.toString());
					sb = new StringBuilder();
					sb.append(cur.charAt(j));
					curChar = cur.charAt(j);
				} else {
					sb.append(curChar);
				}
			}
			curList.add(sb.toString());
			
			if (prevSize != -1 && prevSize != curList.size()) ok = false;
			prevSize = curList.size();
		}
		
		if (!ok) return "Fegla Won";
		if (!check(lists)) return "Fegla Won";
		
		int res = 0;
		for (int i = 0; i < lists.get(0).size(); i++) {
			List<String> comps = new ArrayList<String>();
			
			for (int j = 0; j < lists.size(); j++) {
				comps.add(lists.get(j).get(i));
			}
			
			res += count(comps);
		}
		
		return String.valueOf(res);
	}
	
	private static final boolean check(List<List<String>> lists) {
		for (int i = 0; i < lists.get(0).size(); i++) {
			char temp = lists.get(0).get(i).charAt(0);
			
			for (int j = 0; j < lists.size(); j++) {
				char ch = lists.get(j).get(i).charAt(0);
				
				if (temp != ch) return false; 
			}
		}
		
		return true;
	}
	
	private static int count(List<String> list)  {
		int max = 0;
		for (int i = 0; i < list.size(); i++) {
			max = Math.max(list.get(i).length(), max);
		}
		
		int res = Integer.MAX_VALUE;
		for (int i = 1; i <= max; i++) {
			int tempRes = 0;
			for (int j = 0; j < list.size(); j++) {
				tempRes += Math.abs(i - list.get(j).length());
			}
			
			res = Math.min(res, tempRes);
		}
		
		return res;
	}
	
	public static final String INPUT_FILE_PATH = "C://DiskD//CodeJamInput.txt";
	public static final String OUTPUT_FILE_PATH = "C://DiskD//CodeJamOutput.txt";

	public static void main(String[] args) {
		Scanner in = null;
		PrintWriter writer = null;
		try {
			System.out.println("start");

			in = new Scanner(new File(INPUT_FILE_PATH));
			writer = new PrintWriter(new FileWriter(OUTPUT_FILE_PATH));
			int testCount = in.nextInt();

			for (int i = 0; i < testCount; i++) {
				int N = in.nextInt();
				String[] words = new String[N];
				
				for(int j = 0; j < words.length; j++) {
					words[j] = in.next();
				}
				
				System.out.println(i);
				writer.println("Case #" + (i + 1) + ": " + new TheRepeater().getAnswer(words));
			}
			writer.flush();

			System.out.println("end");
		} catch (IOException ex) {
			ex.printStackTrace();
		} finally {
			if (in != null) in.close();
			if (writer != null) writer.close();
		}
	}

}
