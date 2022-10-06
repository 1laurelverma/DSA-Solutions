#include <iostream>
using namespace std;
int front=-1;int rear=-1;
int var;
void enqueue(int queue[],int size,int x)
{
    if(rear==size-1)
    cout<<"Overflow\n";
    else if(front==-1&&rear==-1)
    {
        front=0;
        rear=0;
    }
    else
    rear++;
    queue[rear]=x;
}
int dequeue(int queue[],int size)
{
    if(front==-1)
    {
    cout<<"Underflow\n";
    return-1;
    }
    else if(front==rear)
    {
        var=queue[front];
        front=-1;
        rear=-1; 
    }
    else
    {
        var=queue[front];
    front++;
    }
    return var;
}
void display(int queue[],int size)
{
    if(front==-1){
        cout<<"Queue is empty\n";
    }
    else
    {
        cout<<"Elements are:";
        for(int i=front;i<=rear;i++)
        {
            cout<<queue[i]<<" ";
        }
        cout<<"\n";
    }
}
int main()
{
    int size;int x=0;int work=1;int c;int v=0;
    cout<<"Enter the size of the queue:";
    cin>>size;
    int queue[size];
    while(work==1)
    {
        cout<<"Enter your choice\n";
        cout<<"1.Insertion\n";
        cout<<"2.Deletion\n";
        cout<<"3.Display\n";
        cout<<"4.EXIT\n";
        cin>>c;
        switch(c)
        {
            case 1:
            cout<<"Enter the element:";
            cin>>x;
            enqueue(queue,size,x);
            break;
            case 2:
            v=dequeue(queue,size);
            if(v!=-1)
            cout<<"Deleted element:"<<v<<"\n";
            break;
            case 3:
            display(queue,size);
            break;
            case 4:
            work=0;
            cout<<"Exit\n";
            break;
        }
    }
    return 0;
}
