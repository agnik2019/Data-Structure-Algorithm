#include<iostream>
#include <vector>
using namespace std;

class MinHeap 
{
public:
vector<int> heap;
int leftchild(int i)
{
    return 2*i+1;
}
int rightchild(int i)
{
    return 2*i+2;
}
int parent(int i){
    return (i-1)/2;
}
void heapify_down(int currentIdx) {
    int leftchildidx = leftchild(currentIdx);
    int rightchildidx = rightchild(currentIdx);
    int parentidx = parent(currentIdx);
    int smallest = currentIdx;
    int size = heap.size();
    if(leftchildidx< size && heap[leftchildidx]<heap[currentIdx])
        smallest = leftchildidx;
    if(leftchildidx< size && heap[rightchildidx]<heap[currentIdx])
        smallest = rightchildidx;
    if(smallest != currentIdx){
        swap(heap[currentIdx], heap[smallest]);
        heapify_down(smallest);
    }
}
void heapify_up(int currentIdx) {
    if(currentIdx && heap[parent(currentIdx)]> heap[currentIdx])
    {
        swap(heap[currentIdx], heap[parent(currentIdx)]);
        heapify_up(parent(currentIdx));
    }
}
unsigned int size()
    {
        return heap.size();
    }
 
    // function to check if heap is empty or not
    bool empty()
    {
        return size() == 0;
    }
    
    // insert key into the heap
    void push(int key)
    {
        // insert the new element to the end of the vector
        heap.push_back(key);
 
        // get element index and call heapify-up procedure
        int index = size() - 1;
        heapify_up(index);
    }
 
    // function to remove element with highest priority (present at root)
    void pop()
    {
        try {
            // if heap has no elements, throw an exception
            if (size() == 0)
                throw out_of_range("Vector<X>::at() : "
                        "index is out of range(Heap underflow)");
 
            // replace the root of the heap with the last element
            // of the vector
            heap[0] = heap.back();
            heap.pop_back();
 
            // call heapify-down on root node
            heapify_down(0);
        }
        // catch and print the exception
        catch (const out_of_range& oor) {
            cout << "\n" << oor.what();
        }
    }
 
    // function to return element with highest priority (present at root)
    int top()
    {
        try {
            // if heap has no elements, throw an exception
            if (size() == 0)
                throw out_of_range("Vector<X>::at() : "
                        "index is out of range(Heap underflow)");
 
            // else return the top (first) element
            return heap.at(0);    // or return A[0];
        }
        // catch and print the exception
        catch (const out_of_range& oor) {
            cout << "\n" << oor.what();
        }
    }
};
 
// Max Heap C++ implementation
int main()
{
    MinHeap pq;
    
    // Note - Priority is decided by element's value
    
    pq.push(3);
    pq.push(2);
    pq.push(15);
    
    cout << "Size is " << pq.size() << endl;    
    
    cout << pq.top() << " ";
    pq.pop();
 
    cout << pq.top() << " ";
    pq.pop();
 
    pq.push(5);
    pq.push(4);
    pq.push(45);
 
    cout << endl << "Size is " << pq.size() << endl;
    
    cout << pq.top() << " ";
    pq.pop();
 
    cout << pq.top() << " ";
    pq.pop();
 
    cout << pq.top() << " ";
    pq.pop();
 
    cout << pq.top() << " ";
    pq.pop();
 
    cout << endl << std::boolalpha << pq.empty();
    
    pq.top();    // top operation on an empty heap
    pq.pop();    // pop operation on an empty heap
 
    return 0;
}


// Size is 3
// 2 3
// Size is 4
// 4 5 15 45
// true
// Vector<X>::at() : index is out of range(Heap underflow)
// Vector<X>::at() : index is out of range(Heap underflow)