package round1b;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;
import java.util.concurrent.CountDownLatch;

@SuppressWarnings("unused")
public class Problem1 implements Solution{
	String[] strs;
	int n;
	
	
	void initialize() {
		n=0;
		strs=null;
	}
	
	@Override
	public String execute(BufferedReader in, PrintWriter log)
			throws IOException {
		// TODO Auto-generated method stub
		String line=in.readLine();
		n=Integer.parseInt(line.trim());
		
		strs=new String[n];
		for (int i=0;i<n;++i) {
			line=in.readLine().trim();
			strs[i]=line;
		}
		
		int resultInt=process();
		
		StringBuilder result=new StringBuilder(" ");
		if (resultInt==-1) result.append("Fegla Won");
		else result.append(resultInt);
		return result.toString();
	}
	
	int process() {
		if (!isPossible()) return -1;
		
		/*int[] count = new int[strs.length];
		int minimalOperations=Integer.MAX_VALUE;
		for (int i = 0;i <n;++i) {
			int sumOperation=0;
			for (int j = 0; j<n;++j) {
				sumOperation+= transformActions(strs[j], strs[i]);
			}
			count[i]=sumOperation;
			minimalOperations=Math.min(minimalOperations, sumOperation);
		}*/
		
		return processInside();
	}
	
	String transformTostandardFor(String str) {
		char[] strChars = str.toCharArray();
		StringBuilder standardForm = new StringBuilder();
		
		for (int i =0;i<strChars.length;) {
			int j=i;
			char c=strChars[i];
			standardForm.append(c);
			for (;j<strChars.length;++j)
				if (strChars[j]!=c)break;;
			i=j;
		}
		
		return standardForm.toString();
	}
	
	boolean isPossible() {
		String standardForm=transformTostandardFor(strs[0]);
		for (int i=1; i<n;++i) {
			if (!standardForm.equals(transformTostandardFor(strs[i])))
				return false;
		}
		
		return true;
	}
	
	int transformActions(String str, String toStr) {
		int[] strCount;
		int[] toStrCount;		
		
		char[] toStrChars = toStr.toCharArray();
		
		strCount=new int[toStr.length()];
		toStrCount=new int[toStr.length()];
		
		int k=0;
		for (int i = 0; i<toStrChars.length;) {
			char c = toStrChars[i];
			int j = i;
			for (; j<toStrChars.length; ++j)
				if (toStrChars[j]!=c) break;;
			toStrCount[k]=j-i;
			k++;
			i=j;
		}		
		
		int l=0;
		char[] strChars=str.toCharArray();
		for (int i = 0; i<strChars.length;) {
			char c = strChars[i];
			int j = i;
			for (; j<strChars.length; ++j)
				if (strChars[j]!=c)break;
			strCount[l]=j-i;
			l++;
			i=j;
		}	
		
		int sumOperation=0;
		for (int i=0; i<k; ++i) sumOperation+= Math.abs(strCount[i]-toStrCount[i]);
		
		return sumOperation;
	}
	
	int[][] creatTable() {
		int[][] table = new int[n][100];
		int[] pos=new int[n];
		Arrays.fill(pos, 0);
		
		int cCount=0;
		while (true){
			
			char c = strs[0].charAt(pos[0]);
			
			for (int i=0; i<table.length;++i) {
				int oldPosI=pos[i];
				int posI = pos[i];
				for (; posI <strs[i].length();++posI) {
					if (strs[i].charAt(posI)!=c) {
						break;
					}
				}
				
				pos[i]=posI;
				table[i][cCount]=pos[i]-oldPosI;
			}
			
			cCount++;
			if (pos[0]==strs[0].length()) break;
		}
		
		int[][] exactTable = new int[n][cCount];
		
		for (int i=0; i<n;++i) {
			for (int j=0; j<cCount;++j) {
				exactTable[i][j]=table[i][j];
			}
		}
		return exactTable;
	}
	
	int processInside() {
		int[][] table = creatTable();
		int count=0;
		for (int i =0; i < table[0].length;++i) {
			int minValue=table[0][i];
			int maxValue=table[0][i];
			for (int j=1; j<table.length;++j) {
				minValue=Math.min(minValue, table[j][i]);
				maxValue=Math.max(maxValue, table[j][i]);
			}
			int sum=0;
			int minSum=Integer.MAX_VALUE;
			for (int x=minValue; x<=maxValue; ++x) {
				sum=0;
				for (int j=0; j<table.length;++j) {
					sum+=Math.abs(x-table[j][i]);
				}
				minSum=Math.min(minSum,sum);
			}
			count+= minSum;
		}
		return count;
	}

}
