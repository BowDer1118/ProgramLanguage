import java.math.BigDecimal;  
import java.util.Scanner;  
  
public class Main {  
  
    public static BigDecimal calculate(String exp) {  
        String[] expArray = exp.split("\\+|\\-|\\*|\\/|\\%");  
        BigDecimal result = new BigDecimal("0");  
        BigDecimal[] data = new BigDecimal[3];  
        StringBuilder temp = new StringBuilder(exp);  
        for (int i = 0, expLen = expArray.length; i < expLen; i++) {  
            data[i] = new BigDecimal(expArray[i].trim().toString());  
            temp = temp.delete(temp.indexOf(expArray[i]), temp.indexOf(expArray[i]) + expArray[i].length());  
        }  
        if (temp.length() == 2) {  
            char o1 = temp.charAt(0);  
            char o2 = temp.charAt(1);  
            System.out.printf("%.1f %c %.1f %c %.1f ", data[0], o1, data[1], o2, data[2]);  
            if ((o1 == '+' || o1 == '-') && (o2 == '*' || o2 == '/' || o2 == '%')) {  
                result = data[1];  
                switch (o2) {  
                case '*':  
                    result = result.multiply(data[2]);  
                    break;  
                case '/':  
                    result = result.divide(data[2], 10, BigDecimal.ROUND_HALF_UP);  
                case '%':  
                    result = result.remainder(data[2]);  
                default:  
                    break;  
                }  
                switch (o1) {  
                case '+':  
                    result = data[0].add(result);  
                    break;  
                case '-':  
                    result = data[0].subtract(result);  
                    break;  
                default:  
                    break;  
                }  
            } else {  
                result = data[0];  
                switch (o1) {  
                case '+':  
                    result = result.add(data[1]);  
                    break;  
                case '-':  
                    result = result.subtract(data[1]);  
                    break;  
                case '*':  
                    result = result.multiply(data[1]);  
                    break;  
                case '/':  
                    result = result.divide(data[1], 10, BigDecimal.ROUND_HALF_UP);  
                    break;  
                case '%':  
                    result = result.remainder(data[1]);  
                    break;  
                default:  
                    break;  
                }  
                switch (o2) {  
                case '+':  
                    result = result.add(data[2]);  
                    break;  
                case '-':  
                    result = result.subtract(data[2]);  
                    break;  
                case '*':  
                    result = result.multiply(data[2]);  
                    break;  
                case '/':  
                    result = result.divide(data[2], 10, BigDecimal.ROUND_HALF_UP);  
                    break;  
                case '%':  
                    result = result.remainder(data[2]);  
                    break;  
                default:  
                    break;  
                }  
            }  
        } else {  
            System.out.printf("%.1f %c %.1f ", data[0], temp.charAt(0), data[1]);  
            switch (temp.charAt(0)) {  
            case '+':  
                result = data[0].add(data[1]);  
                break;  
            case '-':  
                result = data[0].subtract(data[1]);  
                break;  
            case '*':  
                result = data[0].multiply(data[1]);  
                break;  
            case '/':  
                result = data[0].divide(data[1], 10, BigDecimal.ROUND_HALF_UP);  
                break;  
            case '%':  
                result = data[0].remainder(data[1]);  
                break;  
            default:  
                break;  
            }  
        }  
        return result;  
    }  
  
    public static void main(String[] args) {  
        Scanner sc = new Scanner(System.in);  
        StringBuilder sb;  
        while (sc.hasNext()) {  
            sb = new StringBuilder(sc.nextLine());  
            try {  
                System.out.printf("%.1f\n", new BigDecimal(sb.toString()));  
            } catch (Exception e) {  
                System.out.printf("= %.1f\n", calculate(sb.toString()).doubleValue());  
            }  
        }  
        sc.close();  
    }  
}