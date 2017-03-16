import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashSet;

public class A {
	
	private static final boolean String = false;

	public static void main(String[] args) throws IOException {
		String dataFile = "./data/A-small-attempt0.in";
		String outFile = "./out/A.out";
		BufferedReader reader = new BufferedReader(new FileReader(dataFile));
		PrintWriter printer = new PrintWriter(outFile, "UTF-8");
		
		String line = reader.readLine();
		
		int nb_problem = Integer.parseInt(line);
		for (int i = 0; i < nb_problem; ++i) {
			line = reader.readLine();
			//int items = Integer.parseInt(line);
			line = reader.readLine();
			String[] elements = line.split(" ");
			int[] data = new int[elements.length];
			for (int j = 0; j < elements.length; ++j)
				data[j] = Integer.parseInt(elements[j]);
			
			String res = problemA(data);
			System.out.println(res);
			printer.println("Case #"+(i+1)+": "+res);
		}
		
		reader.close();
		printer.close();
		System.out.println("Done");
	}
	
	public static String problemA(int[] data) {
		ArrayList<String> res = new ArrayList<String>();
		
		int total = 0;
		for (int i = 0; i < data.length; ++i)
			total += data[i];
		
		int max1, max2;
		int p1, p2;
		while (total > 0) {
			p1 = -1; 
			p2 = -1;
			max1 = -1; 
			max2 = -1;
			for (int i = 0; i < data.length; ++i) {
				if (data[i] > max1 && data[i] > 0) {
					max1 = data[i];
					p1 = i;
				}
			}
			if (p1 != -1) {data[p1]--; total--;}
			for (int i = 0; i < data.length; ++i) {
				if (data[i] > max2 && data[i] > 0) {
					max2 = data[i];
					p2 = i;
				}
			}
			if (p2 != -1) {data[p2]--; total--;}
			res.add(toString(p1)+toString(p2));
		}
		
		// switch last
		if (res.get(res.size()-1).length() == 1) {
			String elt = res.get(res.size()-1)+res.get(res.size()-2).charAt(1);
			res.set(res.size()-1, elt);
			res.set(res.size()-2, res.get(res.size()-2).substring(0, 1));
		}
		
		String str = "";
		for (String s : res)
			str += s+" ";
		
		return str;
		
	}
	
	public static String toString(int alpha) {
		if (alpha == -1)
			return "";
		String str = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
		return Character.toString(str.charAt(alpha));
	}
	
	
}
