#include<bits/stdc++.h>
#include<iostream> 
#include<list> 
#include<iterator> 
#include<unordered_map>

using namespace std; 
  
class LRU 
{ 
    // Store Key
    list<int> qu; 
  
    // Store Ref of the Key
    unordered_map<int, list<int>::iterator> ad; 
    int csize; //maximum capacity of cache 
  
public: 
    LRU(int); 
    void refer(int); 
    void display(); 
}; 
  
LRU::LRU(int n) 
{ 
    csize = n; 
} 
  
void LRU::refer(int x) 
{ 
    // Not present in cache 
    if (ad.find(x) == ad.end()) 
    { 
        // cache is full 
        if (qu.size() == csize) 
        { 
            //Remove LRU element 
            int last = qu.back(); 
            qu.pop_back(); 
            ad.erase(last); 
        } 
    } 
  
    else
        qu.erase(ad[x]); 
  
    // Ref Update
    qu.push_front(x); 
    ad[x] = qu.begin(); 
} 
  
// Cache Display
void LRU::display() 
{ 
    for (auto it = qu.begin();it != qu.end();it++) 
        cout << (*it) << " "; 
  
    cout << endl; 
} 
  
// Test
int main() 
{ 
    LRU ca(3); 
  
    ca.refer(1); 
    ca.refer(2); 
    ca.refer(3); 
    ca.refer(4); 
    ca.refer(1); 
    ca.refer(2);
    ca.refer(5);
    ca.refer(1);
    ca.refer(2);
    ca.refer(3);
    ca.refer(4);
    ca.refer(5); 
    ca.display(); 
  
    return 0; 
} 
