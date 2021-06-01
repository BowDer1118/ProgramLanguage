package output;

import info.*;

import java.util.List;
import java.util.Map;
import java.util.stream.Collectors;

public class Q4 implements ProcessData {
    public static void main(String[] args) {
        Q4 q=new Q4();
        List<Student> list=q.getStudentList();
        //依照Gender做partition
        Map<Boolean, List<Student>> map=list.stream().collect(Collectors.partitioningBy(student -> student.getInfo().getGender().equals(Gender.MALE)));

        //輸出男性
        System.out.println("Male:");
        map.get(true).forEach(student -> System.out.println(student.getInfo().getFirstName()+" "+student.getInfo().getLastName()));

        System.out.println();

        //輸出女性
        System.out.println("Female:");
        map.get(false).forEach(student -> System.out.println(student.getInfo().getFirstName()+" "+student.getInfo().getLastName()));
    }
}
