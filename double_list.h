
#ifndef DOUBLE_LIST_H
#define DOUBLE_LIST_H

#include <stdio.h>
#include <stdlib.h>

// Data types 

typedef unsigned int uint32;
typedef signed int sint32;
typedef unsigned short uint16;
typedef signed short sint16;
typedef unsigned char uint8;

// struct of double linked list

typedef struct Node {
uint32 data;
struct Node *LeftPointer;
struct Node *RightPointer;

};

//prototypes of functions 

void Inset_Data_At_Beginning(struct Node **List,uint32 data);
void Inset_Data_At_End(struct Node *List,uint32 data);
void Inset_Data_After(struct Node *List,uint32 data,uint32 position);
void Delete_Data_At_Beginning(struct Node **List);
void Delete_Data_At_End(struct Node *List);
void Delete_Data_After(struct Node *List,uint32 position);
void Display_Data_Forward(struct Node *List);
void Display_Data_Reverse(struct Node *List);
void Inset_Data_Before(struct Node *List,uint32 data,uint32 position);


#endif
