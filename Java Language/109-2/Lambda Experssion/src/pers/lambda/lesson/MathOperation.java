package pers.lambda.lesson;

//實現四則運算的接口
@FunctionalInterface    //通知編譯器依照函數式接口，進行抽象方法檢查
public interface MathOperation {
    public Float operation(Integer a,Integer b);
}
