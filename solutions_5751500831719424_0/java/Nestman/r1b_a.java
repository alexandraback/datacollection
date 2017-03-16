package r1b_a;

import java.io.*;
import java.util.*;

public class r1b_a {
	public static void main(String[] args) throws FileNotFoundException, IOException{
		// TODO Auto-generated method stubScanner 
	Scanner sc=new Scanner(new BufferedReader(new InputStreamReader (new FileInputStream("CodeJam2014/r1b_a/A-small-attempt0.in"))));
	//	Scanner sc=new Scanner(new BufferedReader(new InputStreamReader(System.in)));
		PrintWriter ou=new PrintWriter(new FileWriter("CodeJam2014/r1b_a/r1b_a.out"));
		int res,rep,i,j,c,t,nu,ans;
		int[] ti=new int[150];
		char ch;
		char[] ch2=new char[150];
		String[] a=new String[150];
		String s1,s2,ns1,ns2;
		String out;
		boolean vis;
		res=sc.nextInt();
		for(rep=1;rep<=res;rep++){
			
			nu=sc.nextInt();
			s1=sc.nextLine(); 
			vis=true;
			for(i=1;i<=nu;i++){
				c=0;
				s2="";
				a[i]=sc.nextLine();
				s2+=a[i].charAt(0);
				
				for(j=1;j<a[i].length();j++){
					if (a[i].charAt(j)!=s2.charAt(c)) {
						c++;
						s2+=a[i].charAt(j);
					}
				}
				
				if (i==1) s1=s2;
				else if (!s1.equals(s2)) vis=false;
			}
			ans=0;
			if (!vis) ou.print("Case #"+rep+": Fegla Won");
			else{
				System.out.println(s1);
				ans=0;
				for(i=0;i<s1.length();i++){
					ch=s1.charAt(i);
					
					for(j=1;j<=nu;j++){
						c=0; ti[j]=0;
						while ((c<a[j].length())&&(a[j].charAt(c)==ch)){
							ti[j]++;
							c++;
						}
						System.out.print(ti[j]+" ");
					}
					for(j=1;j<=nu;j++){
						a[j]=a[j].substring(ti[j]);
						System.out.println(a[j]);
					}
					System.out.println();
					for(j=1;j<nu;j++)
						for (c=j+1;c<=nu;c++)
							if (ti[j]>ti[c]) {
								t=ti[j];
								ti[j]=ti[c];
								ti[c]=t;
							}
					
					for(j=1;j<=nu;j++) {
						ans+=Math.abs(ti[j]-ti[(nu/2)+1]);
						
					}
				}
				
				out=Integer.toString(ans);
				ou.print("Case #"+rep+": "+ans);
			}
			
			if (rep!=res) ou.println();
			
		}
		
		ou.close();
	}
}