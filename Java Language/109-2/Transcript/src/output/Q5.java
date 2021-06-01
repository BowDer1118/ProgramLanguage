package output;

import info.ProcessData;
import info.ScoreSheet;
import info.Student;

import java.util.DoubleSummaryStatistics;
import java.util.IntSummaryStatistics;
import java.util.List;
import java.util.stream.Collectors;

public class Q5 implements ProcessData {
    public static void main(String[] args) {
        Q5 q=new Q5();
        List<Student> list=q.getStudentList();

        //數學考科平均分數
        IntSummaryStatistics mathIntSummaryStatistics=list.stream().map(Student::getScores) //轉ScoreSheet
                .collect(Collectors.summarizingInt(ScoreSheet::getMath));

        //從IntSummaryStatistics獲得Average
        System.out.println("Math "+String.format("%.2f",mathIntSummaryStatistics.getAverage()));

        //英文考科平均
        IntSummaryStatistics englishIntSummaryStatistics=list.stream().map(Student::getScores)
                .collect(Collectors.summarizingInt(ScoreSheet::getEnglish));
        System.out.println("English "+String.format("%.2f",englishIntSummaryStatistics.getAverage()));

        //國文考科平均
        IntSummaryStatistics chineseIntSummaryStatistics=list.stream().map(Student::getScores)
                .collect(Collectors.summarizingInt(ScoreSheet::getChinese));
        System.out.println("Chinese "+String.format("%.2f",chineseIntSummaryStatistics.getAverage()));

        //所有學生考科平均的平均
        DoubleSummaryStatistics averageDoubleSummaryStatistics=list.stream().map(Student::getScores)
                .collect(Collectors.summarizingDouble(ScoreSheet::getAverage));
        System.out.println("Average "+String.format("%.2f",averageDoubleSummaryStatistics.getAverage()));
    }
}
