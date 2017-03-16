import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.Calendar;
import java.util.List;

import sun.security.timestamp.TSRequest;

public class GCJ_1B_A {
	
	static final String path = ".";
	
	class ConString
	{
		List<Character> c = new ArrayList<Character>();
		List<Integer> n = new ArrayList<Integer>();
	}
	
	class TestCase
	{
		List<ConString> stirngs = new ArrayList<ConString>();
	}
	
	public TestCase readTestCase(BufferedReader br) throws Exception
	{
		TestCase tc = new TestCase();
		Integer strs = Integer.valueOf(br.readLine());
		for (int i=0; i<strs; i++)
		{
			String str = br.readLine();
			ConString cs = new ConString();
			char c = ' ';
			for (int j=0; j<str.length(); j++)
			{
				if (str.charAt(j) != c)
				{
					c = str.charAt(j);
					cs.c.add(c);
					cs.n.add(1);
				} else
				{
					Integer cnt = cs.n.remove(cs.n.size() - 1);
					cs.n.add(cnt+1);
				}
			}
			tc.stirngs.add(cs);
		}
		return tc;
	}
	
	public void writeTestResult(BufferedWriter bw, TestCase tc) throws Exception
	{
		String t = tc.stirngs.get(0).c.toString();
		for (int i=1; i<tc.stirngs.size(); i++)
			if (!t.equals(tc.stirngs.get(i).c.toString()))
			{
				bw.write("Fegla Won");
				return;
			}
		int actionCounter = 0;
		for (int i=0; i<tc.stirngs.get(0).c.size(); i++)
		{
			int localActionCount1 = 0;
			int localActionCount2 = 0;
			
			double charCount = 0;
			
			for (int j=0; j<tc.stirngs.size(); j++)
				charCount += tc.stirngs.get(j).n.get(i);
			
			double target1 = Math.ceil(charCount / tc.stirngs.size());
			double target2 = Math.floor(charCount / tc.stirngs.size());
			
			for (int j=0; j<tc.stirngs.size(); j++)
			{
				localActionCount1 += Math.abs(target1 - tc.stirngs.get(j).n.get(i));
				localActionCount2 += Math.abs(target2 - tc.stirngs.get(j).n.get(i));
			}
			actionCounter += Math.min(localActionCount1, localActionCount2);
		}
		bw.write(actionCounter+"");
	}
	
	public void solve() throws Exception
	{
		BufferedReader br = new BufferedReader(new FileReader(path+"/input"));
		BufferedWriter bw = new BufferedWriter(new FileWriter(path+"/output"));
		int testCases = Integer.valueOf(br.readLine()).intValue();
		for (int i=0; i<testCases; i++)
		{
			System.out.print("Test case "+(i+1)+": ");
			long time = Calendar.getInstance().getTimeInMillis();
			TestCase testCase = readTestCase(br);
			System.out.print(" read in "+(Calendar.getInstance().getTimeInMillis()-time)+"ms, ");
			time = Calendar.getInstance().getTimeInMillis();
			bw.write("Case #"+(i+1)+": ");
			writeTestResult(bw, testCase);
			bw.write("\n");
			System.out.println("solved in "+(Calendar.getInstance().getTimeInMillis()-time)+"ms");
		}
		bw.flush();
		bw.close();
		br.close();
	}
	public static void main(String[] args) throws Exception 
	{
		GCJ_1B_A jam = new GCJ_1B_A();
		jam.solve();
	}
}
