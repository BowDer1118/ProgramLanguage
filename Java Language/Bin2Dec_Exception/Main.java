import java.util.Scanner;  
  
@SuppressWarnings("serial")  
class MyNumberFormatException extends Exception {  
    public MyNumberFormatException() {  
    }  
  
    @Override  
    public String toString() {  
        return "Incorrect Binary Format";  
    }  
}  
  
public class Main {  
  
    public static void main(String[] args) {  
        Scanner sc = new Scanner(System.in);  
        while (sc.hasNext()) {  
            StringBuilder sb = new StringBuilder(sc.next());  
            sb = sb.reverse();  
            int dec = 0;  
            try {  
                for (int i = 0; i < sb.length(); i++) {  
                    char c = sb.charAt(i);  
                    if (c != '0' && c != '1') {  
                        throw new MyNumberFormatException();  
                    }  
                    dec += (Math.pow(2, i) * Character.getNumericValue(c));  
                }  
                System.out.println(dec);  
            } catch (MyNumberFormatException m) {  
                System.out.println(m);  
            }  
        }  
        sc.close();  
    }  
  
}