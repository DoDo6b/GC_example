#include <type.h>

void mark(Object* object){
	if(object->marked) return;

	object->marked = 1;

	if(object->type == TWIN){
		mark(object->head);
		mark(object->tail);
	}
}

void objectPrint(Object* object){
	switch(object->type){
		case INT:
		printf("%d", object->value);
		break;

		case TWIN:
		printf("(");
		objectPrint(object->head);
		printf(", ");
		objectPrint(object->tail);
		printf(")");
		break;
	}
}