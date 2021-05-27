package corpor.output;

import corpor.info.Game;
import corpor.info.ProcessData;
import corpor.info.Team;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Scanner;

public class Q1 implements ProcessData {
    //檢查是否吻合隊伍資訊
    public static boolean isMatchTeam(Game g, String hTeam, String gTeam) {
        //列舉所有可能組合(hTeam vs gTeam 或 gTeam vs hTeam)
        if (g.getHomeRegionCode().contains(hTeam) && g.getGuessRegionCode().contains(gTeam)) {
            return true;
        }

        if (g.getHomeRegionCode().contains(gTeam) && g.getGuessRegionCode().contains(hTeam)) {
            return true;
        }
        //無特定以上組合
        return false;
    }

    public static void main(String[] args) throws FileNotFoundException {
        FileInputStream file = new FileInputStream("src\\corpor\\output\\p1.in");
        Scanner sc = new Scanner(file);
        Q1 q = new Q1();
        ArrayList<Team> teamList = q.getTeamList(sc);
        ArrayList<Game> gameList = q.getGameList(sc);


        //int[0]=NR vs NR CN SU
        //int[1]=CN vs NR CN SU
        //int[2]=SU vs NR CN SU
        int[][] gameLocation = new int[3][3];

        //Record regions name
        String[] regions = new String[3];
        regions[0] = "NR";
        regions[1] = "CN";
        regions[2] = "SU";

        //Record the regions of game location
        for (int i = 0; i < gameLocation.length; i++) {
            for (int j = 0; j < gameLocation[i].length; j++) {
                for (int k = 0; k < gameList.size(); k++) {
                    if (isMatchTeam(gameList.get(k), regions[i], regions[j])) {
                        gameLocation[i][j] += 1;
                    }
                }
            }
        }

        //Format output
        System.out.printf("   %s %s %s\n", regions[0], regions[1], regions[2]);
        for (int i = 0; i < gameLocation.length; i++) {
            System.out.printf("%2s %2d %2d %2d\n", regions[i], gameLocation[i][0], gameLocation[i][1], gameLocation[i][2]);
        }

        sc.close();
    }
}
