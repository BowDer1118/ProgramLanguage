package info;

public class ScoreSheet {
    private int math;
    private int english;
    private int chinese;
    private double average;

    public ScoreSheet(int math, int english, int chinese) {
        this.math = math;
        this.english = english;
        this.chinese = chinese;
        this.average=(math+english+chinese)/3.0;
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
        return "math=" + math +
                ", english=" + english +
                ", chinese=" + chinese +
                ", average=" + average +
                '}';
    }
}
