#include "EstruturaDados.h"


int _tmain(int argc, TCHAR * argv[]) {

	HANDLE temporizador = NULL;
	DWORD WINAPI ThreadTemporizador(LPVOID param);

	SYSTEMTIME tempoSistema;
	FILETIME tempoFicheiro;
	ULARGE_INTEGER tempoInicio;

	int opcao;

	#ifdef UNICODE
		_setmode(_fileno(stdin), _O_WTEXT);
		_setmode(_fileno(stdout), _O_WTEXT);
	#endif

	//arranja o tempo do sistema
	//converte o para tempo de ficheiro em 2 partes de 32 bits

	GetLocalTime(&tempoSistema);//tempo do sistema em horas minutos e segundos
	SystemTimeToFileTime(&tempoSistema, &tempoFicheiro); //hightime lowdatetime filetime 32bits + 32bits
	tempoInicio.HighPart = tempoFicheiro.dwHighDateTime; //ularge_integer: 64bots
	tempoInicio.LowPart = tempoFicheiro.dwLowDateTime;

	system("cls");
	_tprintf(TEXT("Bem vindo ao Space Invaders!\n"));

	_tprintf(TEXT("\nTempo do Sistema:H = %02d M = %02d S = %02d ms = %02d \n"), tempoSistema.wHour, tempoSistema.wMinute, tempoSistema.wSecond, tempoSistema.wMilliseconds);
	
	opcao = menu();
	_tprintf(TEXT("Valor da op�ao = %d"), opcao);
	if (opcao == 1) {
		//iniciaDados();//falta verificacao de ja foram configurados ou nao
	}




	//temporizador = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)ThreadTemporizador, NULL, 0, &temporizador);
	//WaitForSingleObject(temporizador, INFINITE);
	_tprintf(TEXT("\nVou libertar a thread, xau\n"));
	//free(temporizador); era preciso caso fosse um ponteiro
	return 0;
}

void iniciaDados() {

	
}

int menu() {
	int opcao;
	int retorno = 0;
	_tprintf(TEXT("\nMenu Principal\nOp��es:\n 1 - Configurar Campo\n2 - Jogar Single Player\n3 - Jogar Multiplayer\n4 - Sair\n"));
	_tprintf(TEXT("Op��o: "));
	do {
		retorno = _tscanf_s(TEXT("%d"), &opcao);
		if (opcao < 1 || opcao > 4 || retorno != 1) {
			_tprintf(TEXT("\nValor Invalido, insira novamente: "));
			fseek(stdin, 0, SEEK_END);//hacks btw xD
			//falta resolver o decimal
		}
	} while (opcao < 1 || opcao > 4);

	return opcao;

}


DWORD WINAPI ThreadTemporizador(LPVOID param) {
	time_t tempo;
	int i = 0, random;

	srand((int)time(&tempo));
	_tprintf(TEXT("\nThread de 20 a 30\n"));
	while (i < 10) {
		random = (rand() % 10) + 20;
		random = random * 1000;
		Sleep(random);
		_tprintf(TEXT("\nCriei um powerup\nTempo = %d\n"), random);
		i++;
	}
	_tprintf(TEXT("\nAcabei a thread, vou encerrar\n"));
	return 0;

}