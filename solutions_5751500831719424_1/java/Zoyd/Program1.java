
import java.util.*;

class Node {
	public String s;
	public ArrayList<Integer> i; 
}


public class Program1 {
	
	static Node baseStr(String s) {
		StringBuilder sb = new StringBuilder();
		ArrayList<Integer> occ = new ArrayList<>();
		
		sb.append(s.charAt(0));
		int n = 1;
		for (int i = 1; i < s.length(); i++) {
			if (s.charAt(i) != s.charAt(i-1)) {
				sb.append(s.charAt(i));
				occ.add(n);
				n = 1;
			} else {
				n++;
			}			
		}
		occ.add(n);
		
		Node nd = new Node();
		nd.s = sb.toString();
		nd.i = occ;
		return nd;
	}

	
	static int distance(ArrayList<Integer> a, ArrayList<Integer> b) {
		int total = 0;
		
		for (int i = 0; i < a.size(); i++) {
			total += Math.abs(a.get(i) - b.get(i));
		}		
		
		return total;
	}

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);

		int nCases = in.nextInt();
		in.nextLine();
		for (int caseNumber = 1; caseNumber <= nCases; caseNumber++) {
			int n = Integer.parseInt(in.nextLine());
			String[] input = new String[n];
			String s0 = in.nextLine();
			Node n0 = baseStr(s0);
			
			ArrayList<ArrayList<Integer>> data = new ArrayList<>();			
			
			input[0] = s0;
			data.add(n0.i);
			
			boolean possible = true;
			
			
			
			for (int i = 1; i < n; i++) {
				input[i] = in.nextLine();
				Node nd = baseStr(input[i]);
				data.add(nd.i);
				if (! n0.s.equals(nd.s)) {
					possible = false;
				}
			}
			
			int result = 0;
			if (possible) {
				for (int i = 0; i < data.get(0).size(); i++) {
					// médiane de data[i]
					ArrayList<Integer> a = new ArrayList<>();
					for (int j = 0; j < data.size(); j++) {
						a.add(data.get(j).get(i));
					}					
					Collections.sort(a);
					int médiane = a.get(a.size() / 2);
//					System.err.print(" médiane : ");
//					System.err.println(médiane);
					for (int j : a) {
						result += Math.abs(j-médiane);
					}
				}
				
				
//				for (int i = 0; i < data.size(); i++) {
//					ArrayList<Integer> a = data.get(i);
//					int actuel = 0;
//					for (int j = 0; j < data.size(); j++) {						
//						ArrayList<Integer> b = data.get(j);
//						System.err.print(" dist ");
//						System.err.print(a);
//						System.err.print("  -  ");
//						System.err.print(b);
//						System.err.print("  =  ");
//						System.err.println(distance (a, b));						
//						actuel += distance (a, b);
						//System.err.print("   ");
						//System.err.println(actuel);
//					}
//					System.err.print("  best = ");
//					best = Math.min(actuel, best);
//					System.err.println(best);
//					System.err.println();
//				}	
			}
			
			
			System.out.print("Case #");
			System.out.print(caseNumber);
			System.out.print(": ");
			if (possible) {
				System.out.println(result);
			} else {
				System.out.println("Fegla Won");
			}

		}
		in.close();
	}


}
