#include <iostream>
#include <string>

using namespace std;

class List
{
private:
    struct Node
    {
        int id;
        string name;
        Node* next;
    };
    
    Node* head;
    Node* tail;
    int nodeCount;

public:
    List()
    {
        head = NULL;
        tail = NULL;
        nodeCount = 0;
        cout << "-> Initialized" << endl;
    }
    void addNode(int id, string name)
    {
        Node* ptrNode = new Node;
        ptrNode->id = id;
        ptrNode->name = name;
        ptrNode->next = NULL;
        
        if(head == NULL)
        {
            head = ptrNode;
            tail = ptrNode;
        }
        else
        {
            tail->next = ptrNode;
            tail = ptrNode;
        }
        
        cout << "-> Added node " << ++nodeCount << endl;
    }
    
    int getNodeSize()
    {
        return nodeCount;
    }
    
    void displayNodes()
    {
        Node* tmpPtr = head;
        
        while(tmpPtr != NULL)
        {
            cout << tmpPtr->id  << " " << tmpPtr->name << endl;
            tmpPtr = tmpPtr->next;
        }
    }
    
    void deleteNode(int id)
    {
        Node* tmpPtr = head;
        
        while(tmpPtr != NULL)
        {
            if(tmpPtr->id == id)
            {
                if(tmpPtr == head)
                {
                    head = tmpPtr->next;
                }
                else if(tmpPtr == tail)
                {
                    // To be implemented
                }
                break;
            }
            tmpPtr = tmpPtr->next;
        }
    }
};

int main()
{
  List list;
  
  list.addNode(1, "Chris");
  list.addNode(2, "Michael");
  list.addNode(3, "Galo");
  
  list.displayNodes();
  
  return 0;
}