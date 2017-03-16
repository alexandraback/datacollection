package com.mw.google.codejam2014;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class TheRepeater {
	
	static class Data {
		char c;
		int num;
	}
	
	public static String solve(List<String> list) {
		
		List<List<Data>> allDataList = new ArrayList<>();
		for (String s : list) {
			List<Data> dataList = new ArrayList<>();
			Data data = new Data();
			data.c = s.charAt(0);
			data.num = 1;
			dataList.add(data);
			for (int i = 1; i < s.length(); i++) {
				char c = s.charAt(i);
				if (c == data.c) {
					data.num++;
				} else {
					data = new Data();
					data.c = c;
					data.num = 1;
					dataList.add(data);
				}
			}
			allDataList.add(dataList);
		}
		
		List<Data> refDataList = allDataList.get(0);
		int totalSplitSize = refDataList.size();
		List<Integer> maxList = new ArrayList<>(totalSplitSize);
		List<Integer> minList = new ArrayList<>(totalSplitSize);

		for (int i = 1; i < allDataList.size(); i++) {
			List<Data> dataList = allDataList.get(i);
			if (totalSplitSize == dataList.size()) {
				for (int j = 0; j < totalSplitSize; j++) {
					if (refDataList.get(j).c == dataList.get(j).c) {
						if (maxList.size() < j+1) {
							maxList.add(Math.max(refDataList.get(j).num, dataList.get(j).num));
							minList.add(Math.min(refDataList.get(j).num, dataList.get(j).num));
						} else {
							maxList.set(j, Math.max(maxList.get(j), dataList.get(j).num));
							minList.set(j, Math.min(minList.get(j), dataList.get(j).num));
						}
					} else {
						return "Fegla Won";
					}
				}
			} else {
				return "Fegla Won";
			}
		}
		
		int count = 0;
		for (int j = 0; j < maxList.size(); j++) {
			List<Integer> numList = new ArrayList<>();
			for (int i = 0; i < allDataList.size(); i++) {
				numList.add(allDataList.get(i).get(j).num);
			}
			System.out.println(allDataList.get(0).get(j).c);
			count += getMinCount(numList, maxList.get(j), minList.get(j));
		}
		
		return String.valueOf(count);
	}
	
	public static int getMinCount(List<Integer> list, int max, int min) {
		int minCount = Integer.MAX_VALUE;
		for (int i = min; i <= max; i++) {
			System.out.println("i: " + i);
			int tempCount = 0;
			for (Integer j : list) {
				System.out.println("j: " + j);
				tempCount += Math.abs(j - i);
			}
			
			System.out.println("minCount: " + minCount);
			if (minCount >= tempCount) {
				minCount = tempCount;
			} else {
				return minCount;
			}
		}
		
		return minCount;
	}

	public static void main(String[] args) throws FileNotFoundException, UnsupportedEncodingException {
		if (args.length < 1) {
			throw new IllegalArgumentException("Need filename as input");
		}

		File file = new File(args[0]);
		PrintWriter writer = new PrintWriter(args[0] + ".out", "UTF-8");
		Scanner scanner = new Scanner(file);
		int numOfTests = scanner.nextInt();
		for (int i = 1; i <= numOfTests; i++) {
			int num = scanner.nextInt();
			List<String> stringList = new ArrayList<>();
			for (int j = 0; j < num; j++) {
				stringList.add(scanner.next());
			}
			writer.println("Case #" + i + ": " + solve(stringList));
		}
		scanner.close();
		writer.close();

	}
}
