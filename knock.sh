#!/bin/bash

for i in {1..24}
do
    HOST="172.16.1.$i"

    echo "Testando host $HOST..."

    for PORTA in 13 37 30000 3000
    do
        nc -z -w1 $HOST $PORTA 2>/dev/null
        sleep 1
    done

    RESPOSTA=$(curl -s --connect-timeout 3 http://$HOST:1337/)

    if echo "$RESPOSTA" | grep -q "RicardoCry"
    then
        echo
        echo "HOST INFECTADO ENCONTRADO!"
        echo "IP: $HOST"
        echo
        echo "$RESPOSTA"
        exit 0
    fi
done

echo "Nenhum host infectado encontrado."