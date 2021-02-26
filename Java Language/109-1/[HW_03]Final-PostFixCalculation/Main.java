import java.math.BigDecimal;  
import java.util.HashMap;  
import java.util.HashSet;  
import java.util.Map;  
import java.util.Scanner;  
import java.util.Set;  
import java.util.Stack;  
import java.util.StringTokenizer;  
  
public class Main {  
    /** 
     * 成員內部(靜態)類 
     *  
     * @author Peter 
     * 
     */  
    static class InfixToPostFix {  
        /** 
         * This static method return a String array which contain all elements 
         * (ex:numArrayber,operatorArray) in infix string 
         *  
         * @param str the infix string 
         * @return String array which contain all element in infix 
         */  
        static String[] getInfixArray(String str) {  
            StringBuilder sb = new StringBuilder(str);  
            StringTokenizer st = new StringTokenizer(str, "+,-,*,/,(,),%");  
            String[] numArray = new String[st.countTokens()];  
            String[] operatorArray;  
            int index = 0;  
            // 取得運算子陣列  
            while (st.hasMoreElements()) {  
                numArray[index] = st.nextToken();  
                sb = sb.replace(sb.indexOf(numArray[index]), sb.indexOf(numArray[index]) + numArray[index].length(),  
                        "");  
                index++;  
            }  
            // 取得運算子陣列  
            operatorArray = new String[sb.length()];  
            for (int i = 0; i < sb.length(); i++) {  
                operatorArray[i] = String.valueOf(sb.charAt(i));  
            }  
            String[] result = new String[numArray.length + operatorArray.length];  
            // 組合出Infix string  
            sb = new StringBuilder(str); // 重設StringBuilder物件的內容  
            int nIndex = 0, oIndex = 0;  
            int nP, oP;  
            for (int i = 0; i < result.length; i++) {  
                nP = sb.indexOf(numArray[nIndex]);  
                oP = sb.indexOf(operatorArray[oIndex]);  
                if (oP == -1 || (nP != -1 && oP != -1 && nP < oP)) {  
                    sb = sb.replace(nP, nP + numArray[nIndex].length(), "");  
                    result[i] = numArray[nIndex];  
                    if (nIndex < numArray.length - 1) {  
                        nIndex++;  
                    }  
                } else {  
                    sb = sb.replace(oP, oP + operatorArray[oIndex].length(), "");  
                    result[i] = operatorArray[oIndex];  
                    if (oIndex < operatorArray.length - 1) {  
                        oIndex++;  
                    }  
                }  
            }  
            // return infix的陣列  
            return result;  
        }  
  
        /** 
         * This static method return a String array which postfix transformed from infix 
         *  
         * @param str the infix string (as a parameter for getInfixArray static method) 
         * @return String array which represent postfix string 
         */  
        static String[] getPostFix(String str) {  
            String[] infixArray = getInfixArray(str);  
            // 將infix轉postfix  
            String[] result = new String[infixArray.length];  
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
            for (int i = 0; i < infixArray.length; i++) {  
                // 判斷是運算元還是運算子  
                if (!map.containsKey(infixArray[i])) {  
                    // 運算元直接存入陣列  
                    result[count] = infixArray[i];  
                    count++;  
                } else {  
                    // 依照權重處理運算子  
                    if (stack.isEmpty() || map.get(infixArray[i]) == 0) { // 如果stack是空的直接push  
                        stack.push(infixArray[i]);  
                    } else { // 判斷stack中的運算元與當前運算元權重  
                        // 遇到")"將stack中的運算元pop到最頂端為"("並消除"("與")"  
                        if (map.get(infixArray[i]) == -1) {  
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
                        if (map.get(stack.peek()) > map.get(infixArray[i])) { // stack中的運算元權重較大  
                            // 一直pop直到新的運算元權重能壓住舊的運算元  
                            // (也就是stack中的運算元不會大於當前的運算元)  
                            while (!stack.isEmpty() && (map.get(stack.peek()) > map.get(infixArray[i]))) {  
                                result[count] = stack.pop();  
                                count++;  
  
                            }  
                            // 檢查pop後stack中的運算元權重是否與當前運算元相同  
                            if (!stack.isEmpty() && map.get(stack.peek()) == map.get(infixArray[i])) {  
                                // 如果相同，先將舊的pop再push新的運算元到stack  
                                result[count] = stack.pop();  
                                count++;  
                            }  
                            // 將新的運算元push進stack中  
                            stack.push(infixArray[i]);  
                        } else if (map.get(stack.peek()) == map.get(infixArray[i])) { // 權重相同  
                            // 將舊的pop再push新的進stack  
                            result[count] = stack.pop();  
                            count++;  
                            stack.push(infixArray[i]);  
                        } else { // stack中的權重較小  
                            // push進stack  
                            stack.push(infixArray[i]);  
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
  
        /** 
         * This static method return a computing result as A BigDecimal dataType of a 
         * postfix string 
         *  
         * @param str str the infix string (as a parameter for getInfixArray and 
         *            getPostFix static method) 
         * @return BigDecimal Object 
         */  
        static BigDecimal getSoultion(String str) {  
            String[] postFix = getPostFix(str);  
            StringBuilder sb = new StringBuilder();  
            BigDecimal bd1;  
            BigDecimal bd2;  
            // 用來標記標點符號: +,-,*,/,%  
            Set<String> set = new HashSet<String>();  
            set.add("+");  
            set.add("-");  
            set.add("*");  
            set.add("/");  
            set.add("%");  
            Stack<String> stack = new Stack<String>();  
            for (int i = 0; i < postFix.length; i++) {  
                if (postFix[i] != null) {  
                    sb = sb.replace(0, sb.length(), postFix[i]);  
                    // 非標點符號-->數字-->push進stack  
                    if (!set.contains(sb.toString())) {  
                        stack.push(sb.toString());  
                    } else {  
                        // 做運算  
                        bd1 = new BigDecimal(stack.pop());  
                        bd2 = new BigDecimal(stack.pop());  
                        if (sb.toString().equals("+")) {  
                            bd2 = bd2.add(bd1);  
                        } else if (sb.toString().equals("-")) {  
                            bd2 = bd2.subtract(bd1);  
                        } else if (sb.toString().equals("*")) {  
                            bd2 = bd2.multiply(bd1);  
                        } else if (sb.toString().equals("/")) {  
                            bd2 = bd2.divide(bd1);  
                        } else {  
                            bd2 = bd2.remainder(bd1);  
                        }  
                        stack.push(bd2.toString());  
                    }  
                }  
            }  
            return new BigDecimal(stack.pop());  
        }  
  
    }  
  