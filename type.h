#ifndef TYPE_H
#define TYPE_H

#include <stdio.h>

typedef enum{
	INT,
	TWIN
}ObjectType;

typedef struct sObject{
	ObjectType type;
	unsigned char marked;

	struct sObject* next;

	union{
		int value;

		struct{
			struct sObject* head;
			struct sObject* tail;
		};
	};
}Object;

void mark(Object* object);

void objectPrint(Object* object);

#endif