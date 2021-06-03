package info;

public class Student {
    private String id;
    private Person info;
    private ScoreSheet scores;

    public Student(String id, Person info, ScoreSheet scores) {
        this.id = id;
        this.info = info;
        this.scores = scores;
    }


    public String getId() {
        return id;
    }

    public int getIntID(){
        return Integer.parseInt(id);
    }

    public Person getInfo() {
        return info;
    }

    public ScoreSheet getScores() {
        return scores;
    }

    @Override
    public String toString() {
        return "Student{" +
                "id='" + id + '\'' +
                ", info=" + info +
                ", scores=" + scores +
                '}';
    }
}
