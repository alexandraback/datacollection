package Round1B;
import java.io.*;
import java.util.*;
/**
 * @author Amit Jacob
 *
 */
public class Q1 {
	private static final String LOSS_STR = "Fegla Won";
	/**
	 * @param args - Input File Path
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException {
		//Reading the input file:
		String path=args[0];
		File file = new File(path);
		BufferedReader br = new BufferedReader(new FileReader(file));
		String line;
		//Writing the output file:
		File fileout = new File("output.txt");
		fileout.createNewFile();
	    FileWriter writer = new FileWriter(fileout);
	    //var declarations:
	    int nStrings;
	    String[] strs;
	    String res;
	    int maxShows,minShows;
	    //Begin reading:
  		line=br.readLine();
  		int nTests = Integer.parseInt(line);
  		for(int j=0;j<nTests;++j)
  		{
  			line=br.readLine();
  			nStrings = Integer.parseInt(line);
  			strs = new String[nStrings];
  			for(int i=0;i<nStrings;++i)
  			{
  				strs[i]=br.readLine();
  			}
  			if(!checkIfPossible(strs))
  			{
  				writer.write("Case #"+(j+1)+": " + LOSS_STR + "\n");

  			}
  			else
  			{
  				res=getRes(strs[0]);
  				int totalOps=0;
  				for(int k=0;k<res.length();++k)
  				{
  					maxShows=-1;
  					minShows = Integer.MAX_VALUE;
  					for(int i=0;i<strs.length;++i)
  					{
  						int gShows=getShows(strs[i],k);
  						maxShows=Math.max(maxShows,gShows );
  						minShows=Math.min(minShows, gShows);
  					}
  					int bestOps=Integer.MAX_VALUE;
  					for (int i=minShows;i<=maxShows;++i)
  					{
  						int countOps=0;
  						for(int m=0;m<strs.length;++m)
  	  					{
  	  						int gShows=getShows(strs[m],k);
  	  						countOps+=Math.abs(gShows-i);
  	  					}
  						bestOps=Math.min(bestOps, countOps);
  					}
  					totalOps+=bestOps;
  				}
  				writer.write("Case #"+(j+1)+": " + totalOps + "\n");
  			}
			writer.flush();
		}
  		writer.close();
	}
	private static int getShows(String str, int k) {
		char[] strTest = str.toCharArray();
		char lastc = strTest[0];
		int count=1;
		int j=0;
		int i=1;
		while(j<=k && i<str.length())
		{
			if(lastc!=strTest[i])
			{
				if(j<k)
				{
					lastc=strTest[i];
					count = 0;
				}
				++j;
			}
			++i;
			++count;
		}
		return count-1;
	}
	public static boolean checkIfPossible(String[] arr)
	{
		String[] res = new String[arr.length];
		for( int k=0;k<arr.length;++k)
		{
			res[k]=getRes(arr[k]);
		}
		for( int k=1;k<arr.length;++k)
		{
			if(!res[k].equals(res[0]))
				return false;
		}
		return true;
	}
	public static String getRes(String str)
	{
		String res="";
		char lastc;
		char[] strTest;
		strTest= str.toCharArray();
		lastc=strTest[0];
		res=res+lastc;
		for(int i=1;i<strTest.length;++i)
		{
			if(lastc!=strTest[i])
			{
				lastc=strTest[i];
				res+=lastc;
			}
		}
		return res;
	}
}
