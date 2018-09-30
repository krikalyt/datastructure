package datastructurebyKrishna;

public class Queue {

    QueueData front;
    QueueData rear;

    public void inQueue(int data)
    {
        QueueData temp = new QueueData();
        temp.data = data;
        temp.next = null;
        if(front==null)
        {
            front = temp;
            rear = temp;
        }

        else
        {
            rear.next = temp;
            rear = temp;
        }
    }

    public int deQueue()
    {
        if(isEmpty()) {
            throw new ArrayIndexOutOfBoundsException("Queue is Empty");
        }
        int data = front.data;
        front = front.next;
        return data;
    }

    public boolean isEmpty()
    {
        if(front==null)
        {
            return true;
        }
        return false;
    }

    public void show()
    {
        QueueData counter = front;
        while(counter!=null)
        {
            System.out.println(counter.data);
            counter = counter.next;
        }
    }

    //data sample for Queue
    private class QueueData{
        int data;
        QueueData next;
    }
}

