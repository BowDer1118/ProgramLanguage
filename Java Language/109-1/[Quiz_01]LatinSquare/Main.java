import java.util.HashSet;  
import java.util.Scanner;  
import java.util.Set;  
  
public class Main {  
  
    public static boolean isLatinSquare(String[][] array) {  
        // HashSet can't not input the "same" data  
        // Using this feature to check data  
        Set<String> t_set = new HashSet<String>();  
        // Check how many different number  
        Set<String> n_set = new HashSet<String>();  
  
        // Check row data  
        for (int i = 0; i < array.length; i++) {  
            // Suppose first  
            for (int j = 0; j < array[i].length; j++) {  
                t_set.add(array[i][j]);  
                n_set.add(array[i][j]);  
            }  
            if (t_set.size() != array[i].length) {  
                return false;  
            }  
            // Reset hashset  
            t_set.clear();  
        }  
        // Check column data  
        for (int i = 0; i < array.length; i++) {  
            // Suppose first  
            for (int j = 0; j < array[i].length; j++) {  
                t_set.add(array[j][i]);  
                n_set.add(array[i][j]);  
            }  
            if (t_set.size() != array[i].length) {  
                return false;  
            }  
            // Reset hashset  
            t_set.clear();  
        }  
        // Check how many different number  
        if (n_set.size() != array.length) {  
            return false;  
        } else {  
            return true;  
        }  
  
    }  
  
    public static void displayArray(String[][] array) {  
        for (int i = 0; i < array.length; i++) {  
            for (int j = 0; j < array[i].length; j++) {  
                System.out.print(array[i][j] + " ");  
            }  
            System.out.println();  
        }  
    }  
  
    public static void main(String[] args) {  
        Scanner sc = new Scanner(System.in);  
        int n;  
        String array[][];  
        boolean flag = true;  
  
        while (sc.hasNext()) {  
            n = sc.nextInt();  
            if (n == -1) {  
                break;  
            }  
            if (flag) {  
                flag = false;  
            } else {  
                System.out.println();  
            }  
  
            // Initial array  
            array = new String[n][n];  
            // Input data to each row  
            for (int i = 0; i < n; i++) {  
                for (int j = 0; j < n; j++) {  
                    array[i][j] = sc.next();  
                }  
            }  
            if (isLatinSquare(array)) {  
                System.out.println("The input array is a Latin square");  
            } else {  
                System.out.println("The input array is not a Latin square");  
            }  
  
        }  
        sc.close();  
    }  
  
}  