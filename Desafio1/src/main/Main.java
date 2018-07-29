package main;

import javax.print.DocFlavor.BYTE_ARRAY;

public class Main {

	public static void main(String[] args) {
		byte max = Byte.MAX_VALUE;
		byte min = Byte.MIN_VALUE;
		float maximo = Float.MAX_VALUE;
		float minimo = Float.MIN_VALUE;
		
		System.out.println(max);
		max++;
		if (max < 0) {
			
		System.out.println(max + " = " + "Overflow");
		}

		System.out.println(min);
		min--;
		if (min > 0) {
			System.out.println(min + " = " + "Underflow");
		}
		
		System.out.println(maximo);
		maximo += maximo;
		System.out.println(maximo + " = " + "Overflow");
		
		System.out.println(minimo);
		minimo /= 2;
		System.out.println(minimo + " = " + "Underflow");
	
	}
}
