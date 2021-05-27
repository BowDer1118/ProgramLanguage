package corpor.output;

import corpor.info.Game;
import corpor.info.ProcessData;
import corpor.info.Team;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.*;

public class Q6 implements ProcessData {
    //計算 平均得分 與 平均失分
    public static Integer[] getAverage(Team t, ArrayList<Game> gameList) {
        //隊伍 比賽場數 得分 失分
        int[] record = new int[3];
        Game g;

        for (int i = 0; i < gameList.size(); i++) {
            g = gameList.get(i);
            //主場
            if (t.teamRegionCode.equals(g.homeRegionCode)) {
                record[0] += 1;
                record[1] += g.homeScore;
                record[2] += g.guessScore;
            }
            //客場
            if (t.teamRegionCode.equals(g.guessRegionCode)) {
                record[0] += 1;
                record[1] += g.guessScore;
                record[2] += g.homeScore;
            }
        }

        //計算平均
        Integer[] result = new Integer[3];
        result[0] = (int) Math.round((double) record[1] / record[0]);
        result[1] = (int) Math.round((double) record[2] / record[0]);
        result[2] = Math.round(result[0] - result[1]);
        return result;
    }

    //格式化輸出
    public static void displayRank(List<Map.Entry<Team, Integer[]>> list) {
        Team t;
        Integer[] temp;
        for (Map.Entry<Team, Integer[]> e : list) {
            t = e.getKey();
            temp = e.getValue();

            System.out.printf("%s %7s%15s%12d%13d%12d\n", t.teamRegionCode, t.teamName, t.teamCity, temp[0], temp[1], temp[2]);
        }

    }

    public static void main(String[] args) throws FileNotFoundException {
        FileInputStream file = new FileInputStream("src\\corpor\\output\\p1.in");
        Scanner sc = new Scanner(file);
        Q6 q = new Q6();
        ArrayList<Team> teamList = q.getTeamList(sc);
        ArrayList<Game> gameList = q.getGameList(sc);
        q.analyzeGameInfo(teamList, gameList);

        //將隊伍與隊伍的平均資料使用Map儲存
        Map<Team, Integer[]> map = new HashMap<>();
        Team t;

        //處理隊伍資訊並存放至Map中
        for (int i = 0; i < teamList.size(); i++) {
            t = teamList.get(i);
            map.put(t, getAverage(t, gameList));
        }


        //開始依照隊伍平均處理排序問題
        List<Map.Entry<Team, Integer[]>> list = new ArrayList<>(map.entrySet());

        //依照平均得分
        Collections.sort(list, new Comparator<Map.Entry<Team, Integer[]>>() {
            @Override
            public int compare(Map.Entry<Team, Integer[]> o1, Map.Entry<Team, Integer[]> o2) {
                int integer1 = o1.getValue()[0];
                int integer2 = o2.getValue()[0];
                return integer2 - integer1;
            }
        });

        displayRank(list);
        System.out.println();

        //依照平均失分
        Collections.sort(list, new Comparator<Map.Entry<Team, Integer[]>>() {
            @Override
            public int compare(Map.Entry<Team, Integer[]> o1, Map.Entry<Team, Integer[]> o2) {
                int integer1 = o1.getValue()[1];
                int integer2 = o2.getValue()[1];
                return integer2 - integer1;
            }
        });

        displayRank(list);
        System.out.println();

        //依照 得失分差
        Collections.sort(list, new Comparator<Map.Entry<Team, Integer[]>>() {
            @Override
            public int compare(Map.Entry<Team, Integer[]> o1, Map.Entry<Team, Integer[]> o2) {
                int gap1 = o1.getValue()[0] - o1.getValue()[1];
                int gap2 = o2.getValue()[0] - o2.getValue()[1];
                return gap2 - gap1;
            }
        });

        displayRank(list);
    }
}
