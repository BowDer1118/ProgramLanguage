import java.util.Scanner;  
  
public class Main {  
  
    public static int[][] inputArray(Scanner sc) {  
        int[][] array = new int[sc.nextInt()][sc.nextInt()];  
        for (int i = 0, r = array.length; i < r; i++) {  
            for (int j = 0, c = array[i].length; j < c; j++) {  
                array[i][j] = sc.nextInt();  
            }  
        }  
        return array;  
    }  
  
    public static void main(String[] args) {  
        Scanner sc = new Scanner(System.in);  
        int inputNum = sc.nextInt();  
        int m = inputNum;  
        int factor = 2;  
        int n = 1;  
        int count;  
        while (inputNum > 1) {  
            count = 0;  
            while (inputNum % factor == 0) {  
                count++;  
                inputNum /= factor;  
            }  
            if (count % 2 != 0) {  
                n *= factor;  
            }  
            factor++;  
        }  
        System.out.println(n + " " + m * n);  
        sc.close();  
    }  
}  