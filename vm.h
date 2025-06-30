#ifndef VM_H
#define VM_H

#include "type.h"
#include <stdlib.h>

#define STACK_MAX_SIZE 256
#define THRESHOLD 8

typedef struct{
	Object* stack[STACK_MAX_SIZE];
	int stackSize;

	Object* top;

	int numObjects;

	int maxObjects;
}VM;


void push(VM* vm, Object* value);

Object* pop(VM* vm);


VM* newVM();


void markAll(VM* vm);

void markspeep(VM* vm);


void gc(VM* vm);


Object* newObject(VM* vm, ObjectType type);

void pushInt(VM* vm, int intValue);

Object* pushTwin(VM* vm);


void freeVM(VM *vm);

#endif