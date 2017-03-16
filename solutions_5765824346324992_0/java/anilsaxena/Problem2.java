package round1;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.*;


public class Problem2 {
    private static void solveProblem(String input) throws IOException {
	List<String> lines = readFile(input);
	List<String> outputLines = new ArrayList<String>();
	int index = 0;
	int testCases = getInt(lines.get(index++));
	for(int t = 0; t < testCases; t++) {
	    String[] tokens = lines.get(index++).split(" ");
	    int B = getInt(tokens[0]);
	    int N = getInt(tokens[1]);
	    int[] M = new int[B];
	    String[] strs = lines.get(index++).split(" ");
	    for(int i = 0; i < strs.length; i++) {
		M[i] = getInt(strs[i]);
	    }
	    long[] next = new long[B];
	    int barbar = 0;
	    long cycle = findCycle(M);
	    System.out.println("Cycle: " + cycle);
	    long cyclicN = N % cycle;
	    if(cyclicN == 0) {
		cyclicN = cycle;
	    }
	    for(int n = 0; n < cyclicN; n++) {
		long min = next[0];
		barbar = 0;
		for(int b = 1; b < B; b++) {
		    if(next[b] < min) {
			barbar = b;
			min = next[b];
		    }
		}
		next[barbar] += M[barbar];
	    }
	    String testCaseOutput = "Case #" + (t+1) + ": " + (barbar+1);
	    System.out.println(testCaseOutput);
	    outputLines.add(testCaseOutput);
	}
	String output = getTokenSeparatedString(outputLines, "\n");
	writeFile(output, input.replace(".in", ".out"));
    }

    private static long findCycle(int[] M) {
	int min = M[0];
	long lcm = M[0];
	for(int i = 1; i < M.length; i++) {
	    lcm = lcm(lcm, M[i]);
	    min = Math.min(min, M[i]);
	}
	int cycle = 0;
	for(int i = 0; i < M.length; i++) {
	    cycle+= (lcm / M[i]);
	}
	return cycle;
    }
    
    private static long lcm(long a, long b){
	return a * (b / gcd(a, b));
    }
    
    private static long gcd(long a, long b){
	while (b > 0){
	    long temp = b;
            b = a % b; // % is remainder
            a = temp;
        }
        return a;
    }
    
    public static void print(int[] arr) {
	StringBuffer buf = new StringBuffer("[");
	for(int curr: arr) {
	    buf = buf.append(curr).append(" ");
	}
	buf.append("]");
	System.out.println(buf);
    }

    public static void print(long[] arr) {
	StringBuffer buf = new StringBuffer("[");
	for(long curr: arr) {
	    buf = buf.append(curr).append(" ");
	}
	buf.append("]");
	System.out.println(buf);
    }
    
    public static String replace(String sourceString, String replace, String with) {
	if (sourceString == null || replace == null || with == null || replace.equals(with)) {
	    return sourceString;
	}
	StringBuilder buf = new StringBuilder(sourceString.length());
	int start = 0, end = 0;
	while ((end = sourceString.indexOf(replace, start)) != -1) {
	    buf.append(sourceString.substring(start, end)).append(with);
	    start = end + replace.length();
	}
	buf.append(sourceString.substring(start));
	return buf.toString();
    }

    private static int getInt(String str) {
	return Integer.parseInt(str);
    }

    private static List<String> readFile(String fileName) throws IOException {
	BufferedReader reader = new BufferedReader(new FileReader(fileName));
	String line = null;
	List<String> lines = new ArrayList<String>();
	while((line = reader.readLine()) != null) {
	    lines.add(line);
	}
	reader.close();
	return lines;
    }

    private static void writeFile(String text, String fileName) throws IOException {
	FileWriter writer = new FileWriter(fileName);
	writer.write(text);
	writer.close();
    }

    private static String getTokenSeparatedString(Collection<?> listValues, String token) {
	StringBuilder strValue = new StringBuilder("");
	if (listValues != null) {
	    int i = 0;
	    for (Object v : listValues) {
		String value = v.toString();
		if (i == 0) {
		    strValue.append(value);
		} else {
		    strValue.append(token);
		    strValue.append(value);
		}
		i++;
	    }
	}
	return strValue.toString();
    }

    public static List<String> getValueAsList(String valueStr, String delim) {
	List<String> values = new ArrayList<String>();
	if (valueStr != null) {
	    int lastIndex = 0;
	    int currIndex = 0;
	    while ((currIndex = valueStr.indexOf(delim, lastIndex)) != -1) {
		String value = valueStr.substring(lastIndex, currIndex);
		if (value.trim().length() != 0) {
		    values.add(value.trim());
		}
		lastIndex = currIndex + delim.length();
	    }
	    String value = valueStr.substring(lastIndex);
	    if (value.trim().length() != 0) {
		values.add(value.trim());
	    }
	}
	return values;
    }

    public static void main(String[] args) {
	try {
	    solveProblem("B-small-attempt1.in");
	    //solveProblem("input.in");
	}catch(Exception ex) {
	    ex.printStackTrace();
	}
    }


}
