#include <iostream>
#include <vector>
#include <tuple>

using std::vector;
using std::tuple;
using std::make_tuple;
using std::pair;
using std::make_pair;
using std::get;

// Node for Linked List
class Node {
    int data;
    int weight;
    Node* next;

public:
    Node(int data, Node* next = nullptr, int weight = 1) {
        this->data = data;
        this->weight = weight;
        this->next = next;
    }

    int get_data() const { return this->data; }
    int get_weight() const { return this->weight; }
    Node* get_next() const { return this->next; }
    void set_next(Node* next) { this->next = next; }
};

// Nodes are maintained in a sorted order
class List {
    Node* head;

public:
    List () { this->head = nullptr; }
    Node* get_head() const { return this->head; }
    void push(int data,int weight);
};

void List::push(int data, int weight = 1) {
    if (this->head == nullptr) {
        this->head = new Node(data, nullptr, weight);
        return;
    }

    if (this->head->get_data() > data) {
        this->head = new Node(data, this->head, weight);
        return;
    }

    Node* current = this->head;

    while (current->get_next() && current->get_next()->get_data() < data)
        current = current->get_next();

    Node* temp = new Node(data, current->get_next(), weight);
    current->set_next(temp);
}

// Min Heap
class MinHeap {
    vector< tuple<int, int, int> > heap;

    int PARENT (int i) const { return (i - 1) >> 1; }
    int LEFT (int i) const { return (i << 1) + 1; }
    int RIGHT (int i) const { return (i << 1) + 2; }

    void heapify_down (int index) {
        int smallest = index;

        if ( LEFT(index) < size() && get<2>(heap[ LEFT(index) ] ) < get<2>( heap[ smallest ] ))
            smallest = LEFT(index);

        if ( RIGHT(index) < size() && get<2>( heap[ RIGHT(index) ] ) < get<2>( heap[ smallest ] ))
            smallest = RIGHT(index);

        if (smallest != index) {
            std::swap( heap[ index ], heap[ smallest ]);
            heapify_down(smallest);
        }
    }

    void heapify_up (int index) {
        if ( index && get<2>( heap[ this->PARENT(index) ] ) > get<2>( heap[ index ] )) {
            std::swap (heap[ index ], heap [ PARENT(index) ]);
            heapify_up( PARENT(index) );
        }
    }
public:
    bool empty () const { return heap.size() == 0; }
    int size () const { return (int)heap.size(); }

    void push(int src, int dest, int distance) {
        this->heap.push_back( make_tuple(src, dest, distance) );
        heapify_up(this->size() - 1);
    }

    void pop() {
        try {
            if ( this->size() < 1)
                throw std::out_of_range("Heap UnderFlow");

            this->heap[0] = heap.back();
            this->heap.pop_back();

            this->heapify_down(0);
        } catch (const std::out_of_range &error) {
            std::cout << "\n" << error.what();
        }
    }

    tuple<int, int, int> top () const {
        try {
            if (this->size() < 1) 
                throw std::out_of_range("Heap UnderFlow");

            return heap[0];
        } catch (const std::out_of_range &error) {
            std::cout << "\n" << error.what();
            return make_tuple(INT_MAX, INT_MAX, INT_MAX);
        }
    }

    void modify(int key, int new_distance) {
        for (int i = 0; i < this->size(); ++i) {
            if (get<1>( heap[i] ) == key) {
                get<2>( heap[i] ) = new_distance;
                heapify_up(i);
                return;
            }
        }
    }

    bool exists(int key) {
        for (auto x : this->heap) 
            if (get<1>(x) == key)
                return true;

        return false;
    }
};

class Graph {
    vector<List> adjacency_list;
public:
    Graph(size_t number_of_nodes) { this->adjacency_list.resize(number_of_nodes); }
    void add_directed(int start, int end, int weight);    
    void add_undirected(int start, int end, int weight);
    void print_list() const;
    size_t size() const { return this->adjacency_list.size(); }
    vector<pair<int, int>> adjacent (int i) const;
    void DFS();
    void DFSUtil (int v, vector<bool> &visited);
};

void Graph::add_directed(int start, int end, int weight = 1) {
    adjacency_list[start].push(end, weight);
}

void Graph::add_undirected(int start, int end, int weight = 1) {
    this->add_directed(start, end, weight);
    this->add_directed(end, start, weight);
}

void Graph::print_list () const {
    for (size_t i = 0; i < this->adjacency_list.size(); ++i) {
        std::cout << (char)(i + 97) << ": ";
        
        Node* current = this->adjacency_list[i].get_head();

        while (current) {
            std::cout << (char)(current->get_data() + 97)<< " ";
            current = current->get_next();
        }

        std::cout << "\n";
    }
}

vector<pair<int, int>> Graph::adjacent (int i) const {
    Node* current = this->adjacency_list[i].get_head();
    vector<pair<int, int>> result;
    
    while (current) {
        result.push_back( make_pair(current->get_data(), current->get_weight()) );
        current = current->get_next();
    }

    return result;
}

void Graph::DFS() {
    vector<bool> visited (this->size(), false);

    int count = 0;
    for (size_t i = 0; i < this->size(); ++i) {
        if (visited[i] == false) {
            this->DFSUtil(i, visited);
            count += 1;
            std::cout << "\n";
        }
    }

    std::cout << "Number of Connected Components are: " << count << "\n";
}

void Graph::DFSUtil(int v, vector<bool> &visited)
{
    visited[v] = true;
    std::cout << v << " ";
 
    vector< pair<int, int> > connected = this->adjacent(v);

    for (auto node : connected) {
        if (visited[node.first] == false) 
            DFSUtil(node.first, visited);
    }
}

void dijkstra( Graph const &graph, int start, int end) {
    int size = graph.size();

    vector<int> distances(size, INT_MAX);
    distances[start] = 0;
    MinHeap heap;

    // Creating the Min Heap
    for (int i = 0; i < size; ++i)
        heap.push(start, i, distances[i]);

    while (heap.empty() == false) {
        int smallest = get<1>( heap.top() );
        heap.pop();

        // Getting all adjacent nodes to nearest
        vector<pair<int, int>> connected = graph.adjacent(smallest);

        for ( pair<int, int> node : connected ) {
            int data = node.first;

            if (
                heap.exists(data) &&
                distances[ smallest ] != INT_MAX && 
                node.second + distances[ smallest ] < distances[ data ]
            ) {
                distances[ data ] = distances[ smallest ] + node.second;
                heap.modify(data, distances[ data ]);
            }
        }
    }

    if (distances[end] == INT_MAX) {
        std::cout << "No mutual friends between " << start << " and " << end << "\n";
        return;
    } 

    std::cout << "Minimum number of friends between " << start << " and " << end << " is: ";
    std::cout << distances[end] - 1 << "\n";
}

void introverted(Graph const &graph) {
    std::cout << "Part 1\n";
    for (size_t i = 0; i < graph.size(); ++i) {
        vector< pair<int, int> > friends = graph.adjacent(i);

        if (friends.size() <= 1)
            std::cout << i << " is an introvert\n";
    }
}

int main() {
    Graph LabEval(9);

    LabEval.add_undirected(0, 1); // One Group (Both are introverted)

    LabEval.add_undirected(2, 3);
    LabEval.add_undirected(3, 4);
    LabEval.add_undirected(2, 8); // Second Group (4 and 8 are introverted)

    LabEval.add_undirected(5, 6);
    LabEval.add_undirected(6, 7);
    LabEval.add_undirected(5, 7); // Third Group (None are introverted)

    // Part 1
    introverted(LabEval);

    std::cout << "\nPart 2: Connected Components are:\n";
    LabEval.DFS();
    std::cout << "\nPart 3\n";

    dijkstra(LabEval, 4, 8);
    dijkstra(LabEval, 0, 8); // No connection

    return 0;
}

