package output;

import info.ProcessData;
import info.Student;

import java.util.List;

public class Q7 implements ProcessData {
    public static void main(String[] args) {
        Q7 q=new Q7();
        List<Student> list=q.getStudentList();

        //依照三科平均 降序排列
        list.stream().sorted((s1,s2)->{
            double average1=s1.getScores().getAverage();
            double average2=s2.getScores().getAverage();
            if(average2==average1){
                return 0;
            }else if(average2>average1){
                return 1;
            }else{
                return -1;
            }
        }).forEach(student -> System.out.println(student.getId()+" "+student.getInfo().getFirstName()+" "+student.getInfo().getLastName()+" "+String.format("%.2f",student.getScores().getAverage())));
    }
}
