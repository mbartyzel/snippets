#include <stdio.h>

#define IS_NULL(value) (NULL == (value))

void readISNULL(char *src, char *dest, char *buff) {
	if (IS_NULL(src) || IS_NULL(dest) || IS_NULL(buff))
		puts("Error IS_NULL");
	else
		puts("IS_NULL all good");
}

#define WRONG_INIT (NULL == src && NULL == dest)
#define IS_READING_LOCKED (NULL == buff)

void readMACRO(char *src, char *dest, char *buff) {
	if (WRONG_INIT && IS_READING_LOCKED)
		puts("Error MACRO");
	else
		puts("MACRO all good");
}

int main() {
	char *src, *dest, *buff;

	puts("All NULL:");
	readISNULL(src, dest, buff);
	readMACRO(src, dest, buff);

	puts("");
	puts("dest and buff NULL:");
	src = "Something";
	readISNULL(src, dest, buff);
	readMACRO(src, dest, buff);

	puts("");
	puts("Only buff NULL:");
	dest = "Something else";
	readISNULL(src, dest, buff);
	readMACRO(src, dest, buff);

	puts("");
	puts("All set:");
	buff = "Whatever";
	readISNULL(src, dest, buff);
	readMACRO(src, dest, buff);
}
