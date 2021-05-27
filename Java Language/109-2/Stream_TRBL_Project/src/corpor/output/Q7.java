package corpor.output;

import corpor.info.Game;
import corpor.info.ProcessData;
import corpor.info.Team;

import java.util.List;

public class Q7 implements ProcessData {
    public  static Integer[] getGameGrade(Team t,List<Game> gameList){
        //最高得分 最低得分 最高失分 最低失分
        Integer[] result={0,0,0,0};
        gameList.stream().forEach(g->{
            if (g.getHomeRegionCode().equals(t.getTeamRegionCode())) {
                //得分部分
                if (result[0] == 0) {
                    result[0] = g.getHomeScore();
                }
                if (result[1] == 0) {
                    result[1] = g.getHomeScore();
                }

                if (g.getHomeScore() > result[0]) {
                    result[0] = g.getHomeScore();
                }
                if (g.getHomeScore() < result[1]) {
                    result[1] = g.getHomeScore();
                }

                //失分部分
                if (result[2] == 0) {
                    result[2] = g.getGuessScore();
                }
                if (result[3] == 0) {
                    result[3] = g.getGuessScore();
                }

                if (g.getGuessScore() > result[2]) {
                    result[2] = g.getGuessScore();
                }
                if (g.getGuessScore() < result[3]) {
                    result[3] = g.getGuessScore();
                }
            } else if(t.getTeamRegionCode().equals(g.getGuessRegionCode())){
                //得分部分
                if (result[0] == 0) {
                    result[0] = g.getGuessScore();
                }
                if (result[1] == 0) {
                    result[1] = g.getGuessScore();
                }

                if (g.getGuessScore() > result[0]) {
                    result[0] = g.getGuessScore();
                }
                if (g.getGuessScore() < result[1]) {
                    result[1] = g.getGuessScore();
                }

                //失分部分
                if (result[2] == 0) {
                    result[2] = g.getHomeScore();
                }
                if (result[3] == 0) {
                    result[3] = g.getHomeScore();
                }

                if (g.getHomeScore() > result[2]) {
                    result[2] = g.getHomeScore();
                }
                if (g.getHomeScore() < result[3]) {
                    result[3] = g.getHomeScore();
                }
            }
        });

        return result;
    }

    public static void main(String[] args) {
        Q7 q=new Q7();
        List<Team> teamList=q.getTeamList();
        List<Game> gameList=q.getGameList();
        q.analyzeGameInfo(teamList,gameList);

        teamList.stream().forEach(t->{
            //取得成績
            Integer[] result=getGameGrade(t,gameList);
            //格式化輸出
            System.out.printf("%4s  %-7s%17s%8d / %2d%7d / %d\n", t.getTeamRegionCode(), t.getTeamName(), t.getTeamCity(), result[0], result[1], result[2], result[3]);
        });
    }
}
