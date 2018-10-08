package datastructurebyKrishna;

public class BinaryTreeUsingArray {
    int [] binarytreearray;
    int current = 0;
    int size;
    public BinaryTreeUsingArray(int node){
        binarytreearray = new int[node];
        size = node;
    }
    public void insertroot(int data){
        binarytreearray[0] = data;
    }

    public void insert(int position,int value){
        if(position==1){
            binarytreearray[(2*current)+1] = value;
        }
        else{
            binarytreearray[(2*current)+2] = value;
        }
    }

    public void movetoleft(){
        current = ((current*2)+1);
    }
    public void movetoright(){
        current = (current*2)+2;
    }
    public void movetoparent(){
        current = (int) Math.floor((current-1)/2);
    }

    public void inorder(int current){
        if(current>=size){
            return;
        }
        else{
            inorder((current*2)+1);
            System.out.println(binarytreearray[current]);
            inorder((current*2)+2);
        }
    }
}
