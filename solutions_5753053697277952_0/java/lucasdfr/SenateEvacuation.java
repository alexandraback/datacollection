import java.io.IOException;
import java.io.PrintWriter;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.stream.Stream;


public class SenateEvacuation {
	static ArrayList<String> plan;
	static int indexOfMax(int[] P){
		int idx = 0;
		for (int i = 0; i < P.length; i++) {
			if(P[i] > P[idx]) idx = i;
		}
		return idx;
	}
	static String iTs(int i){
		return (char)(i + 65) + ""; 
	}
	static void solve(int[] P){
		plan = new ArrayList<String>();
		int sum = 0;
		for (int i = 0; i < P.length; i++) {
			sum += P[i];
		}
		if(sum % 2 != 0){
			int i = indexOfMax(P);
			P[i] -- ;
			plan.add(iTs(i));
		}
		while (true){
			int i1 = indexOfMax(P);
			if(P[i1] == 0) break;
			P[i1]--;
			String s1 = iTs(i1);
			int i2 = indexOfMax(P);
			String s2 = iTs(i2);
			P[i2]--;
			plan.add(s1+s2);
		}
	}
	public static void main(String[] args) {
		Path pathInput = Paths.get( "src", "input.txt");
		try {
			PrintWriter writer = new PrintWriter("output.txt", "UTF-8");
			Stream<String> input = Files.lines(pathInput, StandardCharsets.UTF_8);
			Iterator<String> it = input.iterator();
			int T = Integer.parseInt(it.next());
			int N;
			for (int i = 1; i < T+1; i++) {
				N = Integer.parseInt(it.next());
				String[] Pstring = it.next().split(" ");
				int[] P = new int[N];
				for (int j = 0; j < Pstring.length; j++) {
					P[j] = Integer.parseInt(Pstring[j]); 
				}
				solve(P);
				writer.print("Case #"+i+": ");
				for (int j = 0; j < plan.size(); j++) {
					writer.print(plan.get(j)+" ");
				}
				writer.println();
			}
			input.close();
			writer.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}
