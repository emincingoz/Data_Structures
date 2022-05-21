import java.util.Scanner;
import java.lang.Math;

public class Palindromic {
    public static void main(String[] args) {
    
      int number, digits = 0;
      Scanner inp = new Scanner(System.in);
      
      System.out.print("Enter a number: ");
      number = inp.nextInt();
      
      boolean flag = isPalindrom2(number);
      System.out.println(flag);
      
    }
    ///////////////////////////////////////////
    
    static boolean isPalindrom(int number) {
      int temp, craft = 0, digits;
      
      digits = digitCount(number);
      
      if (digits == 1) {
        System.out.println("\nThe number is palindromic");
        return true;
      }
      
      for (int i = 0; i < (digits/2); i++) {
        temp = numberInDigit(number, i);
        
        craft += (temp * Math.pow(10, digits - i - 1)) + (temp * Math.pow(10, i));
      }
      
      if ((digits % 2) != 0) {
	      temp = numberInDigit(number, (digits / 2));
	      
			  craft += (temp * Math.pow(10, (digits / 2)));
		  }
		  
      if (craft == number){
        System.out.println("\n" + number + " is palindromic");
        return true;
      }
      
      System.out.println("\n" + number + " is NOT palindromic");
      return false;
    }
    static int digitCount(int number) {
      int digits = 0; 
      
      while (number > 0) {
        number /= 10;
        digits++;
      }
      return digits;
    }
    static int numberInDigit(int number, int digit) {
      int temp;
      
      temp = number % (int)Math.pow(10, digit + 1);
      temp = temp / (int)Math.pow(10, digit);
      
      return temp;
    }
    /////////////////////////////////////////////////
    static boolean isPalindrom2(int number) {
      int temp = number, reversedNumber = 0, lastNumber;
      
      while (temp != 0) {
        lastNumber = temp % 10;
        reversedNumber = (reversedNumber * 10) + lastNumber;
        
        temp /= 10;
      }
      
      if (number == reversedNumber) {
        System.out.println("\n" + number + " is palindromic");
        return true;
      }
      else {
        System.out.println("\n" + number + " is NOT palindromic");
        return false;
      }
    }
}