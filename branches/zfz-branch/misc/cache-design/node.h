#ifndef INCLUDED_NODE
#define INCLUDED_NODE

#include <ostream>

typedef struct Node
{
   int key;
   int val;
   Node* prev;
   Node* next;

   Node(int k=0, int v=0) : key(k), val(v), prev(0), next(0)
   {}
   ~Node() { key = val = 0; prev = next = 0; }

   const Node& operator=(const Node& node)
   {
       if (this != &node)
       {
           key = node.key;
           val = node.val;
       }
       return *this;
   }

   friend std::ostream& operator<<(std::ostream& o, const Node& node)
   {
       o << "[" << node.getkey() << ", " << node.getval() << "]";
       return o;
   }
   void setkey(int k)  { key = k;    }
   void setval(int v)  { val = v;    }
   int  getkey() const { return key; }
   int  getval() const { return val; }
} Node;


#endif /* INCLUDED_NODE */
