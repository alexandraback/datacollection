package com.devon;

import java.io.InputStream;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;

public class Repeater {
	public void go(InputStream is) {
		Scanner s = new Scanner(is);
		int count = s.nextInt();
		for(int i=0;i<count;i++) {
			int n = s.nextInt();
			String[] strs = new String[n];
			for(int j=0;j<n;j++) {
				strs[j] = s.next();
			}
			int steps = align(strs);
			System.out.println("Case #"+(i+1)+": " +  (steps >= 0 ? steps: "Fegla Won"));
		}
		
	}

	static class RString {
		List<Character> chars;
		List<Integer> counts;
		
		public boolean sameChars(RString rs)
		{
			if(this.chars.size() != rs.chars.size()) {
				return false;
			}
			
			for(int i=0;i<this.chars.size();i++) {
				if(this.chars.get(i) != rs.chars.get(i)) {
					return false;
				}
			}
			
			return true;
		}
	}
	
	private RString parseString(String s)
	{	
		List<Character> chars = new LinkedList<Character>();
		List<Integer> counts = new LinkedList<Integer>();
		char cs = 0;
		int ccount = 0;
		for(int i=0;i<s.length();i++) {
			char ns = s.charAt(i);
			if(ns != cs) {
				chars.add(cs);
				counts.add(ccount);
				cs = ns;
				ccount = 1;
			} else {
				ccount++;
			}
		}
		
		chars.add(cs);
		counts.add(ccount);
		
		
		RString result = new RString();
		result.chars = chars;
		result.counts = counts;
		
		return result;
	}
	
	private int align(String[] strs) {
		RString[] rss = new RString[strs.length]; 
		
		for(int i=0;i<strs.length;i++) {
			rss[i] = parseString(strs[i]);
		}
		
		RString first = rss[0];
		for(int i=1;i<strs.length;i++) {
			if(!first.sameChars(rss[i])) {
				return -1;
			}
		}
		
		
		int steps = 0;
		for(int i=0;i<first.chars.size();i++) {
			int median = getMedian(i, rss);
			
			for(int j=0;j<rss.length;j++) {
				steps += Math.abs(median - rss[j].counts.get(i));
			}
		}
		
		return steps;
	}

	private int getMedian(int i, RString[] rss) {
		int[] a = new int[rss.length];
		for(int j=0;j<rss.length;j++) {
			a[j] = rss[j].counts.get(i);
		}
		
		Arrays.sort(a);
		
		return a[a.length / 2];
	}
	
	
}
