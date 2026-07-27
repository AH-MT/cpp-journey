#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int data):data(data){
        next = nullptr;
    }
};
void add(node* &head, int value, int index){
    node* n = new node (value);
    if (index == 0) {
        n->next = head;
        head = n;
        return;
    }

    node* temp = head;

    for(int i=0; i<index-1  && temp != nullptr; i++){
        temp = temp->next;
    }
    if (temp == nullptr) {
        cout << "Index out of range!" << endl;
        delete n;
        return;
    }


    n->next = temp->next;
    temp->next = n;

}
void display(const node* head, int start, int end) {
    if (head == nullptr) {
        cout << "List is empty!" << endl;
        return;
    }

    if (start < 0 || end < 0 || start > end) {
        cout << "Invalid range!" << endl;
        return;
    }

    const node* temp = head;
    int index = 0;

    while (temp != nullptr && index < start) {
        temp = temp->next;
        index++;
    }

    if (temp == nullptr) {
        cout << "Start index out of range!" << endl;
        return;
    }

    while (temp != nullptr && index <= end) {
        cout << temp->data << " ";
        temp = temp->next;
        index++;
    }

    cout << endl;
}
void remove(node*& head, int index) {
    if (head == nullptr) {
        cout << "List is empty!" << endl;
        return;
    }

    if (index < 0) {
        cout << "Invalid index!" << endl;
        return;
    }

    // حذف اولین نود
    if (index == 0) {
        node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    node* pre = head;

    for (int i = 0; i < index - 1; i++) {
        if (pre == nullptr || pre->next == nullptr) {
            cout << "Index out of range!" << endl;
            return;
        }
        pre = pre->next;
    }
    
    if (pre->next == nullptr) {
        cout << "Index out of range!" << endl;
        return;
    }

    node* toDelete = pre->next;
    pre->next = toDelete->next;
    delete toDelete;
}
void search(const node* &head, int value){
    const node* temp = head;
    int index = 0;
    bool find =false;
    while(temp != nullptr){
        if(temp->data == value){
            cout<<"index: "<<index<<endl;
            find = true;
        }
        temp = temp->next;
        index++;
    }
    if(!find){
        cout<<"not found....";
    }
    return;
}
void clear(node* &head){
    if (head == nullptr) {
        return; 
    }
    node* temp = head;
    head = head->next;
    
    while (head != nullptr){
        delete temp;
        temp = head;
        head = head->next;
    }
    delete temp;
    head = nullptr; 
}

int main(){


    return 0;
}
