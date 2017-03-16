package round1C2016;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.PriorityQueue;

public class A {
	
	static class Party implements Comparable<Party>{
		char id;
		int people;
		Party(int i, int p){
			id=(char)(i+64);
			people=p;
		}
		@Override
		public int compareTo(Party that) {
			return -this.people+that.people;
		}
	}
	
	static String ats(PriorityQueue<Party> p){
		String res = "";
		while(!p.isEmpty()){
			if(p.size()==2)
				res+=p.poll().id+""+p.poll().id;
			else
				res+=p.poll().id+" ";
		}
		return res;
	}
	
	public static void main(String[] args) throws Exception {
//		BufferedReader br = new BufferedReader(new FileReader("A-small-attempt0.in"));
//        PrintWriter pw = new PrintWriter(new File("A-small.out"));
        BufferedReader br = new BufferedReader(new FileReader("A-large.in"));
        PrintWriter pw = new PrintWriter(new File("A-large.out"));
        int T = Integer.parseInt(br.readLine());
        for(int i=1;i<=T;i++){
        	int N = Integer.parseInt(br.readLine());
        	String[] l = br.readLine().split(" ");
        	PriorityQueue<Party> parties = new PriorityQueue<A.Party>();
        	int all = 0;
        	for(int j=1;j<=l.length;j++){
        		parties.add(new Party(j, Integer.parseInt(l[j-1])));
        		all+=Integer.parseInt(l[j-1]);
        	}
        	String res = "";
        	while(!parties.isEmpty()){
        		if(parties.peek().people==1)
        			break;
        		Party maj = parties.poll();
        		Party next = parties.poll();
        		if(all-2>=2*next.people){
        			maj.people-=2;
        			all-=2;
        			res+=""+maj.id+maj.id+" ";
        		} else {
        			maj.people-=1;
        			next.people-=1;
        			all-=2;
        			res+=""+maj.id+next.id+" ";
        		}
        		if(maj.people>0)
        			parties.add(maj);
        		if(next.people>0)
        			parties.add(next);
        	}
        	pw.println("Case #"+i+": "+res+ats(parties));
        }
        pw.close();
        br.close();
	}
}
