#include <iostream>
 
using namespace std;
 
int main() {
 
    int falta, p1, p2;
    
    cin >> falta;
    
    cin >> p1 >> p2;
    
    if(p1+p2 > falta) cout << "Deixa para amanha!\n";
    else cout << "Farei hoje!\n";
 
    return 0;
}
