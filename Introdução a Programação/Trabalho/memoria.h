#ifndef MEMORIA_H
#define MEMORIA_H

void exibirMemoria();
int alocarFirstFit();
int alocarBestFit();
int alocarWorstFit();
int liberarProcesso();
void compactarMemoria();
void relatorioMemoria();
void relatorioEficiencia();
int maiorBlocoLivre();
int contarFragmentos();
int buscarPID();

#endif
