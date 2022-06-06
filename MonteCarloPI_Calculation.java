import java.util.Scanner;

public class MonteCarloPI {
  
  public static void main(String[] args) {
    
    System.out.println("Enter dot count: ");
    
    Scanner sc = new Scanner(System.in);
    
    int n = sc.nextInt();
    int numberInCircle = 0;
    
    long start = System.currentTimeMillis();
    
    for(int i = 0; i < n; i++) {
      double x = Math.random();
      double y = Math.random();
      
      // Aşağıda karşılaştırma yapıldığı için kök almaya gerek yok.
      //double distance = Math.sqrt(x * x + y * y);
      double distance = x * x + y * y;
      
      // Çember sınırı geçmiş mi kontrol edilir.
      if (distance <= 1)
        numberInCircle++;
    }
    
    long end = System.currentTimeMillis();
    long time = end - start;
    
    double pi = 4.0 * numberInCircle / n;
    
    System.out.println("PI: " + pi);
    System.out.println("Java's PI: " + Math.PI);
    System.out.println("Time: " + time + " ms");
    
  }
}