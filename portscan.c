#include <stdio.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int meusocket;
    int conecta;

    int porta;
    int inicio = 1;
    int final = 1024;

    char *destino;

    if (argc < 2) {
        printf("Uso: %s IP\n", argv[0]);
        return 1;
    }

    destino = argv[1];

    struct sockaddr_in alvo;

    for (porta = inicio; porta <= final; porta++) {
        meusocket = socket(AF_INET, SOCK_STREAM, 0);

        if (meusocket < 0) {
            printf("Erro ao criar socket\n");
            return 1;
        }

        alvo.sin_family = AF_INET;
        alvo.sin_port = htons(porta);
        alvo.sin_addr.s_addr = inet_addr(destino);

        conecta = connect(meusocket, (struct sockaddr *)&alvo, sizeof alvo);

        if (conecta == 0) {
            printf("Porta %d - status [ABERTA]\n", porta);
        }

        close(meusocket);
    }

    return 0;
}
