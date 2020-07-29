#include <iostream>
#include <deque>

using namespace std;

string verificar_horario(int hora_atendimento, int chegada, int limite){
	if(hora_atendimento < chegada) return "VAZIO";
	else if(hora_atendimento > limite) return "CRITICO";
	else return "OK";
}

struct paciente{
	int horario_chegou;
	int horario_limite;
};

int main(){
	int numero, i, hora_chegou, minuto_chegou, limite, criticos = 0, atendimento;

	while(cin >> numero){
		criticos = 0;
		paciente temp;
		deque <paciente> lista;
		for(i=0; i<numero; i++){
			cin >> hora_chegou >> minuto_chegou >> limite;
			temp.horario_chegou = (hora_chegou * 60) + minuto_chegou;
			temp.horario_limite = temp.horario_chegou + limite;
			lista.push_back(temp);
		}

		atendimento = 420;
		string resultado;

		while(!lista.empty()){
			resultado = verificar_horario(atendimento, lista[0].horario_chegou, lista[0].horario_limite);
			if(resultado == "CRITICO"){
				criticos++;
				lista.pop_front();
			}
			else if(resultado == "OK") lista.pop_front();
			atendimento += 30;
		}

		cout << criticos << endl;	

	}
	return 0;
}
