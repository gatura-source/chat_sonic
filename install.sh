#/bin/bash
gcc -o cmdgen 0-main.c cmdgen.h connection.c handle_api_key.c -ljansson

chmod +r output.json
