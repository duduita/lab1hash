// CPP program to implement hashing with chaining 
#include<bits/stdc++.h> 
using namespace std; 
  
class Hash 
{ 
    int BUCKET;    // No. of buckets 
  
    // Pointer to an array containing buckets 
    list<int> *table; 
public: 
    Hash(int V);  // Constructor 
  
    // inserts a key into hash table 
    int add(int x, int &collisions); 

    // verify if a key exists into hash table
    int containsItem(int x, int &collisions); 
  
    // deletes a key from hash table 
    void remove(int key, int &collisions); 
  
      // deletes a key from hash table 
    int worstcase(); 

    // deletes a key from hash table 
    int size(); 

    // hash function to map values to key 
    int hashFunction(int x) { 
        return (x % BUCKET); 
    } 
  
    void displayHash(); 
}; 
  
Hash::Hash(int b) 
{ 
    this->BUCKET = b; 
    table = new list<int>[BUCKET]; 
} 

Hash h(13);  

int Hash::add(int key, int &collisions) 
{ 
    if(h.containsItem(key, collisions)==0){
      int index = hashFunction(key); 
      table[index].push_front(key);
      return 1; 
    }
    return 0;
    
} 

int Hash::size() 
{ 
    // find the key in the table
    int j; 
    int k=0;
    for(j=0; j<13; j++){
      // find the key in (j)th list
      list <int> :: iterator i; 
      for (i = table[j].begin(); i != table[j].end(); i++)
        k++;
    }
    return k;
} 

int Hash::worstcase() 
{ 
    // find the key in the table
    int j, k;
    int pior=0;
    for(j=0; j<13; j++){
      k = 0;
      // find the key in (j)th list
      list <int> :: iterator i; 
      for (i = table[j].begin(); i != table[j].end(); i++)
        k++;
      if(k>pior)
        pior = k;
    }
    return pior;
} 

int Hash::containsItem(int key, int &collisions) 
{ 
    // get the hash index of key 
    int index = hashFunction(key); 

    // find the key in (inex)th list 
    list <int> :: iterator i; 
    for (i = table[index].begin(); i != table[index].end(); i++) { 
      if (*i == key) 
        return 1;
      collisions++;
    } 
    return 0;  
} 
  
void Hash::remove(int key, int &collisions) 
{ 
  // get the hash index of key 
  int index = hashFunction(key); 
  
  // find the key in (inex)th list 
  list <int> :: iterator i; 
  for (i = table[index].begin(); 
           i != table[index].end(); i++) { 
    if (*i == key) 
      break; 
  } 
  
  // if key is found in hash table, remove it 
  if (i != table[index].end()) 
    table[index].erase(i); 
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
  int a[] = {1,14,2, 27, 27, 28}; 
  int n = sizeof(a)/sizeof(a[0]); 
  int collisions=0;

  // insert the keys into the hash table 
 // 7 is count of buckets in 
               // hash table 
  for (int i = 0; i < n; i++)  
    h.add(a[i], collisions);   
  
  // delete 12 from hash table 
  h.remove(14, collisions); 

  // display the Hash table 
  h.displayHash(); 
  
  cout << "existe o numero 14? " <<
  h.containsItem(14, collisions);
  cout << endl; 

  cout << "size: " <<
  h.size();
  cout << endl; 

  cout << "worst case: " <<
  h.worstcase();

  cout << endl; 
  cout << "collisions: ";
  cout << collisions;

  return 0; 
} 