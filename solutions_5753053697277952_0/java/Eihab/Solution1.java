import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Solution1 {
	static BufferedReader br;
    static StringTokenizer sc;
    static PrintWriter out;

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new FileReader("input.in"));
        out = new PrintWriter("output.out");
        sc = new StringTokenizer("");
        int t = nxtInt();
        for (int i = 1; i <= t; i++) {
        	out.print("Case #" + i + ":");
        	int n = nxtInt();
        	int[] senates = new int[n];
        	for (int j = 0; j < n; j++)
        		senates[j] = nxtInt();
        	
        	char[] sol = new char[2];
        	int sum = sum(senates);
			while (sum(senates) > 0) {
				sum = sum(senates);
				while (sum > 3 || sum == 2) {
					//int max;
					int order = getMaxOrder(senates, senates.length);
					sol = new char[2];
					sol[0] = (char) (order + 65);
					senates[order]--;
					order = getMaxOrder(senates, senates.length);
					//max = getMax(senates, senates.length);
					sol[1] = (char) (order + 65);
					senates[order]--;
					sum = sum(senates);
					
					String s = new String(sol);
					out.print(" " + s);
				}
				if (sum == 3) {
					sol = new char[1];
					int order = getMaxOrder(senates, senates.length);
					sol[0] = (char) (order + 65);
					senates[order]--;
					
					String s = new String(sol);
					out.print(" " + s);
				}				
			}
			
			out.println();
        }
        System.out.println("finish");
        br.close();
        out.close();
    }    
    
    static int sum(int[] senates) {
    	int sum = 0;
    	for (int i = 0; i < senates.length; i++)
    		sum += senates[i];
    	return sum;
    }

    static String nxtTok() throws IOException {
        while (!sc.hasMoreTokens()) {
            String s = br.readLine();
            if (s == null) {
                return null;
            }
            sc = new StringTokenizer(s.trim());
        }
        return sc.nextToken();
    }

    static int nxtInt() throws IOException {
        return Integer.parseInt(nxtTok());
    }

    static long nxtLng() throws IOException {
        return Long.parseLong(nxtTok());
    }

    static double nxtDbl() throws IOException {
        return Double.parseDouble(nxtTok());
    }

    static int[] nxtIntArr(int n) throws IOException {
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = nxtInt();
        }
        return a;
    }

    static long[] nxtLngArr(int n) throws IOException {
        long[] a = new long[n];
        for (int i = 0; i < n; i++) {
            a[i] = nxtLng();
        }
        return a;
    }

    static char[] nxtCharArr() throws IOException {
        return nxtTok().toCharArray();
    }
    
    static int getMin(int arr[], int count)
    {
    	int min = arr[0];
    	for (int i = 1; i < count; i++)
    		if (arr[i] < min)
    			min = arr[i];

    	return min;
    }

    static int getMax(int arr[], int count)
    {
    	int max = arr[0];
    	for (int i = 1; i < count; i++)
    		if (arr[i] > max)
    			max = arr[i];

    	return max;
    }
    
    static int getMaxOrder(int arr[], int count)
    {
    	int order = 0;
    	int max = arr[0];
    	for (int i = 1; i < count; i++)
    		if (arr[i] > max) {
    			max = arr[i];
    			order = i;
    		}

    	return order;
    }

    static void sortAsc(int arr[], int count)
    {
        int temp;

        for (int i = 0; i < count - 1; i++)
        {
            for (int j = i + 1; j < count; j++)
            {
                if (arr[i] > arr[j])
                {
                    temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
    }

    static void sortDesc(int arr[], int count)
    {
        int temp;

        for (int i = 0; i < count - 1; i++)
        {
            for (int j = i + 1; j < count; j++)
            {
                if (arr[i] < arr[j])
                {
                    temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
    }
}