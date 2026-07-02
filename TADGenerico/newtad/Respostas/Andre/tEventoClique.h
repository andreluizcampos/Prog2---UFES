#ifndef _EVENTOCLIQUE_H
#define _EVENTOCLIQUE_H

typedef struct EventoClique tEventoCLique;

#include"tAmbiente.h"

tEventoCLique* CriaCique (char *caracateres);
 void LiberaEventoClique( void *eve);

 void ProcessaEventoCique( tAmbiente a, char c, void *eve);

 int IdentificaEventoClique( char c, void *eve);

#endif