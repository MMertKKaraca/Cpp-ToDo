#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <string>

using namespace std;

#define UP 72
#define DOWN 80
#define A 97
#define D 100
#define U 117
#define K 107

int selectedToDo = 1;

class Node{
    public:
        string item;
        Node *link;
        Node(){item="";link=NULL;}
};
class LinkedList{
    public:
        void addnode(string);
        void linkedprint(int);
        int ToDoCount();
        void deleteNode(int);
        void updateNode(string);
        LinkedList(){ListHead=NULL;ListTail=NULL;}

    private:
        Node* ListHead;
        Node* ListTail;
};

void LinkedList::addnode(string additem){
    Node* newNode =new Node;
    newNode ->item = additem;
    newNode ->link = NULL;

    if(ListHead==NULL){
        ListHead=newNode;
        ListTail=newNode;
    }
    else{
       ListTail->link = newNode;
       ListTail = newNode;
    }
}


void LinkedList::linkedprint(int tmpSelectedToDo){
    Node* tmpNode = ListHead;
    int tmpToDoCount = ToDoCount();
    int count = 1;

    if(tmpSelectedToDo<=0){
        tmpSelectedToDo = 1;
        selectedToDo = 1;
    }
    else{
        if(tmpSelectedToDo>tmpToDoCount){
            tmpSelectedToDo = tmpToDoCount;
            selectedToDo = tmpToDoCount;
        }
    }

    if(tmpNode == NULL){
        cout<<"ToDo bombos";
    }
    else{
         while(tmpNode != NULL){
            if(count==tmpSelectedToDo){
                cout <<"> ";
            }
            cout << tmpNode->item<<"\n";
            tmpNode = tmpNode->link;
            count++;
        }
    }
}

int LinkedList::ToDoCount(){
    Node* tmpNode = ListHead;
    int tmpToDoCount = 0;
    while(tmpNode != NULL){
        tmpNode = tmpNode->link;
        tmpToDoCount++;
    }
    return tmpToDoCount;
}

void LinkedList::deleteNode(int tmpSelectedToDo){
    Node* tmpNode = ListHead;
    Node* delNode;
    int count = 1;
    if(tmpSelectedToDo != 1){
        while(count + 1 != selectedToDo){
        tmpNode = tmpNode->link;
            count++;
        }
        delNode = tmpNode->link;
        if(delNode == ListTail){
            tmpNode->link = NULL;
            ListTail = tmpNode;
            delete(delNode);
        }
        else{
            tmpNode->link= delNode->link;
            delete(delNode);
        }
    }
    else{
        delNode = ListHead;
        ListHead = delNode->link;
        delete(delNode);
    }
    selectedToDo = 1;
}

void LinkedList::updateNode(string tmpUpdateToDo){
    Node* tmpNode = ListHead;
    int count = 1;
    while(count != selectedToDo){
        tmpNode = tmpNode->link;
        count++;
    }
    tmpNode->item = tmpUpdateToDo;
}


int main(){
    LinkedList ToDo;
    bool status = true;

    while(status){
        cout<<"(↑ ↓)Arrow oklari ile ToDo sec. (a)ToDo ekle. (u)Secilen ToDo guncelle. (d)Secilen ToDo sil. (k)Programdan cik. \n\n";
        ToDo.linkedprint(selectedToDo);
        
        switch(_getch()){
            case UP:{
                system("CLS");
                selectedToDo--;
                break;
            };
            case DOWN:{
                system("CLS");
                selectedToDo++;
                break;
            };
            case A:{
                system("CLS");
                string newToDo;
                cout<<"ToDo ekle: ";
                getline(cin, newToDo);
                ToDo.addnode(newToDo);
                system("CLS");
                break;
            };
            case D:{
                system("CLS");
                if(ToDo.ToDoCount()!=0){
                    ToDo.deleteNode(selectedToDo);
                }
                break;
            };
            case U:{
                system("CLS");
                if(ToDo.ToDoCount()!=0){
                    string updateToDo;
                    cout<<"ToDo update: ";
                    getline(cin, updateToDo);
                    ToDo.updateNode(updateToDo);
                    system("CLS");
                }
                break;
            };
            case K:{
                status = false;
                break;
            };
        }
    }
    
    
    return 0;
}