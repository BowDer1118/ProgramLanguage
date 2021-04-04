package pers.peter.lesson.stream;

import org.junit.Test;

import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;

public class StreamMethod {
    @Test
    //透過案例了解Stream的使用
    public void case1() {
        //集合所有偶數並求和
        List<String> list = Arrays.asList("1", "2", "3", "4", "5");
        int sum = list.stream()   //獲取字串
                .mapToInt(s -> Integer.parseInt(s)) //將String轉換成Int(要求自己實現Function函數式)
                .filter(n -> n % 2 == 0)  //過濾(須完成Predicate函數式)]
                .sum();  //將所有整數求和
        System.out.println(sum);
    }

    @Test
    public void case2() {
        //要求首字母大寫
        List<String> list = Arrays.asList("lily", "smith", "jackson");
        List<String> newList=list.stream()   //獲取流對象
                .map(s -> s.substring(0, 1).toUpperCase() + s.substring(1))  //map要求實現Function函數式)
                .collect(Collectors.toList());  //將流中的數據轉換成List集合
        System.out.println(newList);
    }

    @Test
    public void case3() {
        //不重複奇數 由大到小排序
        List<Integer> list=Arrays.asList(1,60,30,21,51,60,51,73);
        List<Integer> newList=list.stream()
                .distinct() //去除重複的流數據
                .filter(n->n%2==1) //過濾奇數出來
                .sorted((a,b)->b-a) //排序(需實現排序規則)
                .collect(Collectors.toList());
        System.out.println(newList);
    }
}
