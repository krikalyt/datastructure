package datastructurebyKrishna;

import java.util.Date;
import java.util.Scanner;

public class main {
    public static void main(String[] args) throws Exception{
        BinaryTreeUsingArray binaryTreeUsingArray = new BinaryTreeUsingArray(3);
        binaryTreeUsingArray.insertroot(10);
        binaryTreeUsingArray.insert(1,20);
        binaryTreeUsingArray.insert(2,31);
        infixtopostfix infixtopostfix = new infixtopostfix("A+B*C+D");
        System.out.println(infixtopostfix.getTheResult());
    }
}
