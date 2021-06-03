package output;

import info.ProcessData;
import info.Student;

import java.util.Comparator;
import java.util.List;
import java.util.stream.Collectors;

public class Q6 implements ProcessData {
    public static void main(String[] args) {
        Q6 q=new Q6();
        List<Student> studentList=q.getStudentList();

        System.out.println("各科不及格的同學:");
        System.out.printf("%-12s%s\n","Id","Name");

        System.out.println("----------------Math----------------");
        studentList.stream().filter(s->s.getScores().getMath()<60).sorted(Comparator.comparingInt(Student::getIntID)).forEach(s-> System.out.printf("%-12s%s\n",s.getId(),s.getInfo().getFirstName()+" "+s.getInfo().getLastName()));

        System.out.println("----------------English----------------");
        studentList.stream().filter(s->s.getScores().getEnglish()<60).sorted(Comparator.comparingInt(Student::getIntID)).forEach(s-> System.out.printf("%-12s%s\n",s.getId(),s.getInfo().getFirstName()+" "+s.getInfo().getLastName()));

        System.out.println("----------------Chinese----------------");
        studentList.stream().filter(s->s.getScores().getChinese()<60).sorted(Comparator.comparingInt(Student::getIntID)).forEach(s-> System.out.printf("%-12s%s\n",s.getId(),s.getInfo().getFirstName()+" "+s.getInfo().getLastName()));

    }
}
