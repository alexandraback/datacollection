import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;
import java.nio.charset.Charset;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.List;


public class MushroomMonster {

	public static void main(String[] args) throws FileNotFoundException, UnsupportedEncodingException {
        String fileName = "A-large.in";
        PrintWriter writer = new PrintWriter("A-large.out", "UTF-8");
        try {
            List<String> lines = Files.readAllLines(Paths.get(fileName), Charset.defaultCharset());
            int t = Integer.parseInt(lines.get(0));
            for (int i = 0; i < t; i++) {
            	int n = Integer.parseInt(lines.get(2*i+1));
            	String line[] = lines.get(2*i+2).split(" ");
            	int m[] = new int[n];
            	for (int j = 0; j < n; j++) {
            		m[j] = Integer.parseInt(line[j]);
            	}
            	writer.println("Case #"+(i+1)+": "+mushroomMonster(n,m));
            }
            writer.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
	}
	
	public static String mushroomMonster(int n, int m[]) {
		int y = 0;
		int z = 0;
		int max = 0;
		for (int i = 0; i < n-1; i++) {
			int d = m[i]-m[i+1];
			if (d > 0) y += d;
			if (d > max) max = d;
		}
		for (int i = 0; i < n-1; i++) {
			if (m[i] < max) z += m[i];
			else z += max;
		}
		return y+" "+z;
	}

}
