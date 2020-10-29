import java.util.Scanner;   
   
   
   
public class Main {   
   /**  
     * Check num is odd  
     *   
     * @param n which will be check number  
  * @return boolean result  
   */   
    public boolean isOdd(int n) {   
      if (n % 2 == 0) {   
          return false;   
      }   
      return true;   
   }   
   
 /**  
     * Display all number from 2D-array  
     *   
     * @param array the display data  
    */   
    public void displayResult(int[][] array, int sum) {   
        System.out.print(sum + "\n");   
   
     for (int i = 0; i < array.length; i++) {   
            for (int j = 0; j < array[i].length; j++) {   
             System.out.printf("%5d", array[i][j]);   
         }   
          System.out.print("\n");   
        }   
  }   
   
 /**  
     * Input data to array  
  *   
     * @param array which need to input  
     */   
    public void inputNum(int[][] array, int num) {   
     int r = array.length - 1;// Row start point   
        int c = (array[0].length - 1) / 2;// Column start point   
   
       for (int i = 1; i <= num; i++) {   
            if (array[r][c] == 0) {   
                array[r][c] = i;   
           }   
          if (r + 1 > array.length - 1) {   
             r = 0;   
         } else {   
               r++;   
           }   
          if (c + 1 > array[0].length - 1) {   
              c = 0;   
         } else {   
               c++;   
           }   
          // Next position   
           if (array[r][c] != 0) {   
                // Back to last position   
               if (c - 1 < 0) {   
                    c = array[0].length - 1;   
               } else {   
                   c--;   
               }   
              if (r - 1 < 0) {   
                    r = array.length - 1;   
              } else {   
                   r--;   
               }   
   
             while (array[r][c] != 0 && array[r][c] != num) {   
                   // Change row index   
                    if (r - 1 < 0) {   
                        r = array.length - 1;   
                  } else {   
                       r--;   
                   }   
              }   
   
         }   
      }   
   
 }   
   
   
   
   public static void main(String[] args) {   
       Main m = new Main();   
       Scanner sc = new Scanner(System.in);   
       int num = 0;   
       while (sc.hasNext()) {   
         if (num != 0) {   
                System.out.print("\n");   
            }   
          num = sc.nextInt();   
            if (m.isOdd(num)) {   
                int[][] matrix = new int[num][num]; // Init array   
              int sum = num * ((num * num + 1) / 2); // The sum of length   
   
               // Filled the array   
                m.inputNum(matrix, num * num);   
   
                // Output   
              m.displayResult(matrix, sum);   
          } else {   
               System.out.print("It is not an odd number.\n");   
            }   
      }   
      sc.close();   
    }   
   
}  