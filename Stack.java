package datastructurebyKrishna;

class Stack{
   private StackData head;
   public void push(int data)
   {
       StackData temp = new StackData();
       temp.data = data;
       temp.next = null;

       if(head==null)
       {
           head = temp;
       }
       else
       {
           StackData counter = new StackData();
           counter = head;
           while(counter.next!=null)
           {
               counter = counter.next;
           }
           counter.next = temp;
       }
   }

   public int pop() throws Exception
   {
       StackData temp =  head;
       StackData temp2=null;
       if(isEmpty())
       {
           throw new Exception("StackData is Empty");
       }
       else{
           while(temp.next!=null)
           {
               temp2 = temp;
               temp = temp.next;
           }
           if(head.next==null)
           {
               int finaldata=head.data;
               head=null;
               return finaldata;
           }
           int finaldata  = temp.data;
           temp2.next = null;
           return finaldata;
       }
   }

   public boolean isEmpty()
   {
        if(head==null)
        {
            return true;
        }
        return false;
   }

   public void show()
   {
       StackData temp = new StackData();
       temp = head;
       while(temp!=null)
       {
           System.out.println(temp.data);
           temp = temp.next;
       }
   }

   private class StackData {
        int data;
        StackData next;
   }
}


