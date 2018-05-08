#define _UNICODE//tem haver com outras bibliotecas que vao buscar esta
#define UNICODE//por as duas pelo sim pelo nao
#include <time.h>
#include <windows.h>
#include <tchar.h>
#include <io.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
//#define _CRT_SECURE_NO_WARNINGS



typedef struct {
	int posX;//canto superior esquerdo do qual come�a a posicao
	int posY;
	int larg;//largura
	int alt;//altura
}tamanhoPosicao;

typedef struct {
	int IDNave;
	int speed;//tera varias categorias de velocidade
	int resistencia;//resistencia da nave????? sera?
	int vida;//vida da nave
	int numBombas;//numero de bombas que a nave tem
	int pontos;//quantos pontos tem este jogador
	HANDLE *threadID;//duvidas aqui, nao sei se os jogadores sao com handles
	tamanhoPosicao tamPosNave;


}navesDefensoras;

typedef struct {
	int IDNave;
	int speed;//tera varias categorias de velocidade
	int movimento;//tera varias categorias de movimento
	int vida;//vida/resistencia da nave
	int numBombas;//numero de bombas que a nave tem
	HANDLE *threadID;
	tamanhoPosicao tamPosNave;


}navesInvasoras;

typedef struct {
	int IDPowerup;//identifica qual � o powerup
	int IDTipo;//identifica o tipo do powerup
	int speed;//nao sei se e preciso aqui
	HANDLE *threadPW;//threadsPowerups
	tamanhoPosicao tamPosPowerup;

}powerup;


typedef struct {
	int dimX;//dimensao em x
	int dimY;//dimensao em y
	int nivel;//talvez va funcionar como factor de multiplicacao para os elementos abaixo
	int nNavesInvasoras;
	int speed;//numero de naves com este tipo talvez? ou porcoes
	int tipoComportamento;//numero de naves com este tipo talvez? ou porcoes
	int frequenciaDisparo;
	int numVidasJog;//numero de vidas para cada jogador?
}jogo;

typedef struct {
	int IDOrigem;//nave que o dispara caso seja defensora, senao esta a 0
	int posX;
	int posY;
	TCHAR direcao;//N para Norte S para Sul

}tiros;

typedef struct {
	int IDOrigem;//nave que o dispara caso seja defensora, senao esta a 0
	int tipoBomba;//identifica o tipo de bomba que e
	int posX;
	int posY;
	TCHAR direcao;//N para Norte S para Sul


}bombas;


//identificador de id's
//0 - Vazio
//1 - Defensor
//2 - Invasor
//3 - Powerup
//4 - tiro
//5 - bomba

typedef struct {
	int ID;//identifica quem est� nesta posicao
	int numID;//identifica o id dentro do id. ex: inimigo com o id 233
}posCampo;

//o campo tera sempre este tamanho
posCampo campo[800][600];

//threads para o jogo
//threads para cada jogador
//threads tiros
//threads bombas
//thread geracaoPowerup e movimentoPowerup?
//threads navesInvasoras talvez baseada em cada tipo?
//thread temporizacao

//variaveis globais


