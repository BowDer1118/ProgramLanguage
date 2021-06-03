package output;

import info.ProcessData;
import info.Student;

import java.util.Comparator;
import java.util.List;

public class Q1 implements ProcessData {
    public static void main(String[] args) {
        Q1 q=new Q1();
        List<Student> studentList=q.getStudentList();

        System.out.println("按學號升序的學生資料：");
        System.out.printf("%-12s%-22s%-10s%10s%12s%10s%10s%10s%10s\n","Id","Name","City","Birthday","Gender","Math","English","Chinese","Average");
        studentList.stream().sorted(Comparator.comparingInt(Student::getIntID)) //依照student ID排序
                   .forEach(student -> System.out.printf("%-12s%-22s%-12s%-14s%-12s%4d   %7d   %7d   %7.2f\n",student.getId(),student.getInfo().getFirstName()+" "+student.getInfo().getLastName(),student.getInfo().getCity(),student.getInfo().getBirthday(),student.getInfo().getGender(),student.getScores().getMath(),student.getScores().getEnglish(),student.getScores().getChinese(),student.getScores().getAverage()));

        System.out.println("按出生日期降序的學生姓名：");
        System.out.printf("%-22s%s\n","Name","Birthday");
        studentList.stream().sorted((s1,s2)->{
            String birth1=s1.getInfo().getBirthday();
            String birth2=s2.getInfo().getBirthday();
            //year,month,day
            int[] record1={Integer.parseInt(birth1.substring(0,4)),Integer.parseInt(birth1.substring(5,7)),Integer.parseInt(birth1.substring(8))};
            int[] record2={Integer.parseInt(birth2.substring(0,4)),Integer.parseInt(birth2.substring(5,7)),Integer.parseInt(birth2.substring(8))};
            if(record2[0]==record1[0]){
                if(record2[1]==record1[1]){
                    return record2[2]-record1[2];
                }else{
                    return record2[1]-record1[1];
                }
            }else{
                return record2[0]-record1[0];
            }
        }).forEach(student -> System.out.printf("%-22s%s\n",student.getInfo().getFirstName()+" "+student.getInfo().getLastName(),student.getInfo().getBirthday()));
    }
}
