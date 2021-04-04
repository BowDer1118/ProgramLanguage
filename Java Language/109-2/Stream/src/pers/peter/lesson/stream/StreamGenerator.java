package pers.peter.lesson.stream;


import org.junit.Test;

import java.util.ArrayList;
import java.util.List;
import java.util.Random;
import java.util.stream.IntStream;
import java.util.stream.Stream;

public class StreamGenerator {
    //基於陣列創建Stream
    @Test   //使用jUnit的Test註解來Run程式
    public void generator1() {
        String[] arr = {"LILY", "Andy", "Jackson", "Smith"};
        //使用Stream的of方法
        Stream<String> stream = Stream.of(arr);
        //forEach要求一個Consumer接口的實現
        stream.forEach(s -> System.out.println(s));
    }

    //基於集合創建Stream
    @Test
    public void generator2() {
        List<String> list = new ArrayList<>();
        list.add("LILY");
        list.add("Andy");
        list.add("Jackson");
        list.add("Smith");

        //使用List類自帶的方法來獲取stream對象
        Stream<String> stream=list.stream();
        stream.forEach(s-> System.out.println(s));
    }

    //無限長度流
    @Test
    public void generator3(){
        //Stream.generate要實例化一個Supplier接口
        Stream<Integer> stream=Stream.generate(()->new Random().nextInt(100000));
        //使用limit限制stream中的物品數量
        stream.limit(10).forEach(i-> System.out.println(i));
    }

    //基於迭代器創建流
    @Test
    public void generator4(){
        //iterate(起始值,偏移值)
        Stream<Integer> stream=Stream.iterate(1,n->n+1);   //無限長度序列
        stream.limit(100).forEach(i-> System.out.println(i));   //限制長度
    }

    //基於字串序列創建流
    @Test
    public void generator5(){
        String str="abcdefg";
        //使用String.chars()獲取IntStream對象
        IntStream stream=str.chars();
        stream.forEach(c-> System.out.println((char)c));
    }
}
