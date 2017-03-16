import java.io.*;

import java.awt.geom.Point2D;
import java.text.*;
import java.math.*;
import java.util.*;

public class gcj implements Runnable {
	
	///////////////////////
	// File name variables
	final String problem = "B";
	
	// final String filename = problem + "-sample";

	//final String filename = problem + "-small-attempt1";

	//final String filename= problem+"-small-attempt3";
	final String filename= problem+"-large";
	
	// Output Float format
	// e.g. out.write(df.format(T0));
	//DecimalFormat df = new DecimalFormat("0.000000");
	
	//////////////////////////////////////////
	// Hard core function
	public void solve() throws Exception {
		int numBarber = iread(), position = iread();
		
		long maxBarbarTime = 0;
		long[] barberTimeArray = new long[numBarber];
		
		for (int i = 0; i < numBarber; i++) {
			barberTimeArray[i] = iread();
			if (barberTimeArray[i] > maxBarbarTime) {
				maxBarbarTime = barberTimeArray[i];
			}
		}
		
		// corner case check
		if (position <= numBarber) {
			out.write(position + "");
			return;
		}
		
		
		long maxTotalTime = (long) (maxBarbarTime * Math.max(0, position - numBarber));
		long curMax = maxTotalTime, curLow = 0, mid = -1;
		Result result = new Result(0, 0);
		
		do {
			mid = (curMax - curLow) / 2 + curLow;
			result = calFinishedPerson(mid, barberTimeArray);
			if ((position > result.maxNumPeopleFinished - result.overlappedCount && 
			    position <= result.maxNumPeopleFinished) || (position == result.maxNumPeopleFinished)) {
				break;
			} else if (position > result.maxNumPeopleFinished) {
				curLow = mid + 1;
			} else {
				curMax = mid - 1;
			}
			
		} while (true);
		
		// Then approach to the finish point
		if (result.overlappedCount == 0 && mid > 0) {
			long timeFinished = 0;
			for (int i = 0; i < numBarber; i++) {
				if (timeFinished < ((mid / barberTimeArray[i]) * barberTimeArray[i])) {
					timeFinished = mid / barberTimeArray[i] * barberTimeArray[i];
				}
			}
			mid = timeFinished;
			// update the result again
			result = calFinishedPerson(mid, barberTimeArray);
		}
		
		long actualPosition = result.maxNumPeopleFinished - result.overlappedCount + 1;
		for (int i = 0; i < numBarber; i++) {
			if (mid % barberTimeArray[i] == 0) {
				if (actualPosition == position) {
					out.write((i+1) + "");
					return;
				}
				actualPosition++;
			}
		}
	}
	
	// Helper object
	public class Result {
		public Result(long maxNumPeopleFinished, long overlappedCount) {
			this.maxNumPeopleFinished = maxNumPeopleFinished;
			this.overlappedCount = overlappedCount;
		}
		public long maxNumPeopleFinished = 0;
		public long overlappedCount = 0;
	}
	
	// Calculate the number of people finished at a certain time
	private Result calFinishedPerson(long curTime, long[] barberTimeArray) {
		long maxNumPeopleFinished = 0, overlappedCount = 0;
		
		for (int i = 0; i < barberTimeArray.length; i++) {
			if (curTime % barberTimeArray[i] == 0) {
				overlappedCount++;
			}
			maxNumPeopleFinished += curTime / barberTimeArray[i] + 1;
		}
		
		return new Result(maxNumPeopleFinished, overlappedCount);
	}
	
	//////////////////////////////////////////
	/// Helper functions
	public void solve_gcj() throws Exception {
		int tests = iread();
		for (int test = 1; test <= tests; test++) {
			out.write("Case #" + test + ": ");
			solve();
			out.write("\n");
		}
	}

	public void run() {
		try {
			// Helper in-&-out for local test
			//in = new BufferedReader(new InputStreamReader(System.in));
			//out = new BufferedWriter(new OutputStreamWriter(System.out));
			
			// For real file input and output
			in = new BufferedReader(new FileReader(filename + ".in"));
			out = new BufferedWriter(new FileWriter(filename + ".out"));
			solve_gcj();
			out.flush();
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(1);
		}
	}

	public int iread() throws Exception {
		return Integer.parseInt(readword());
	}

	public double dread() throws Exception {
		return Double.parseDouble(readword());
	}

	public long lread() throws Exception {
		return Long.parseLong(readword());
	}

	BufferedReader in;

	BufferedWriter out;

	public String readword() throws IOException {
		StringBuilder b = new StringBuilder();
		int c;
		c = in.read();
		while (c >= 0 && c <= ' ')
			c = in.read();
		if (c < 0)
			return "";
		while (c > ' ') {
			b.append((char) c);
			c = in.read();
		}
		return b.toString();
	}

	/////////////////////////
	// Main Function
	public static void main(String[] args) {
		try {
			Locale.setDefault(Locale.US);
		} catch (Exception e) {

		}
		new Thread(new gcj()).start();
	}
}
