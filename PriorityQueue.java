package datastructurebyKrishna;

public class PriorityQueue {
    protected PriorityQueueData head;
    public void push(int data, int priority)
    {
        PriorityQueueData temp = new PriorityQueueData(data,priority,null);
        if(head==null)
        {
            head = temp;
        }
        else
        {
            if(temp.priority>head.priority)
            {
                temp.next = head;
                head = temp;
            }
            else
            {
                PriorityQueueData counter=head;
                PriorityQueueData counter2=head.next;
                while(true)
                {
                    if(counter2==null)
                    {
                        counter.next = temp;
                        break;
                    }
                    if(temp.priority<=counter.priority && temp.priority>counter2.priority)
                    {
                        temp.next = counter2;
                        counter.next = temp;
                        break;
                    }
                    else{
                        counter = counter.next;
                        counter2 = counter2.next;
                    }
                }
            }
        }
    }

    public int deleteHighestPriority() throws Exception
    {
        if(head==null){ throw new Exception("Empty Priority Queue");}
        int data = head.data;
        head = head.next;
        return data;
    }

    public void show()
    {
        PriorityQueueData counter = head;
        while(counter!=null)
        {
            System.out.println(counter.data);
            counter = counter.next;
        }
    }

    public int getHighestPriority() throws Exception
    {
        if(head==null) { throw new Exception("Empty Priority Queue");}
        return head.data;
    }

    public boolean isEmpty(){ return head==null; }



//Data Sample for Priority Queue
    private class PriorityQueueData{
        int data;
        int priority;
        PriorityQueueData next;

        private PriorityQueueData(int data,int priority,PriorityQueueData next)
        {
            this.data = data;
            this.priority = priority;
            this.next = next;
        }
    }
}


