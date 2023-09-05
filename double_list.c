#include "double_list.h"
void Inset_Data_At_Beginning(struct Node **List,uint32 data){

    struct Node *temp=NULL;
    temp=(struct Node *)malloc(sizeof(struct Node));
    if(NULL != temp){
      temp->data=data;
      if(NULL == *List){
        temp->LeftPointer=NULL;
        temp->RightPointer=NULL;
        (*List)=temp;
      }
      else{

        temp->RightPointer=(*List);
        temp->LeftPointer=NULL;
        (*List)->LeftPointer=temp;
        (*List)=temp;
      }

    }
    else{
         printf("can not allocate temp \n");
    }

}


void Inset_Data_At_End(struct Node *List,uint32 data){

    if(NULL == List){
        printf("Use the fun Insert_At_Beginning \n");
    }
    else{
        struct Node * temp = NULL;
        struct Node * counterPtr = NULL;
        temp=(struct Node *)malloc(sizeof(struct Node));
         if(NULL != temp){
         temp->data=data;
         temp->RightPointer=NULL;
         counterPtr=List;
         while(counterPtr->RightPointer != NULL){
            counterPtr=counterPtr->RightPointer;
         }
         temp->LeftPointer=counterPtr;
         counterPtr->RightPointer=temp;

    }
    else{
         printf("can not allocate temp \n");
    }

}

}

void Inset_Data_After(struct Node *List,uint32 data,uint32 position){

     if(NULL == List){
        printf("Use the fun Insert_At_Beginning \n");
    }
    else{

        struct Node *temp=NULL;
        struct Node *nodeposition=NULL;
        struct Node *nodeNext=NULL;
        nodeposition = List;
        while(1 != position){
            nodeposition=nodeposition->RightPointer;
            position--;
        }
        nodeNext=nodeposition->RightPointer;
        temp=(struct Node *)malloc(sizeof(struct Node));
        if(NULL != temp){
            temp->data=data;
            if(nodeNext == NULL){
                nodeposition->RightPointer=temp;
                temp->LeftPointer=nodeposition;
                temp->RightPointer=NULL;
            }
            else{
                nodeposition->RightPointer=temp;
                nodeNext->LeftPointer=temp;
                temp->LeftPointer=nodeposition;
                temp->RightPointer=nodeNext;

            }
        }
        else{
           printf("can not allocate temp \n");
        }
    }

}


void Delete_Data_At_Beginning(struct Node **List){

     if(NULL == *List){
        printf("The list is empty \n");
     }
     else{

    *List=(*List)->RightPointer;
    (*List)->LeftPointer=NULL;
     }
}


void Delete_Data_At_End(struct Node *List){

     struct Node *temp=NULL;
     temp=List;
     if(temp->RightPointer == NULL){
        printf("use fun delete at beginning \n");
     }
     else{
        while(temp->RightPointer !=NULL){
            temp=temp->RightPointer;
        }
        temp->LeftPointer->RightPointer=NULL;
        free(temp);
        temp=NULL;
     }

}


void Delete_Data_After(struct Node *List,uint32 position){

      struct Node *nodeCounter=NULL;
      struct Node *nodeBefore=NULL;
      uint32 nodePosition=position;
      if(nodePosition ==1){
        printf("use delete data at beginning \n");
      }
      else{
            nodeCounter=List;
         if(List->RightPointer == NULL){
            printf("use fun delete at end \n");
         }
         else{
            while(nodePosition>1){
               nodeCounter=nodeCounter->RightPointer ;
               nodePosition--;
            }

            nodeBefore=nodeCounter->LeftPointer;
            nodeBefore->RightPointer=nodeCounter->RightPointer;
            nodeCounter->RightPointer->LeftPointer=nodeBefore;
            free(nodeCounter);
            nodeCounter=NULL;

         }

      }

}


void Display_Data_Forward(struct Node *List){
    if(NULL == List){
        printf("the list is empty \n");
    }
  else{
    printf("the data is ");
    printf("%d ",List->data);
    while(List->RightPointer != NULL){
        List=List->RightPointer;
          printf("%d ",List->data);

    }
    printf("\n");
  }
}


void Display_Data_Reverse(struct Node *List){


       if(NULL == List){
        printf("the list is empty \n");
    }
    else{
      while(List->RightPointer !=NULL){
            List=List->RightPointer;
        }
    printf("the data is ");
    printf("%d ",List->data);
    while(List->LeftPointer != NULL){
        List=List->LeftPointer;
          printf("%d ",List->data);

    }
    printf("\n");
    }
}


void Inset_Data_Before(struct Node *List,uint32 data,uint32 position){

        if(position==1){
             printf("use insert data at beginning \n");
        }
        else{
        struct Node *temp=NULL;
        struct Node *nodeCounter=NULL;
         struct Node *nodeBefore=NULL;
        uint32 nodePosition =position;
        temp=(struct Node *)malloc(sizeof(struct Node));
        nodeCounter=List;
        if(NULL != temp){

            temp->data=data;
            while(nodePosition > 1){
                nodeCounter=nodeCounter->RightPointer;
                nodePosition--;
            }
            nodeBefore=nodeCounter->LeftPointer;
            nodeBefore->RightPointer=temp;
            nodeCounter->LeftPointer=temp;
            temp->LeftPointer=nodeBefore;
            temp->RightPointer=nodeCounter;

        }
        else{
            printf("can not allocate memory");
        }
}
}





