import java.util.Scanner;  
  
public class Main {  
    /** 
     * check number is prime or not 
     *  
     * @param n be checked number 
     * @return boolean result 
     */  
    public static boolean isPrime(int n) {  
        for (int i = 2; i <= Math.sqrt(n); i++) {  
            if (n % i == 0) {  
                return false;  
            }  
        }  
        return true;  
    }  
  
    /** 
     * determine if palindromic or not 
     * @param sb which will be check 
     * @return  boolean result 
     */  
    public static boolean isPalindromic(StringBuilder sb) {  
        //若數值小於10則一律回傳是迴文  
        if (sb.length() <= 1) {  
            return true;  
        }  
        // 用來存放被比較的字串  
        String str1, str2;  
        if (sb.length() == 2) {  
            str1 = sb.substring(0, 1);  
            str2 = sb.substring(1, 2);  
        } else {  
            str1 = sb.substring(0, sb.length() / 2);  
            str2 = sb.reverse().substring(0, sb.length() / 2);  
        }  
        // 比較字串  
        if (str1.equals(str2)) {  
            return true;  
        } else {  
            return false;  
        }  
  
    }  
  
    public static void main(String[] args) {  
        Scanner sc = new Scanner(System.in);  
        int num, count, target_number;  
        // EOF  
        while (sc.hasNext()) {  
            count = 0;  
            target_number = 1;  
            num = sc.nextInt();  
            if (num == 0) {  
                System.out.println();  
                continue;  
            }  
            while (count < num) {  
                target_number++;  
                // 若target_number是質數且屬於迴文  
                if (isPrime(target_number) && isPalindromic(new StringBuilder(Integer.toString(target_number)))) {  
                    count++;  
                    // 若為第10個或最後一個則換行  
                    if (count % 10 == 0 || count == num) {  
                        System.out.print(target_number + "\n");  
                    } else {  
                        System.out.print(target_number + " ");  
                    }  
                }  
            }  
        }  
    }  
  
} 