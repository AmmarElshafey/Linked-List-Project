// Linked List project.cpp 

#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node* next;
    Node()          //initialize
    {
        data = 0;
        next = nullptr;
    }
};
class LinkedList
{
private :
    Node* head;     // Pointer to the first node
public:
    LinkedList()    //constructor
    {
        head = nullptr;
    }
    ~LinkedList()  //destructor
    {
        Node* temp;
        while (head != nullptr)
        {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
    bool IsEmpty()
    {
        return (head == nullptr);
    }
    void Display()
    {
        Node* temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout <<"NULL"<< endl;
    }
    int Count()
    {
        int result=0 ;
        Node* temp = head;
        while (temp != nullptr)
        {
            result++;
            temp = temp->next;
        }
        return result;
    }
    bool IsFound(int check)
    {
            Node * temp = head;
        while (temp != nullptr)
        {
            if (temp->data == check) return true;
            temp = temp->next;
        }
        return false;
    }
    void InsertAtBegin(int value)
    {
        Node* newNode = new Node();  //it calls the constructor Node()
        newNode->data = value;
        newNode->next = head;
        head = newNode;
    }
    void InsertAtEnd(int value)
    {
        if (IsEmpty())
        {
            InsertAtBegin(value);
            return;
        }
        else
        {
            Node* temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            Node* newNode = new Node();
            newNode->data = value;
            temp->next = newNode;
            newNode->next = nullptr;
        }
    }
    void InsertBefore(int before, int value)
    {
        if (IsEmpty() || head->data == before)
           
            {
                InsertAtBegin(value);
                return;
            }
        else
        {

            if (IsFound(before))
            {
                Node* temp = head;
                while (temp->next!=nullptr &&temp->next->data != before)
                {
                    temp = temp->next;          //we stoped before the num you want insert before
                }
                Node* newNode = new Node();
                newNode->data = value;
                newNode->next = temp->next;  //connect newNode with before
                temp->next = newNode;       //connect prev with newNode
            }
            else
                cout << "the number you want to insert befor isn't found" << endl;
        }
    }
    void Delete(int value)
    {
        if (IsEmpty()) 
        {
            cout << "List is empty, nothing to delete." << endl;
            return;
        }
        if (!IsFound(value)) {
            cout << "The value you want to delete is not found." << endl;
            return;
        }
        {
            Node* delptr = head;
            if (head->data == value)
            {
                head = head->next;
            }
            else
            {
                Node* prev = nullptr;
                while (delptr->data != value)
                {
                    prev = delptr;
                    delptr = delptr->next;
                }
                prev->next = delptr->next;
            }
                delete delptr;
        }
    }

};
int main()
{
    LinkedList list;
    if (list.IsEmpty())
        cout << "List is empty" << endl;
    else
    {
        cout << "List has" << list.Count() << " Elements" << endl;
    }
    int atBegin;
    cout << "Enter the value you want to insert at begin : " << endl;
    cin >> atBegin;
    list.InsertAtBegin(atBegin);

    int atEnd;
    cout << "Enter the value you want to insert at end : " << endl;
    cin >> atEnd;
    list.InsertAtEnd(atEnd);

    int before,value;
    cout << "Enter the number you want to insert before and the value you want to insert : " << endl;
    cin >> before>>value;
    list.InsertBefore(before, value);

    cout << "Linked list is : ";
    list.Display();

    int check;
    cout << "Enter the number you want to check : " << endl;
    cin >> check;
    if (list.IsFound(check))
        cout << "Your number " << check <<" is found" << endl;
    else
        cout << "Your number " << check <<" is not found" << endl;

    int delnum;
    cout << "Enter the number you want to delete : " << endl;
    cin >> delnum;
    list.Delete(delnum);
    cout << "After deletion, the linked list is : ";
    list.Display();
}

