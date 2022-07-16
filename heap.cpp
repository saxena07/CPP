#include <iostream>
#include <vector>
using namespace std;


int left(vector<int>& heap,int parent)
{
    int l = 2 * parent + 1;
    if(l < (int) heap.size())
        return l;
    else
        return -1;
}
 

int right(vector<int>& heap,int parent)
{
    int r = 2 * parent + 2;
    if(r < (int) heap.size())
        return r;
    else
        return -1;
}
 

int parent(int child)
{
    int p = (child - 1)/2;
    if(child == 0)
        return -1;
    else
        return p;
}


int ExtractMin(vector<int>& heap)
{
    if ( heap.size() == 0)
    {
        return -1;
    }
    else
        return  heap.front();
}
 


void heapifyup(vector<int>& heap,int in)
{
    if (in >= 0 && parent(in) >= 0 && heap[parent(in)] > heap[in])
    {
        int temp = heap[in];
        heap[in] = heap[parent(in)];
        heap[parent(in)] = temp;
        heapifyup(heap, parent(in));
    }
}
 

void heapifydown(vector<int>& heap,int in)
{
 
    int child = left(heap,in);
    int child1 = right(heap,in);
    if (child >= 0 && child1 >= 0 && heap[child] > heap[child1])  child = child1;
    if (child > 0)
    {
        int temp = heap[in];
        heap[in] = heap[child]; 
        heap[child] = temp;
        heapifydown(heap,child);
    }
}


void DeleteMin(vector<int>& heap)
{
    if ( heap.size() == 0)
    {
        cout<<"Heap is Empty"<<endl;
        return;
    }
    heap[0] =  heap.at( heap.size() - 1);
     heap.pop_back();
    heapifydown(heap, 0);
    cout<<"Element Deleted"<<endl;
}
  

void Insert(vector<int>& heap,int element)
{
     heap.push_back(element);
    heapifyup( heap,heap.size()-1);
}


void DisplayHeap(vector<int>& heap)
{
    vector <int>::iterator pos =  heap.begin();
    cout<<"Heap -->  ";
    while (pos !=  heap.end())
    {
        cout<<*pos<<" ";
        pos++;
    }
    cout<<endl;
}
 



int main()
{
    vector<int> h;
    cout<<"h";
    return 0;
}