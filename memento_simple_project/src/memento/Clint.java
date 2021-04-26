package memento;

//助記物類-->用來記錄Player的角色狀態
class Memento {
    private String currentLevel;
    private int health;
    private int money;

    public Memento(String currentLevel, int health, int money) {
        this.currentLevel = currentLevel;
        this.health = health;
        this.money = money;
    }

    public String getCurrentLevel() {
        return currentLevel;
    }

    public int getHealth() {
        return health;
    }

    public int getMoney() {
        return money;
    }

    /*
     *   只有Getters沒有Setters
     *   因為Memento類 只做備份(或稱快照)的工作
     *   不干涉修改
     */
}

class Player {
    private String currentLevel;
    private int health;
    private int money;

    public Player(String currentLevel, int health, int money) {
        this.currentLevel = currentLevel;
        this.health = health;
        this.money = money;
        System.out.println(this.toString());
    }

    //Getters and Setters
    public String getCurrentLevel() {
        return currentLevel;
    }

    public void setCurrentLevel(String currentLevel) {
        this.currentLevel = currentLevel;
    }

    public int getHealth() {
        return health;
    }

    public void setHealth(int health) {
        this.health = health;
    }

    public int getMoney() {
        return money;
    }

    public void setMoney(int money) {
        this.money = money;
    }

    @Override
    public String toString() {
        return "當前玩家資訊: " + "關卡層數 " + currentLevel + " 生命值 " + health + " 獲得金錢 " + money;
    }

    //提供備份的功能
    public Memento savePlayerState() {
        System.out.println("已保存玩家資料!");
        System.out.println("備份的玩家資訊: " + "關卡層數 " + currentLevel + " 生命值 " + health + " 獲得金錢 " + money);
        //將當前狀態
        return new Memento(currentLevel, health, money);
    }

    //提供恢復的功能
    public void revertPlayerStatus(Memento memento) {
        System.out.println("讀取玩家最後存檔...");
        System.out.println("讀取成功!");
        System.out.println(this.toString());
        this.currentLevel = memento.getCurrentLevel();
        this.health = memento.getHealth();
        this.money = memento.getMoney();
    }

}


public class Clint {
    public static void main(String[] args) {
        Player player = new Player("L001", 100, 0);
        //保存當前狀態
        Memento m = player.savePlayerState();

        //模擬進攻關卡
        player.setHealth(80);
        player.setMoney(1000);
        System.out.println();

        //若成功攻克
        if(player.getHealth()>0){
            System.out.println("攻克成功，進入下一關!!");
            m= player.savePlayerState();        //儲存當前狀態
            player.setCurrentLevel("L002");     //更新關卡回合
        }else{
            System.out.println("攻克失敗，");
        }
        System.out.println(player);

        //模擬進攻關卡
        player.setHealth(0);
        player.setMoney(2000);
        System.out.println();

        if(player.getHealth()>0){
            System.out.println("攻克成功，進入下一關!!");
            //儲存當前狀態並更新關卡回合
            m= player.savePlayerState();
            player.setCurrentLevel("L003");
        }else{
            System.out.println("攻克失敗，讀取上次備份...");
            //讀取備份檔並覆蓋當前狀況
            player.setCurrentLevel(m.getCurrentLevel());
            player.setHealth(m.getHealth());
            player.setMoney(m.getMoney());
        }
        System.out.println(player);

    }
}
