package T_1302;

import java.math.BigInteger;
import java.util.Scanner;

public class main {
	public static void main(String[] arg)
	{
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();	
		
		int a[] = new int[45005];
		int b[] = new int[45005];
		
		while(T>0)
		{
			BigInteger m = BigInteger.valueOf(in.nextInt());
			int n = in.nextInt();		
			BigInteger result = BigInteger.valueOf(0);
			
			for(int i=0; i<n; i++)
			{
				a[i] = in.nextInt();
				b[i] = in.nextInt();
				BigInteger Big_a = BigInteger.valueOf(a[i]);
				BigInteger Big_b = BigInteger.valueOf(b[i]);
				Big_a = Big_a.modPow(Big_b, m);
				
				result = result.add(Big_a);
			}
			
			System.out.println(result.mod(m));
			
			T--;
		}		
	}
}

