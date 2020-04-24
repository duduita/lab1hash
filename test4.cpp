#include <iostream>

using namespace std;


void myFunction(int &collisions) {
  collisions++;
  cout << collisions;

}

int main() {
  int a = 2;
  myFunction(a);
  cout << a;
  
  return 0;
}

// Liam Refsnes
// Jenny Refsnes
// Anja Refsnes
