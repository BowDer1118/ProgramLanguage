package corpor.output;

import corpor.info.Game;
import corpor.info.ProcessData;
import corpor.info.Team;

import java.util.List;
import java.util.Map;
import java.util.stream.Collectors;

public class Q9 implements ProcessData {
    public static void main(String[] args) {
        Q9 q=new Q9();
        List<Team> teamList=q.getTeamList();
        List<Game> gameList=q.getGameList();
        q.analyzeGameInfo(teamList,gameList);

        //使用partitioningBy分類
        Map<Boolean,List<Game>> map=gameList.stream().collect(Collectors.partitioningBy(g->g.getHomeRegion().equals(g.getGuessRegion())));

        System.out.println("false"+" "+map.get(false).size());
        System.out.println("true"+" "+map.get(true).size());
    }
}
