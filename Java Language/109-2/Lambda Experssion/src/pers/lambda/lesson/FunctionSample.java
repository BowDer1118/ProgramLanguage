package pers.lambda.lesson;

import java.util.Random;
import java.util.function.Function;

//利用Function函數式街口生成 定長隨機字串
public class FunctionSample {
    public static void main(String[] args) {
        //第一個為 輸入資料類型 第二個為 返回值
        Function<Integer,String> randomStringFunction=l->{
            String chars="abcdefghijklmnopqrstuvwxyzz0123456789";
            StringBuffer stringBuffer=new StringBuffer();
            Random random=new Random();
            for (int i = 0; i < l; i++) {
                int position=random.nextInt(chars.length());
                stringBuffer.append(chars.charAt(position));
            }

            return stringBuffer.toString();
        };
        //使用apply接收輸入並返回結果
        String randomString=randomStringFunction.apply(32);
        System.out.println(randomString);

    }
}
