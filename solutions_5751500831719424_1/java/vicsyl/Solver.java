package google.jam.repeater;

import google.jam.template.Template;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.LinkedList;
import java.util.List;

public class Solver {

	static int solve(List<String> inputs) {
		
		
		String characters = null;
		LinkedList<List<Integer>> occurences = new LinkedList<>();
		
		
		for(int j = 0; j < inputs.size(); j++) {

			StringBuilder sb = new StringBuilder();
			String input = inputs.get(j);

			int ocList = 0;
			for(int i = 0; i < input.length(); i++) {
				
				 
				char c = input.charAt(i);
				int occurence = 1;						
				while(i + 1 < input.length() && input.charAt(i + 1) == c) {
					i++;
					occurence++; 
					
				}
				if(occurences.size() <= ocList) {
					occurences.add(new ArrayList<Integer>());
				} 
				occurences.get(ocList).add(occurence);
				ocList++;
				sb.append(c);
			}
			
			if(characters == null) {
				characters = sb.toString();
			} else {
				if(!characters.equals(sb.toString())) {
					
					return -1;
				}
			}
			
		}
		
		int ret = 0;
		for(List<Integer> list : occurences) {
			
			int ith = list.size() / 2;
			Collections.sort(list);
			int pivot = list.get(ith);
			
			for(int i : list) {
				ret += Math.abs(i - pivot);
			}
		}
		
		return ret;
		
	} 
	
public static void main(String[] args) throws IOException {
		
		File file = new File(args[0]);
		File outFile = new File(Template.class.getName() + ".txt");
		
		BufferedReader bufferedReader = null;
		PrintWriter printWriter = null;
		
		try {
		
		bufferedReader = new BufferedReader(new InputStreamReader(new FileInputStream(file)));
			
		printWriter = new PrintWriter(outFile);
		
		String line = bufferedReader.readLine();
		int numberOfTestCases = Integer.parseInt(line);
		
				
		
		
			for(int i = 0; i < numberOfTestCases; i++) {
				
					line = bufferedReader.readLine();
					int numberOfStrings = Integer.parseInt(line);
					
					List<String> inputs = new ArrayList<>();
					for(int j = 0; j < numberOfStrings; j++) {
						inputs.add(bufferedReader.readLine());						
					}
				
					int ret = solve(inputs);
					
					if(ret == -1) {
						printWriter.println("Case #" + (i+1) + ": Fegla Won");	
					} else {
						printWriter.println("Case #" + (i+1) + ": " + ret);
					}
					
					
			}
			
		} finally {
			if(bufferedReader != null) {
				bufferedReader.close();
			}
			if(printWriter != null) {
				printWriter.close();
			}

		}
		
	}

	
}
