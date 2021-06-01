package output;

import info.Person;
import info.ProcessData;
import info.Student;

import java.util.Comparator;
import java.util.List;

public class Q1 implements ProcessData {
    public static void main(String[] args) {
        Q1 q=new Q1();
        List<Student> list=q.getStudentList();

        System.out.println("學生按照學號升序印出");
        //按照學號升序排序並輸出
        list.stream().sorted(Comparator.comparingInt(s->Integer.parseInt(s.getId())))
                .forEach(student -> System.out.println(student.getId()+" "+student.getInfo().getFirstName()+" "+student.getInfo().getLastName()));

        System.out.println();

        System.out.println("學生按照出生日降序");
        list.stream().sorted((s1,s2)->{
            int year1=Integer.parseInt(s1.getInfo().getBirthday().substring(0,4));
            int year2=Integer.parseInt(s2.getInfo().getBirthday().substring(0,4));
            int month1=Integer.parseInt(s1.getInfo().getBirthday().substring(4,6));
            int month2=Integer.parseInt(s2.getInfo().getBirthday().substring(4,6));
            int day1=Integer.parseInt(s1.getInfo().getBirthday().substring(6));
            int day2=Integer.parseInt(s2.getInfo().getBirthday().substring(6));

            //年齡小到大
            if(year1==year2){
                if(month1==month2){
                    return day2-day1;
                }else{
                    return month2-month1;
                }
            }else{
                return year2-year1;
            }
        }).forEach(s-> System.out.println(s.getInfo().getBirthday()+" "+s.getInfo().getFirstName()+" "+s.getInfo().getLastName()));
    }
}
