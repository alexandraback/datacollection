import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;
import java.nio.charset.Charset;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.List;


public class Logging {

	public static void main(String[] args) throws FileNotFoundException, UnsupportedEncodingException {
        String fileName = "C-small-attempt0.in";
        PrintWriter writer = new PrintWriter("C-small-attempt0.out", "UTF-8");
        try {
            List<String> lines = Files.readAllLines(Paths.get(fileName), Charset.defaultCharset());
            int t = Integer.parseInt(lines.get(0));
            int used = 1;
            for (int i = 1; i <= t; i++) {
            	int n = Integer.parseInt(lines.get(used));
            	int x[] = new int[n];
            	int y[] = new int[n];
            	for (int j = 0; j < n; j++) {
            		String line[] = lines.get(used+j+1).split(" ");
            		x[j] = Integer.parseInt(line[0]);
            		y[j] = Integer.parseInt(line[1]);
            	}
            	writer.println("Case #"+i+":");
            	writer.println(logging(n,x,y));
            	used += n+1;
            }
            writer.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
	}
	
	public static String logging (int n, int x[], int y[]) {
		String result = "";
		int xmin = x[0];
		int xmax = x[0];
		int ymin = y[0];
		int ymax = y[0];
		for (int i = 1; i < n; i++) {
			if (x[i] < xmin) xmin = x[i];
			else if (x[i] > xmax) xmax = x[i];
			if (y[i] < ymin) ymin = y[i];
			else if (y[i] > ymax) ymax = y[i];
		}
		for (int i = 0; i < n; i++) {
			int t = 0;
			int rx = Math.min(Math.abs(x[i]-xmin), Math.abs(x[i]-xmax));
			int ry = Math.min(Math.abs(y[i]-ymin), Math.abs(y[i]-ymax));
			if (Math.min(rx, ry) == 0) {
				result = (i != n-1) ? result + "0\n" : result + "0";
			} else if (n <= 5) {
				result = (i != n-1) ? result + "1\n" : result + "1";
			}
			else if (Math.min(rx, ry) == rx) {
				if (rx == Math.abs(x[i]-xmin)) {
					for(int j = 0; j < n; j++) {
						if(x[i] < x[j]) t++;
					}
				} else {
					for(int j = 0; j < n; j++) {
						if(x[i] > x[j]) t++;
					}
				}
				result = (i != n-1) ? result + t + "\n" : result + t+ "";
			} else {
				if (ry == Math.abs(y[i]-ymin)) {
					for(int j = 0; j < n; j++) {
						if(y[i] < y[j]) t++;
					}
				} else {
					for(int j = 0; j < n; j++) {
						if(x[i] < x[j]) t++;
					}
				}
				result = (i != n-1) ? result + t + "\n" : result + t+ "";
			}
		}
		return result;
	}

}
