package GoogleCodeJam_2014_Qualification;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;

public class Problem_A_Magic_Trick {

	public static void main(String[] args) throws IOException 
	{
		BufferedReader leer = new BufferedReader(new FileReader("A-small-attempt0.in"));
		BufferedWriter out = new BufferedWriter(new FileWriter("A-small-attempt0.out"));
		int casos = Integer.parseInt(leer.readLine());
		StringTokenizer partes;
		StringBuilder salida = new StringBuilder();
		Set<Integer> posibilidad;
		int p1,p2,cont,num,aux,Ncaso = 0;
		while(casos-- != 0)
		{
			p1 = Integer.parseInt(leer.readLine());
			posibilidad = new HashSet<Integer>();
			for(int i=0; i<4; i++)
			{
				partes = new StringTokenizer(leer.readLine());
				if(i+1 == p1)
				{
					for(int j=0; j<4; j++)
						posibilidad.add(Integer.parseInt(partes.nextToken()));
				}
			}
			p2 = Integer.parseInt(leer.readLine());
			cont = 0;
			num = 0;
			for(int i=0; i<4; i++)
			{
				partes = new StringTokenizer(leer.readLine());
				if(i+1 == p2)
				{
					for(int j=0; j<4; j++)
					{
						aux = Integer.parseInt(partes.nextToken());
						if(posibilidad.contains(aux))
						{
							cont++;
							num = aux;
						}
					}
				}
			}
			if(cont == 0) salida.append("Case #"+(++Ncaso)+": Volunteer cheated!\n");
			else
			{
				if(cont == 1) salida.append("Case #"+(++Ncaso)+": "+num+"\n");
				else salida.append("Case #"+(++Ncaso)+": Bad magician!\n");
			}
		}
		leer.close();
		out.append(salida);
		out.close();
	}

}
