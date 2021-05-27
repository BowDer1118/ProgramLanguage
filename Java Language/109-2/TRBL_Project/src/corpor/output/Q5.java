package corpor.output;

import corpor.info.Game;
import corpor.info.ProcessData;
import corpor.info.Team;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.*;

public class Q5 implements ProcessData {
    //格式化輸出 結果
    public static void displayRank(List<Map.Entry<Team, Double>> list) {
        Team t;
        for (int i = 0; i < list.size(); i++) {
            t = list.get(i).getKey();
            double rate = list.get(i).getValue();
            System.out.printf("%-2d  %s  %-7s%17s %2d %2d %4.2f%%\n", (i + 1), t.teamRegionCode, t.teamName, t.teamCity, t.winTimes, t.loseTimes, rate);
        }
    }

    public static void main(String[] args) throws FileNotFoundException {
        FileInputStream file = new FileInputStream("src\\corpor\\output\\p1.in");
        Scanner sc = new Scanner(file);
        Q5 q = new Q5();
        ArrayList<Team> teamList = q.getTeamList(sc);
        ArrayList<Game> gameList = q.getGameList(sc);
        q.analyzeGameInfo(teamList, gameList);

        Team t;
        //將隊伍與勝率做成Key-Value 並使用Map儲存與排列
        Map<Team, Double> map = new HashMap<>();

        for (int i = 0; i < teamList.size(); i++) {
            t = teamList.get(i);
            //四捨五入到小數點第二位
            double rate = Math.round(((double) t.winTimes / (t.winTimes + t.loseTimes) * 10000.0)) / 100.0;
            map.put(t, rate);
        }

        //將Map中的Entry(Key-Value)取出 並放入List 做排序
        List<Map.Entry<Team, Double>> list = new ArrayList<>(map.entrySet());
        //依照Value做自然排序(升序)
        Collections.sort(list, Map.Entry.comparingByValue());
        //反轉串列(升序--->降序)(勝率高到低)
        Collections.reverse(list);

        displayRank(list);
    }
}
