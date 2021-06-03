package output;

import info.City;
import info.Gender;
import info.ProcessData;
import info.Student;

import java.util.List;
import java.util.Map;
import java.util.stream.Collectors;

public class Q4 implements ProcessData {
    public static void main(String[] args) {
        Q4 q=new Q4();
        List<Student> list=q.getStudentList();

        Map<Boolean,List<Student>>map=list.stream().collect(Collectors.partitioningBy(s->s.getInfo().getGender().equals(Gender.MALE)));
        map.entrySet().stream().forEach(e->{
            if(e.getKey()){
                System.out.println("---------MALE-----------");
            }else{
                System.out.println("---------FEMALE-----------");
            }
            e.getValue().stream().forEach(s-> System.out.println(s.getInfo().getFirstName()+" "+s.getInfo().getLastName()));
            System.out.println();
        });
    }
}
