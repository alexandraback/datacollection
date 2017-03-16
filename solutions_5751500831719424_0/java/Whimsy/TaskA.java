import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;
import java.util.TreeMap;


class Pair{
	char c;
	int num;
	public Pair(char c,int num) {
		this.c = c;
		this.num = num;
	}
}

public class TaskA {
	Scanner in = new Scanner(System.in);
	PrintWriter out = null;
	
	public TaskA() {
		try {
//			in = new Scanner(new File("a.in"));
			in = new Scanner(new File("A-small-attempt1.in"));
			out = new PrintWriter(new File("A.out"));
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	public static void main(String[] args) {
		new TaskA().solve();
	}
	private void solve() {
		int testCase = in.nextInt();
		for (int i = 0;i<testCase;++i){
			work(i+1);
		}
		out.close();
	}
	private void work(int test) {
		
		int n = in.nextInt();
		
		List<Pair>[] lists = (List<Pair>[]) new List[n];
		
		for (int i = 0;i<n;++i){
			lists[i] = new ArrayList<Pair>();
		}
		for (int i = 0;i<n;++i){
			String s = in.next();
			for (int j = 0;j<s.length();++j){
				char c = s.charAt(j);
				
				put(lists[i],c);
				
			}
		}
		
		
		boolean flag = identical(lists,n);
		out.printf("Case #%d: ", test);
		if (!flag){
			out.println("Fegla Won");
		} else {
			int finalAns = 0;
			for (int i = 0;i<lists[0].size();++i){
				ArrayList<Integer> arr = new ArrayList<Integer>();
				for (int j = 0;j<n;++j){
					arr.add(lists[j].get(i).num);
				}
				Collections.sort(arr);
				int mid = arr.get(arr.size() / 2);
				int ans = 0;
				for (int j = 0;j<arr.size();++j){
					ans += Math.abs(arr.get(j)-mid);
				}
				finalAns += ans;
			}
			
			out.println(finalAns);
		}

	
	}
	private boolean identical(List<Pair>[] lists,int n) {
		for (int i = 1;i<n;++i){
			if (lists[i].size() != lists[0].size()) return false;
			
			for (int j = 0;j<lists[0].size();++j){
				if (lists[0].get(j).c != lists[i].get(j).c){
					return false;
				}
			}
			
		}
		
		return true;
	}
	private void put(List<Pair> list, char c) {
		if (list.size() == 0){
			list.add( new Pair(c,1));
		} else {
			if (list.get(list.size()-1).c == c){
				list.set(list.size()-1, new Pair(c,list.get(list.size()-1).num+1) )  ;
			} else {
				list.add( new Pair(c,1));
			}
		}
	}
}
