package corpor.output;

import corpor.info.Game;
import corpor.info.ProcessData;
import corpor.info.Team;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.*;

public class Q9 implements ProcessData {
    public static void main(String[] args) throws FileNotFoundException {
        FileInputStream file = new FileInputStream("src\\corpor\\output\\p1.in");
        Scanner sc = new Scanner(file);
        Q9 q = new Q9();
        ArrayList<Team> teamList = q.getTeamList(sc);
        ArrayList<Game> gameList = q.getGameList(sc);
        q.analyzeGameInfo(teamList, gameList);

        //依照題目要求包裝所有資料
        Map<Boolean,ArrayList<Game>> areaMap= new HashMap<>();
        Map<Boolean,Integer> resultMap=new HashMap<>();
        Game g;
        //代表同區的比賽
        ArrayList<Game> trueList=new ArrayList<>();
        //代表跨區的比賽
        ArrayList<Game> falseList=new ArrayList<>();

        //判斷 同區 跨區
        for (int i = 0; i < gameList.size(); i++) {
            g=gameList.get(i);
            if(g.homeRegionCode.contains(g.guessRegionCode.substring(0,2))){
                trueList.add(g);
            }else{
                falseList.add(g);
            }
        }

        //存放結果
        areaMap.put(true,trueList);
        areaMap.put(false,falseList);

        //產生結果
        resultMap.put(true,trueList.size());
        resultMap.put(false,falseList.size());

        //格式化輸出
        System.out.println("false"+" "+resultMap.get(false));
        System.out.println("true"+" "+resultMap.get(true));
    }
}
