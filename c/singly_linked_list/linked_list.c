/*!*****************************************************************************
*  \author     Prashant Gandhi
*  \date       05/22/2022
********************************************************************************
*  \file       linked_list.c
*
*  \brief      This files contains Singly linked list function definations.
*
*  \note       None
*
*******************************************************************************/
#include "linked_list.h"

/*!*****************************************************************************
*  \fn         RING_BUFFER *CreateRingBuffer(uint32_t *buffer, uint32_t ringSize)
*  \brief      Allocates and initializes a ring
*
*  \param[in]  buffer     - pointer to user's buffer
*  \param[in]  ringSize   - size of user's buffer
*
*  \retval     pointer to a ring if successful, else NULL
*
******************************************************************************/
static void *createNode( void )
{
    LINKED_LIST *localPtr = (LINKED_LIST *)malloc(sizeof(LINKED_LIST));
    localPtr->data        = (LINKED_LIST_TYPE)0x00;
    localPtr->nextNode    = LINKED_LIST_NULL;

    return localPtr;
}

/******************************************************************************/
void *InitializeLinkedList( void )
{
    return LINKED_LIST_NULL;
}

/******************************************************************************/
void InsertItem(void **pLinkedListHead, const LINKED_LIST_TYPE cData)
{
    bool status = true;

    LINKED_LIST* localHeadPtr = (LINKED_LIST *)(*pLinkedListHead);

    LINKED_LIST *localTempPtr = (LINKED_LIST *)createNode();
    localTempPtr->data = cData;

    if ( LINKED_LIST_NULL == localHeadPtr )
    {
        *pLinkedListHead = localTempPtr;
    }
    else
    {
        while ( LINKED_LIST_NULL != localHeadPtr->nextNode )
        {
            localHeadPtr = localHeadPtr->nextNode;
        }
        
        localHeadPtr->nextNode = localTempPtr;
    }

    return;
}

/******************************************************************************/
void *SearchItem(void *pLinkedListHead, const LINKED_LIST_TYPE cData)
{
    bool found = false;

    while ( LINKED_LIST_NULL != pLinkedListHead )
    {
        if ( ((LINKED_LIST *)pLinkedListHead)->data == cData )
        {
            found = true;
            break;
        }
        
        pLinkedListHead = ((LINKED_LIST *)pLinkedListHead)->nextNode;
    }

    return pLinkedListHead;
}

/******************************************************************************/
bool RemoveItem(void **pLinkedListHead, const LINKED_LIST_TYPE cData)
{
    bool status = false;

    if ( (pLinkedListHead != LINKED_LIST_NULL ) && 
       ( (*pLinkedListHead) != LINKED_LIST_NULL ) )
    {
        LINKED_LIST *localTempPtr = *pLinkedListHead;

        if ( localTempPtr->data == cData)
        {
            status           = true;
            *pLinkedListHead = localTempPtr->nextNode;
            free( localTempPtr );
        }
        else
        {
            while ( LINKED_LIST_NULL != localTempPtr->nextNode )
            {
                if ( localTempPtr->nextNode->data == cData )
                {
                    status                  = true;
                    LINKED_LIST *deleteNode = localTempPtr->nextNode;
                    localTempPtr->nextNode  = localTempPtr->nextNode->nextNode;
                    free( deleteNode );
                    break;
                }
                else
                {
                    localTempPtr = localTempPtr->nextNode;
                }
            }
        }
    }
}

/******************************************************************************/
uint32_t LinkedListSize(const void *pLinkedListHead)
{
    uint32_t listSize = 0;

    while ( LINKED_LIST_NULL != pLinkedListHead )
    {
        listSize++;
        pLinkedListHead = ((LINKED_LIST *)pLinkedListHead)->nextNode;
    }

    return listSize;
}

/******************************************************************************/
bool IsLinkedListEmpty(const void *pLinkedListHead)
{
    bool empty = false;

    if ( LinkedListSize( pLinkedListHead ) == 0 )
    {
        empty = true;
    }

    return empty;
}

/******************************************************************************/
void PrintLinkedList(const void *pLinkedListHead)
{
    while ( LINKED_LIST_NULL != pLinkedListHead )
    {
        printf("NODE DATA = %d \n", ((LINKED_LIST*)pLinkedListHead)->data);
        pLinkedListHead = ((LINKED_LIST*)pLinkedListHead)->nextNode;
    }
}

/******************************************************************************/
void DestroyLinkedList(void **pLinkedListHead)
{
    LINKED_LIST *localTempPtr  = (LINKED_LIST *)(*pLinkedListHead);
    LINKED_LIST *LocalDeletPtr = LINKED_LIST_NULL;
    *pLinkedListHead           = LINKED_LIST_NULL;

    while ( LINKED_LIST_NULL != localTempPtr )
    {
        LocalDeletPtr = localTempPtr;
        localTempPtr  = localTempPtr->nextNode;

        free( LocalDeletPtr );
    }

    return;
}


/******************************************************************************
 * Entry point.
 ******************************************************************************/
int main( void )
{
    LINKED_LIST *TestLinkedList = LINKED_LIST_NULL;

    LINKED_LIST_TYPE linkedListData = 0;

    for ( linkedListData = 0; linkedListData < 10; ++linkedListData )
    {
        InsertItem( (void *)&TestLinkedList, linkedListData );
    }

    PrintLinkedList( TestLinkedList );

    if ( IsLinkedListEmpty( TestLinkedList ) == true )
    {
        printf("\n");
        printf("List is empty. \n");
        printf("\n");
    }
    else
    {
        printf("\n");
        printf("List is not empty. \n");
        printf("\n");
    }

    printf("\n");
    printf("Size of the list = %d \n", LinkedListSize(TestLinkedList));
    printf("\n");

    if ( RemoveItem( (void *)&TestLinkedList, 0 ) == true )
    {
        PrintLinkedList(TestLinkedList);
        printf("\n");
        printf("Size of the list after removal = %d \n", LinkedListSize(TestLinkedList));
        printf("\n");
    }

    DestroyLinkedList( (void *)&TestLinkedList );

    if ( IsLinkedListEmpty( TestLinkedList ) == true )
    {
        printf("\n");
        printf("After destroy, list is empty. \n");
        printf("\n");
    }
    else
    {
        printf("\n");
        printf("After destroy, list is not empty. \n");
        printf("\n");
    }

    return 0;
}