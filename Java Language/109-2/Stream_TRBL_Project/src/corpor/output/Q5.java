package corpor.output;

import corpor.info.Game;
import corpor.info.ProcessData;
import corpor.info.Team;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Map;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

public class Q5 implements ProcessData {
    public static void main(String[] args) {
        Q5 q = new Q5();
        List<Team> teamList = q.getTeamList();
        List<Game> gameList = q.getGameList();
        q.analyzeGameInfo(teamList, gameList);

        //將隊伍與勝率做成Key-Value 並使用Map儲存與排列
        Map<Team, Double> map = teamList.stream().collect(Collectors.toMap(team -> team, t -> Math.round(((double) t.getWinTimes() / (t.getWinTimes() + t.getLoseTimes()) * 10000.0)) / 100.0));

        //將Map中的Entry(Key-Value)取出 並放入List 做排序
        List<Map.Entry<Team, Double>> list = new ArrayList<>(map.entrySet());
        //依照Value做自然排序(升序)
        list.sort(Map.Entry.comparingByValue());
        //反轉串列(升序--->降序)(勝率高到低)
        Collections.reverse(list);


        //依照題目要求輸出
        IntStream.range(0, list.size())
                .peek(i -> System.out.print((i + 1) + " "))
                .mapToObj(list::get).forEach(e -> {
            Team t = e.getKey();
            double rate = e.getValue();
            System.out.printf("%s  %-7s%17s %2d %2d %4.2f%%\n", t.getTeamRegionCode(), t.getTeamName(), t.getTeamCity(), t.getWinTimes(), t.getLoseTimes(), rate);
        });
    }
}
