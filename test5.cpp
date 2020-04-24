// CPP program to implement hashing with chaining 
#include<bits/stdc++.h> 
using namespace std; 

class Hash 
{ 
    int BUCKET;    // No. of buckets 
  
    // Pointer to an array containing buckets 
    list<std::string> *table; 
public: 
    Hash(int V);  // Constructor 
  
    // inserts a key into hash table 
    int add(std::string x, int &collisions); 
  
    // hash function to map values to key 
    int hashFunction(std::string x) { 
        int b;
        int count = 0;
        b = x.length();
        for(int i=0; i<b; i++)
          count += int(x[i]); 
        return (count % BUCKET); 
    } 
  
    void displayHash(); 
}; 
  
Hash::Hash(int b) 
{ 
    this->BUCKET = b; 
    table = new list<std::string>[BUCKET]; 
} 

Hash h(13);  

int Hash::add(std::string key, int &collisions) 
{ 
    if(1==1){
      int index = hashFunction(key); 
      table[index].push_front(key);
      return 1; 
    }
    return 0;
    
} 

// function to display hash table 
void Hash::displayHash() { 
  for (int i = 0; i < BUCKET; i++) { 
    cout << i; 
    for (auto x : table[i]) 
      cout << " --> " << x; 
    cout << endl; 
  } 
} 

// Driver program  
int main() 
{ 
  // array that contains keys to be mapped 
  std::string a[] = {"sarah","du"}; 
  int n = sizeof(a)/sizeof(a[0]); 
  int collisions=0;

  for (int i = 0; i < n; i++)  
    h.add(a[i], collisions);  

  // display the Hash table 
  h.displayHash(); 


  return 0; 
} 