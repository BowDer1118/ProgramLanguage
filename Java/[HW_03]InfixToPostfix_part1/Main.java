import java.util.Scanner;  
import java.util.StringTokenizer;  
  
public class Main {  
  
    public static void main(String[] args) {  
        Scanner sc = new Scanner(System.in);  
        String str;  
        String str_array[];  
        StringBuilder sb;  
        StringTokenizer st;  
        int count;  
        double total;  
        boolean flag;  
        // EOF  
        while (sc.hasNext()) {  
            count = 0;  
            total = 0.0;  
            flag = true;  
            // Store string  
            str = sc.next();  
            // Spilt the string  
            st = new StringTokenizer(str, "+,-,*,/,(,),%");  
            // Initial array  
            str_array = new String[st.countTokens()];  
            sb = new StringBuilder(str);  
            while (st.hasMoreElements()) {  
                str_array[count] = st.nextElement().toString();  
                // Sum the number  
                total += Double.valueOf(str_array[count]);  
                count++;  
            }  
            // Display number  
            for (int i = 0; i < str_array.length; i++) {  
                if (i == str_array.length - 1) {  
                    System.out.println(str_array[i]);  
  
                } else {  
                    System.out.print(str_array[i] + " ");  
                }  
                // Delete number from string  
                sb.replace(sb.indexOf(str_array[i]), sb.indexOf(str_array[i]) + str_array[i].length(), "");  
            }  
            // Display operator  
            for (int i = 0; i < sb.length(); i++) {  
                if (i == sb.length() - 1) {  
                    System.out.println(sb.charAt(i));  
                } else {  
                    System.out.print(sb.charAt(i) + " ");  
                }  
            }  
            // Display the sum of number with format output  
            System.out.printf("%.3f\n", total);  
        }  
        sc.close();  
    }  
  
}  