package corpor.info;

public class Game {
    private String matchID;
    private String homeRegionCode;
    private String guessRegionCode;
    private int homeScore;
    private int guessScore;
    private String matchDay;

    public Game() {

    }

    public Game(String matchID, String homeRegionCode, String guessRegionCode, int homeScore, int guessScore, String matchDay) {
        this.matchID = matchID;
        this.homeRegionCode = homeRegionCode;
        this.guessRegionCode = guessRegionCode;
        this.homeScore = homeScore;
        this.guessScore = guessScore;
        this.matchDay = matchDay;
    }


    //Only provide Getter (Can't modify Game information)
    public String getMatchID() {
        return matchID;
    }

    public String getHomeRegion() { return homeRegionCode.substring(0, 2);}

    public String getHomeRegionCode() {
        return homeRegionCode;
    }

    public String getGuessRegion() { return guessRegionCode.substring(0, 2);}

    public String getGuessRegionCode() {
        return guessRegionCode;
    }

    public int getHomeScore() {
        return homeScore;
    }

    public int getGuessScore() {
        return guessScore;
    }

    public String getMatchDay() {
        return matchDay;
    }

    @Override
    public String toString() {
        return "Game{" +
                "matchID='" + matchID + '\'' +
                ", homeRegionCode='" + homeRegionCode + '\'' +
                ", guessRegionCode='" + guessRegionCode + '\'' +
                ", homeScore=" + homeScore +
                ", guessScore=" + guessScore +
                ", matchDay='" + matchDay + '\'' +
                '}';
    }
}
