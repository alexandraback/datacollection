import java.util.*;
import java.io.*;

public class A {
        
    public static void main(String[] args) throws Exception {
    	Scanner s = new Scanner(new FileReader("a.in"));
    	PrintWriter p = new PrintWriter(new FileWriter("a.out"));
    	int t = s.nextInt();
    	for(int i=0; i<t; i++) {
    		int n = s.nextInt();
    		Word[] words = new Word[n];
    		for(int j=0; j<n; j++)
    			words[j] = new Word(s.next());
    		boolean check = false;
    		for(int j=0; j<n; j++) {
    			for(int k=0; k<n; k++)
    				if(!words[j].check(words[k])) {
    					check = true;
    					break;
    				}
    			if(check)
    				break;
    		}
    		if(check) {
    			p.println("Case #" + (i+1) + ": Fegla Won");
    			continue;
    		}
    		int ans = 0;
    		for(int j=0; j<words[0].freq.size(); j++) {
				int c = 1;
				int min = 1000000000;
				while(true) {
					int tmp = 0;
					for(int k=0; k<n; k++)
						tmp += Math.abs(words[k].freq.elementAt(j)-c);
					if(min > tmp)
						min = tmp;
					else break;
					c++;
				}
				ans += min;
    		}
    		p.println("Case #" + (i+1) + ": " + ans);
    	}
    	p.close();
    }
}

class Word {
	
	Vector<Integer> freq;
	String letters;
	
	public Word(String word) {
		freq = new Vector<Integer>();
		letters = "";
		for(int i=0; i<word.length(); i++) {
			char tmp = word.charAt(i);
			letters += tmp;
			int f = 0;
			while(word.charAt(i) == tmp) {
				f++;
				i++;
				if(i == word.length())
					break;
			}
			freq.addElement(f);
			i--;
		}
	}
	
	public boolean check(Word w) {
		return letters.equals(w.letters);
	}
}