#include <iostream>
#include <string>
#include "Refei��o.h"
#include "aluno_staff.h"
#include "Mesa.h"
#include "time.h"
using namespace std;
//flav


void centerstring(const char* s) // para escrever texto no centro -> from born2c0de https://www.dreamincode.net/forums/topic/13749-center-text-with-cout/
{
	int l = strlen(s);
	int pos = (int)((80 - l) / 2);
	for (int i = 0; i < pos; i++) {
		cout << " ";
	}
	cout << s;
}

void inicializacao() {//Fase inicial, se n�o houver dados gardados
	refeicao* refeicao=new struct refeicao; // criar refei��o
	//alterar_refeicao(refeicao);
	int tam = rand()%30+20; //tamanho da cantina
	tam = rand() % 30 + 20;//http://www.cplusplus.com/forum/general/114978/ -> AeonFlux1212 �"o rand conv�m ser acionado duas vezes para ter a certeza que gera um n�mero aleat�rio 
	int n_mesa = 0;//n�mero de mesas
	int rnd=random_mesa(); //n cadeiras por mesa
	rnd = random_mesa();//http://www.cplusplus.com/forum/general/114978/ -> AeonFlux1212
	int tam_ant=0;//se tam <=1
	mesa *mesa = new struct mesa[20];//criar a vari�vel struct mesa com o nome "mesa"
	while (tam != 0) {
		if(tam <= 1) {
			inserir_mesas(mesa, n_mesa, 0);
			n_mesa -= 1;
			tam = tam_ant;
		}
		else {
			n_mesa += 1;
			inserir_mesas(mesa, n_mesa, rnd);
			tam_ant = tam;
			tam = tam - rnd;
			rnd = random_mesa();
		}
	}
	//mostrar_mesas(mesa, n_mesa);
	//nova pessoa(aluno/staff) nova fila
	
	int tam_pessoa = rand()%50+30; //1� entrega, fila com o m�ximo de 50 pessoas
	int pos_especial = 0; //para os alunos especiais
	f_espera* f_espera = new struct f_espera[51];
	pessoa*pessoa = new struct pessoa[51];
	for (int i = 1; i <= tam_pessoa; i++) {
		criar_pessoa(pessoa, i);
	};
	for (int i = 1; i <= tam_pessoa; i++) {
		mostrar_pessoa(pessoa, i);
	};
	//verificar_repeticao(pessoa, tam_pessoa);
	for (int i = 0; i <= tam_pessoa; i++) { //primeiro inserir, depois ordenar
		adicionar_fila_espera(f_espera, i, pessoa);
	}
}
void extrair(){

}
void guardar() {

}
void opcoes() {

}
void menu(){
	centerstring("Cantina EDA");
}
int main() {
	srand(time(NULL));
	//inicializacao();
	//extrair();
	return 0;
}