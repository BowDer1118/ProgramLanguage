package corpor.output;

import corpor.info.Game;
import corpor.info.ProcessData;
import corpor.info.Team;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Q10 implements ProcessData {
    //處理在各地區中的 比賽勝敗 結果 並回傳各地區的統計數據(以Map的資料結構)
    public static Map<Boolean, ArrayList<Game>> getAreaGames(String local, ArrayList<Game> gameList) {
        Map<Boolean, ArrayList<Game>> resultMap = new HashMap<>();
        ArrayList<Game> winList = new ArrayList<>();
        ArrayList<Game> loseList = new ArrayList<>();
        Game g;

        for (int i = 0; i < gameList.size(); i++) {
            g = gameList.get(i);
            if (g.homeRegionCode.contains(local)) {
                if (g.homeScore > g.guessScore) {
                    winList.add(g);
                } else {
                    loseList.add(g);
                }
            }
        }

        resultMap.put(true, winList);
        resultMap.put(false, loseList);

        return resultMap;
    }

    //格式化輸出 結果
    public static void displayResult(String[] areaString, Map<String, Map<Boolean, ArrayList<Game>>> map) {
        System.out.printf("%6s   %5s %6s\n", "Region", "Win_#", "Lose_#");
        for (int i = 0; i < map.size(); i++) {
            Map<Boolean, ArrayList<Game>> e = map.get(areaString[i]);
            System.out.printf("%-6s   %5d %6d\n", areaString[i], e.get(true).size(), e.get(false).size());
        }
    }

    public static void main(String[] args) throws FileNotFoundException {
        FileInputStream file = new FileInputStream("src\\corpor\\output\\p1.in");
        Scanner sc = new Scanner(file);
        Q10 q = new Q10();
        ArrayList<Team> teamList = q.getTeamList(sc);
        ArrayList<Game> gameList = q.getGameList(sc);
        q.analyzeGameInfo(teamList, gameList);

        //代表各地區的勝敗場
        Map<Boolean, ArrayList<Game>> areaMap = new HashMap<>();
        //代表各地區 與 各地區的統計解果
        Map<String, Map<Boolean, ArrayList<Game>>> totalMap = new HashMap<>();
        //分類依據
        String[] areaString = new String[3];
        areaString[0] = "SU";
        areaString[1] = "NR";
        areaString[2] = "CN";

        //對不同地區做資料處理
        for (int i = 0; i < 3; i++) {
            areaMap = getAreaGames(areaString[i], gameList);
            totalMap.put(areaString[i], areaMap);
        }
        //將處理完的資料輸出
        displayResult(areaString, totalMap);

    }
}
