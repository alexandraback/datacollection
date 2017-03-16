import java.io.*;
import java.util.*;


public class Main{
	
	
	private static boolean allAtEnd(String[] arr, int[] indices){
		for (int i = 0; i < arr.length; ++i){
			if (indices[i] < arr[i].length())
				return false;
		}
		return true;
	}
	
	
	private static int distToMedian(int[] counts){
		Arrays.sort(counts);
		
		int median = counts[counts.length/2];
		int sum = 0;
		for (int i = 0; i < counts.length; ++i)
			sum += Math.abs(counts[i] - median);
		
		return sum;
	}
	
	
	
	public static void main(String[] args){
		FastReader in = FastReader.SYSTEM_READER;
		
		int t = in.nextUnsignedInt();
		for (int tc = 1; tc <= t; ++tc){
			int n = in.nextUnsignedInt();
			String[] arr = new String[n];
			for (int i = 0; i < n; ++i)
				arr[i] = in.nextUnspacedString();
			
			int[] indices = new int[n];
			int actions = 0;
			boolean isOneAtEnd = false;
			boolean missingLetter = false;
			while (!isOneAtEnd){
				int[] counts = new int[n];
				char c = arr[0].charAt(indices[0]);
				
				for (int i = 0; i < n; ++i){
					String s = arr[i];
					int len = s.length();
					while ((indices[i] < len) && (s.charAt(indices[i]) == c)){
						++counts[i];
						++indices[i];
					}
					
					if (indices[i] == len)
						isOneAtEnd = true;
				}
				
				for (int i = 0; i < n; ++i){
					if (counts[i] == 0){
						missingLetter = true;
						break;
					}
				}
				if (missingLetter)
					break;
				
				actions += distToMedian(counts);
			}
			
			if (missingLetter || (isOneAtEnd && !allAtEnd(arr, indices)))
				System.out.printf("Case #%d: Fegla Won\n", tc);
			else
				System.out.printf("Case #%d: %d\n", tc, actions);
		}
		
	}
	
}

final class FastReader{
	
	public static final FastReader SYSTEM_READER = new FastReader(System.in);
	
	private final InputStream in;
	private final byte[] buffer = new byte[1<<16];
	private int pos, count;
	
	public FastReader(InputStream in){
		this.in = in;
		pos = count = 0;
	}
	
	public int nextUnsignedInt(){
		int c;
		while ((c = read()) < '0');
		
		int result = c - '0';
		while ((c = read() - '0') >= 0)
			result = 10*result + c;
		return result;
	}
	
	public int nextInt(){
		int c;
		while (((c = read()) < '0') && (c != '-'));
		
		boolean isNegative = false;
		if (c == '-'){
			isNegative = true;
			c = read();
		}
		
		int result = c - '0';
		while ((c = read() - '0') >= 0)
			result = 10*result + c;
		return isNegative ? -result : result;
	}
	
	
	public String nextUnspacedString(){
		StringBuilder s = new StringBuilder();
		int c;
		while ((c = read()) < 33);
		s.append((char)c);
		while ((c = read()) >= 33)
			s.append((char)c);
		return s.toString();
	}
	
	public char nextNonWhitespaceChar(){
		int c;
		while ((c = read()) < 33);
		return (char)c;
	}
	
    
	private boolean fillBuffer(){
		try{
			return (count = in.read(buffer, pos = 0, buffer.length)) > 0;
		} catch (Exception e){
			return false;
		}
	}
	
	
	public int read(){
		if (pos == count)
			if (!fillBuffer())
				return -1;
		return buffer[pos++];
	}
	
}

