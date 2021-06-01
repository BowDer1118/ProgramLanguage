package output;

import info.ProcessData;
import info.Student;

import java.util.List;
import java.util.Map;
import java.util.stream.Collectors;

public class Q8 implements ProcessData {
    public static void main(String[] args) {
        Q8 q=new Q8();
        List<Student> list=q.getStudentList();

        //依照考科平均分成及格與不及格
        Map<Boolean,List<Student>> map=list.stream().collect(Collectors.partitioningBy(student -> student.getScores().getAverage()>=60));

        System.out.println("及格者");
        map.get(true).forEach(student -> System.out.println(student.getId()+" "+student.getInfo().getFirstName()+" "+student.getInfo().getLastName()+" "+String.format("%.2f",student.getScores().getAverage())));

        System.out.println();

        System.out.println("不及格者");
        map.get(false).forEach(student -> System.out.println(student.getId()+" "+student.getInfo().getFirstName()+" "+student.getInfo().getLastName()+" "+String.format("%.2f",student.getScores().getAverage())));

    }
}
