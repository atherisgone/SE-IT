package sib;
import java.util.*;

class Complex2 {

	float real,imag;
	String p;
	Complex2()
	{
			real=0;
			imag=0;
	}
	Complex2 (float comp1,float comp2)
	{
			real=comp1;
			imag=comp2;
	}
	public void AddNum(Complex2 c1, Complex2 c2)
	{
		float real,imag;
		real=(c1.real+c2.real);
		imag=(c1.imag+c2.imag);
		System.out.println("Sum of complex number is: "+real+"+("+imag+")i");
	}
}

public class Complex
{
		public static void main(String args[])
		{
				float num1,num2;
				Complex2 cal=new Complex2();
				Scanner input=new Scanner(System.in);
				System.out.print("Enter the first number: \n");
				num1=input.nextInt();
				num2=input.nextInt();
				Complex2 Obj1=new Complex2(num1,num2);
				System.out.println("1st complex number: ("+Obj1.real+")+("+Obj1.imag+")i" );
				System.out.print("Enter the second number: \n");
				num1=input.nextInt();
				num2=input.nextInt();
				Complex2 Obj2=new Complex2(num1,num2);
				System.out.println("2nd complex number: ("+Obj2.real+")+("+Obj2.imag+")i" );
				cal.AddNum(Obj1, Obj2);
		}
}
