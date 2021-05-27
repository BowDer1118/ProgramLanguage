package corpor.info;

public class Team {
    public String teamName;
    public String teamCity;
    public String teamRegionCode;
    public String teamSetUpDate;
    public int winTimes;
    public int loseTimes;
    public int teamRank;

    public Team() {

    }

    public Team(String teamName, String teamCity, String teamRegionCode, String teamSetUpDate) {
        this.teamName = teamName;
        this.teamCity = teamCity;
        this.teamRegionCode = teamRegionCode;
        this.teamSetUpDate = teamSetUpDate;
        this.winTimes = 0;
        this.loseTimes = 0;
        this.teamRank = 0;
    }

    //Getters
    public String getTeamName() {
        return teamName;
    }

    public String getTeamCity() {
        return teamCity;
    }

    public String getTeamRegionCode() {
        return teamRegionCode;
    }

    public String getTeamSetUpDate() {
        return teamSetUpDate;
    }

    public int getWinTimes() {
        return winTimes;
    }

    public int getLoseTimes() {
        return loseTimes;
    }

    public int getTeamRank() {
        return teamRank;
    }


    //Update win and lose time
    public void addWinTime() {
        winTimes += 1;
    }

    public void addLoseTime() {
        loseTimes += 1;
    }

    //Calculate teamRank
    public void setTeamRank() {
        teamRank = winTimes * 2 - loseTimes;
    }

    @Override
    public String toString() {
        return "Team{" +
                "teamName='" + teamName + '\'' +
                ", teamCity='" + teamCity + '\'' +
                ", teamRegionCode='" + teamRegionCode + '\'' +
                ", teamSetUpDate='" + teamSetUpDate + '\'' +
                ", winTimes=" + winTimes +
                ", loseTimes=" + loseTimes +
                ", teamRank=" + teamRank +
                '}';
    }
}
