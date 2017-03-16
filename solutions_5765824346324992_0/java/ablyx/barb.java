import java.io.*;
import java.util.*;

class barb{

	public static Comparator<barbtup> bcmp = new Comparator<barbtup>()
    {
        public int compare(barbtup bt1 , barbtup bt2)//change compare so that it gives descending instead of ascending
        {
            if((bt1.btime - bt2.btime)==0){
            	return bt1.bno - bt2.bno;
            }
            else{
            	return bt1.btime - bt2.btime;
            }
            //return bt1.btime - bt2.btime;
        }
    };
	
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int numcase = sc.nextInt();
		//public Comparator
		for(int i =0;i<numcase;i++){
			int numb = sc.nextInt();
			int pos = sc.nextInt();
			//Queue<Integer> mushin1 = new LinkedList<Integer>();
			//Queue<Integer> mushin2 = new LinkedList<Integer>();
			ArrayList<Integer> seq = new ArrayList<Integer>();
			ArrayList<barbtup> sortt = new ArrayList<barbtup>();
			for(int j=0;j<numb;j++){
				int barbtime = sc.nextInt();
				barbtup bt = new barbtup(j+1,barbtime);
				sortt.add(bt);
				seq.add(j+1);
				//mushin1.offer(mushtime);
				//mushin2.offer(mushtime);
			}
			Collections.sort(sortt,bcmp);
			//while(Collections.max(sortt,bcmp)!=Collections.min(sortt,bcmp)){
			while(sortt.get(0).btime!=sortt.get(numb-1).btime){
				sortt.get(0).btime = sortt.get(0).btime + sortt.get(0).otime;
				//System.out.println(sortt.get(0).btime);
				seq.add(sortt.get(0).bno);
				Collections.sort(sortt,bcmp);
			}
			//System.out.println(seq);
			int seqsize = seq.size();
			pos = (pos-1)%seqsize;
			int ans = seq.get(pos);
			
			System.out.println("Case #"+(i+1)+": "+ans);
		}
	}
	
}

class barbtup{
	int bno;
	int btime;
	int otime;
	public barbtup(int bno,int btime){
		this.bno = bno;
		this.btime = btime;
		otime = btime;
	}
}