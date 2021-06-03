package output;

import info.ProcessData;
import info.Student;

import java.util.IntSummaryStatistics;
import java.util.List;

public class Q5 implements ProcessData {
    public static void main(String[] args) {
        Q5 q=new Q5();
        List<Student> list=q.getStudentList();

        System.out.printf("%-13s%7s%10s%10s\n","Subject","Average","Min","Max");
        IntSummaryStatistics math=list.stream().mapToInt(s->s.getScores().getMath()).summaryStatistics();
        System.out.printf("%-13s%7.2f%10d%10d\n","Math",math.getAverage(),math.getMin(),math.getMax());
        IntSummaryStatistics english=list.stream().mapToInt(s->s.getScores().getEnglish()).summaryStatistics();
        System.out.printf("%-13s%7.2f%10d%10d\n","English",english.getAverage(),english.getMin(),english.getMax());
        IntSummaryStatistics chinese=list.stream().mapToInt(s->s.getScores().getChinese()).summaryStatistics();
        System.out.printf("%-13s%7.2f%10d%10d\n","Chinese",chinese.getAverage(),chinese.getMin(),chinese.getMax());
    }
}
