package output;

import info.ProcessData;
import info.Student;

import java.util.List;

public class Q7 implements ProcessData {
    public static void main(String[] args) {
        Q7 q=new Q7();
        List<Student> studentList=q.getStudentList();

        System.out.println("依照平均分數排序的學生資料：");
        System.out.printf("%-12s%-25s%s\n","Id","Name","Average");
        studentList.stream().sorted((s1,s2)->(int)(s2.getScores().getAverage()-s1.getScores().getAverage()))
                            .forEach(s-> System.out.printf("%-12s%-27s%s\n",s.getId(),s.getInfo().getFirstName()+" "+s.getInfo().getLastName(),String.format("%.2f",s.getScores().getAverage())));

    }
}
