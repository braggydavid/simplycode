/* [minwindow] Given a word (assume every char is unique in this word) 
   and a string, find the length of the shortest snippet/substring that 
   contains all characters of the word. For example: with word "abc" and 
   the string "a brilliant cat is eating a big cake", the shortest 
   snippet is "big ca", which has length 6. */

#include <string>
#include<vector>
#include <iostream>

using namespace std;

int miniwindow(const string &whole, const string &word);
