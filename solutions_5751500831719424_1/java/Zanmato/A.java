import java.io.BufferedReader;
import java.io.File;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;


public class A {

	public static void main(String[] args) throws Exception{
		FileOutputStream fop = null;
		File file;
		BufferedReader br = new BufferedReader(new FileReader("c:\\A-large.in"));
		//BufferedReader br = new BufferedReader(new FileReader("c:\\in.in"));
		try {
			file = new File("c:\\A-large.out");
			fop = new FileOutputStream(file);
		
			int testcase = Integer.parseInt(br.readLine());
			
			for(int i=0;i<testcase;i++){
				int n = Integer.parseInt(br.readLine());
				List<String> list = new ArrayList<String>();
				for(int j=0;j<n;j++){
					list.add(br.readLine());
				}
				 
				//System.out.println(list.get(0).length()-list.get(1).length());
				
				String first = list.get(0);
				String prev = first.charAt(0)+"";
				String dStr = prev;
				for(int j=1;j<first.length();j++){
					String cur = first.charAt(j)+"";
					
					if(prev.compareTo(cur) != 0){
						dStr += cur;
					}
					
					prev = cur;
				}
				
				String ans = "";
				int cnt = 0;
				for(int j=0;j<dStr.length();j++){
					String c = dStr.charAt(j)+"";
					//System.out.println("c:"+c);
					
					List<Integer> cnts = getCountChar(list, c);
					
					//System.out.println(Arrays.toString(cnts.toArray()));
					
					if(cnts.contains(new Integer(0))){
						ans = "Fegla Won";
						break;
					}
					else{
						cnt += calc(cnts);
					}
				}
				
				for(String s:list){
					if(s.length()>0){
						ans = "Fegla Won";
					}
				}
				
				if(ans.length()==0){
					ans = cnt+"";
				}
				
				String out = "Case #"+(i+1)+": "+ans+"\n";
				System.out.print(out);
				byte[] contentInBytes = out.getBytes();
				fop.write(contentInBytes);
			}
		} finally {
	        br.close();
	        fop.flush();
			fop.close();
	    }
	}

	private static List<Integer> getCountChar(List<String> list, String c){
		List<Integer> cnts = new ArrayList<Integer>();
		
		for(int i=0;i<list.size();i++){
			int cnt = 0;
			String s = list.get(i);
			
			//System.out.println("s:"+s);
			
			for(int j=0;j<s.length();j++){
				String s1 = s.charAt(j)+""; 
				if(s1.compareTo(c)==0) cnt++;
				else break;
			}
			
			list.set(i, s.substring(cnt));
			
			cnts.add(cnt);
		}
		
		return cnts;
	}
	
	private static boolean checkStrings(String str1, String str2){
		for(int i=0;i<str1.length();i++){
			if(!str2.contains(str1.charAt(i)+"")){
				return false;
			}
		}
		for(int i=0;i<str2.length();i++){
			if(!str1.contains(str2.charAt(i)+"")){
				return false;
			}
		}
		return true;
	}
	
	private static int calc(List<Integer> cnts){
		Integer[] sCnts = cnts.toArray(new Integer[cnts.size()]);
		Arrays.sort(sCnts);

		int m = sCnts.length;
		if(m%2==0) m = m/2-1;
		else m = m/2;

		int changeTo = sCnts[m];
		int cnt = 0;
		
		for(Integer c:sCnts){
			cnt += Math.abs(changeTo-c);
		}
		
		if(m%2==0){
			int changeTo2 = sCnts[m+1];
			int cnt2 = 0;
			
			for(Integer c:sCnts){
				cnt2 += Math.abs(changeTo2-c);
			}
			
			if(cnt2<cnt) cnt = cnt2;
		}
		
		//System.out.println("changeTo:"+changeTo+", cnt:"+cnt);
		
		return cnt;
	}
}
 