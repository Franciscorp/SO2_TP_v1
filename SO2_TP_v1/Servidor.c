#include "EstruturaDados.h"


int _tmain(int argc, TCHAR * argv[]) {

	SYSTEMTIME tempoSistema;
	FILETIME tempoFicheiro;
	ULARGE_INTEGER tempoInicio;

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

	return 0;
}
