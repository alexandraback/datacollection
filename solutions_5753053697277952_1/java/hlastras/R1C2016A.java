package es.hlastras.gcj2016.round1c;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Scanner;

public class R1C2016A{
	
//	private static String INPUT_FILE = "test.txt";
	private static String INPUT_FILE = "A-large.in";
	private static String OUTPUT_FILE = "A-large.out";
	private static String ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	

	public static void main(String[] args) throws Exception {		
		
		System.out.println("Starting");
		long init = System.currentTimeMillis();
		new R1C2016A().execute();
		long end = System.currentTimeMillis();
		System.out.println("End");
		System.out.println("Time: "+(end-init)+" miliseconds");

	}

	
	public void execute() throws Exception {
		BufferedReader input = new BufferedReader(new FileReader(INPUT_FILE));
		PrintWriter output = new PrintWriter(new FileWriter(OUTPUT_FILE));
		Scanner sc = new Scanner(input);
		
		String result = "";
		
		int cases = sc.nextInt();		
		for (int i = 0; i < cases; i++) {
			result = "";
			int n = sc.nextInt();
			int[] persons = new int[n];
			for (int j = 0; j < persons.length; j++) {
				persons[j]=sc.nextInt();
			}
			
			while(haveMore(persons)){
				String a = extract(persons);
				String b = null;
				if(hayMayoria(persons)){
					b = extract(persons);
					if(hayMayoria(persons)){
						undo(persons, a);
						undo(persons, b);
						b=null;
						a=null;
					}
				}else{
					b = extract(persons);
					if(hayMayoria(persons)){
						undo(persons, b);
						b=null;
					}
					
				}
				
				if(a!=null){
					result+=a;
				}
				if(b!=null){
					result +=b;
				}
				if(a!=null || b!=null){
					result+=" ";
				}
			}
			
			
			System.out.println("Case #"+(i+1)+": "+result);
			output.println("Case #"+(i+1)+": "+result);
		}
		
		
		
		sc.close();
		input.close();
		output.close();	
	}


	private boolean hayMayoria(int[] persons) {
		int senadores = 0;
		int max = -1;
		for (int i = 0; i < persons.length; i++) {
			senadores += persons[i];
			if(persons[i]>max){
				max = persons[i];
			}
		}
		int mayoria = senadores/2 + 1;
		if(max >=mayoria){
			return true;
		}
		return false;
	}


	private void undo(int[] persons, String a) {
		persons[ALPHABET.indexOf(a)]++;		
	}


	private String extract(int[] persons) {
		int max = -1, pos=-1;
		for (int i = 0; i < persons.length; i++) {
			if(persons[i]>max){
				max = persons[i];
				pos = i;
			}
		}
		
		persons[pos]--;
		return ALPHABET.substring(pos, pos+1);
	}


	private boolean haveMore(int[] persons) {
		for (int i = 0; i < persons.length; i++) {
			if(persons[i]>0){
				return true;
			}
		}
		return false;
	}
}
