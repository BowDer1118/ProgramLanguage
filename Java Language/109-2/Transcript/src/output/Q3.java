package output;

import info.City;
import info.Person;
import info.ProcessData;
import info.Student;

import java.util.List;
import java.util.Map;
import java.util.stream.Collectors;

public class Q3 implements ProcessData {
    public static void main(String[] args) {
        Q3 q=new Q3();
        List<Student> list=q.getStudentList();

        //按照城市的居住地點分類並輸出學生姓名
        Map<City,List<Person>> map=list.stream().map(Student::getInfo).collect(Collectors.groupingBy(Person::getCity));

        //按照城市輸出
        map.forEach((city, people) -> {
            System.out.println(city);
            //輸出同城市的學生的姓名
            people.forEach(person -> System.out.println(person.getFirstName()+" "+person.getLastName()));
            System.out.println();
        });
    }
}
