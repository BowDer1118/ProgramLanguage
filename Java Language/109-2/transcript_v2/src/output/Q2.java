package output;

import info.City;
import info.ProcessData;
import info.Student;

import java.util.List;
import java.util.Set;
import java.util.stream.Collectors;

public class Q2 implements ProcessData {
    public static void main(String[] args) {
        Q3 q=new Q3();
        List<Student> studentList=q.getStudentList();

        Set<City> set=studentList.stream().map(s->s.getInfo().getCity()).collect(Collectors.toSet());
        System.out.println("學生居住的所有城市:");
        set.stream().forEach(System.out::println);
    }
}
