package GoogleCodeJamRound1;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collection;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

public class Problem_B {

	static class two {
		int id;
		int time;

		two(int i, int t) {
			id = i;
			time = t;
		}
	}

	public static int haircut(int a, int b, int[] v) {

		int[] remain = new int[10000];
		int max = 0;
		int last = 0;
		int sum = 0;
		int min =10000;
		if (b<=a) return b-1;
		b = b-a;
		for (int i = 0; i < a; i++) {
			if (max < v[i])
				max = v[i];
			if (max == v[i]) {
				last = i;
			}
			if (min >=v[i])  min =v[i];
			sum += v[i];
		}
		int t = 0;
		for (int k=min; k>=1; k--)
		{
			int count = 0;
			for (int i=0; i<a; i++)
			{
				if (v[i]%k==0) count++;
			}
			if (count == a) 
			{
				min = k;
				break;
			}
		}
		for (int i=0; i<a; i++) v[i]/=min;
		int com=1;
		for (int i=0; i<a; i++) com*=v[i];
		
		
		for (int i = 0; i < a; i++)
		{
			t += com/v[i];
		}

		int la = b / t;

		int present = b%t;
		System.out.println( " " + present +" " +b);
		if (present == 0) {
			
			return last;
		}
		
		

		List<two> temp = new ArrayList<two>();
		for (int i = 0; i < a; i++) {
			for (int j = 1; j <=t; j++) {
				
				int time;
				
				{ time = remain[i] + v[i] * j;
				
				}
				temp.add(new two(i, time));
			}
		}
		
		Collections.sort(temp, new Comparator<two>() {
			public int compare(two i1, two i2) {
				return i1.time - i2.time;
			}
		});
		/*for (int i=0; i<a*(t-1); i++)
		{
			System.out.print(temp.get(i).id+" " +temp.get(i).time+" ");
			System.out.println("");
		}*/
		
		return temp.get(present-1).id;

	}

	public static void main(String[] args) {
		String inFile = "//Users//lixuefei//Documents//JavaWorkspace//Interview//src//GoogleCodeJamRound1//in.txt";
		String outFile = "//Users//lixuefei//Documents//JavaWorkspace//Interview//src//GoogleCodeJamRound1//result.txt";
		int n = 0;
		String line;
		try {
			FileReader fileReader = new FileReader(inFile);
			BufferedReader br = new BufferedReader(fileReader);
			FileWriter fileWriter = new FileWriter(outFile);
			BufferedWriter bw = new BufferedWriter(fileWriter);
			line = br.readLine();
			n = Integer.parseInt(line);
			for (int i = 0; i < n; i++) {
				line = br.readLine();
				String[] parts = line.split(" ");
				int B = Integer.parseInt(parts[0]);
				int N = Integer.parseInt(parts[1]);

				line = br.readLine();
				String[] part = line.split(" ");
				int[] M = new int[B];
				for (int j = 0; j < B; j++) {
					M[j] = Integer.parseInt(part[j]);
				}
				//for (N=1; N<=10; N++)
				{
					int result = haircut(B, N, M)+1;
					bw.write("Case #" + (i + 1) + ": " + result + "\n");
				}
				

			}
			br.close();
			bw.close();
		} catch (IOException ex) {
			ex.printStackTrace();
		}

	}
}
