package datastructurebyKrishna;

public class BinarySearchTree {
    BinarySearchTreeData head;
    BinarySearchTreeData current;
   public BinarySearchTree(){
       head = null;
       current=head;
   }
   public void insert(int data){
       BinarySearchTreeData temp = new BinarySearchTreeData();
       temp.data = data;
       if(head==null){
           head = temp;
           current= head;
           return;
       }
       current = head;
       while(true){
           if(current.left == null){
               if(temp.data<current.data){
                   current.left = temp;
                   break;
               }
           }
           if(current.right==null){
               if(temp.data>current.data){
                   current.right = temp;
                   break;
               }
           }
           if(temp.data>current.data){
               movetoright();
           }else{
               movetoleft();
           }
       }
   }
   public void movetoleft(){
       current = current.left;
   }

   public void movetoright(){
       current = current.right;
   }


    public void preorder(BinarySearchTreeData binaryTreeData){
        if(binaryTreeData==null)
            return;
        else{
            System.out.println(binaryTreeData.data);
            preorder(binaryTreeData.left);
            preorder(binaryTreeData.right);
        }
    }
    //data sample
    class BinarySearchTreeData{
        int data;
        BinarySearchTreeData left;
        BinarySearchTreeData right;
        BinarySearchTreeData parent;
    }
}