import java.util.Scanner;  
  
public class Main {  
  
    public static void main(String[] args) {  
        Scanner sc = new Scanner(System.in);  
        int count = sc.nextInt();  
        sc.nextLine();  
        for (int i = 0; i < count; i++) {  
            StringBuilder str = new StringBuilder(sc.nextLine());  
            StringBuilder oStr = new StringBuilder(sc.nextLine());  
            StringBuilder nStr = new StringBuilder(sc.nextLine());  
            while (str.indexOf(oStr.toString()) != -1) {  
                str = str.replace(str.indexOf(oStr.toString()), str.indexOf(oStr.toString()) + oStr.length(),  
                        nStr.toString());  
            }  
            System.out.println(str.reverse());  
        }  
        sc.close();  
    }  
}  