package googlecodejam;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.LinkedHashMap;
import java.util.List;
import java.util.Scanner;
import java.util.TreeMap;

public class TheRepeater {
	public static void main(String[]Args) throws FileNotFoundException{
		Scanner sc = new Scanner(new File("e:\\A-small-attempt2.in"));
		PrintWriter out = new PrintWriter(new File("e:\\1.out"));
		int t = sc.nextInt();
		for (int i = 0; i < t; i++) {
			int n = sc.nextInt();
			ArrayList<String> all=new ArrayList<String>();
			String s=sc.next();
			all.add(s);
			int size=0;
			StringBuffer sb = new StringBuffer("");
			//System.out.println(s);
			ArrayList<LinkedHashMap<String,Integer>> comp=new ArrayList<LinkedHashMap<String,Integer>>();
			LinkedHashMap<String,Integer> len=new LinkedHashMap<String,Integer>();
			LinkedHashMap<String,Integer> templen=new LinkedHashMap<String,Integer>();
			LinkedHashMap<String,Integer> templen2=new LinkedHashMap<String,Integer>();
			size+=s.length();
			for (int k = 0; k <s.length(); k++) {
				if(k==0){
					sb.append(s.charAt(k));
					len.put(s.charAt(k)+""+sb.length()+"", 1);
				}
				else if(s.charAt(k)!=s.charAt(k-1)){
				sb.append(s.charAt(k));
				len.put(s.charAt(k)+""+sb.length()+"", 1);
				}
				else{
					//System.out.println("here"+sb);
					int temp=len.remove(s.charAt(k)+""+sb.length()+"");
					len.put(s.charAt(k)+""+sb.length()+"", ++temp);
				}
				//System.out.println(len);
				//System.out.println(sb);
			}
			templen2=new LinkedHashMap<String,Integer>(len);
			comp.add(templen2);
			
			int flag=0;
			for (int j = 0; j < n-1; j++) {
				s=sc.next();
				all.add(s);
				size+=s.length();
				int x=0;
				int count=0;
				templen=new LinkedHashMap<String,Integer>();
				for (int j2 = 0; j2 < s.length(); j2++) {
//					System.out.println("here"+len);
//					System.out.println(s.charAt(j2));
//					System.out.println(count);
//					System.out.println(x);
					
					if(j2==0&&s.charAt(j2)!=sb.charAt(x)){
						flag=1;
						break;
					}
					if(s.charAt(j2)==sb.charAt(x)){
						++count;
						
					}
					else{
						++x;
						if(x>sb.length()-1){
							flag=1;
							break;
						}
						if(s.charAt(j2)!=sb.charAt(x)){
							flag=1;
							break;
						}
						else{
							
							int temp=len.remove(s.charAt(j2-1)+""+(x)+"")+count;
							len.put(s.charAt(j2-1)+""+(x)+"", temp);
							templen.put(s.charAt(j2-1)+""+(x)+"", (count));
							count=1;
						}
					}
					if(j2==s.length()-1){
						
						int temp=len.remove(s.charAt(j2)+""+(x+1)+"")+count;
						len.put(s.charAt(j2)+""+(x+1)+"", temp);
						templen.put(s.charAt(j2)+""+(x+1)+"", (count));
					}
				}
				System.out.println("here"+templen);
				templen2=new LinkedHashMap<String,Integer>(templen);
				comp.add(templen2);
				
				if(flag==1){
					break;
				}
				
			}
			System.out.println(comp);
			ArrayList<Integer> val=new ArrayList<Integer>(len.values());
			int total=0;
			int moves=0;
			for (LinkedHashMap<String, Integer> t1 : comp) {
				ArrayList<Integer> val2=new ArrayList<Integer>(t1.values());
				for (int j = 0; j < val2.size(); j++) {
					total+=Math.abs(val2.get(j)-(val.get(j)/n));
				}
			}
//			for (Iterator iterator = val.iterator(); iterator.hasNext();) {
//				Integer temp = (Integer) iterator.next();
//				total+=temp/n;
//			}
//			for (String s1:all){
//				moves+=Math.abs(s1.length()-total);
//			}
			
			if(flag==1){
				out.println("Case #"+(i+1)+": Fegla Won");
			}
			else{
				out.println("Case #"+(i+1)+": "+(total));
			}
			//out.println("Case #"+(i+1)+": "+n+" "+l);
		}
		out.close();
	}
}
