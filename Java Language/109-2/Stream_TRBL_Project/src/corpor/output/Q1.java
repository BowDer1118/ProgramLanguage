package corpor.output;

import corpor.info.Game;
import corpor.info.ProcessData;
import corpor.info.Team;

import java.util.*;
import java.util.stream.Collectors;

public class Q1 implements ProcessData {
    public static void main(String[] args) {
        Q1 q=new Q1();
        List<Team> teamList=q.getTeamList();
        List<Game> gameList=q.getGameList();
        q.analyzeGameInfo(teamList,gameList);

        System.out.println("   NR CN SU");

        String[] regions={"NR","CN","SU"};

        Arrays.stream(regions).map(r->{
            //主場
            Map<String,Long>map1=gameList.stream().filter(g->g.getHomeRegion().equals(r))
                             .collect(Collectors.groupingBy(Game::getGuessRegion,Collectors.counting()));
            //客場
            Map<String,Long>map2=gameList.stream().filter(g->g.getGuessRegion().equals(r))
                    .collect(Collectors.groupingBy(Game::getHomeRegion,Collectors.counting()));
            //合併且去除重複的Entry
            map1.putAll(map2);

            //將結果組合成字串並輸出
            return r+" "+ map1.get("NR")+" "+map1.get("CN")+" "+map1.get("SU");
        }).forEach(System.out::println);

    }
}
