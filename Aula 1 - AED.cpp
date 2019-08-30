#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <cstdlib>

using namespace std;

typedef struct lista {
	char *nome;
	int telefone;
	struct lista *next;
} Dados;

void readFile();
void execStruct();
void outro(int argc, char** argv);
void commandLine(int argc, char** argv);

Dados loadDados(char* nome, int telefone, lista* next);
void printDado(Dados dado);

int main(int argc, char** argv) {
	
	//readFile();
	//execStruct();
	//outro(argc, argv);	
	commandLine(argc, argv);
	
	
	system("EXIT");
}

void commandLine(int argc, char** argv){
	if(argc < 3){
		system("EXIT");
	}
	
	Dados a, b;
	
	a = loadDados(argv[1], atoi(argv[2]), 0);
	
	if(argc >= 5){
		b = loadDados(argv[3], atoi(argv[4]), &a);
	}else{
		b = loadDados("", 0, &a);
	}
	
	printDado(b);
	printDado(*b.next);
}

void outro(int argc, char** argv){
	
	char t[] = "test";
	
	int* test = &argc;
	
	printf("O numero e %d\n\n", argc);
	printf("O numero e %d\n\n", &argc);
	printf("O numero e %d\n\n", *test);
	
	for(int i = 0; i < argc; i++){
		printf("O numero e %d\n\n", i);
		printf(argv[i]);
	}
}

void execStruct(){
	Dados a = loadDados("test", 12345, 0);
	
	Dados b = loadDados("anderson", 12345, &a);
	
	Dados c = loadDados("fndjghsjkd", 12345, &b);
	
	Dados d = loadDados("nksdhfjks", 12345, &c);
	
	printDado(a);
	
	printDado(b);
	
	printDado(c);
	
	printDado(d);
	
	printDado(*b.next);
}

void readFile(){
	ifstream fs;
	
	fs.open ("test.txt", std::fstream::in | std::fstream::out | std::fstream::app);
	
	//fs << "alguma coisa";
	
	char x;
	
	while(fs >> x){
		printf("%c", x);
	}
	
	fs.close();
}

Dados loadDados(char* nome, int telefone, lista* next){
	Dados a;
	a.nome = nome;
	a.telefone = telefone;
	a.next = next;
	return a;
}

void printDado(Dados dado){
	printf("\n");
	printf("O nome e %s\n", dado.nome);
	printf("O telefone e %d\n", dado.telefone);
	printf("O next e %d\n", dado.next);
	printf("\n");
}
