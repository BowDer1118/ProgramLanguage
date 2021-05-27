package corpor.output;

import corpor.info.Game;
import corpor.info.ProcessData;
import corpor.info.Team;

import java.util.Arrays;
import java.util.List;
import java.util.Map;
import java.util.stream.Collectors;

public class Q10 implements ProcessData {
    public static void main(String[] args) {
        Q10 q=new Q10();
        List<Team> teamList=q.getTeamList();
        List<Game> gameList=q.getGameList();
        q.analyzeGameInfo(teamList,gameList);

        //將比賽依照地域分群 在依照勝敗場分群
        Map<String, Map<Boolean,List<Game>>> map =gameList.stream().collect(Collectors.groupingBy(g->g.getHomeRegion(),Collectors.partitioningBy(g->g.getHomeScore()>g.getGuessScore())));
        //格式化輸出
        System.out.printf("%6s   %5s %6s\n", "Region", "Win_#", "Lose_#");
        String[] regions=map.keySet().toArray(String[]::new);

        //輸出List<Game>的size等同於輸出 勝/敗場 次數
        Arrays.stream(regions).peek(s -> System.out.printf("%-6s",s)).map(map::get).forEach(e->{
            System.out.printf("%8d%7d\n",e.get(true).size(),e.get(false).size());
        });
    }
}
