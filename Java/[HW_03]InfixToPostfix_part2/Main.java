import java.util.HashMap;  
import java.util.Map;  
import java.util.Scanner;  
import java.util.Stack;  
import java.util.StringTokenizer;  
  
public class Main {  
    /** 
     * This method return a String array processed with StringTokenizer 
     *  
     * @param str from user input 
     * @return String array which those string represent a number in original string 
     */  
    public static String[] getNumArray(String str) {  
        StringTokenizer st = new StringTokenizer(str, "+,-,*,/,(,),%");  
        String[] result = new String[st.countTokens()];  
        int count = 0;  
        while (st.hasMoreElements()) {  
            result[count] = st.nextToken();  
            count++;  
        }  
        return result;  
    }  
  
    /** 
     * This method return a String array through some process with number array and 
     * original string 
     *  
     * @param str   from user input 
     * @param array represent the num_Array 
     * @return String array which those string represent an operator in original 
     *         string 
     */  
    public static String[] getOperatorArray(String str, String[] array) {  
        StringBuilder sb = new StringBuilder(str);  
  
        for (int i = 0; i < array.length; i++) {  
            sb.replace(sb.indexOf(array[i]), sb.indexOf(array[i]) + array[i].length(), "");  
        }  
        String[] result = new String[sb.length()];  
  
        for (int i = 0; i < sb.length(); i++) {  
            result[i] = String.valueOf(sb.charAt(i));  
        }  
        return result;  
    }  
  
    /** 
     * This method is to do Infix to Postfix and return the result after using Stack 
     * to solve the problem 
     *  
     *  
     * @param str      from user input 
     * @param num      represent the num_Array 
     * @param operator represent the operator_Array 
     * @return String array represent the solution of this problem 
     */  
    public static String[] getStringArray(String str, String[] num, String[] operator) {  
        StringBuilder sb = new StringBuilder(str);  
        String[] result = new String[num.length + operator.length];  
        int nIndex = 0, oIndex = 0;  
        int nP, oP;  
        for (int i = 0; i < result.length; i++) {  
            nP = sb.indexOf(num[nIndex]);  
            oP = sb.indexOf(operator[oIndex]);  
            // 如果先找到運算元  
            if (oP == -1 || (nP != -1 && oP != -1 && nP < oP)) {  
                sb = sb.replace(nP, nP + num[nIndex].length(), "");  
                result[i] = num[nIndex];  
                if (nIndex < num.length - 1) {  
                    nIndex++;  
                }  
            } else {  
                sb = sb.replace(oP, oP + operator[oIndex].length(), "");  
                result[i] = operator[oIndex];  
                if (oIndex < operator.length - 1) {  
                    oIndex++;  
                }  
            }  
        }  
        return result;  
    }  
  
    public static String[] getResultArray(String[] str) {  
        String[] result = new String[str.length];  
        Map<String, Integer> map = new HashMap();  
        Stack<String> stack = new Stack<String>();  
        // 將運算子放入map並設定權重  
        map.put("*", 3);  
        map.put("/", 3);  
        map.put("%", 3);  
        map.put("+", 2);  
        map.put("-", 2);  
        map.put("(", 0);  
        map.put(")", -1);  
        // 開始Infix to Postfix  
        int count = 0;  
        for (int i = 0; i < str.length; i++) {  
            // 判斷是運算元還是運算子  
            if (!map.containsKey(str[i])) {  
                // 運算元直接存入陣列  
                result[count] = str[i];  
                count++;  
            } else {  
                // 依照權重處理運算子  
                if (stack.isEmpty() || map.get(str[i]) == 0) { // 如果stack是空的直接push  
                    stack.push(str[i]);  
                } else { // 判斷stack中的運算元與當前運算元權重  
                    // 遇到")"將stack中的運算元pop到最頂端為"("並消除"("與")"  
                    if (map.get(str[i]) == -1) {  
                        while (map.get(stack.peek()) != 0) {  
                            result[count] = stack.pop();  
                            count++;  
                        }  
                        // 捨棄左右括號  
                        if (!stack.isEmpty()) {  
                            stack.pop();  
                        }  
                        continue;  
                    }  
                    if (map.get(stack.peek()) > map.get(str[i])) { // stack中的運算元權重較大  
                        // 一直pop直到新的運算元權重能壓住舊的運算元  
                        // (也就是stack中的運算元不會大於當前的運算元)  
                        while (!stack.isEmpty() && (map.get(stack.peek()) > map.get(str[i]))) {  
                            result[count] = stack.pop();  
                            count++;  
  
                        }  
                        // 檢查pop後stack中的運算元權重是否與當前運算元相同  
                        if (!stack.isEmpty() && map.get(stack.peek()) == map.get(str[i])) {  
                            // 如果相同，先將舊的pop再push新的運算元到stack  
                            result[count] = stack.pop();  
                            count++;  
                        }  
                        // 將新的運算元push進stack中  
                        stack.push(str[i]);  
                    } else if (map.get(stack.peek()) == map.get(str[i])) { // 權重相同  
                        // 將舊的pop再push新的進stack  
                        result[count] = stack.pop();  
                        count++;  
                        stack.push(str[i]);  
                    } else { // stack中的權重較小  
                        // push進stack  
                        stack.push(str[i]);  
                    }  
                }  
            }  
        }  
        // 如果字串每個運算元與運算子都處理完畢，將stack剩下的東西全部pop出來  
        while (!stack.isEmpty()) {  
            result[count] = stack.pop();  
            count++;  
        }  
        return result;  
    }  
  
    public static void main(String[] args) {  
        Scanner sc = new Scanner(System.in);  
        String input_string;  
        String[] numArray;  
        String[] operatorArray;  
        String[] stringArray;  
        String[] resultArray;  
  
        while (sc.hasNext()) {  
            input_string = sc.next();  
            numArray = getNumArray(input_string);  
            operatorArray = getOperatorArray(input_string, numArray);  
            stringArray = getStringArray(input_string, numArray, operatorArray);  
            resultArray = getResultArray(stringArray);  
            for (String s : resultArray) {  
                if (s != null) {  
                    System.out.print(s + " ");  
                }  
            }  
            System.out.println();  
        }  
        sc.close();  
  
    }  
  
}  