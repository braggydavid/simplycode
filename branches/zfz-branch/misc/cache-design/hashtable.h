#ifndef INCLUDED_HASHTABLE
#define INCLUDED_HASHTABLE

#include <list>


class DataUnit
{
private:
   int m_key;
   int m_val;

public:
   DataUnit(int k, int v): m_key(k), m_val(v)
   {}

   int key() const { return m_key; }
   int val() const { return m_val; }
};


enum {MaxLen = 6151};

class HashTable
{
private:
   std::list<DataUnit>* d;
   int size;

   int hash(int key) { return key % size; }
   std::list<DataUnit>::iterator find(int key);

public:
   HashTable(int n=MaxLen)
   {
       d = new std::list<DataUnit>[n];
       size = n;
   }
   ~HashTable() { delete [] d; }

   bool insert(int key, int val);
   bool has(int key);
   void remove(int key);
   int  get(int key);
};


#endif /* INCLUDED_HASHTABLE */
