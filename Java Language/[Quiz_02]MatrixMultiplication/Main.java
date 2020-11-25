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
        int count = sc.nextInt();    
        for (int i = 0; i < count; i++) {    
            int[][] e1 = inputArray(sc); // 2*3    
            int[][] e2 = inputArray(sc); // 3*4    
            int[][] result = new int[e1.length][e2[0].length]; // 2*4    
            for (int j = 0, r = result.length; j < r; j++) {    
                for (int k = 0, c = result[0].length; k < c; k++) {    
                    for (int index = 0, range = e1[0].length; index < range; index++) {    
                        result[j][k] += e1[j][index] * e2[index][k];    
                    }    
    
                }    
            }    
    
            for (int x = 0, r = result.length; x < r; x++) {    
                StringBuilder sb = new StringBuilder();    
                for (int y = 0, c = result[x].length; y < c; y++) {    
                    sb.append(result[x][y] + " ");    
                }    
                System.out.println(sb.toString().trim());    
            }    
            if (i != count - 1) {    
                System.out.println();    
            }    
    
        }    
        sc.close();    
    }    
}  