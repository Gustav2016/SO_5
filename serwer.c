#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/msg.h>

int main()
{
int ID;	
key_t klucz;
char dane[30];

printf("Wprowadz wiadomosc:");
scanf("%s", dane);

if ((klucz = ftok("./serwer",'b')) == -1)
{
	perror("ftok");
	exit(1);
}

if ((ID = msgget(klucz, IPC_CREAT | 0666)) == -1)
{
	perror("msgget");
	exit(1);
}
	
if (msgsnd (ID, NULL, 30, IPC_NOWAIT) == -1)
	perror("msgsnd");

return 0;
}
