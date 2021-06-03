package output;

import info.ProcessData;
import info.Student;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.Map;
import java.util.stream.Collectors;

public class Q8 implements ProcessData {
    public static void outputResult(Map<Boolean, List<Student>> subject) {
        //調整成 及格的人先輸出
        List<Map.Entry<Boolean,List<Student>>> tempList=new ArrayList<>(subject.entrySet());
        tempList.stream().sorted((e1,e2)->{if(e1.getKey())return -1;return 1;}).forEach(e->{
            if(e.getKey()){
                System.out.println("----------------及格----------------");
            }else{
                System.out.println("----------------不及格----------------");
            }
            e.getValue().forEach(s-> System.out.printf("%-12s%s\n",s.getId(),s.getInfo().getFirstName()+" "+s.getInfo().getLastName()));
        });
    }

    public static void main(String[] args) {
        Q8 q = new Q8();
        List<Student> studentList = q.getStudentList();

        System.out.println("各科及格與不及格的學生：");
        System.out.printf("%-12s%s\n","Id","Name");

        System.out.println("================Math==================");
        Map<Boolean,List<Student>> math=studentList.stream().sorted(Comparator.comparingInt(Student::getIntID))
                            .collect(Collectors.partitioningBy(s->s.getScores().getMath()>60));
        outputResult(math);

        System.out.println();
        System.out.println("=============English==================");
        Map<Boolean,List<Student>> english=studentList.stream().sorted(Comparator.comparingInt(Student::getIntID))
                .collect(Collectors.partitioningBy(s->s.getScores().getEnglish()>60));
        outputResult(english);

        System.out.println();
        System.out.println("=============Chinese==================");
        Map<Boolean,List<Student>> chinese=studentList.stream().sorted(Comparator.comparingInt(Student::getIntID))
                .collect(Collectors.partitioningBy(s->s.getScores().getChinese()>60));
        outputResult(chinese);
    }


}
