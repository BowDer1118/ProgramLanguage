package output;

import info.City;
import info.ProcessData;
import info.Student;

import java.util.List;
import java.util.Set;
import java.util.stream.Collectors;

public class Q2 implements ProcessData {
    public static void main(String[] args) {
        Q2 q=new Q2();
        List<Student> list=q.getStudentList();

        //將學生的城市轉存在Set中
        Set<City> citySet=list.stream().map(student -> student.getInfo().getCity()).collect(Collectors.toSet());
        //輸出Set內容
        citySet.forEach(city -> System.out.print(city+" "));
    }
}
