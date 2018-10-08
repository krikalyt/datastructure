package datastructurebyKrishna;

public class BinaryTree {
    BinaryTreeData head;
    BinaryTreeData current;
    public void inserthead(int data){
        BinaryTreeData temp = new BinaryTreeData(data,null,null,null);
        if(head==null){
            head = temp;
            current = head;
        }
    }

    public void insert(int data,int position)throws Exception{
        BinaryTreeData temp = new BinaryTreeData(data,null,null,current);
        if(position==0)
        {
            current.left = temp;
        }
        else if(position==1) {
            current.right = temp;
        }
        else
            throw new Exception("wrong position");
    }

    public void changetoup(){
        current = current.parent;
    }
    public void changetoleft(){
        current = current.left;
    }
    public void changetoright(){
        current = current.right;
    }

    public void preorder(BinaryTreeData binaryTreeData){
        if(binaryTreeData==null)
            return;
        else{
            System.out.println(binaryTreeData.data);
            preorder(binaryTreeData.left);
            preorder(binaryTreeData.right);
        }
    }

    public void postorder(BinaryTreeData binaryTreeData){
        if(binaryTreeData==null)
            return;
        else{
            postorder(binaryTreeData.left);
            postorder(binaryTreeData.right);
            System.out.println(binaryTreeData.data);
        }
    }

    public class BinaryTreeData{
        int data;
        BinaryTreeData left;
        BinaryTreeData right;
        BinaryTreeData parent;

        public BinaryTreeData(){

        }
        public BinaryTreeData(int data, BinaryTreeData left, BinaryTreeData right, BinaryTreeData parent){
            this.data = data;
            this.left  = left;
            this.right = right;
            this.parent = parent;
        }
    }
}


