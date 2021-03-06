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
void makeCycle(node* &head, int pos)
{
    node* temp = head;
    node* startnode;
    int count = 1;
    while(temp->next != NULL)
    {
        if(count == pos) startnode = temp;
        temp = temp->next;
        count++;
    }
    temp->next = startnode;
}

bool detectCycle(node* &head)
{
    node* slow = head;
    node* fast = head;
    while(fast && fast->next)
    {
        slow = slow-> next;
        fast = fast->next->next;
        if(fast == slow) return true;
    }
    return false;
}

void removeCycle(node* &head)
{
    node* slow = head;
    node* fast = head;
    do{
        slow = slow->next;
        fast = fast ->next->next;
    }while(slow!= fast);
    fast = head;
    while(slow ->next != fast->next)
    {
        slow = slow->next;
        fast = fast->next;
    }
    slow->next = NULL;
}
//find intersection point
void makeintersection(node* &head1, node* &head2, int pos)
{
    node* temp1 = head1;
    pos--;
    while(pos--) temp1 = temp1->next;
    node* temp2 = head2;
    while(temp2->next) temp2 = temp2->next;
    temp2->next = temp1;
}
int length(node* head)
{
    int l = 0;
    while(head){
        head = head->next;
        l++;
    }
    return l;
}
node* intersection(node* &head1, node* &head2)
{
 int l1 = length(head1);
    int l2 = length(head2);
    int d = abs(l1-l2);
    node* ptr1;
    node* ptr2;
    ptr1 = (l1>l2)? head1: head2;
    ptr2 = (l1>l2)? head2: head1;
    while(d)
    {
        ptr1 = ptr1->next;
       if(ptr1==NULL) return NULL;
        d--;
    }
    while(ptr1 && ptr2)
    {
        if(ptr1 == ptr2) return ptr1;
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    return NULL;
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
    makeCycle(head,3);
    //
    cout<<detectCycle(head)<<endl;
    removeCycle(head);
    display(head); 
    // node* reversednode = reverseknodes(head,2); 
    // display(reversednode);
    return 0;
}