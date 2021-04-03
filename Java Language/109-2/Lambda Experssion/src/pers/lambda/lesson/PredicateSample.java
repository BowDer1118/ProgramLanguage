package pers.lambda.lesson;

import java.util.Arrays;
import java.util.List;
import java.util.function.Predicate;

public class PredicateSample {
    //將Predicate接口當作參數
    public static void filter(List<Integer>list,Predicate<Integer> predicate){
        for(Integer num:list){
            if(predicate.test(num)){
                System.out.print(num+" ");
            }
        }
        System.out.println();
    }

    public static void main(String[] args) {
        //使用Lambda表達式實現Predicate接口
        Predicate<Integer> predicate=n->n>4;
        System.out.println(predicate.test(10));

        List<Integer> list=Arrays.asList(1,2,3,4,5,6,7,8,9,10);

        //使用Lambda表達式實現Predicate接口

        //取出奇數
        filter(list,n->n%2==1);
        //取出偶數
        filter(list,n->n%2==0);

        //找到大於5的所有偶數
        filter(list,n->n>5&&n%2==0);
    }


}
