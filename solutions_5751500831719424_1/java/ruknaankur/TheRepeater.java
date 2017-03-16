package com.self.code.jam.fourteen;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.Reader;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

public class TheRepeater {

	public static void main(String[] argv)
	{
		try
		{
			long startTime = System.currentTimeMillis();
			Reader reader = new FileReader("D:\\workspace\\Learn\\src\\com\\self\\code\\jam\\fourteen\\tr\\A-large.in");
			BufferedReader bufReader = new BufferedReader(reader);
			int x = Integer.parseInt(bufReader.readLine().trim());
			int count = 0;

			File file = new File("D:\\workspace\\Learn\\src\\com\\self\\code\\jam\\fourteen\\tr\\A-large.out");
			FileWriter writer = new FileWriter(file);
			
			for (int i = 0; i < x ; i++)
			{
				count++;
				String res = TheRepeater.movesToMakeStringIdentical(bufReader);
				writer.write("Case #"+count+": " + res + "\n");
			}
			writer.close();
			System.out.println("Total time = " +( System.currentTimeMillis() - startTime));
		}
		catch (Exception e) {
			e.printStackTrace();
		}
	}

	private static String movesToMakeStringIdentical(BufferedReader bufReader) throws NumberFormatException, IOException {
		int N = Integer.parseInt(bufReader.readLine().trim());
		String[] strArr = new String[N];
		
		String uniqueString = null; 
		
		Map<Integer, int[]> charMap = new HashMap<Integer, int[]>();// key = index of the character in uniquestring, value = List of no of occurrences in each string
		
		boolean returnFaglaWon = false;
		
		
		for (int i= 0; i< N;i++)
		{
			strArr[i] = bufReader.readLine(); 
			String s = strArr[i];
			String lastChar = null;
			
			String fullNonRepeatStr = "";
			
			for (int j=0; j<s.length(); j++)
			{
				String charctr = s.substring(j, j+1);
				
				if (j == 0) {
					fullNonRepeatStr = fullNonRepeatStr + charctr;
					increaseTheCount(charMap, fullNonRepeatStr.length() -1 , i, N);
				}
				else {
					if (!lastChar.equalsIgnoreCase(charctr))
					{
						fullNonRepeatStr = fullNonRepeatStr + charctr;
					}
					increaseTheCount(charMap, fullNonRepeatStr.length() -1 , i, N);
				}
				lastChar = charctr;
				
			}
			
			if (i == 0)
			{
				uniqueString = fullNonRepeatStr;
			}
			else if (!uniqueString.equalsIgnoreCase(fullNonRepeatStr))
				returnFaglaWon = true;
				
			
		}
		
		if (returnFaglaWon)
			return "Fegla Won";
		
		int totalMoves = 0;
		
		
		for (int i=0; i<uniqueString.length();i++)
		{
			int[] arr = charMap.get(i);
			Arrays.sort(arr);
			
			int len = arr.length;
			int mid = (len-1)/2;
			
			if (len%2 == 0)
			{
				// check for mid and mid +1
				totalMoves = totalMoves + Math.min(getMoves(arr, mid), getMoves(arr, mid+1));
			}
			else {
				mid = (len-1) /2;
				
				totalMoves = totalMoves + getMoves(arr, mid);
				
			}
		}
		
		
		return String.valueOf(totalMoves);
	}

	private static int getMoves(int[] arr, int mid) {
		int midEl = arr[mid];
		int moves = 0;
		for (int i =0; i<arr.length;i++)
		{
			moves = moves + Math.abs(arr[i]-midEl);
			
		}
		
		return moves;
	}

	private static void increaseTheCount(Map<Integer, int[]> charMap, int keyIndex, int listIndex, int N) {
		if (charMap == null) return;
		if (charMap.get(keyIndex) == null)
			charMap.put(keyIndex, new int[N]);
		
		int[] arr = charMap.get(keyIndex);
		arr[listIndex] = arr[listIndex] + 1; 
	}

}
