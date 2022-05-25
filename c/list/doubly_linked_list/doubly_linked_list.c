/*!*****************************************************************************
*  \author     Prashant Gandhi
*  \date       05/22/2022
********************************************************************************
*  \file       doubly_linked_list_cfg.h
*
*  \brief      Funtion definations for Doubly Linked List.
*
*  \details    None
*
*  \note       None
*
*******************************************************************************/
#include <stdlib.h>
#include <stdio.h>

#include "doubly_linked_list.h"
#include "../milkyway_list_common.h"

/*!*****************************************************************************
*  \brief      Creats the node for the list.
*
*  \param[in]  None
*
*  \retval     Pointer to the created node.
*
******************************************************************************/
static void *CreateNode( void )
{
    DOUBLY_LINKED_LIST *localPtr = 
       ( DOUBLY_LINKED_LIST * )malloc( sizeof( DOUBLY_LINKED_LIST ) );
    localPtr->mData         = (LIST_TYPE)0x00;
    localPtr->mNextNode     = LIST_NULL;
    localPtr->mPreviousNode = LIST_NULL;

    return localPtr;
}

/*!*****************************************************************************
*  \brief      Returns pointer to the list's tail.
*
*  \param[in]  pcHead - pointer to the head of the list.
*
*  \retval     Pointer to the list's tail.
*
******************************************************************************/
static void *GetTail( const void *pcHead )
{
    DOUBLY_LINKED_LIST *localPtr = LIST_NULL;

    if ( LIST_NULL != pcHead )
    {
        localPtr = (DOUBLY_LINKED_LIST *)pcHead;

        while ( LIST_NULL != localPtr->mNextNode )
        {
            localPtr = localPtr->mNextNode;
        }
    }
    
    return localPtr;
}

/******************************************************************************/
void *InitializeDoublyLinkedList( void )
{
    return LIST_NULL;
}

/******************************************************************************/
void InsertItem( void **ppHead, const LIST_TYPE cData )
{
    DOUBLY_LINKED_LIST *localPtr = (DOUBLY_LINKED_LIST *)(*ppHead);

    if ( LIST_NULL == localPtr )
    {
        *ppHead = (DOUBLY_LINKED_LIST *)CreateNode();
        ((DOUBLY_LINKED_LIST *)(*ppHead))->mData = cData;
    }
    else
    {
        while( LIST_NULL != localPtr->mNextNode )
        {
            localPtr = localPtr->mNextNode;
        }

        localPtr->mNextNode                = (DOUBLY_LINKED_LIST *)CreateNode();
        localPtr->mNextNode->mData         = cData;
        localPtr->mNextNode->mPreviousNode = localPtr;
    }

    return;
}

/******************************************************************************/
bool RemoveItem( void **ppHead, const LIST_TYPE cData )
{
    bool status = false;

    if ( ( LIST_NULL != ppHead ) &&
         (  LIST_NULL != ( *ppHead ) ) )
    {
        DOUBLY_LINKED_LIST *localNextNode = (DOUBLY_LINKED_LIST *)(*ppHead);
        DOUBLY_LINKED_LIST *localPrevNode = localNextNode->mPreviousNode;

        while ( LIST_NULL != localNextNode )
        {
            if ( localNextNode->mData == cData )
            {
                break;
            }

            localNextNode = localNextNode->mNextNode;
        }

        if ( LIST_NULL != localNextNode )
        {
            status                         = true;
            DOUBLY_LINKED_LIST *tempDelPtr = localNextNode;
            localPrevNode                  = localNextNode->mPreviousNode;

            if ( LIST_NULL == localNextNode->mNextNode )
            {
                localPrevNode->mNextNode = LIST_NULL;
                localNextNode            = LIST_NULL;
            }
            else if ( LIST_NULL == localPrevNode )
            {
                localNextNode                = localNextNode->mNextNode;
                localNextNode->mPreviousNode = LIST_NULL;
                (*ppHead)                    = localNextNode;
            }
            else
            {
                localNextNode                = localNextNode->mNextNode;
                localPrevNode->mNextNode     = localNextNode;
                localNextNode->mPreviousNode = localPrevNode;
            }

            free ( tempDelPtr );
        }
    }
    
    return status;
}

/******************************************************************************/
void *SearchItem( const void *pcHead, const LIST_TYPE cData )
{
    void *localPtr = LIST_NULL;

    if ( LIST_NULL != pcHead )
    {
        while ( LIST_NULL != pcHead )
        {
            if ( ((DOUBLY_LINKED_LIST *)pcHead)->mData == cData )
            {
                localPtr = (DOUBLY_LINKED_LIST *)pcHead;
                break;
            }
            else
            {
                pcHead = ((DOUBLY_LINKED_LIST *)pcHead)->mNextNode;
            }
        }
        
    }

    return localPtr;
}

/******************************************************************************/
LIST_TYPE Front( const void *pcHead )
{
    LIST_TYPE retVal = (LIST_TYPE)( 0 );

    if( LIST_NULL != pcHead )
    {
        retVal = ((DOUBLY_LINKED_LIST *)pcHead)->mData;
    }

    return retVal;
}

/******************************************************************************/
LIST_TYPE Back( const void *pcHead )
{
    LIST_TYPE retVal = (LIST_TYPE)( 0 );
    DOUBLY_LINKED_LIST *tail       = (DOUBLY_LINKED_LIST *)GetTail( pcHead );

    if ( LIST_NULL != tail )
    {
        retVal = tail->mData;
    }

    return retVal;
}

/******************************************************************************/
uint32_t ListSize( const void *pcHead )
{
    uint32_t size = 0;

    if ( LIST_NULL != pcHead )
    {
        while ( LIST_NULL != pcHead )
        {
            size++;
            pcHead = ((DOUBLY_LINKED_LIST *)pcHead)->mNextNode;
        }
    }

    return size;
}

/******************************************************************************/
bool IsListEmpty( const void *pCHead )
{
    bool empty = false;

    if ( ListSize( pCHead ) == 0 )
    {
        empty = true;
    }

    return empty;
}

/******************************************************************************/
void PrintListForward( const void *pcHead )
{
    while( LIST_NULL != pcHead )
    {
        printf("Node Data = %f \n", ((DOUBLY_LINKED_LIST*)pcHead)->mData);

        pcHead = ((DOUBLY_LINKED_LIST *)pcHead)->mNextNode;
    }

    return;
}

/******************************************************************************/
void PrintListBackward( const void *pcHead )
{
    DOUBLY_LINKED_LIST *localPtr = (DOUBLY_LINKED_LIST *)GetTail( pcHead );

    while ( LIST_NULL != localPtr )
    {
        printf("Node Data = %f \n", ((DOUBLY_LINKED_LIST*)localPtr)->mData);

        localPtr = localPtr->mPreviousNode;
    }
    
    return;
}

/******************************************************************************/
void DestroyList( void **ppHead )
{
    if ( ( LIST_NULL != ppHead ) && 
         ( LIST_NULL != ( *ppHead ) ) )
    {
        DOUBLY_LINKED_LIST *localPtr       = (DOUBLY_LINKED_LIST *)( *ppHead );
        DOUBLY_LINKED_LIST *localDeletePtr = LIST_NULL;

        while ( LIST_NULL != localPtr )
        {
            localDeletePtr = localPtr;
            localPtr       = localPtr->mNextNode;

            free( localDeletePtr );
        }
        
        *ppHead = LIST_NULL;
    }

    return;
}

/******************************************************************************
 * Entry point.
 ******************************************************************************/
int main( void )
{
    printf( "************************************************************* \n");
    printf( "* DOUBLY LINKED LIST \n");
    printf( "************************************************************* \n");

    MILKYWAY_LIST_COMMON *DoublyList =
        (MILKYWAY_LIST_COMMON *)malloc( sizeof( MILKYWAY_LIST_COMMON ) );

    DoublyList->mListPtr           = LIST_NULL;
    DoublyList->mInitializeList    = InitializeDoublyLinkedList;
    DoublyList->mInsertItem        = InsertItem;
    DoublyList->mRemoveItem        = RemoveItem;
    DoublyList->mSearchItem        = SearchItem;
    DoublyList->mFront             = Front;
    DoublyList->mBack              = Back;
    DoublyList->mEmpty             = IsListEmpty;
    DoublyList->mPrintListForward  = PrintListForward;
    DoublyList->mPrintListBackward = PrintListBackward;
    DoublyList->mSize              = ListSize;
    DoublyList->mDestroy           = DestroyList;

    uint32_t count = 0;

    for ( count = 0; count < 10; ++count )
    {
        DoublyList->mInsertItem( &DoublyList->mListPtr, (LIST_TYPE)count );
    }

    printf(" FORWARD LIST \n");
    DoublyList->mPrintListForward( DoublyList->mListPtr );

    printf(" BACKWARD LIST \n");
    DoublyList->mPrintListBackward( DoublyList->mListPtr );

    DOUBLY_LINKED_LIST *Ptr =
        (DOUBLY_LINKED_LIST *)DoublyList->mSearchItem( DoublyList->mListPtr, 9.0 );

    if ( LIST_NULL != Ptr )
    {
        printf( "Searched item was = %f \n", Ptr->mData );
    }
    else
    {
        printf( "Searched item is not found. \n");
    }

    if ( DoublyList->mRemoveItem( &DoublyList->mListPtr, 0.0 ) == true )
    {
        printf(" FORWARD LIST \n");
        DoublyList->mPrintListForward( DoublyList->mListPtr );

        printf(" BACKWARD LIST \n");
        DoublyList->mPrintListBackward( DoublyList->mListPtr );
    }

    if ( DoublyList->mEmpty( DoublyList->mListPtr ) == false )
    {
        printf( "List size before destroy = %d \n", DoublyList->mSize( DoublyList->mListPtr ) );

        DoublyList->mDestroy( &DoublyList->mListPtr );

        printf( "List size after destroy = %d \n", DoublyList->mSize( DoublyList->mListPtr ) );
    }
    else
    {
        printf( "List is Empty. \n");   
    }

    return 0;
}