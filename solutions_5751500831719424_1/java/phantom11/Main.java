import java.util.List;
import java.io.InputStreamReader;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.BufferedWriter;
import java.util.ArrayList;
import java.io.BufferedReader;
import java.io.FileOutputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.FileInputStream;
import java.io.Writer;
import java.util.StringTokenizer;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author Lokesh Khandelwal
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream;
		try {
			inputStream = new FileInputStream("A-large.in");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		OutputStream outputStream;
		try {
			outputStream = new FileOutputStream("output_large_A.txt");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		InputReader in = new InputReader(inputStream);
		OutputWriter out = new OutputWriter(outputStream);
		TaskA solver = new TaskA();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskA {
    public void solve(int testNumber, InputReader in, OutputWriter out) {
        int n = in.nextInt(), i, j, k;
        List<Compressed> a[] = new List[n];

        for(i=0;i<n;i++) {
            a[i] = compress(in.next());
        }
//        if(testNumber == 5)
//        for(i=0;i<n;i++) {
//            for(j=0;j<a[i].size();j++) {
//                DebugUtils.print(a[i].get(j).character+" "+a[i].get(j).freq);
//            }
//        }
        boolean status = true;
        int l1 = a[0].size();
        for(i=1;i<n;i++) {
            int l2 = a[i].size();
            if(l1 != l2) {
                status = false;
                break;
            }
            for(j=0;j<l1;j++) {
                if(a[0].get(j).character != a[i].get(j).character) {
                    status = false;
                    break;
                }
            }
        }
        if(!status) {
            String res = "Fegla Won";
            out.printLine("Case #"+testNumber+": "+res);
            return;
        }
        int ans = 0;
        for(i=0;i<l1;i++) {
            int sum = 0;
            boolean isOne = false;
            for(j=0;j<n;j++) {
                if(a[j].get(i).freq == 1) {
                    isOne = true;
                }
                sum += a[j].get(i).freq;
            }
            int p = sum / n, c = 0;
            if(p > 0)
            for(j=0;j<n;j++) {
                c += Math.abs(a[j].get(i).freq - p);
            }
            if(sum % n != 0) {
                int c1 = 0;
                for(j=0;j<n;j++) {
                    c1 += Math.abs(a[j].get(i).freq - (p + 1));
                }
                c = Math.min(c, c1);
            }

            ans += c;
        }
        out.printLine("Case #"+testNumber+": "+ans);
    }
    public ArrayList<Compressed> compress(String a) {
        int n = a.length();
        int i, count = 1;
        char c = a.charAt(0);
        char last = c;
        ArrayList<Compressed> res = new ArrayList<Compressed>();
        for(i=1;i<n;i++) {
            if(a.charAt(i) == last) {
                count++;
            }
            else {
                res.add(new Compressed(count, last));
                last = a.charAt(i);
                count = 1;
            }
        }
        if(count > 0) {
            res.add(new Compressed(count, last));
        }
        return res;
    }
    class Compressed {
        int freq;
        char character;
        public Compressed(int freq, char character) {
            this.character = character;
            this.freq = freq;
        }
    }
}

class InputReader
{
    BufferedReader in;
    StringTokenizer tokenizer=null;

    public InputReader(InputStream inputStream)
    {
        in=new BufferedReader(new InputStreamReader(inputStream));
    }
    public String next()
    {
        try{
            while (tokenizer==null||!tokenizer.hasMoreTokens())
            {
                tokenizer=new StringTokenizer(in.readLine());
            }
            return tokenizer.nextToken();
        }
        catch (IOException e)
        {
            return null;
        }
    }
    public int nextInt()
    {
        return Integer.parseInt(next());
    }
}

class OutputWriter {
	private final PrintWriter writer;

	public OutputWriter(OutputStream outputStream) {
		writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
	}

	public OutputWriter(Writer writer) {
		this.writer = new PrintWriter(writer);
	}

	public void print(Object...objects) {
		for (int i = 0; i < objects.length; i++) {
			if (i != 0)
				writer.print(' ');
			writer.print(objects[i]);
		}
	}

	public void printLine(Object...objects) {
		print(objects);
		writer.println();
	}

	public void close() {
		writer.close();
	}
}

