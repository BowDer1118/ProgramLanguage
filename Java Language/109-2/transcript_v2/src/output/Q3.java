package output;

import info.City;
import info.ProcessData;
import info.Student;

import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;
import java.util.stream.Collectors;

public class Q3 implements ProcessData {
    public static void main(String[] args) {
        Q3 q=new Q3();
        List<Student> studentList=q.getStudentList();

        Map<City,List<Student>> map=studentList.stream().collect(Collectors.groupingBy(student -> student.getInfo().getCity()));
        Set<Map.Entry<City,List<Student>>> set=new HashSet<>(map.entrySet());


        set.stream().forEach(e->{
            System.out.printf("-----------%s-----------\n",e.getKey());
            List<Student> list=e.getValue();
            list.stream().forEach(s->{
                System.out.println(s.getInfo().getFirstName()+" "+s.getInfo().getLastName());
            });
            System.out.println();
        });
    }
}
