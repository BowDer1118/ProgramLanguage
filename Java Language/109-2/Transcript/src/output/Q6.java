package output;

import info.ProcessData;
import info.ScoreSheet;
import info.Student;

import java.util.List;
import java.util.Map;
import java.util.stream.Collectors;


public class Q6 implements ProcessData {
    public static void displayResult(String subject,Map<Boolean,List<Student>> map){
        System.out.println("["+subject+" Grade"+"]");
        map.forEach((booleanValue, students) ->{
            if(booleanValue){
                System.out.println("成績及格者:");
            }else{
                System.out.println("成績不及格者:");
            }
            students.forEach(student -> System.out.println(student.getId()+" "+student.getInfo().getFirstName()+" "+student.getInfo().getLastName()));
        });
    }

    public static void main(String[] args) {
        Q6 q=new Q6();
        List<Student> list=q.getStudentList();

        //根據考科別輸出該科不及格與及格的同學 學號與姓名

        //數學
        Map<Boolean,List<Student>> mathMap=list.stream().collect(Collectors.partitioningBy(s->s.getScores().getMath()>=60));
        displayResult("Math",mathMap);
        System.out.println();

        //英文
        Map<Boolean,List<Student>> englishMap=list.stream().collect(Collectors.partitioningBy(s->s.getScores().getEnglish()>=60));
        displayResult("English",englishMap);
        System.out.println();

        //中文
        Map<Boolean,List<Student>> chineseMap=list.stream().collect(Collectors.partitioningBy(s->s.getScores().getChinese()>=60));
        displayResult("Chinese",chineseMap);
    }
}
