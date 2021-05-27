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

public class Q3 implements ProcessData {
    //格式化輸出
    public static void displayRank(ArrayList<Team> list) {

        System.out.printf("---------------------------%s------------------------------\n", list.get(0).teamRegionCode.substring(0, 2));

        for (int i = 0; i < list.size(); i++) {
            Team t = list.get(i);
            System.out.printf("#%2d %s  %-7s%18s %2d %2d %2d\n", (i + 1), t.teamRegionCode, t.teamName, t.teamCity, t.winTimes, t.loseTimes, t.teamRank);
        }
    }

    public static void main(String[] args) throws FileNotFoundException {
        FileInputStream file = new FileInputStream("src\\corpor\\output\\p1.in");
        Scanner sc = new Scanner(file);
        Q3 q = new Q3();
        ArrayList<Team> teamList = q.getTeamList(sc);
        ArrayList<Game> gameList = q.getGameList(sc);
        q.analyzeGameInfo(teamList, gameList);

        //儲存每個地區的隊伍
        ArrayList<Team> tempList = new ArrayList<>();
        String[] regionString = new String[3];
        Team t;

        regionString[0] = "SU";
        regionString[1] = "NR";
        regionString[2] = "CN";

        //依照地區處理
        for (int i = 0; i < regionString.length; i++) {
            tempList.clear();
            //蒐集同地區隊伍
            for (int j = 0; j < teamList.size(); j++) {
                t = teamList.get(j);
                if (t.teamRegionCode.contains(regionString[i])) {
                    tempList.add(t);
                }
            }

            //降序排列
            Collections.sort(tempList, new Comparator<Team>() {
                @Override
                public int compare(Team o1, Team o2) {
                    return -(o1.teamRank - o2.teamRank);
                }
            });
            //輸出地區資訊
            displayRank(tempList);
        }
    }
}
