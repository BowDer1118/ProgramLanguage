package pers.lambda.practice;

import java.util.Arrays;
import java.util.List;
import java.util.function.Function;

public class PracticeFunction {
    public static void main(String[] args) {
        List<Integer> list= Arrays.asList(1,2,13,14,18,101);

        Function<List<Integer>,Integer> findMaxNumber=l->{
            int number=l.get(0);

            for (int i = 0; i < l.size(); i++) {
                if(l.get(i)>number){
                    number=l.get(i);
                }
            }
            return  Integer.valueOf(number);
        };

        System.out.println(findMaxNumber.apply(list));
    }
}
