#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>

#ifndef URL
#define URL "https://api.writesonic.com/v2/business/content/chatsonic?engine=premium"
#endif

#ifndef accept
#define accept "application/json"
#endif

#ifndef content
#define content "application/json"
#endif

char *handle_api_key(FILE *stream);
int check_conn(FILE *stream);
const char *_connect(FILE *stream, char *prompt, char *api);
#endif
