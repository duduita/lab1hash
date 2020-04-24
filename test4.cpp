#include <iostream>

using namespace std;


void myFunction(int &collisions) {
  collisions++;
  cout << collisions;

}

int main() {
    string a = "sarah";
    cout << a;
    cout << endl;
    int b;
    int count = 0;
    b = a.length();
    for(int i=0; i<b; i++){
        count += int(a[i]); 
    }
    cout << count;


  return 0;
}

// Liam Refsnes
// Jenny Refsnes
// Anja Refsnes
