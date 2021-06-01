package info;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.List;
import java.util.stream.Collectors;
import java.util.stream.Stream;

public interface ProcessData {
    default List<Student> getStudentList() {
        //外部資源的串流
        Stream<String> resource=Stream.empty();
        try {
            //導入外部資源
            resource=Files.lines(Paths.get("test_input.txt"));
        } catch (IOException e) {
            e.printStackTrace();
        }

        //處理資料---獲得學生物件
        List<Student> list=resource.skip(3)    //省略文本的說明
                .map(s -> {
                    //處理每行字串
                    String[] strings=s.split(" ");

                    String id=strings[0];
                    Person person=new Person(strings[1],strings[2],City.values()[Integer.parseInt(strings[3])],strings[4],Gender.values()[Integer.parseInt(strings[5])]);
                    ScoreSheet scoreSheet=new ScoreSheet(Integer.parseInt(strings[6]),Integer.parseInt(strings[7]),Integer.parseInt(strings[8]));
                    //創造Student物件
                    return new Student(id,person,scoreSheet);
                }).collect(Collectors.toList());
        //回傳處理完畢的Student容器
        return list;
    }
}
