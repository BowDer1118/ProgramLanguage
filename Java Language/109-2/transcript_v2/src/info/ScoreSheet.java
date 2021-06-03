package info;

public class ScoreSheet {
    int math;
    int english;
    int chinese;
    double average;

    public ScoreSheet(int math, int english, int chinese, double average) {
        this.math = math;
        this.english = english;
        this.chinese = chinese;
        this.average = average;
    }

    public int getMath() {
        return math;
    }

    public int getEnglish() {
        return english;
    }

    public int getChinese() {
        return chinese;
    }

    public double getAverage() {
        return average;
    }

    @Override
    public String toString() {
        return "ScoreSheet{" +
                "math=" + math +
                ", english=" + english +
                ", chinese=" + chinese +
                ", average=" + average +
                '}';
    }
}
