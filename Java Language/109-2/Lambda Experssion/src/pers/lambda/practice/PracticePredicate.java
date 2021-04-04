package pers.lambda.practice;

import java.util.Arrays;
import java.util.List;
import java.util.function.Predicate;

public class PracticePredicate {
    public static void filter(List<String> list,Predicate<String> p){
        System.out.println("集合中的元素有: "+list.toString());
        System.out.println("集合中包含字符'a'的元素有:");
        for (int i = 0; i < list.size(); i++) {
          if(p.test(list.get(i))){
              System.out.print(list.get(i)+" ");
          }
        }
        System.out.println();
    }
    public static void main(String[] args) {
        List<String> list=Arrays.asList("java","python","php","HTML");
        filter(list,s->s.contains("a"));
    }
}
