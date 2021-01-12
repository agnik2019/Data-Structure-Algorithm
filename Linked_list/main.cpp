#include<iostream>
using namespace std;

class node{
    public:
        int val;
        node* next;
        node(int data){
            val = data;
            next = NULL;
        }
};
void insertAtHead(node* &head,int val)
{
    node* n = new node(val);
    n->next = head;
    head = n;
}
void insert_at_tail(node* &head, int val)
{
    node* n = new node(val);
    if(!head){
        head = n;
        return;
    }
    node *temp = head;
    while(temp->next)
        temp = temp->next;
    temp->next = n;
}
void deleteAtHead(node* &head)
{
    node* todelete = head;
    head = head->next;
    delete todelete;   
}
void deletion(node* &head, int val)
{
    if(!head) return;
    if(!head->next) deleteAtHead(head);
    node* temp = head;
    while(temp->next->val != val)
    {
        temp = temp->next;
    }
    node* todelete = temp->next;
    temp->next = temp->next->next;
    delete todelete;
}
node* reverse(node* &head)
{
    node* prevptr = NULL;
    node* currptr = head;
    node* nextptr;
    while(currptr)
    {
        nextptr = currptr -> next;
        currptr -> next = prevptr;
        prevptr = currptr;
        currptr = nextptr;
    }
    return prevptr;
}
node* recursive_reverse(node* &head)
{
    if(!head || !head->next) return head;
    node* newhead = recursive_reverse(head->next);
    head ->next ->next = head;
    head->next = NULL;
    return newhead;
}
//reverse k nodes
node* reverseknodes(node* &head, int k)
{
    node* prevptr = NULL;
    node* currptr = head;
    node* nextptr;
    int count = 0;
    while(currptr && count<k)
    {
        nextptr = currptr->next;
        currptr->next = prevptr;
        prevptr = currptr;
        currptr = nextptr;
        count++;
    }
    if(nextptr)
    {
        head->next = reverseknodes(nextptr,k);
    }
    return prevptr;
}

void display(node* head)
{
    node* temp = head;
    while(temp)
    {
        cout<< temp->val << "->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}
int main()
{
    node* head = NULL;
    insert_at_tail(head,1);
    insert_at_tail(head,2);
    insert_at_tail(head,3);
    insert_at_tail(head,4);
    insert_at_tail(head,5);
    insert_at_tail(head,6);
    display(head); 
    node* reversednode = reverseknodes(head,2); 
    display(reversednode);
    return 0;
}