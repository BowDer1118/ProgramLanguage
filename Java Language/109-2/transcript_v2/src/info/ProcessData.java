package info;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.List;
import java.util.Locale;
import java.util.stream.Collectors;

public interface ProcessData {
    default List<Student> getStudentList() {
        List<Student> result = null;
        try {
            result = Files.lines(Paths.get("test_in.txt")).map(s -> {
                String[] strings = s.split(" +");
                Person person = new Person(strings[1], strings[2],City.valueOf(strings[3].toUpperCase(Locale.ROOT)), strings[4],Gender.valueOf(strings[5]));
                ScoreSheet scoreSheet = new ScoreSheet(Integer.parseInt(strings[6]), Integer.parseInt(strings[7]), Integer.parseInt(strings[8]), Double.parseDouble(strings[9]));
                return new Student(strings[0], person, scoreSheet);
            }).collect(Collectors.toList());
        } catch (IOException e) {
            e.printStackTrace();
        }
        return result;
    }
}
