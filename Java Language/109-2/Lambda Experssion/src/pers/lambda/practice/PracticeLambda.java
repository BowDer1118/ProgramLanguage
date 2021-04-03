package pers.lambda.practice;

public class PracticeLambda {
    public static void main(String[] args) {
        MathOperation divide=(a,b)->a/b+0f;
        System.out.println(divide.operation(6,3));
    }
}
