import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;

public class onec_alpha {
	public static void main(String[] args) {
		try {
			process();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
	private static void process()
	throws IOException {
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		
		int testCases = Integer.parseInt(reader.readLine());
		
		for (int i = 0; i < testCases; ++i) {
			System.out.println("Case #" + (i+1) + ":" + processTestCase(reader));
		}
		
		reader.close();
	}
	
	private static String processTestCase(BufferedReader reader)
	throws IOException {
		int N = Integer.parseInt(reader.readLine());
		String testCase = reader.readLine();
		String[] sarr = testCase.split(" ");
		
		// System.out.println("Input: " + testCase);
		
		int[] arr = new int[N];
		int totalCount = 0;
		
		for (int i = 0; i < N; ++i) {
			arr[i] = Integer.parseInt(sarr[i]);
			totalCount += arr[i];
		}
		
		String ret = "";
		
		while (totalCount > 0) {
			int highValue = calcHighValue(arr);
			
			if (totalCount == 1) {
				int index = getFirstIndexWithValue(arr, 1);
				ret += " " + (char) ('A' + index);
				arr[index]--;
				totalCount--;
			}
			else if (totalCount == 2) {
				int index = getFirstIndexWithValue(arr, 1);
				ret += " " + (char) ('A' + index);
				arr[index]--;
				index = getFirstIndexWithValue(arr, 1);
				ret += (char) ('A' + index);
				arr[index]--;
				totalCount -= 2;
			}
			else if (totalCount == 3) {
				int index = getFirstIndexWithValue(arr, 1);
				ret += " " + (char) ('A' + index);
				arr[index]--;
				totalCount--;
			}
			else if (totalCount == 4) {
				int index = getFirstIndexWithValue(arr, highValue);
				ret += " " + (char) ('A' + index);
				arr[index]--;
				highValue = calcHighValue(arr);
				index = getFirstIndexWithValue(arr, highValue);
				ret += (char) ('A' + index);
				arr[index]--;
				totalCount -= 2;
			}
			else {
				int index = getFirstIndexWithValue(arr, highValue);
				ret += " " + (char) ('A' + index);
				arr[index]--;
				totalCount--;
				
				highValue = calcHighValue(arr);
				if ((double) highValue > ((double) totalCount / 2.0)) {
					index = getFirstIndexWithValue(arr, highValue);
					ret += (char) ('A' + index);
					arr[index]--;
					totalCount--;
				}
			}
			
			// System.out.println("  intermediate: " + ret);
			
			int newCount = 0;
			for (int i = 0; i < N; ++i) newCount += arr[i];
			for (int i = 0; i < N; ++i) {
				if ((double) arr[i] > ((double) newCount / 2.0)) {
					System.out.println("problem! " + i + ", " + arr[i] + ", " + newCount);
				}
			}
		}
		
		return ret;
	}
	
	private static int getFirstIndexWithValue(int[] arr, int val) {
		for (int i = 0; i < arr.length; ++i) if (arr[i] == val) return i;
		return -1;
	}
	
	private static int calcHighValue(int[] arr) {
		int val = 0;
		for (int i = 0; i < arr.length; ++i) val = Math.max(val, arr[i]);
		return val;
	}
}