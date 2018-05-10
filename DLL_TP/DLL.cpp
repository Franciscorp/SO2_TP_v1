#include <windows.h>
#include "DLL.h"
//Para verificar ao carregar a dll que a aplicação irá ocupar mais memória
char ponteiro[40960];
//Definição da variável global
int nDLL = 1234;
//Exportar a função para ser utilizada fora da DLL
int UmaString(void) {
	TCHAR str[TAM];
	_tprintf(TEXT("Dentro da Dll\nIntroduza uma frase:"));
	_fgetts(str, TAM, stdin);
	if (_tcslen(str) > 1) //Introduzir mais caracteres do que apenas <enter>
		return 1;
	else
		return 0;
}

int soma(int x, int y){
	return x + y;
}

typedef struct {
	int idJog;
	TCHAR movimento;//inteiro ou tchar?
}mensagem;


	HANDLE hMap;
	LARGE_INTEGER t;
	//t.QuadPart = 1 * sizeof(mensagem);
	mensagem *msg;


	int escreveMensagensMemPart() {
		hMap = CreateFileMapping(INVALID_HANDLE_VALUE, NULL, PAGE_READWRITE, sizeof(mensagem), NULL, TEXT("bufferMensagens"));

		if (hMap == NULL) {
			_tprintf(TEXT("Erro no FileMapping\n"));
			return -1;
		}
		msg = (mensagem *)MapViewOfFile(hMap, FILE_MAP_WRITE, 0, 0, 10 * sizeof(mensagem));

	}

