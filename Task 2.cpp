#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

struct Node
{
    Node* next;
    string data;

    Node(string _data) : data(_data), next(nullptr) {}
};

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
        }
        else if (last->data == _data)
        {
            remove_last();
        }

        Node* temp = first;

        while (temp != last)
        {
            Node* slow = first;
            Node* fast = first->next;

            while (fast && fast->data != _data)
            {
                fast = fast->next;
                slow = slow->next;
            }

            if (!fast)
            {
                return;
            }

            slow->next = fast->next;

            delete fast;

            temp->next = slow->next;
            temp = temp->next;
        }
        
    }

    void clear()
    {
        while (!is_empty()) 
        {
            remove_first();
        }
    }

private:
    Node* first;
    Node* last;
};

void tokenize(string const& str, const char delim, vector<string>& out)
{
    stringstream ss(str);

    string s;
    while (getline(ss, s, delim)) 
    {
        out.push_back(s);
    }
}

int main()
{
    List list;
    bool quit = false;

    do
    {
        cout << "Select option:" << endl;
        cout << "1: Insert" << endl;
        cout << "2: Display items" << endl;
        cout << "3: Delete" << endl;
        cout << "4: Clear" << endl;
        cout << "5: Exit" << endl;

        string input;
        getline(cin, input);

        vector<string> items;
        const char delim = ' ';
        tokenize(input, delim , items);

        if (items[0] == "insert") 
        {
            for(int i = 1; i < items.size(); i++)
            {
                list.push_back(items[i]);
            }
        }
        else if(items[0] == "display")
        {
            list.print();
        }
        else if(items[0] == "delete")
        {
            list.remove(items[1]);
        }
        else if(items[0] == "clear")
        {
            list.clear();
        }
        else if(items[0] == "exit")
        {
            quit = true;
        }

    } while (!quit);


    return 0;
}