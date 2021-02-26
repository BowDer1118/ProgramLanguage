import java.util.ArrayDeque;  
import java.util.Collections;  
import java.util.Scanner;  
import java.util.Vector;  
  
public class Main {  
  
    public static void main(String[] args) {  
        Scanner sc = new Scanner(System.in);  
        while (sc.hasNext()) {  
            Vector<Integer> vector = new Vector<Integer>();  
            while (true) {  
                int input = sc.nextInt();  
                if (input == 0) {  
                    break;  
                }  
                vector.add(input);  
            }  
            Collections.sort(vector);  
            ArrayDeque<Integer> array = new ArrayDeque<>();  
            for (int integer : vector) {  
                if (integer % 2 == 0) {  
                    array.addLast(integer);  
                } else {  
                    array.addFirst(integer);  
                }  
            }  
            while (!array.isEmpty()) {  
                if (array.size() != 1) {  
                    System.out.print(array.removeFirst() + " ");  
                } else {  
                    System.out.println(array.removeFirst());  
                }  
            }  
        }  
        sc.close();  
    }  
  
}  