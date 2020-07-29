#include <iostream>
#include <deque>

using namespace std;

int main()
{
    deque <int> territorio;
    
    int total = 0, soma = 0, i, numeros, temp;
    
    cin >> numeros;
    
    for(i=0; i<numeros; i++){
        cin >> temp;
        territorio.push_back(temp);
        total += temp;
    }
    
    for(i=0; i<numeros; i++){
        soma += territorio[i];
        total -= territorio[i];
        if (soma == total){
            cout << i+1 << endl;
            break;
        }
    }
    
    return 0;
}

