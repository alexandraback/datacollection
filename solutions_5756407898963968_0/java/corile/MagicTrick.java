import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;


public class MagicTrick {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		
		//Open The file
		BufferedReader br=null;
		try {
			br = new BufferedReader(new FileReader("A-small-attempt0.in"));
			//br = new BufferedReader(new InputStreamReader(System.in));
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		//FileWriter fstream = new FileWriter("out.txt");
		//BufferedWriter out = new BufferedWriter(fstream);
		
		//Get the test case number
		int casenum = readLineAsInt(br);
		
		//Process each case
		for(int j = 1; j <= casenum; j++)
		{
			//Read the selected row
			int row1 = readLineAsInt(br);
			String[] s = new String[5];
			try {
				for(int i=1;i<=4;i++)
					s[i] = br.readLine();
			} catch (IOException e) {
				e.printStackTrace();
			}
			
			//Parse the selected row into integers
			String[] numbers1 = new String[4];
			for(int i=0;i<4;i++)
				numbers1[i] = s[row1].split(" ")[i];
			
			//Read the next selected row
			int row2 = readLineAsInt(br);
			s = new String[5];
			try {
				for(int i=1;i<=4;i++)
					s[i] = br.readLine();
			} catch (IOException e) {
				e.printStackTrace();
			}
			
			//Parse the selected row into integers
			String[] numbers2 = new String[4];
			for(int i=0;i<4;i++)
				numbers2[i] = s[row2].split(" ")[i];
			
			//printStringArray(numbers1);
			//printStringArray(numbers2);
			
			List<String> commonNumbers = getCommonElements(numbers1, numbers2);
			
			printOutput(j,commonNumbers);
			
			//System.out.println("Case #"+(j+1)+": "+getProbability(numDiamonds, x, y));
		}
		try {
			br.close();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

	}
	
	@SuppressWarnings("finally")
	public static int readLineAsInt(BufferedReader br)
	{
		int val = 0;
		try {
			val = Integer.parseInt(br.readLine());
		} catch (NumberFormatException e) {
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}finally{
			return val;
		}
	}
	
	public static void printStringArray(String[] s)
	{
		for(String str:s)
		{
			System.out.print(str+", ");
		}
		System.out.println("");
	}
	
	public static List<String> getCommonElements(String[] a,String[] b)
	{
		List<String> ret = new ArrayList<String>();
		for(String str_a:a)
		{
			for(String str_b:b)
			{
				if(str_a.equals(str_b))
					ret.add(str_a);
			}
		}
		
		return ret;
	}
	
	public static void printOutput(int caseNum, List<String> s)
	{
		System.out.print("Case #"+caseNum+": ");
		if (s.size()==0)
			System.out.println("Volunteer cheated!");
		else if (s.size()==1)
			System.out.println(s.get(0));
		else
			System.out.println("Bad magician!");
	}
}
