package corpor.output;

import corpor.info.Game;
import corpor.info.ProcessData;
import corpor.info.Team;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Scanner;

public class Q8 implements ProcessData {
    //計算勝敗場在各地區的勝敗場
    public static int[] calculateWinLose(Team t, ArrayList<Game> gameList) {
        int[] result = new int[6];
        Game g;

        for (int i = 0; i < gameList.size(); i++) {
            g = gameList.get(i);
            //如果t在主場
            if (t.teamRegionCode.equals(g.homeRegionCode)) {
                //在各地區
                if (g.guessRegionCode.contains("NR")) {
                    //判斷勝敗
                    if (g.homeScore > g.guessScore) {
                        result[0] += 1;
                    } else {
                        result[1] += 1;
                    }
                } else if (g.guessRegionCode.contains("CN")) {
                    if (g.homeScore > g.guessScore) {
                        result[2] += 1;
                    } else {
                        result[3] += 1;
                    }
                } else {
                    if (g.homeScore > g.guessScore) {
                        result[4] += 1;
                    } else {
                        result[5] += 1;
                    }
                }
            } else if (t.teamRegionCode.equals(g.guessRegionCode)) { //如果t在客場
                //在各地區
                if (g.homeRegionCode.contains("NR")) {
                    //判斷勝敗
                    if (g.guessScore > g.homeScore) {
                        result[0] += 1;
                    } else {
                        result[1] += 1;
                    }
                } else if (g.homeRegionCode.contains("CN")) {
                    if (g.guessScore > g.homeScore) {
                        result[2] += 1;
                    } else {
                        result[3] += 1;
                    }
                } else {
                    if (g.guessScore > g.homeScore) {
                        result[4] += 1;
                    } else {
                        result[5] += 1;
                    }
                }
            }
        }

        return result;
    }

    //格式化輸出 結果
    public static void displayRank(Team t, int[] number) {
        System.out.printf("%s%12s%17s%12d%12d%12d%12d%12d%12d\n", t.teamRegionCode, t.teamName, t.teamCity, number[0], number[1], number[2], number[3], number[4], number[5]);
    }

    public static void main(String[] args) throws FileNotFoundException {
        FileInputStream file = new FileInputStream("src\\corpor\\output\\p1.in");
        Scanner sc = new Scanner(file);
        Q8 q = new Q8();
        ArrayList<Team> teamList = q.getTeamList(sc);
        ArrayList<Game> gameList = q.getGameList(sc);
        q.analyzeGameInfo(teamList, gameList);

        System.out.printf("%s%10s%17s%12s%12s%12s%12s%12s%12s\n", "TeamID", "Name", "City", "NR_Win#", "NR_Lose#", "CN_Win#", "CN_Lose#", "SU_Win#", "SU_Lose#");

        Team t;
        int[] result;
        //處理所有隊伍資訊
        for (int i = 0; i < teamList.size(); i++) {
            t = teamList.get(i);
            result = calculateWinLose(t, gameList);
            displayRank(t, result);
        }

    }
}
