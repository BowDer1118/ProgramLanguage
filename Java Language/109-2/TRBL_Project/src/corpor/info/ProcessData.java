package corpor.info;

import java.util.ArrayList;
import java.util.Scanner;

public interface ProcessData {
    //Process input and return Team information sorted as ArrayList
    default ArrayList<Team> getTeamList(Scanner sc) {
        ArrayList<Team> list = new ArrayList<>();
        int num = sc.nextInt();
        sc.nextLine();

        for (int i = 0; i < num; i++) {
            String temp = sc.nextLine();
            String[] sub_string = temp.split(" "); //Split the string to analysis team info

            if (sub_string[1].equals("New")) {
                list.add(new Team(sub_string[0], (sub_string[1] + " " + sub_string[2] + " " + sub_string[3]), sub_string[4], sub_string[5]));
            } else {
                list.add(new Team(sub_string[0], sub_string[1], sub_string[2], sub_string[3]));
            }
        }

        return list;
    }

    //Process input and return Game information sorted as ArrayList
    default ArrayList<Game> getGameList(Scanner sc) {
        ArrayList<Game> list = new ArrayList<>();
        int num = sc.nextInt();

        for (int i = 0; i < num; i++) {
            list.add(new Game(sc.next(), sc.next(), sc.next(), sc.nextInt(), sc.nextInt(), sc.next()));
        }

        return list;
    }

    //Analyze teamList and gameList and filled all field of teamList's elements
    default void analyzeGameInfo(ArrayList<Team> teamList, ArrayList<Game> gameList) {
        for (int i = 0; i < gameList.size(); i++) {
            Game g = gameList.get(i);
            Team home = new Team();
            Team guess = new Team();

            for (int j = 0; j < teamList.size(); j++) {
                if (teamList.get(j).teamRegionCode.equals(g.homeRegionCode)) {
                    home = teamList.get(j);
                }
                if (teamList.get(j).teamRegionCode.equals(g.guessRegionCode)) {
                    guess = teamList.get(j);
                }
            }

            if (g.homeScore > g.guessScore) {
                home.addWinTime();
                guess.addLoseTime();
            } else {
                guess.addWinTime();
                home.addLoseTime();
            }

            //After all field were filled and calculate the rank
            home.setTeamRank();
            guess.setTeamRank();
        }
    }
}
