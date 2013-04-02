import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.math.BigInteger;

public class Main{


	public static String split(String s){
	
		String new_s = new String();

		for (int i=0; i < s.length();i++){
			if (s.charAt(i) == ' ') continue;
			else new_s += s.charAt(i);
		}

		return new_s;
	}


	public static void main(String[] args) throws Exception{


		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

		String s;

		s = in.readLine();
		int n = Integer.parseInt(s);

		for (int i=0; i < n;i++){
			s = in.readLine();
			String[] numbers = s.split("/");
			
			String s1 = split(numbers[0]);			
			String s2 = split(numbers[1]);

//			numbers[1].trim();

//			System.out.println(s1);

//			System.out.println(s2);

			BigInteger n1 = new BigInteger(s1);
			BigInteger n2 = new BigInteger(s2);

			BigInteger gcd = n1.gcd(n2);

			n1 = n1.divide(gcd);
			n2 = n2.divide(gcd);

			System.out.println(n1 + " / "+ n2);

		}		
	}
}
