#include <iostream>
#include <string>
using namespace std;

class List 
{
public:
    List(): first(nullptr), last(nullptr) {}

    ~List()
    {
        clear();
    }

    bool is_empty() 
    {
        return first == nullptr;
    }

    void push_back(string _data)
    {
        Node* temp = new Node(_data);

        if (is_empty()) 
        {
            first = temp;
            last = temp;
            return;
        }

        last->next = temp;
        last = temp;
    }

    void print() 
    {
        if (is_empty()) return;
        
        Node* temp = first;

        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void remove_first() 
    {
        if (is_empty()) return;

        Node* temp = first;

        first = temp->next;

        delete temp;
    }

    void remove_last() 
    {
        if (is_empty()) return;

        if (first == last) 
        {
            remove_first();
            return;
        }

        Node* temp = first;

        while (temp->next != last) 
        { 
            temp = temp->next; 
        }

        temp->next = nullptr;

        delete last;

        last = temp;
    }

    void remove(string _data) 
    {
        if (is_empty()) return;

        if (first->data == _data)
        {
            remove_first();
            return;
        }
        else if (last->data == _data)
        {
            remove_last();
            return;
        }

        Node* slow = first;
        Node* fast = first->next;

        while (fast && fast->data != _data)
        {
            fast = fast->next;
            slow = slow->next;
        }

        if(!fast)
        {
            cout << "This element does not exist" << endl;
            return;
        }

        slow->next = fast->next;

        delete fast;
    }

    void clear()
    {
        while (!is_empty()) 
        {
            remove_first();
        }
    }

private:
    class Node
    {
    public:
        Node* next;
        string data;

        Node(string _data) : data(_data), next(nullptr) {}
    };

    Node* first;
    Node* last;
};

int main()
{
    List list;
    string item;
    int choice;
    bool quit = false;

    do
    {
        cout << "Select option:" << endl;
        cout << "1: Insert" << endl;
        cout << "2: Display items" << endl;
        cout << "3: Delete" << endl;
        cout << "4: Clear" << endl;
        cout << "5: Exit" << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "\nEnter item to insert: ";

            cin >> item;
            list.push_back(item);

            break;
        case 2:
            cout << endl;

            list.print();

            break;
        case 3:
            cout << "\nEnter item to remove: ";

            cin >> item;
            list.remove(item);

            break;
        case 4:
            list.clear();

            break;
        case 5:
            quit = true;

            break;
        default:
            cout << "\nInvalid selection\n" << endl;

            break;
        }
    } while (!quit);

    return 0;
}