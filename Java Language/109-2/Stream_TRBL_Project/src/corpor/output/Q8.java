package corpor.output;

import corpor.info.Game;
import corpor.info.ProcessData;
import corpor.info.Team;

import java.util.List;

public class Q8 implements ProcessData {//計算勝敗場在各地區的勝敗場

    public static Integer[] calculateWinLose(Team t, List<Game> gameList) {
        Integer[] result = {0, 0, 0, 0, 0, 0};

        gameList.stream().forEach(g -> {
            //如果t在主場
            if (t.getTeamRegionCode().equals(g.getHomeRegionCode())) {
                //在各地區
                if (g.getGuessRegionCode().contains("NR")) {
                    //判斷勝敗
                    if (g.getHomeScore() > g.getGuessScore()) {
                        result[0] += 1;
                    } else {
                        result[1] += 1;
                    }
                } else if (g.getGuessRegionCode().contains("CN")) {
                    if (g.getHomeScore() > g.getGuessScore()) {
                        result[2] += 1;
                    } else {
                        result[3] += 1;
                    }
                } else {
                    if (g.getHomeScore() > g.getGuessScore()) {
                        result[4] += 1;
                    } else {
                        result[5] += 1;
                    }
                }
            } else if (t.getTeamRegionCode().equals(g.getGuessRegionCode())) { //如果t在客場
                //在各地區
                if (g.getHomeRegionCode().contains("NR")) {
                    //判斷勝敗
                    if (g.getGuessScore() > g.getHomeScore()) {
                        result[0] += 1;
                    } else {
                        result[1] += 1;
                    }
                } else if (g.getHomeRegionCode().contains("CN")) {
                    if (g.getGuessScore() > g.getHomeScore()) {
                        result[2] += 1;
                    } else {
                        result[3] += 1;
                    }
                } else {
                    if (g.getGuessScore() > g.getHomeScore()) {
                        result[4] += 1;
                    } else {
                        result[5] += 1;
                    }
                }
            }
        });
        return result;
    }

    public static void main(String[] args) {
        Q8 q = new Q8();
        List<Team> teamList = q.getTeamList();
        List<Game> gameList = q.getGameList();
        q.analyzeGameInfo(teamList, gameList);

        System.out.printf("%s%10s%17s%12s%12s%12s%12s%12s%12s\n", "TeamID", "Name", "City", "NR_Win#", "NR_Lose#", "CN_Win#", "CN_Lose#", "SU_Win#", "SU_Lose#");

        teamList.stream().forEach(t->{
            Integer[] result = calculateWinLose(t, gameList);
            System.out.printf("%s%12s%17s%12d%12d%12d%12d%12d%12d\n", t.getTeamRegionCode(), t.getTeamName(), t.getTeamCity(), result[0], result[1], result[2], result[3], result[4], result[5]);
        });
    }
}
