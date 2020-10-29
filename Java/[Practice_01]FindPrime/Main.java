import java.util.Scanner;    
    
public class Main {    
 public static void main(String[] args) {    
       Scanner sc = new Scanner(System.in);    
       boolean flag;    
      int num = sc.nextInt();    
        String str = "";    
       for (int i = 2; i <= num; i++) {    
            flag = true;    
           for (int j = 2; j <= Math.sqrt(i); j++) {    
               if (i % j == 0) {    
                  flag = false;    
                  break;    
             }    
          }    
          if (flag)    
              str += i + " ";    
        }    
      System.out.println(str.substring(0, str.length() - 1));    
        sc.close();    
    }    
}