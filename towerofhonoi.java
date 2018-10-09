package datastructurebyKrishna;

public class towerofhonoi {
    public static void towerofhonoi(int n,char from, char to, char auxiliary){
        if(n==1){
            System.out.println("Moving Disk 1 from "+from +" to "+to);
            return;
        }
        towerofhonoi(n-1,from,auxiliary,to);
        System.out.println("moving disk "+n+" from "+from+" to "+to);
        towerofhonoi(n-1,auxiliary,to,from);
    }
}