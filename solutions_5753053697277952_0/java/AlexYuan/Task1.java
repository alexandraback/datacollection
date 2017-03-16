package codejam;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.HashMap;
import java.util.Map;
import java.util.PriorityQueue;

public class Task1 {
	private static BufferedReader br = null;
	private static BufferedWriter bw = null;
	public static void main(String[] args) throws Exception {
		br = new BufferedReader(new FileReader("A-small-attempt0.in"));
		bw = new BufferedWriter(new FileWriter("result.txt"));
		int size = Integer.parseInt(br.readLine());
		String line = "";
		int index = 0;
		while((line = br.readLine())!= null ){
			index++;
			int total = 0;
			int len = Integer.parseInt(line);
			StringBuilder sb = new StringBuilder();
			String[] info = br.readLine().split(" ");
			PriorityQueue<party> pq = new PriorityQueue<party>(len, new comp());
			for(int i = 0;i<len;i++){
				int num = Integer.parseInt(info[i]);
				total += num;
				party p = new party((char)('A'+i), num);
				pq.add(p);
			}
			while(!pq.isEmpty() && total>3){
				party large = pq.poll();
				party small = pq.poll();
				if(large.size - small.size >1){
					sb.append(large.name+""+large.name+" ");
					large.size-=2;
					total-=2;
					if(large.size==0) continue;
					pq.offer(small);
					pq.offer(large);
				}else if(large.size - small.size <= 1){
					sb.append(large.name+""+small.name+" ");
					large.size-=1;
					small.size-=1;
					total-=2;
					if(large.size!=0)
						pq.offer(large);
					if(small.size!=0)
						pq.offer(small);
				}
			}
			if(total == 3){
				party p1 = pq.poll();
				party p2 = pq.poll();
				party p3 = pq.poll();
				sb.append(p1.name+" ");
				sb.append(p2.name+""+p3.name+" ");
			}else if(total == 2){
				party p2 = pq.poll();
				party p3 = pq.poll();
				sb.append(p2.name+""+p3.name+" ");				
			}
			sb.deleteCharAt(sb.length()-1);
			String res = "Case #"+index+": "+sb.toString();
			bw.write(res);
			bw.newLine();
		}
		if(bw != null){
			bw.close();			
		}
		if(br != null){
			br.close();
		}
	}
}
class comp implements Comparator<party>{
	public int compare(party p1, party p2){
		return p2.size - p1.size;
	}
}
class party{
	char name;
	int size;
	public party(char n, int s) {
		name = n;
		size = s;
	}
}