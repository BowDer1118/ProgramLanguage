package pers.lambda.practice;

import java.util.Arrays;
import java.util.List;
import java.util.function.Predicate;

public class PracticePredicate {
    public static void filter(List<String> list, Predicate<String> p){
        System.out.println("集合中的元素有 "+list.toString());
        System.out.println("集合中包含'a'的元素為:");
        for (String s: list) {
            if(p.test(s)){
                System.out.print(s+" ");
            }
        }
        System.out.println();
    }
    public static void main(String[] args) {
        List<String> list= Arrays.asList("java","python","php","HTML");
        filter(list,s->s.contains("a"));
    }
}
