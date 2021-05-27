package corpor.output;

import corpor.info.Game;
import corpor.info.ProcessData;
import corpor.info.Team;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.*;

public class Q4 implements ProcessData {
    //格式化輸出
    public static void displayRank(ArrayList<Team> teamList) {
        Team t;
        for (int i = 0; i < teamList.size(); i++) {
            t = teamList.get(i);
            double rate = Math.round(((double) t.winTimes / (t.winTimes + t.loseTimes)) * 10000.0) / 100.0;
            System.out.printf("%-2d  %s  %-7s%17s %2d %2d %2d %4.2f%%\n", (i + 1), t.teamRegionCode, t.teamName, t.teamCity, t.winTimes, t.loseTimes, t.teamRank, rate);
        }
    }

    public static void main(String[] args) throws FileNotFoundException {
        FileInputStream file = new FileInputStream("src\\corpor\\output\\p1.in");
        Scanner sc = new Scanner(file);
        Q4 q = new Q4();
        ArrayList<Team> teamList = q.getTeamList(sc);
        ArrayList<Game> gameList = q.getGameList(sc);
        q.analyzeGameInfo(teamList, gameList);

        //依照勝率降序排序(勝利高到低)
        Collections.sort(teamList, new Comparator<Team>() {
            @Override
            public int compare(Team o1, Team o2) {
                return -(o1.teamRank - o2.teamRank);
            }
        });

        displayRank(teamList);
    }
}
