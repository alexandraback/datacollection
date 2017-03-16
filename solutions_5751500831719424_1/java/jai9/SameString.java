package codejam;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Iterator;
import java.util.List;
import java.util.Map;

public class SameString {

	public static void main(String[] args) throws FileNotFoundException {

		ConsoleReader reader;
		if (args.length > 0) {

			reader = new ConsoleReader(args[0]);
		} else {

			reader = new ConsoleReader();
		}

		int num = Integer.parseInt(reader.readLine());
		for (int i = 1; i <= num; i++) {
			
			System.out.print("Case #" + i + ": ");
			int n=Integer.parseInt(reader.readLine());
			List<StringBuilder> strings=new ArrayList<StringBuilder>();
			for(int j=0;j<n;j++) {
				
				strings.add(new StringBuilder(reader.readLine()));
			}
			
			int moves=makeEqual(strings);
			
			System.out.println((moves>=0?moves:"Fegla Won"));

		}
		
	}
	
	private static int makeEqual(List<StringBuilder> strings) {
		
		int moves=0;
		
		while(true) {
			
			boolean exit=true;
			for(int i=0;i<strings.size();i++) {
				if(strings.get(i).length()>0)
					exit=false;
			}
			
			if(exit) {
				return moves;
			}
			
			List<String> tempList=new ArrayList<String>();
			Map<String,Integer> buckets=new HashMap<String,Integer>();
			
			for(int i=0;i<strings.size();i++) {
				
				if(strings.get(i).length()==0)
					return -1;

					String pre=null;
					if(strings.get(i).length()>1) {
						pre=strings.get(i).substring(0, 2);
					} else {
						pre=strings.get(i).substring(0, 1);
					}
					
					tempList.add(pre);
					if(buckets.containsKey(pre))
						buckets.put(pre,buckets.get(pre)+1);
					else 
						buckets.put(pre,1);

			}
			
			if(buckets.size()>2) {
				return -1;
			}
			if(buckets.size()==2) {
				
				String sameCharStr=sameChar(buckets);
				if(sameCharStr==null||sameCharStr.length()==1)
					return -1;
				String diffCharStr=diffChar(buckets);
				
				int sameCharFreq=buckets.get(sameCharStr);
				int diffCharFreq=buckets.get(diffCharStr);
				if(sameCharFreq>diffCharFreq) {
					moves+=addChar(strings, diffCharStr);
				} else {
					moves+=deleteChar(strings, sameCharStr);
				}
				
				
			} else {
				for(int i=0;i<strings.size();i++) {
					
					strings.get(i).delete(0, 1);
				}
				
				
			}
			
		}
		
		
	}
	
	private static String sameChar(Map<String,Integer> buckets) {

		String single=null;
		String str=null;
		Iterator<String> it=buckets.keySet().iterator();
		for(int i=0;i<2;i++) {
			String temp=it.next();
			if(temp.length()==1) {
				
				single=temp;
			}
			if(temp.length()==2&&temp.charAt(0)==temp.charAt(1)) {
				str=temp;
				break;
			}
		}
		
		if(str==null)
			str=single;
		
		return str;
		
	}

	private static String diffChar(Map<String,Integer> buckets) {

		String single=null;
		String str=null;
		Iterator<String> it=buckets.keySet().iterator();
		for(int i=0;i<2;i++) {
			String temp=it.next();
			if(temp.length()==1) {
				
				single=temp;
			}
			if(temp.length()==2&&temp.charAt(0)!=temp.charAt(1)) {
				str=temp;
				break;
			}
		}
		
		if(str==null)
			str=single;
		
		return str;
		
	}

	private static int addChar(List<StringBuilder> strings,String pre) {
		
		int count=0;
		for(int i=0;i<strings.size();i++) {
			
			String temp=strings.get(i).toString();
			if((pre.length()==2&&temp.startsWith(pre))||(pre.length()==1&&temp.equals(pre))) {
				strings.get(i).insert(0, pre.charAt(0));
				count++;
			}
		}
		
		return count;
	}
	
	private static int deleteChar(List<StringBuilder> strings,String pre) {
		
		int count=0;
		for(int i=0;i<strings.size();i++) {
			
			String temp=strings.get(i).toString();
			if(temp.startsWith(pre)) {
				strings.get(i).delete(0, 1);
				count++;
			}
		}
		return count;
}
	

	
	public static class ConsoleReader {

		private BufferedReader br;

		public ConsoleReader(String file) throws FileNotFoundException {

			br = new BufferedReader(new FileReader(new File(file)));

		}

		public ConsoleReader() {

			br = new BufferedReader(new InputStreamReader(System.in));

		}

		public String readLine() {

			try {

				return br.readLine();
			} catch (IOException e) {
				System.err.println("Exception while reading " + e);
			}

			return null;
		}

	}


}