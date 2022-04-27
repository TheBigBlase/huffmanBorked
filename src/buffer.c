#include "triAlphabet.h"
#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct Buffer{
	char* path;
	short size;
}Buffer;

void writeToBuff(Buffer * buf, char* path){
	buf->size = strlen(path) + buf->size;
	buf->path = realloc(buf->path, buf->size + 1);
	buf->path = strcat(buf->path, path);
}
