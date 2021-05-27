package corpor.output;

import corpor.info.Game;
import corpor.info.ProcessData;
import corpor.info.Team;

import java.util.Arrays;
import java.util.Comparator;
import java.util.List;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

public class Q3 implements ProcessData {
    public static void main(String[] args) {
        Q3 q = new Q3();
        List<Team> teamList = q.getTeamList();
        List<Game> gameList = q.getGameList();
        q.analyzeGameInfo(teamList, gameList);

        Comparator<Team> comparator=(a,b)-> b.getTeamRank()-a.getTeamRank();

        String[] regionString = {"SU", "NR", "CN"};

        Arrays.stream(regionString)
                .peek(s -> System.out.printf("---------------------------%s------------------------------\n", s))   //先輸出區域代碼
                .map(s -> {
                    //產生區域隊伍並排序
                    List<Team> tempList = teamList.stream().filter(t -> t.getTeamRegionCode().contains(s))
                            //依照積分排序
                            .sorted(comparator)
                            .collect(Collectors.toList());
                    return tempList;
                }).forEach(teams -> {   //輸出區域隊伍
            IntStream.range(0, teams.size()).forEach(i -> {
                Team t = teams.get(i);
                System.out.printf("#%d %s  %-7s%18s %2d %2d %2d\n", (i + 1), t.getTeamRegionCode(), t.getTeamName(), t.getTeamCity(), t.getWinTimes(), t.getLoseTimes(), t.getTeamRank());
            });
        });
    }
}
