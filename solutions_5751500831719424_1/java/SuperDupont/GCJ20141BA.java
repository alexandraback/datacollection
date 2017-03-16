/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package gcj20141ba;

import java.io.*;
import java.util.regex.Pattern;

/**
 *
 * @author Nous
 */
public class GCJ20141BA {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args)throws IOException
    {
        // TODO code application logic here
        Reader rr;
        Writer ww;
        LineNumberReader Lnr;
        String s;
        String[][] TTabs;
        long a,b,c;
        int i,j,k,m,n,ntc;
        Pattern pat;

         TTabs = new String[100][];

        int NbTestCases;
        String sout;
        int  FlagOK;

        // Pi x 10e30, au cas où :
        // BigNbr bnPIe30;
        // bnPIe30 = new BigNbr("3141592653589793238462643383279");

        // Variables Fonctionnelles liées au Test Case :
        int NbStr,NbCarTtes, NbOut,min,max;
        char[][] Carac;
        int[][] NbCar;
        int[] NbCarStr;
        
        NbCarTtes=0;
        NbOut=0;

        
        

        //       ll=new long[100];
        pat =  Pattern.compile(" +"); // Pour séparer les mots
        //       pat =  Pattern.compile(" *"); // Pour séparer chaque caractère
        //               (attention : commence alors par "")
        // Titre
        System.out.println("2014-1B-A");

        // Nombre de cas
        rr=new InputStreamReader(new FileInputStream("A-large.in"),
                "ISO-8859-1");
        ww=new OutputStreamWriter(new FileOutputStream("File.out"),
                "ISO-8859-1");
        Lnr = new LineNumberReader(rr);
        NbTestCases = Integer.parseInt(Lnr.readLine());

        // Cas par cas
        for(ntc=1;ntc<=NbTestCases;ntc++)
        {
            // Début du cas
            s=Lnr.readLine();
            TTabs[0] = pat.split(s);

            NbStr = Integer.parseInt(TTabs[0][0]);
            
            Carac=new char[NbStr][100];
            NbCarStr = new int[NbStr];
            NbCar = new int [NbStr][100];
            

            // Intégrer l'ensemble des données
            for(i=0;i<NbStr;i++)
            {
                s=Lnr.readLine();
                k=0;
                Carac[i][k]=s.charAt(0);
                NbCar[i][k]=1;
                for(j=1;j<s.length();j++)
                {
                    if(Carac[i][k]==s.charAt(j))
                    {
                        NbCar[i][k]++;
                    } else
                    {
                        k++;
                        Carac[i][k]=s.charAt(j);
                        NbCar[i][k]=1;
                    }
                }
                NbCarStr[i]=k+1;
            }

            // C'est Parti :
            // Premier test : A-t-on le même nombre de lettres, sinon KO
            FlagOK=1;
            for(i=1;i<NbStr;i++)
            {
                if(NbCarStr[i]!=NbCarStr[0])
                {
                    FlagOK=0;
                    break;
                }
            }
            
            // Deuxième test : les mêmes lettres ?
            if(FlagOK==1)
            {
                NbCarTtes=NbCarStr[0];
                for(j=0;j<NbCarTtes;j++)
                {
                    for(i=1;i<NbStr;i++)
                    {
                        if(Carac[0][j]!=Carac[i][j])
                        {
                            FlagOK=0;
                            break;
                        }
                    }
                }
            }
            
            // C'est bon : On compte les solutions
            if(FlagOK==1)
            {
                NbOut=0;
                for(j=0;j<NbCarTtes;j++)
                {
                    // Min et max de lettres
                    min=101;
                    max=0;
                    for(i=0;i<NbStr;i++)
                    {
                        if(NbCar[i][j]>max) max =NbCar[i][j];
                        if(NbCar[i][j]<min) min =NbCar[i][j];
                    }
                    
                    // On regarde la meilleure solution
                    m=100000000;
                    for(k=min;k<=max;k++)
                    {
                        n=0;
                        for(i=0;i<NbStr;i++)
                        {
                            if(NbCar[i][j]>k) n+=NbCar[i][j]-k;
                            if(NbCar[i][j]<k) n+=k-NbCar[i][j];
                        }
                        if(n<m)m=n;
                    }
                    NbOut+=m;
                }
            }
            
            // Résultat du Test Case
            if(FlagOK!=1) sout="Fegla Won";
            else sout=""+NbOut;
            System.out.println("Case #"+ntc+": "+sout);
            ww.write("Case #"+ntc+": "+sout+"\n");
        }
        ww.close();
    }

}
