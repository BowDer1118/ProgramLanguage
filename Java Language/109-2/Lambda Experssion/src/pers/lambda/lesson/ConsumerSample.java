package pers.lambda.lesson;

import java.util.function.Consumer;

public class ConsumerSample {
    //控制輸出
    public static void output(Consumer<String> consumer){
        String text="我是測試的文字";
        consumer.accept(text);
    }
    public static void main(String[] args) {
        //向控制台輸出
        output(s-> System.out.println("向控制台輸出: "+s));
        output(s->{
            System.out.println("向XXX網站發送封包: "+s);
        });
    }
}
