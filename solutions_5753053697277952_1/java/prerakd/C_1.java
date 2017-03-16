import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;
import java.util.TreeSet;


public class C_1 {

	/**
	 * @param args
	 * @throws FileNotFoundException 
	 */
	public static void main(String[] args) throws FileNotFoundException {
		// TODO Auto-generated method stub
		
		Scanner in=new Scanner(new File("/home/prerak/Desktop/test.txt"));
		PrintWriter pw=new PrintWriter(new File("/home/prerak/Desktop/ans.txt"));
		int test=in.nextInt();
		
		for(int t=1;t<=test;t++)
		{
			int count=0;
			String str="";
			TreeSet<c> ts=new TreeSet<c>();
			int n=in.nextInt();
			int sum=0;
			for(int i=0;i<n;i++)
			{
				int val=in.nextInt();
				sum+=val;
				c o=new c(i,val);
				ts.add(o);
			}
			while(!ts.isEmpty())
			{
				if(ts.size()%2==1 && ts.first().valu==ts.last().valu && ts.first().valu==1 && ts.size()>1)
				{
					c tp=ts.last();
					//System.out.println(tp.valu);
					if(count%2==0)
					{
						str+=(char)(65+tp.ind);
						count+=2;
					}
					else
					{
						str+=" ";
						str+=(char)(65+tp.ind);
						count++;
					}
					ts.remove(tp);
				}
				else
				{
					c temp=ts.last();
					ts.remove(temp);
					str+=(char)(65+temp.ind);
					temp.valu--;
					if(temp.valu>0)
					{
						ts.add(temp);
					}
					
					count++;
				}
				if(count%2==0)
					str+=" ";
					
				
			}
			pw.println("Case #"+t+": "+str);
		}
		pw.close();
		

	}

}
class c implements Comparable<c>
{
	int ind,valu;
	public c(int i,int v)
	{
		ind=i;
		valu=v;
	}
	public int compareTo(c ob)
	{
		if(this.valu==ob.valu)
		{
			return this.ind-ob.ind;
		}
		return this.valu-ob.valu;
	}
}
