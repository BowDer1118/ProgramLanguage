package pers.peter.practice.stream;

import org.junit.Test;

import java.util.ArrayList;
import java.util.List;
import java.util.stream.Stream;

class Student {
    String name;
    String sex;
    String className;

    public Student(String name, String sex, String className) {
        this.name = name;
        this.sex = sex;
        this.className = className;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getSex() {
        return sex;
    }

    public void setSex(String sex) {
        this.sex = sex;
    }

    public String getClassName() {
        return className;
    }

    public void setClassName(String className) {
        this.className = className;
    }

    @Override
    public String toString() {
        return "Student{" +
                "name='" + name + '\'' +
                ", sex='" + sex + '\'' +
                ", className='" + className + '\'' +
                '}';
    }
}

public class PracticeStream {
    @Test
    public void output1() {
        Student[] stds = new Student[3];
        stds[0] = new Student("張銘", "男", "一班");
        stds[1] = new Student("小紅", "女", "一班");
        stds[2] = new Student("麗麗", "女", "一班");

        Stream<Student> stream = Stream.of(stds);
        stream.forEach(s -> System.out.println(s));
    }

    @Test
    public void output2() {
        List<Student> list = new ArrayList<>();

        list.add(new Student("張銘", "男", "一班"));
        list.add(new Student("小紅", "女", "一班"));
        list.add(new Student("麗麗", "女", "一班"));

        Stream<Student> stream = list.stream();
        stream.forEach(s -> System.out.println(s));
    }
}