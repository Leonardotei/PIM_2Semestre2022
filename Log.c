#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <ctype.h>
#include <dos.h>
#include <time.h>

FILE *arqLog;
FILE *arqSession;

void logSis(modulo,action){



    char *dadosDeSession;

    arqLog = fopen("bd/Log/BD_Log.txt", "ab");


    struct tm *p;
    time_t seconds;

    time(&seconds);
    p = localtime(&seconds);
    fprintf(arqLog,"\n %d:%d:%d", p->tm_hour, p->tm_min, p->tm_sec);

    time_t mytime;
    mytime = time(NULL);
    struct tm tm = *localtime(&mytime);
    fprintf(arqLog," | %d/%d/%d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
    fprintf(arqLog," | %s | %s | ",modulo,action);

    arqSession = fopen("bd/Session/BD_Session.pro", "rb");

    // COLETA DADOS DA SESSION
    do
    {

        dadosDeSession = fgetc(arqSession);
        fprintf(arqLog,"%c",dadosDeSession);

    }while (dadosDeSession != EOF);

    fclose(arqSession);
    fclose(arqLog);

}
