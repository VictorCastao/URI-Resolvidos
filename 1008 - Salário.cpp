#include <iostream>

using namespace std;

int main(){
	int num, horas;
	double valor;
	cin >> num;
	cin >> horas;
	cin >> valor;
	cout << "NUMBER = " << num << endl;
	cout.precision(2);
	cout.setf(ios::fixed);
	cout << "SALARY = U$ " << horas*valor << endl;
	return 0;
}
