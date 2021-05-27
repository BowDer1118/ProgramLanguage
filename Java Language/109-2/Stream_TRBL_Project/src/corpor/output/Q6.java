package corpor.output;

import corpor.info.Game;
import corpor.info.ProcessData;
import corpor.info.Team;

import java.util.ArrayList;
import java.util.List;
import java.util.Map;
import java.util.stream.Collectors;

public class Q6 implements ProcessData {
    public static Integer[] getAverage(Team t,List<Game> gameList){
        //隊伍 比賽場數 得分 失分
        int[] record=new int[3];

        //主場
        gameList.stream().filter(g->t.getTeamRegionCode().equals(g.getHomeRegionCode()))
                         .forEach(g->{
                             record[0]+=1;
                             record[1]+=g.getHomeScore();
                             record[2]+=g.getGuessScore();
                         });
        //客場
        gameList.stream().filter(g->t.getTeamRegionCode().equals(g.getGuessRegionCode()))
                         .forEach(g->{
                             record[0]+=1;
                             record[1]+=g.getGuessScore();
                             record[2]+=g.getHomeScore();
                         });

        //計算平均
        Integer[] result=new Integer[3];
        result[0] = (int) Math.round((double) record[1] / record[0]);
        result[1] = (int) Math.round((double) record[2] / record[0]);
        result[2] = Math.round(result[0] - result[1]);
        return result;
    }

    public static void main(String[] args) {
        Q6 q = new Q6();
        List<Team> teamList = q.getTeamList();
        List<Game> gameList = q.getGameList();
        q.analyzeGameInfo(teamList, gameList);

        //處理隊伍資訊並存放至Map中
        Map<Team,Integer[]> map=teamList.stream().collect(Collectors.toMap(team -> team,team ->getAverage(team,gameList)));

        //開始依照隊伍平均處理排序問題
        List<Map.Entry<Team, Integer[]>> list = new ArrayList<>(map.entrySet());


        list.stream().sorted((a,b)->b.getValue()[0]-a.getValue()[0])    //依照平均得分排序
                     .forEach(e->{
                         Team t;
                         Integer[] temp;
                         t = e.getKey();
                         temp = e.getValue();
                         System.out.printf("%s %7s%15s%12d%13d%12d\n", t.getTeamRegionCode(), t.getTeamName(), t.getTeamCity(), temp[0], temp[1], temp[2]);
                     });

        System.out.println();

        list.stream().sorted((a,b)->b.getValue()[1]-a.getValue()[1])    //依照平均失分排序
                .forEach(e->{
                    Team t;
                    Integer[] temp;
                    t = e.getKey();
                    temp = e.getValue();
                    System.out.printf("%s %7s%15s%12d%13d%12d\n", t.getTeamRegionCode(), t.getTeamName(), t.getTeamCity(), temp[0], temp[1], temp[2]);
                });

        System.out.println();

        list.stream().sorted((a,b)->b.getValue()[2]-a.getValue()[2])    //依照得失分差排序
                .forEach(e->{
                    Team t;
                    Integer[] temp;
                    t = e.getKey();
                    temp = e.getValue();
                    System.out.printf("%s %7s%15s%12d%13d%12d\n", t.getTeamRegionCode(), t.getTeamName(), t.getTeamCity(), temp[0], temp[1], temp[2]);
                });
    }
}
