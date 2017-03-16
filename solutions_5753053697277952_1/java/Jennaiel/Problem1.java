/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package problem1;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.PriorityQueue;


/**
 *
 * @author daishan
 */
public class Problem1 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
            String line,line_parts[];
        try{            
            
            BufferedReader br = new BufferedReader(new FileReader("A-large.in"));
            BufferedWriter bw= new BufferedWriter(new FileWriter("out.txt"));
            int tests = Integer.parseInt(br.readLine());
            PriorityQueue<Party>  heap ;
            ArrayList<Party> senators;
            Party now;
            int n,id,sum;
            

            for(int i=0;i<tests;i++){
                bw.write("Case #"+(i+1)+":");
                sum=0;
                n=Integer.parseInt(br.readLine());
                senators = new ArrayList<>(n);
                line = br.readLine();
                line_parts=line.split(" ");
                for(int j=0;j<n;j++){
                    id = Integer.parseInt(line_parts[j]);
                    now = new Party(j,id);
                    senators.add(now);
                    sum+=id;
                }
                //System.out.println(senators);
                heap = new PriorityQueue<>(n);
                for(Party p:senators){
                    heap.add(p);                    
                }
                while(!heap.isEmpty()){
                   // System.out.println(heap);
                   // System.out.println(sum);
                    if(sum%2==1){
                        now = heap.poll();
                        now.senators--;
                        sum--;
                        bw.write(" "+(char)('A'+now.id));
                        if(now.senators>0){
                            heap.add(now);
                        }
                    }
                    else{
                        now = heap.poll();
                        now.senators--;
                        sum--;
                        bw.write(" "+(char)('A'+now.id));
                        if(now.senators>0){
                            heap.add(now);
                        };
                        now = heap.poll();
                        now.senators--;
                        sum--;
                        bw.write((char)('A'+now.id));
                        if(now.senators>0){
                            heap.add(now);
                        };
                    }
                }
                
                
                
                
                
                bw.write("\n");                
                
            }
                
            
            br.close();
            bw.close();
        }
        catch(Exception e){
            e.printStackTrace();            
        }
    }
}

class Party implements Comparable<Party>{
    int id;
    int senators;
    
    public Party(int c,int sen){
        id=c;
        senators=sen;
    }

    @Override
    public int compareTo(Party o) {
        return o.senators-this.senators;
    }
    
    @Override
    public String toString(){
        return (""+(char)('A'+this.id)+" :"+ this.senators);
    }
}
