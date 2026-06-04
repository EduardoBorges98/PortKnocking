#!/bin/bash

HOST="37.59.174.235"

for PORTA in 13 37 30000 3000
do
    echo "Batendo na porta $PORTA..."
    nc -z -w1 $HOST $PORTA
    sleep 1
done

echo "Acessando o serviço ativado..."
curl -i http://$HOST:1337/
