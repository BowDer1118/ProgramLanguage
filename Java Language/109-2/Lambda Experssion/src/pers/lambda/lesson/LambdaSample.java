package pers.lambda.lesson;

public class LambdaSample {
    public static void main(String[] args) {
        //標準使用方式(實現類與實例化 的方法)
        MathOperation addition = (Integer a, Integer b) -> {
            System.out.println("加法運算");
            return a + b + 0f;  //0f讓返回值成為float
        };
        System.out.println(addition.operation(5, 3));

        //實現過程中忽略參數的資料類型
        MathOperation substraction = (a, b) -> {
            System.out.println("減法運算");
            return a - b + 0f;
        };
        System.out.println(substraction.operation(5, 3));

        //更簡化的書寫法(單行程式碼可以忽略return與大括號)
        MathOperation mutiplication = (a, b) -> a * b + 0f;
        System.out.println(mutiplication.operation(3,5));

        /*
        * Lambda表達式只能實現有且只有一個抽象方法的接口，稱為 『函數式接口』
        * */
    }
}
