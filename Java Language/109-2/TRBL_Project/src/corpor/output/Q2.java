package corpor.output;

import corpor.info.Game;
import corpor.info.ProcessData;
import corpor.info.Team;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Scanner;

public class Q2 implements ProcessData {
    //格式化輸出 結果
    public static void displayRank(ArrayList<Team> teamList) {
        System.out.printf("%-4s%8s%9s%17s%7s%7s\n", "Rank", "TeamID", "Name", "City", "Win_#", "Lose_#");
        for (int i = 0; i < teamList.size(); i++) {
            Team t = teamList.get(i);
            System.out.printf("%-4d%8s%9s%17s%7s%7s\n", (i + 1), t.getTeamRegionCode(), t.getTeamName(), t.getTeamCity(), t.getWinTimes(), t.getLoseTimes());
        }
    }

    public static void main(String[] args) throws FileNotFoundException {
        FileInputStream file = new FileInputStream("src\\corpor\\output\\p1.in");
        Scanner sc = new Scanner(file);
        Q2 q = new Q2();
        ArrayList<Team> teamList = q.getTeamList(sc);
        ArrayList<Game> gameList = q.getGameList(sc);
        q.analyzeGameInfo(teamList, gameList);

        //Sort teamList
        Collections.sort(teamList, new Comparator<Team>() {
            @Override
            public int compare(Team o1, Team o2) {
                if (o1.winTimes == o2.winTimes) {   //若勝場數相同依照地區代號排序
                    return o1.teamRegionCode.compareTo(o2.teamRegionCode);
                }   //降序排列(勝場高到低)
                return -(o1.winTimes - o2.winTimes);
            }
        });

        displayRank(teamList);
        sc.close();
    }
}
