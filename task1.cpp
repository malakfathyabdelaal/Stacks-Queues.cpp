#include <iostream>
#include <string>
#include <fstream>
using namespace std;
class Node
{
    public:
    string pc, arrival;
    int mins;
    Node * next;
    Node(string p="", string a="", int m=0)
    {
        pc=p;
        arrival=a;
        mins=m;
        next=0;
    }
    int minutes()
    {
        int hrs=stoi(arrival.substr(0,2));
        int mints=stoi(arrival.substr(3,2));
        return hrs*60+mints;
    }

};
class printerList
{
    public:
    Node*head;
    printerList(){head=0;}
    void add(Node*temp)
    {
        if(!head)
        {
            head=temp;
            return;
        }
        if(head->minutes()>temp->minutes())
        {
            temp->next=head;
            head=temp;
            return;
        }
        Node*start=head;
        while((start->next&&start->next->minutes()<temp->minutes()) || (start->next&&start->next->minutes()==temp->minutes()&&start->next->mins<temp->mins))
            start=start->next;
        if(start->next) temp->next=start->next;
        start->next=temp;
    }

    void removeHead()
    {
        if(head==0) return ;
        Node*temp=head;
        head=head->next;
        delete temp;
    }

    bool emptyList()
    {
        return head==0;
    }

};
class printerQueue
{
    public:
    printerList L;
    int jobsCount;
    printerQueue(int j=0){jobsCount=j;}
    void enqueue(Node*n)
    {
        L.add(n);
    }

    void dequeue()
    {
        L.removeHead();
    }

    Node* first()
    {
        return L.head;
    }

    void displayQueue()
    {
        cout<<"Jobs Executed: "<<jobsCount<<endl;
        Node* curr;
        Node* prev;
        int occupation=0;
        float waiting=0;
        prev=first();
        curr=prev->next;
        int execution=prev->minutes();
        occupation+=prev->mins;
        cout<<prev->pc<<'\t'<<prev->arrival<<' '<<prev->mins<<'\t';
        cout<<"executed at ";
        if(execution/60<10)cout<<'0';
        cout<<execution/60<<':';
        if(execution%60<10)cout<<'0';
        cout<<execution%60<<'\t';
        cout<<"waiting time: "<<execution-prev->minutes()<<endl;
        while(curr)
        {
            prev=first();
            dequeue();
            curr=prev->next;
            if(!curr) break;
            occupation+=curr->mins;
            cout<<curr->pc<<'\t'<<curr->arrival<<' '<<curr->mins<<'\t';
            execution=max(prev->minutes()+prev->mins,curr->minutes());
            cout<<"executed at ";
            if(execution/60<10)cout<<'0';
            cout<<execution/60<<':';
            if(execution%60<10)cout<<'0';
            cout<<execution%60<<'\t';
            cout<<"waiting time: "<<execution-curr->minutes()<<endl;
            waiting+=execution-curr->minutes();
        }
        cout<<"The printer was occupied for "<<occupation<<" minutes"<<endl;
        cout<<"Average waiting time for all jobs is "<<waiting/jobsCount;
    }

};
int main() {
    Node*n;
    printerQueue pq;
    int jobsNum, mt;
    string pc, time;
    ifstream infile("Printer.txt");
    infile>>jobsNum;
    pq.jobsCount=jobsNum;
    //cout<<jobsNum;
    for(int i=0;i<jobsNum;i++)
    {
        infile>>pc>>time>>mt;
        //cout<<pc<<'\t'<<time<<'\t'<<mt<<'\t'<<i<<endl;
        n=new Node(pc,time,mt);
        pq.enqueue(n);
    }
    pq.displayQueue();
    return 0;
}
