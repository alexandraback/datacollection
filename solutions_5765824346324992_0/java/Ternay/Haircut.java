import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;
import java.nio.charset.Charset;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.List;


public class Haircut {

	public static void main(String[] args) throws FileNotFoundException, UnsupportedEncodingException {
        String fileName = "B-small-attempt1.in";
        PrintWriter writer = new PrintWriter("B-small-attempt1.out", "UTF-8");
        try {
            List<String> lines = Files.readAllLines(Paths.get(fileName), Charset.defaultCharset());
            int t = Integer.parseInt(lines.get(0));
            for (int i = 0; i < t; i++) {
            	String line[] = lines.get(2*i+1).split(" ");
            	int b = Integer.parseInt(line[0]);
            	int n = Integer.parseInt(line[1]);
            	line = lines.get(2*i+2).split(" ");
            	int m[] = new int[b];
            	int min = 0;
            	int max = 0;
            	for (int j = 0; j < b; j++) {
            		m[j] = Integer.parseInt(line[j]);
            		if (j == 0) {
            			min = m[j];
            			max = m[j];
            		}
            		else if(m[j] < min) min = m[j];
            		else if(m[j] > max) max = m[j];
            	}
            	writer.println("Case #"+(i+1)+": "+haircut(b,n,m,min,max));
            }
            writer.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
	}
	
	public static int haircut(int b, int n, int m[], int min, int max) {
		if (n <= b) return n;
		if (min == max) return (n%b == 0) ? b : n%b;
		int c = n-b;
		int lcm = lcm(m,max);
		int sum = 0;
		for (int i = 0; i < b; i++) sum += lcm/m[i];
		int div = c/sum;
		c -= div*sum;
		if (c == 0) return b;
		int j = 1;
		while (true) {
			for (int i = 0; i < b; i++) {
				if (j%m[i] == 0) {
					c--;
					if (c == 0) return i+1;
				}
			}
			j++;
		}
	}
	
	public static int lcm(int m[], int max) {
		int i = 1;
		while (true) {
			boolean valid = true;
			for (int j = 0; j < m.length; j++) {
				if (max*i%m[j] != 0) valid = false;
			}
			if (valid) return max*i;
			i++;
		}
	}

}
