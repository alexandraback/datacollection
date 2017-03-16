package gcj2016.r1c;


import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;

public class Senators {
	private static final String INPUT_FILE_NAME = "A-small.in";
	private static final String OUTPUT_FILE_NAME = "A-small.out";

	public static void main(String[] args) {
		new Senators().start();
	}

	private int[] p;
	private Integer n;
	private int sumSen;
	
	private void start() {
		try (
				MyReader reader = new MyReader(new BufferedReader(new FileReader(INPUT_FILE_NAME)));
				PrintWriter printer = new PrintWriter(new FileWriter(OUTPUT_FILE_NAME))) {
			Integer ncases = reader.nextInt();
			for(int i = 0 ; i < ncases ; i++) {
				String rs = solve(reader);
				printer.println("Case #" + (i+1) + ":" + rs );
			}
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
	
	private String solve(MyReader reader) {
		n = reader.nextInt();
		p = new int[n];
		sumSen = 0;
		for(int i = 0 ; i < n ; i++) {
			p[i] = reader.nextInt();
			sumSen += p[i];
		}
		return plan();
	}

	private String plan() {
		int cnt = 0;
		String rs = "";
		while ( cnt < sumSen ) {
			String move = getMove();
			cnt += move.length();
			rs += " "+move;
		}
		return rs;
	}

	private String getMove() {
		String move = "";
		int sumCurSen = 0;
		for(int i = 0 ; i < n ; i++) {
			sumCurSen += p[i];
		}
		for(int i = 0 ; i < n ; i++) {
			if (canRemove(i,sumCurSen)) {
				move = "" + (char)(i+'A');
				p[i]--;
				return move;
			}
		}	
		
		for(int i = 0 ; i < n ; i++)
			for(int j = 0 ; j < n ; j++)
				if ( canRemoveDouble(i,j,sumCurSen)) {
					move = "" + (char)(i+'A') + (char)(j+'A');
					p[i]--;
					p[j]--;
					return move;
				}
		return move;
	}

	private boolean canRemoveDouble(int i, int j, int sumCurSen) {
		if ( p[i] == 0 || p[j] == 0 ) return false;
		int restHalf = (sumCurSen-2)/2;
		if ( i == j ) {
			if ( p[i] == 1) return false;
			if ( (p[i]-2) > restHalf ) return false;
			for(int k = 0 ; k < n ; k++)
				if ( k != i && p[k] > restHalf ) return false;
			return true;
		} else {
			if ( p[i]-1 > restHalf || p[j]-1 > restHalf ) return false;
			for(int k = 0 ; k < n ; k++)
				if  (k != i && k !=j && p[k] > restHalf ) return false;
			return true;
		}
	}

	private boolean canRemove(int i, int sumCurSen) {
		if ( p[i] == 0 ) return false;
		int restHalf = (sumCurSen - 1) /2;
		if ( p[i] - 1 > restHalf ) return false;
		for(int j = 0 ; j < n ; j++)
			if ( j != i && p[j] > restHalf ) return false;
		return true;
	}

	public int[] toArray(ArrayList<Integer> list) {
		int[] a = new int[list.size()];
		for(int i = 0 ; i < a.length ; i++) {
			a[i] = list.get(i);
		}
		return a;	
	}
	
	public static List<Integer> toList(int[] a) {
		List<Integer> list = new ArrayList<Integer>();
		for(int i = 0 ; i < a.length ; i++)
			list.add(a[i]);
		return list;
	}

	public static String list2String(ArrayList<Integer> list) {
		StringBuilder sb = new StringBuilder();
		for(int i = 0 ; i < list.size() - 1; i++) {
			sb.append(list.get(i)+" ");
		}
		sb.append(list.get(list.size()-1));
		return sb.toString();
	}

	public class MyReader implements AutoCloseable {

		private BufferedReader br;
		private int index;
		private String[] words;

		public MyReader(BufferedReader br) {
			this.br = br;
		}
				
		public Integer nextInt() {
			try {
				String s = getNextWord();
				if ( s == null ) return null;
				return Integer.parseInt(s);
			} catch (Exception e) {
				e.printStackTrace();
				return null;
			}
		}				
		
		private String getNextWord() throws IOException {
			if ( words == null || index >= words.length) {
				String line = br.readLine();
				if ( line == null ) return null;
				index = 0;
				words = line.split(" ");
			}
			return words[index++];
		}
		
		public Long nextLong() {
			try {
				String s = getNextWord();
				if ( s == null ) return null;
				return Long.parseLong(s);
			} catch (Exception e) {
				e.printStackTrace();
				return null;
			}
			
		}
		

		public String nextString() {
			try {
				String s = getNextWord();
				if ( s == null ) return null;
				return s;
			} catch (IOException e) {
				e.printStackTrace();
				return null;
			}
		}

		@Override
		public void close() throws Exception {
			try { this.br.close(); } catch (Exception e) {}
		}
	}
}
