#ifndef _STRING_H_
#define _STRING_H_

typedef struct String String;

String *newString(const char *str);
void freeString(String *s);

#endif