#include <iostream>
#include <iomanip>

#include "lru.h"

void LRU::adjust(Node* curr)
{
   if (curr == head) { return; }

   Node* prev = curr->prev;
   Node* next = curr->next;
   prev->next = next;

   (next ? next->prev : tail ) = prev;

   curr->next = head;
   curr->prev = NULL;

   head->prev = curr;
   head = curr;
}

void LRU::insert(const Node& node, int loc)
{
   Node* p = (Node*) loc;
   *p = node;
   adjust(p);
}

int LRU::add(const Node& node)
{
   Node* p = &mem[size++];
   *p = node;
   if (!head)
   {
       // first time add
       head = tail = p;
   }
   else
   {
       p->next = head;

       head->prev = p;
       head = p;
   }
   return (int) p;
}

bool LRU::full()
{
   return size == max_size;
}

Node* LRU::exempt()
{
   if (size <= 0) { return NULL; }

   Node* p = tail;
   tail = tail->prev;
   p->prev = NULL;
   if (tail)
   {
       tail->next = NULL;
   }
   else
   {
       head = NULL;
   }
   return p;
}

Node* LRU::read(int loc)
{
   Node* p = (Node*) loc;
   adjust(p);
   return p;
}

void LRU::print()
{
   if (size <= 0) { return; }

   Node *p = head;
   while (1)
   {
       std::cout << *p;
       p = p->next;
       if (!p) { break; }
       std::cout << "->";
   }
   std::cout << std::endl;
}
