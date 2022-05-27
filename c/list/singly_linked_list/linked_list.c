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
#include "../milkyway_list_common.h"

/*!*****************************************************************************
*  \brief      Creats the node for the list.
*
*  \param[in]  None
*
*  \retval     Pointer to the created node.
*
******************************************************************************/
static void *createNode( void )
{
    LINKED_LIST *localPtr = (LINKED_LIST *)malloc(sizeof(LINKED_LIST));
    localPtr->data        = (LIST_TYPE)0x00;
    localPtr->nextNode    = LIST_NULL;

    return localPtr;
}

/******************************************************************************/
void *InitializeLinkedList( void )
{
    return LIST_NULL;
}

/******************************************************************************/
void InsertItem(void **pLinkedListHead, const LIST_TYPE cData)
{
    bool status = true;

    LINKED_LIST* localHeadPtr = (LINKED_LIST *)(*pLinkedListHead);

    LINKED_LIST *localTempPtr = (LINKED_LIST *)createNode();
    localTempPtr->data = cData;

    if ( LIST_NULL == localHeadPtr )
    {
        *pLinkedListHead = localTempPtr;
    }
    else
    {
        while ( LIST_NULL != localHeadPtr->nextNode )
        {
            localHeadPtr = localHeadPtr->nextNode;
        }
        
        localHeadPtr->nextNode = localTempPtr;
    }

    return;
}

/******************************************************************************/
void *SearchItem(const void *pLinkedListHead, const LIST_TYPE cData)
{
    void *localPtr = LIST_NULL;

    while ( LIST_NULL != pLinkedListHead )
    {
        if ( ((LINKED_LIST *)pLinkedListHead)->data == cData )
        {
            localPtr = (LINKED_LIST *)pLinkedListHead;
            break;
        }
        else
        {
            pLinkedListHead = ((LINKED_LIST *)pLinkedListHead)->nextNode;
        }
    }        

    return localPtr;
}

/******************************************************************************/
bool RemoveItem(void **pLinkedListHead, const LIST_TYPE cData)
{
    bool status = false;

    if ( (pLinkedListHead != LIST_NULL ) && 
       ( (*pLinkedListHead) != LIST_NULL ) )
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
            while ( LIST_NULL != localTempPtr->nextNode )
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
LIST_TYPE Front( const void *pcHead )
{
    LIST_TYPE retVal = (LIST_TYPE)( 0 );

    if( LIST_NULL != pcHead )
    {
        retVal = ((LINKED_LIST *)pcHead)->data;
    }

    return retVal;
}

/******************************************************************************/
LIST_TYPE Back( const void *pcHead )
{
    LIST_TYPE retVal = (LIST_TYPE)( 0 );

    if( LIST_NULL != pcHead )
    {
        while ( LIST_NULL != ((LINKED_LIST *)pcHead)->nextNode)
        {
            pcHead = ((LINKED_LIST *)pcHead)->nextNode;
        }
        
        retVal = ((LINKED_LIST *)pcHead)->data;
    }

    return retVal;
}

/******************************************************************************/
uint32_t LinkedListSize(const void *pLinkedListHead)
{
    uint32_t listSize = 0;

    while ( LIST_NULL != pLinkedListHead )
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
    while ( LIST_NULL != pLinkedListHead )
    {
        printf("NODE DATA = %d \n", ((LINKED_LIST*)pLinkedListHead)->data);
        pLinkedListHead = ((LINKED_LIST*)pLinkedListHead)->nextNode;
    }
}

/******************************************************************************/
void DestroyLinkedList(void **pLinkedListHead)
{
    LINKED_LIST *localTempPtr  = (LINKED_LIST *)(*pLinkedListHead);
    LINKED_LIST *LocalDeletPtr = LIST_NULL;
    *pLinkedListHead           = LIST_NULL;

    while ( LIST_NULL != localTempPtr )
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
    MILKYWAY_LIST_COMMON *MilkywayList =
        ( MILKYWAY_LIST_COMMON * )malloc( sizeof( MILKYWAY_LIST_COMMON ) );
    
    MilkywayList->mListPtr        = LIST_NULL;
    MilkywayList->mInitializeList = InitializeLinkedList;
    MilkywayList->mInsertItem     = InsertItem;
    MilkywayList->mRemoveItem     = RemoveItem;
    MilkywayList->mFront          = Front;
    MilkywayList->mBack           = Back;
    MilkywayList->mSearchItem     = SearchItem;
    MilkywayList->mEmpty          = IsLinkedListEmpty;
    MilkywayList->mSize           = LinkedListSize;
    MilkywayList->mPrintList      = PrintLinkedList;
    MilkywayList->mDestroy        = DestroyLinkedList;

    LIST_TYPE linkedListData = 0;

    for ( linkedListData = 0; linkedListData < 10; ++linkedListData )
    {
        MilkywayList->mInsertItem( &MilkywayList->mListPtr, linkedListData );
    }

    MilkywayList->mPrintList( MilkywayList->mListPtr );

    if ( MilkywayList->mEmpty( MilkywayList->mListPtr ) == true )
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
    printf( "Size of the list = %d \n", MilkywayList->mSize( MilkywayList->mListPtr ) );
    printf("\n");

    if ( MilkywayList->mRemoveItem( &MilkywayList->mListPtr, 0 ) == true )
    {
        MilkywayList->mPrintList( MilkywayList->mListPtr );
        printf("\n");
        printf("Size of the list after removal = %d \n", MilkywayList->mSize( MilkywayList->mListPtr ));
        printf("\n");
    }

    MilkywayList->mDestroy( &MilkywayList->mListPtr );

    if ( MilkywayList->mEmpty( MilkywayList->mListPtr ) == true )
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