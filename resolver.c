#include <stdio.h>
#include <netdb.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Uso: %s dominio.com\n", argv[0]);
        return 1;
    }

    struct hostent *alvo = gethostbyname(argv[1]);

    if (alvo == NULL) {
        printf("Erro ao resolver o host.\n");
        return 1;
    }

    printf("IP: %s\n", inet_ntoa(*(struct in_addr *)alvo->h_addr));

    return 0;
}
