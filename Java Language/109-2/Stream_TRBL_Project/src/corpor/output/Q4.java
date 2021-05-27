package corpor.output;

import corpor.info.Game;
import corpor.info.ProcessData;
import corpor.info.Team;

import java.util.Comparator;
import java.util.List;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

public class Q4 implements ProcessData {
    public static void main(String[] args) {
        Q4 q = new Q4();
        List<Team> teamList = q.getTeamList();
        List<Game> gameList = q.getGameList();
        q.analyzeGameInfo(teamList, gameList);

        //自定義comparator與排序teamList
        Comparator<Team> comparator = (a, b) -> b.getTeamRank() - a.getTeamRank();
        teamList = teamList.stream().sorted(comparator).collect(Collectors.toList());

        List<Team> finalTeamList = teamList;
        //依照題目格式化輸出
        IntStream.range(0, teamList.size()).peek(i -> System.out.print((i+1) + "  "))
                .mapToObj(finalTeamList::get)
                .forEach(t -> {
                    double rate = Math.round(((double) t.getWinTimes() / (t.getWinTimes() + t.getLoseTimes())) * 10000.0) / 100.0;
                    System.out.printf("%s  %-7s%17s %2d %2d %2d %4.2f%%\n", t.getTeamRegionCode(), t.getTeamName(), t.getTeamCity(), t.getWinTimes(), t.getLoseTimes(), t.getTeamRank(), rate);
                });

    }
}
