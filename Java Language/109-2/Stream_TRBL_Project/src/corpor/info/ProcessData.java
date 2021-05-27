package corpor.info;

import org.junit.jupiter.api.Test;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.List;
import java.util.stream.Collectors;
import java.util.stream.Stream;


public interface ProcessData {
    //Process input and return Team information sorted as ArrayList
    @Test
    default List<Team> getTeamList() {
        Stream<Team> teamStream = Stream.empty();
        try {
            teamStream = Files.lines(Paths.get("src\\corpor\\info\\TRBL_input_data.in"))
                    .skip(1)
                    .map(str -> {
                        String[] strings = str.split(" ");
                        if (strings[1].equals("New")) {
                            return new Team(strings[0], strings[1] + " " + strings[2] + " " + strings[3], strings[4], strings[5]);
                        } else {
                            return new Team(strings[0], strings[1], strings[2], strings[3]);
                        }
                    }).limit(12);
        } catch (IOException e) {
            e.printStackTrace();
        }
        return teamStream.collect(Collectors.toList());
    }

    //Process input and return Game information sorted as ArrayList
    default List<Game> getGameList() {
        Stream<Game> gameStream = Stream.empty();
        try {
            gameStream = Files.lines(Paths.get("src\\corpor\\info\\TRBL_input_data.in"))
                    .skip(14)
                    .map(str -> {
                        String[] strings = str.split(" ");
                        return new Game(strings[0], strings[1], strings[2], Integer.parseInt(strings[3]), Integer.parseInt(strings[4]), strings[5]);
                    });

        } catch (IOException e) {
            e.printStackTrace();
        }
        return gameStream.collect(Collectors.toList());
    }

    //Analyze teamList and gameList and filled all field of teamList's elements
    default void analyzeGameInfo(List<Team> teamList, List<Game> gameList) {
        teamList.stream()
                .map(t -> {
                    //主場分區代號吻合
                    List<Game> homeList = gameList.stream().filter(g -> g.getHomeRegionCode().equals(t.getTeamRegionCode())).collect(Collectors.toList());
                    //客場代號吻合
                    List<Game> guessList = gameList.stream().filter(g -> g.getGuessRegionCode().equals(t.getTeamRegionCode())).collect(Collectors.toList());

                    //計算在主場的勝場數
                    long homeWins = homeList.stream().filter(g -> g.getHomeScore() > g.getGuessScore()).count();
                    long homeLoses = homeList.size() - homeWins;

                    //計算在客場的勝場數
                    long guessWins = guessList.stream().filter(g -> g.getGuessScore() > g.getHomeScore()).count();

                    long guessLoses = guessList.size() - guessWins;


                    //更新勝敗場數並計算積分
                    t.setWinTime(Long.valueOf(homeWins + guessWins).intValue());
                    t.setLoseTime(Long.valueOf(homeLoses + guessLoses).intValue());
                    t.setTeamRank();
                    return t;
                })
                .collect(Collectors.toList());
    }
}
