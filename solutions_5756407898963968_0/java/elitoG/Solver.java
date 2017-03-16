import java.io.BufferedReader;
import java.io.EOFException;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;



public class Solver {
	
	public static void main(String[] args) {
		Solver solver = new Solver();
		solver.readFromFile("src/A-small-attempt1.in");
	}

	private ArrayList<ArrayList<Integer>> first_cards = new ArrayList<ArrayList<Integer>>();
	private ArrayList<ArrayList<Integer>> last_cards = new ArrayList<ArrayList<Integer>>();
	private int nb_case = 0;
	private int first_guess = 0;
	private int last_guess = 0;
	
	public Solver() {
		init();
	}
	
	private void solveACase() {
		first_cards.get(first_guess-1).retainAll(last_cards.get(last_guess-1));
		if (first_cards.get(first_guess-1).size() == 1) {
			System.out.println(first_cards.get(first_guess-1).get(0));
		} else if (first_cards.get(first_guess-1).size() == 0) {
			System.out.println("Volunteer cheated!");
		} else {
			System.out.println("Bad magician!");
		}
	}
	
	private void init() {
		for (int i = 0; i < 4; i++) {
			first_cards.add(new ArrayList<Integer>());
			last_cards.add(new ArrayList<Integer>());
		}
	}
	
	public void readFromFile(String f) {
		BufferedReader br=null;
		String chaine = null;
		
	    try {
	    	try {
	    		br = new BufferedReader(new FileReader(f));
	    		nb_case = Integer.parseInt(br.readLine());
	    		if (nb_case > 0) {
	    			for (int i = 1; i <= nb_case; i++) {
	    				first_guess = Integer.parseInt(br.readLine());
	    				String four_case[] = new String[4];
	    				for (int j = 0; j < 4; j++) {
	    					chaine = br.readLine();
	    					four_case = chaine.split(" ");
	    					first_cards.get(j).clear();
	    					for (int j2 = 0; j2 < 4; j2++) {
	    						first_cards.get(j).add(Integer.parseInt(four_case[j2]));
							}
						}
	    				last_guess = Integer.parseInt(br.readLine());
	    				for (int j = 0; j < 4; j++) {
	    					chaine = br.readLine();
	    					four_case = chaine.split("\\s");
	    					last_cards.get(j).clear();
	    					for (int j2 = 0; j2 < 4; j2++) {
	    						last_cards.get(j).add(Integer.parseInt(four_case[j2]));
							}
						}
	    				System.out.print("Case #"+ i + ": ");
	    				solveACase();
					}
	    		}
       		} catch(EOFException e) {
       			br.close();
       		}
	    } catch(FileNotFoundException e) {
	    	System.out.println("fichier inconnu : " + f);
	    } catch(IOException e) {
	    	System.out.println("IO Exception");
	    }
	}

}