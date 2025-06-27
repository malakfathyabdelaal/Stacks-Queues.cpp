#include <iostream>
#include <fstream>
#include <string>

using namespace std;
class Node {
    public:
    string data;
    Node* next;
    Node(string d) {
        data = d;
        next = nullptr;
    }
};

class Stack {
    public:
    Node* top;
    Stack() {
        top = nullptr;
    }
    void push(string d) {
            Node* newnode = new Node(d);
            if(top == nullptr) {
                top = newnode;
                return;
            }
            newnode->next = top;
            top = newnode;
        }

    string pop() {
        if (top){
            Node* todel = top;
            string d = top->data;
            top = top->next;
            delete todel;
            return d;
        }
        else {
            cout<<"Stack is empty"<<endl;
            return "";
        }
    }
    void clear() {

        while (top) {
            Node* todel = top;
            top = top->next;
            delete todel;
        }
    }
    string Top() {
        if(!isEmpty()) {return top->data;}
        cout << "Stack is empty" << endl;
        return "";
    }
    bool isEmpty() {return top == nullptr; }


};
int main()
{
    Stack List;
    Stack BackupList;
    string elem,Choice, url;
    int StackNum = 0;
    int StackCount=0;
    int ctr=0;
    ifstream infile("urls.txt");
    string firstLine;
    getline(infile,firstLine);
    StackNum = stoi(firstLine);

    while (infile && StackCount<StackNum) {
            getline(infile, url);
            if(url[0]=='h'&&url[1]=='t'&&url[2]=='t'){
            List.push(url);
            StackCount++;

            }
    }

    cout<<"the current page is :"<<List.Top()<<endl;
    while(infile>>Choice) {
        cout<<"the choice Number"<<ctr+1<<":"<<Choice<<endl;
        if (Choice=="Backward") {
                if (!List.isEmpty()) {
                    elem=List.pop();
                    BackupList.push(elem);
                    cout<<"the current page is :"<<List.Top()<<endl;
                    cout<<"the next page is :"<<BackupList.Top()<<endl;
                    elem=List.pop();
                    BackupList.push(elem);
                    cout<<"the previous page is :"<<List.Top()<<endl;
                    elem=BackupList.pop();
                    List.push(elem);

        }
        else if (BackupList.isEmpty()){
            cout<<"there is no next pages"<<endl;
        }
        else if (List.isEmpty()){
            cout<<"there is no previous pages"<<endl;
        }

    }
    else if (Choice=="Forward") {
            if (!BackupList.isEmpty()) {
            elem=BackupList.pop();
            List.push(elem);
            cout<<"the current page is :"<<List.Top()<<endl;
            cout<<"the next page is :"<<BackupList.Top()<<endl;
            elem=List.pop();
            BackupList.push(elem);
            cout<<"the previous page is :"<<List.Top()<<endl;
            elem=BackupList.pop();
            List.push(elem);
        }
        else if (BackupList.isEmpty()){
            cout<<"there is no next pages"<<endl;
        }
        else if (List.isEmpty()){
            cout<<"there is no previous pages"<<endl;
        }

    }
    ctr++;

}
    return 0;
}
