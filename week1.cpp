#include <iostream>
#include <vector>
#include <cstdint> // For uintptr_t
class Node {
public:
int data;
Node* link;
Node (int data, Node* link = nullptr) {
this->data = data;
this->link = link;
}
};
class DLLNode {
public:
int data;
DLLNode* prev;
DLLNode* next;
DLLNode (int data, DLLNode* prev, DLLNode* next) {
this->data = data;
this->prev = prev;
this->next = next;
};
};
DLLNode* create_list (std::vector<int> const &arr) {
DLLNode* head = nullptr;
for (int x : arr) {
head = new DLLNode (x, nullptr, head);
if (head->next) head->next->prev = head;
}
return head;
}
void print_list (DLLNode* head) {
while (head) {
std::cout << head->data << " -> ";
head = head->next;
}
std::cout << "nullptr\n";
}
Node* XOR (Node* x, Node* y) {
uintptr_t a = (uintptr_t) (x);
uintptr_t b = (uintptr_t) (y);
return (Node*) (a ^ b);
}
void print_list (Node* const head) {
Node* current = head;
Node* prev = nullptr;
Node *next;
while (current) {
std::cout << current->data << " —> ";
next = XOR (prev, current->link);
prev = current;
current = next;
}
std::cout << "nullptr\n";
}
Node* insert (Node* head, int const data) {
Node* new_node = new Node(data, XOR (head, nullptr));
if (head)
head->link = XOR(new_node, XOR(head->link, nullptr));
return new_node;
}
Node* create_list (DLLNode* head) {
Node* list = nullptr;
while (head->next)
head = head->next;
while (head) {
list = insert (list, head->data);
DLLNode* temp = head;
head = head->prev;
delete temp;
}
return list;
}
int main() {
DLLNode* dhead = create_list ({5, 4, 3, 2, 1});
std::cout << "Doubly Linked List created as: ";
print_list (dhead);
Node* head = create_list (dhead);
std::cout << "XOR list created from Doubly Linked List: ";
print_list (head);
return 0;
}
