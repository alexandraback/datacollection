package mypackage;
import java.io.*;
import java.util.*;

public class ProblemeA {
  private static InputReader in;
  private static PrintWriter out;
  public static boolean SUBMIT = true;
  public static final String CHEMIN = "C:\\Users\\dev\\workspace\\GoogleJamDream\\src\\";
  public static final String NAME = "A-large";

  private static void main2() throws IOException {
   //Char
   /* char[] s = in.next().toCharArray();
    int n = s.length; */
	//Integer
	  int i=0;
	int[] p = new int[1000];
	char myChar;
	int n = in.nextInt();
	for (i=0;i<n;i++) {
		p[i]=in.nextInt();
	}
	int nbrTotal=0;
	for (i=0;i<n;i++){
		nbrTotal=nbrTotal+p[i];
	}
	
	while (nbrTotal!=0) {
		boolean secondEvac = false;
		int evacuateOne =0, evacuateTwo =0;
		evacuateOne = biggestParty(p,n);
		p[evacuateOne]--;
		nbrTotal--;
		
		if(nbrTotal!=0) {
		evacuateTwo = biggestParty(p,n);
		p[evacuateTwo]--;
		nbrTotal--;
		
		secondEvac = checkMajority(p,n);
		}
		if (secondEvac) {
			p[evacuateTwo]++;
			nbrTotal++;
			myChar = (char) (evacuateOne +65);
		    out.print(myChar);
		} else {
			myChar = (char) (evacuateOne +65);
		    out.print(myChar);
			myChar = (char) (evacuateTwo +65);
		    out.print(myChar);
		}
	out.print(" ");
	}
	out.println();
  }
  
  public static int biggestParty(int[] p,int n) {
	  int number=0,i=0,partyNbr=0;
	  for (i=0;i<n;i++) {
		  if(p[i]>number) {
			  number=p[i];
			  partyNbr=i;
		  }
	  }
	  return partyNbr;
  }
  
  public static boolean checkMajority(int[] p,int n) {
	  int nbrSenate=0,i=0;
	  boolean max =false;
	  for (i=0;i<n;i++) {
		  nbrSenate=nbrSenate+p[i];
	  }
	  for (i=0;i<n;i++) {
		  if (nbrSenate/2<p[i]) {
			  max=true;
		  }
	  }
	  return max;
  }

  public static void main(String[] args) throws IOException {
    if (SUBMIT) {
      in = new InputReader(new FileInputStream(new File(CHEMIN+NAME + ".in")));
      out = new PrintWriter(new BufferedWriter(new FileWriter(CHEMIN+NAME + ".out")));
    } else {
      in = new InputReader(System.in);
      out = new PrintWriter(System.out, true);
    }

    int numCases = in.nextInt();
    for (int test = 1; test <= numCases; test++) {
      out.print("Case #" + test + ": ");
      main2();
    }

    out.close();
    System.exit(0);
  }

  static class InputReader {
    public BufferedReader reader;
    public StringTokenizer tokenizer;

    public InputReader(InputStream stream) {
      reader = new BufferedReader(new InputStreamReader(stream), 32768);
      tokenizer = null;
    }

    public String next() {
      while (tokenizer == null || !tokenizer.hasMoreTokens()) {
        try {
          tokenizer = new StringTokenizer(reader.readLine());
        } catch (IOException e) {
          throw new RuntimeException(e);
        }
      }
      return tokenizer.nextToken();
    }

    public int nextInt() {
      return Integer.parseInt(next());
    }
  }
}
