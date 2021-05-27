package corpor.output;

import corpor.info.Game;
import corpor.info.ProcessData;
import corpor.info.Team;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Scanner;

public class Q7 implements ProcessData {
    public static int[] getGameGrade(Team t, ArrayList<Game> gameList) {
        //最高得分 最低得分 最高失分 最低失分
        int[] result = new int[4];
        Game g;

        for (int i = 0; i < gameList.size(); i++) {
            g = gameList.get(i);
            if (g.homeRegionCode.equals(t.teamRegionCode)) {
                //得分部分
                if (result[0] == 0) {
                    result[0] = g.homeScore;
                }
                if (result[1] == 0) {
                    result[1] = g.homeScore;
                }

                if (g.homeScore > result[0]) {
                    result[0] = g.homeScore;
                }
                if (g.homeScore < result[1]) {
                    result[1] = g.homeScore;
                }

                //失分部分
                if (result[2] == 0) {
                    result[2] = g.guessScore;
                }
                if (result[3] == 0) {
                    result[3] = g.guessScore;
                }

                if (g.guessScore > result[2]) {
                    result[2] = g.guessScore;
                }
                if (g.guessScore < result[3]) {
                    result[3] = g.guessScore;
                }
            } else if(t.teamRegionCode.equals(g.guessRegionCode)){
                //得分部分
                if (result[0] == 0) {
                    result[0] = g.guessScore;
                }
                if (result[1] == 0) {
                    result[1] = g.guessScore;
                }

                if (g.guessScore > result[0]) {
                    result[0] = g.guessScore;
                }
                if (g.guessScore < result[1]) {
                    result[1] = g.guessScore;
                }

                //失分部分
                if (result[2] == 0) {
                    result[2] = g.homeScore;
                }
                if (result[3] == 0) {
                    result[3] = g.homeScore;
                }

                if (g.homeScore > result[2]) {
                    result[2] = g.homeScore;
                }
                if (g.homeScore < result[3]) {
                    result[3] = g.homeScore;
                }
            }
        }

        return result;
    }
    //格式化輸出 結果
    public static void displayResult(Team t, int[] result) {
        System.out.printf("%4s  %-7s%17s%8d / %2d%7d / %d\n", t.teamRegionCode, t.teamName, t.teamCity, result[0], result[1], result[2], result[3]);
    }

    public static void main(String[] args) throws FileNotFoundException {
        FileInputStream file = new FileInputStream("src\\corpor\\output\\p1.in");
        Scanner sc = new Scanner(file);
        Q7 q = new Q7();
        ArrayList<Team> teamList = q.getTeamList(sc);
        ArrayList<Game> gameList = q.getGameList(sc);
        q.analyzeGameInfo(teamList, gameList);

        Team t;
        //處理所有隊伍資訊
        for (int i = 0; i < teamList.size(); i++) {
            t = teamList.get(i);
            //計算隊伍的得失分
            int[] result = getGameGrade(t, gameList);
            //輸出計算結果
            displayResult(t, result);
        }

    }
}
