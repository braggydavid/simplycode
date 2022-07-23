#include "hashtable.h"

using namespace std;

std::list<DataUnit>::iterator HashTable::find(int key)
{
   int h = hash(key);
   list<DataUnit>& l = d[h];
   for (list<DataUnit>::iterator it = l.begin();
        it != l.end(); ++it)
   {
       if (it->key() == key)
       {
           return it;
       }
   }
   return l.end();
}

bool HashTable::insert(int key, int val)
{
   int h = hash(key);
   list<DataUnit>::iterator it = find(key);
   if (it != d[h].end()) { return false; }

   d[h].push_back(DataUnit(key, val));
   return true;
}

bool HashTable::has(int key)
{
   int h = hash(key);
   return find(key) != d[h].end();
}

void HashTable::remove(int key)
{
   int h = hash(key);
   list<DataUnit>::iterator it = find(key);
   if (it != d[h].end()) { d[h].erase(it); }
}

int HashTable::get(int key)
{
   int h = hash(key);
   list<DataUnit>::iterator it = find(key);
   if (it != d[h].end()) { return it->val(); }

   throw "key doesnt exists";
}
