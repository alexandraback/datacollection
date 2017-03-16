/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package googlecodejamproject;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

/**
 *
 * @author Jeje
 */
public class TheRepeater {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws IOException{
        FileInputStream handle = new FileInputStream("A-small-practice.in");
        FileOutputStream handle2 = new FileOutputStream("A-small-practice.out");
	BufferedReader reader = new BufferedReader(new InputStreamReader(handle));
		
        int nombreDeTests=Integer.parseInt(reader.readLine());

         for(int j=0;j<nombreDeTests;j++){
             
            int nombreDeMots=Integer.parseInt(reader.readLine());
             
            ArrayList<String> tableauDesMots=new ArrayList<>();
            
            for(int i=0;i<nombreDeMots;i++){
                tableauDesMots.add(reader.readLine());
            }
                       
            int nvalueInt=result(tableauDesMots);
            String nvalue="";
            
            if(nvalueInt==-1){
                nvalue="Fegla Won";
            }
            else{
                nvalue=""+nvalueInt;
            }
                      
            int nouveauJ=j+1;
            handle2.write(("Case #"+nouveauJ+": "+nvalue+"\n").getBytes());  
            
         }
    }
    
     public static int result(ArrayList<String> listeDesMots){
         
         ArrayList<ArrayList>imageListe=new ArrayList<>();
         
         for(int i=0;i<listeDesMots.size();i++){
             String mot=listeDesMots.get(i);
             char ancienCaractere=mot.charAt(0);
             int compteur=1;
             ArrayList<Character>tableauCarac=new ArrayList<Character>();
            ArrayList<Integer>tableauValeur=new ArrayList<Integer>();
             for(int j=1;j<mot.length();j++){
                 if(mot.charAt(j)==ancienCaractere){
                     compteur++;
                 }
                 else{
                     tableauCarac.add(ancienCaractere);
                     tableauValeur.add(compteur);
                     compteur=1;
                     ancienCaractere=mot.charAt(j);
                 }
             }
             tableauCarac.add(ancienCaractere);
             tableauValeur.add(compteur);
             imageListe.add(tableauCarac);
             imageListe.add(tableauValeur);
         }
         
         boolean possible=true;
         
         for(int i=0;i<(listeDesMots.size()-1);i++){
             possible=possible && ((imageListe.get(2*i)).equals(imageListe.get(2*(i+1))));
         }
         
         if(!possible){
             return -1;
         }
         
         int compteur=0;
         
         for(int i=0;i<imageListe.get(0).size();i++){
             
             ArrayList<Integer>liste=new ArrayList<Integer>();
             
             for(int j=0;j<listeDesMots.size();j++){
                 liste.add((int)(imageListe.get(2*j+1).get(i)));
             }
             
             //compteur+=Math.abs((int)(imageListe.get(1).get(i))-(int)(imageListe.get(3).get(i)));
             compteur+=meilleurNombre(liste);
         }
                  
         return compteur;
    }
     
     public static int meilleurNombre(ArrayList<Integer>listeDeNombres){
         int minimum=listeDeNombres.get(0);
         int maximum=listeDeNombres.get(0);
         for(int i=0;i<listeDeNombres.size();i++){
             if(listeDeNombres.get(i)<minimum){
                 minimum=listeDeNombres.get(i);
             }
             if(listeDeNombres.get(i)>maximum){
                 maximum=listeDeNombres.get(i);
             }
         }
         int distance=0;
         int MIN=-1;
         for(int i=minimum;i<=maximum;i++){
             distance=0;
             for(int j=0;j<listeDeNombres.size();j++){
                distance+=Math.abs(i-listeDeNombres.get(j));
             }
             if(MIN==-1){
                 MIN=distance;
             }
             if(distance<MIN){
                 MIN=distance;
             }
         }
         return MIN;
     }
    
}