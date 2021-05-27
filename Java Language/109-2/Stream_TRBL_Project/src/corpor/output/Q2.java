package corpor.output;

import corpor.info.Game;
import corpor.info.ProcessData;
import corpor.info.Team;

import java.util.Comparator;
import java.util.List;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

public class Q2 implements ProcessData {
    public static void main(String[] args) {
        Q2 q=new Q2();
        List<Team> teamList=q.getTeamList();
        List<Game> gameList=q.getGameList();
        q.analyzeGameInfo(teamList,gameList);

        //排序Comparator
        Comparator<Team> comparator=(a,b)->{
            if(a.getWinTimes()==b.getWinTimes()){
                return a.getTeamRegionCode().compareTo(b.getTeamRegionCode());
            }

            return -(a.getWinTimes()-b.getWinTimes());
        };

        System.out.printf("%-4s%8s%9s%17s%7s%7s\n", "Rank", "TeamID", "Name", "City", "Win_#", "Lose_#");

        teamList=teamList.stream().sorted(comparator).collect(Collectors.toList());

        List<Team> finalTeamList = teamList;

        IntStream.range(0,teamList.size()).forEach(i->{
            Team t= finalTeamList.get(i);
            System.out.printf("%-4d%8s%9s%17s%7s%7s\n", (i + 1), t.getTeamRegionCode(), t.getTeamName(), t.getTeamCity(), t.getWinTimes(), t.getLoseTimes());
        });
    }
}
