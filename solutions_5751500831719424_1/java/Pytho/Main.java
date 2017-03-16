import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.regex.Pattern;

import org.apache.commons.math3.Field;

import static java.lang.Math.*;





public class Main extends Util {
	

	
	public static void main(String[] args){
		(new Main()).mainA();
	}
	
	public void mainA(){
		scanFile("A-large.in");
		s.useDelimiter(Pattern.compile("\\s"));
		outputInFile("Al0.out");
		int T=s.nextInt();
		for (int i=0;i<T;i++){
			int N=s.nextInt();
			boolean first=true;
			boolean sol=true;
			List<String> tmpl=new ArrayList<String>();
			List<List<Integer>> aij=new ArrayList<List<Integer>>();
			for (int j=0;j<N;j++){
				String l=s.next()+"!";
				char c=l.charAt(0);
				int cc=0;
				int idx=0;
//				List<Integer> a=new ArrayList<Integer>();
				if (sol){
					for (int k=0;k<l.length();k++){
						if (l.charAt(k)!=c){
							if (first){
								List<Integer> ai=new ArrayList<Integer>();
								ai.add(cc);
								aij.add(ai);
								tmpl.add(String.valueOf(c));
							}else{
								if (idx>=tmpl.size()||tmpl.get(idx).charAt(0)!=c){
									sol=false;
									break;
								}
								List<Integer> ai=aij.get(idx);
								ai.add(cc);
							}
							cc=1;
							c=l.charAt(k);
							idx++;
						}else{
							cc++;
						}
					}
				}
				first=false;
//				showln(l);
			}
			if (!sol){
				showln("Case #%d: Fegla Won", i+1);
			}else{
				int act=0;
				int len=aij.get(0).size();
				boolean sol2=true;
				for (List<Integer> ai: aij){
					if (ai.size()!=len){
						showln("Case #%d: Fegla Won", i+1);
						sol2=false;
						break;
					}
					Collections.sort(ai);
					int k=ai.get(ai.size()/2);
					for (int e: ai){
						act+=abs(k-e);
					}
				}
				if (sol2){
					showln("Case #%d: %d",i+1,act);
				}
			}
		}
	}


}
