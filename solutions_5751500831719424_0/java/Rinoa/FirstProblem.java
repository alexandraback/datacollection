import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;


public class FirstProblem {
	public static void main(String[] args) {
		List<String[]> input=readInput("D:\\A-small-attempt0.in");
		String[] result=solve(input);
		outputResults("D:\\A-small-attempt0.out",result);
	}

	public static String[] solve(List<String[]> input)
	{
		String[] result=new String[input.size()];
		for(int i=0; i<result.length; i++)
		{
			result[i]=solveSingle(input.get(i));
		}
		return result;
	}
	
	private static String solveSingle(String[] array)
	{
		String[] unr=new String[array.length];
		for(int i=0; i<array.length; i++)
		{
			unr[i]=getUnRepeated(array[i]);				
		}
		
		for(int i=1; i<unr.length; i++)
			if(!unr[i].equals(unr[i-1]))
				return "Fegla Won";
		
		char[] symbols=unr[0].toCharArray();
		
		int nums=0;
		
		for(int i=0; i<symbols.length; i++)
		{
			boolean exit=false;
			while(!exit)
			{
				int more=0;
				exit=true;
				for(int j=0; j<array.length; j++)
				{
					if(array[j].length()>i+1 && array[j].substring(i+1, i+2).equals(array[j].substring(i,i+1)))
					{
						array[j]=array[j].substring(0,i)+array[j].substring(i+1);
						more++;
						exit=false;
					}
				}
				nums+=Math.min(more,array.length-more);
			}
		}
		
		return String.valueOf(nums);
	}
	
	public static String getUnRepeated(String str)
	{
		char[] letters=str.toCharArray();
		List<Character> result=new ArrayList<Character>();
		result.add(letters[0]);
		for(int i=1; i<letters.length; i++)
		{
			if(letters[i]!=letters[i-1])
			{
				result.add(letters[i]);
			}
		}
		char[] res=new char[result.size()];
		for(int i=0; i<res.length; i++)
			res[i]=result.get(i);
		return String.valueOf(res);
	}
	
	public static List<String[]> readInput(String fileName)
	{
		List<String[]> results=new ArrayList<String[]>();
		try(Scanner in=new Scanner(new File(fileName)))
		{
			int numberOfCases=Integer.parseInt(in.nextLine());
			for(int i=0; i<numberOfCases; i++)
			{
				int numberOfWords=Integer.parseInt(in.nextLine());
				
				String[] array=new String[numberOfWords];
				
				for(int j=0; j<numberOfWords; j++)
					array[j]=in.nextLine();
				
				results.add(array);
			}
		}
		catch(Exception e)
		{
			e.printStackTrace();
		}
		return results;
	}
	
	public static void outputResults(String fileName, String[] results)
	{
		File flt = new File(fileName);
		try(FileWriter wrt = new FileWriter(flt);) {
			if (flt.exists()) {
				flt.delete();
				flt.createNewFile();
			}	
			for(int i=0; i<results.length; i++)
			{
				wrt.append("Case #"+(i+1)+": "+results[i]+"\n");
			}
			
			wrt.flush();
		} catch (IOException e) {
			System.out.println("Произошла ошибка при записи");
			e.printStackTrace();
		}
	}
}
