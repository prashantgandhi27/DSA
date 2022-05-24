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
    localPtr->mData         = (DOUBLY_LINKED_LIST_TYPE)0x00;
    localPtr->mNextNode     = DOUBLY_LINKED_LIST_NULL;
    localPtr->mPreviousNode = DOUBLY_LINKED_LIST_NULL;

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
    DOUBLY_LINKED_LIST *localPtr = DOUBLY_LINKED_LIST_NULL;

    if ( DOUBLY_LINKED_LIST_NULL != pcHead )
    {
        localPtr = (DOUBLY_LINKED_LIST *)pcHead;

        while ( DOUBLY_LINKED_LIST_NULL != localPtr->mNextNode )
        {
            localPtr = localPtr->mNextNode;
        }
    }
    
    return localPtr;
}

/******************************************************************************/
void *InitializeDoublyLinkedList( void )
{
    return DOUBLY_LINKED_LIST_NULL;
}

/******************************************************************************/
void InsertItem( void **ppHead, const DOUBLY_LINKED_LIST_TYPE cData )
{
    DOUBLY_LINKED_LIST *localPtr = (DOUBLY_LINKED_LIST *)(*ppHead);

    if ( DOUBLY_LINKED_LIST_NULL == localPtr )
    {
        *ppHead = (DOUBLY_LINKED_LIST *)CreateNode();
        ((DOUBLY_LINKED_LIST *)(*ppHead))->mData = cData;
    }
    else
    {
        while( DOUBLY_LINKED_LIST_NULL != localPtr->mNextNode )
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
bool RemoveItem( void **ppHead, const DOUBLY_LINKED_LIST_TYPE cData )
{
    bool status = false;

    if ( ( DOUBLY_LINKED_LIST_NULL != ppHead ) &&
         (  DOUBLY_LINKED_LIST_NULL != ( *ppHead ) ) )
    {
        DOUBLY_LINKED_LIST *localNextNode = (DOUBLY_LINKED_LIST *)(*ppHead);
        DOUBLY_LINKED_LIST *localPrevNode = localNextNode->mPreviousNode;

        while ( DOUBLY_LINKED_LIST_NULL != localNextNode )
        {
            if ( localNextNode->mData == cData )
            {
                break;
            }

            localNextNode = localNextNode->mNextNode;
        }

        if ( DOUBLY_LINKED_LIST_NULL != localNextNode )
        {
            status                         = true;
            DOUBLY_LINKED_LIST *tempDelPtr = localNextNode;
            localPrevNode                  = localNextNode->mPreviousNode;

            if ( DOUBLY_LINKED_LIST_NULL == localNextNode->mNextNode )
            {
                localPrevNode->mNextNode = DOUBLY_LINKED_LIST_NULL;
                localNextNode            = DOUBLY_LINKED_LIST_NULL;
            }
            else if ( DOUBLY_LINKED_LIST_NULL == localPrevNode )
            {
                localNextNode                = localNextNode->mNextNode;
                localNextNode->mPreviousNode = DOUBLY_LINKED_LIST_NULL;
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
void *SearchItem( const void *pcHead, const DOUBLY_LINKED_LIST_TYPE cData )
{
    void *localPtr = DOUBLY_LINKED_LIST_NULL;

    if ( DOUBLY_LINKED_LIST_NULL != pcHead )
    {
        while ( DOUBLY_LINKED_LIST_NULL != pcHead )
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
DOUBLY_LINKED_LIST_TYPE Front( const void *pcHead )
{
    DOUBLY_LINKED_LIST_TYPE retVal = (DOUBLY_LINKED_LIST_TYPE)( 0 );

    if( DOUBLY_LINKED_LIST_NULL != pcHead )
    {
        retVal = ((DOUBLY_LINKED_LIST *)pcHead)->mData;
    }

    return retVal;
}

/******************************************************************************/
DOUBLY_LINKED_LIST_TYPE Back( const void *pcHead )
{
    DOUBLY_LINKED_LIST_TYPE retVal = (DOUBLY_LINKED_LIST_TYPE)( 0 );
    DOUBLY_LINKED_LIST *tail       = (DOUBLY_LINKED_LIST *)GetTail( pcHead );

    if ( DOUBLY_LINKED_LIST_NULL != tail )
    {
        retVal = tail->mData;
    }

    return retVal;
}

/******************************************************************************/
uint32_t ListSize( const void *pcHead )
{
    uint32_t size = 0;

    if ( DOUBLY_LINKED_LIST_NULL != pcHead )
    {
        while ( DOUBLY_LINKED_LIST_NULL != pcHead )
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
    while( DOUBLY_LINKED_LIST_NULL != pcHead )
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

    while ( DOUBLY_LINKED_LIST_NULL != localPtr )
    {
        printf("Node Data = %f \n", ((DOUBLY_LINKED_LIST*)localPtr)->mData);

        localPtr = localPtr->mPreviousNode;
    }
    
    return;
}

/******************************************************************************/
bool DestroyList( void **ppHead )
{
    bool status = false;

    if ( ( DOUBLY_LINKED_LIST_NULL != ppHead ) && 
         ( DOUBLY_LINKED_LIST_NULL != ( *ppHead ) ) )
    {
        status                             = true;
        DOUBLY_LINKED_LIST *localPtr       = (DOUBLY_LINKED_LIST *)( *ppHead );
        DOUBLY_LINKED_LIST *localDeletePtr = DOUBLY_LINKED_LIST_NULL;

        while ( DOUBLY_LINKED_LIST_NULL != localPtr )
        {
            localDeletePtr = localPtr;
            localPtr       = localPtr->mNextNode;

            free( localDeletePtr );
        }
        
        *ppHead = DOUBLY_LINKED_LIST_NULL;
    }

    return status;
}

/******************************************************************************
 * Entry point.
 ******************************************************************************/
int main( void )
{
    printf( "************************************************************* \n");
    printf( "* DOUBLY LINKED LIST \n");
    printf( "************************************************************* \n");

    DOUBLY_LINKED_LIST *UnitTestList = InitializeDoublyLinkedList();

    uint32_t count = 0;

    for ( count = 0; count < 10; ++count )
    {
        InsertItem( (void *)&UnitTestList, (DOUBLY_LINKED_LIST_TYPE)count );
    }

    printf(" FORWARD LIST \n");
    PrintListForward( UnitTestList );

    printf(" BACKWARD LIST \n");
    PrintListBackward( UnitTestList );

    DOUBLY_LINKED_LIST *Ptr = (DOUBLY_LINKED_LIST *)SearchItem( UnitTestList, 9.0 );

    if ( DOUBLY_LINKED_LIST_NULL != Ptr )
    {
        printf( "Searched item was = %f \n", Ptr->mData );
    }
    else
    {
        printf( "Searched item is not found. \n");
    }

    if ( RemoveItem( (void *)&UnitTestList, 0.0 ) == true )
    {
        printf(" FORWARD LIST \n");
        PrintListForward( UnitTestList );

        printf(" BACKWARD LIST \n");
        PrintListBackward( UnitTestList );
    }

    if ( IsListEmpty( UnitTestList ) == false )
    {
        printf( "List size before destroy = %d \n", ListSize( UnitTestList ) );

        if ( DestroyList( (void *)&UnitTestList ) == true )
        {
            printf( "List size after destroy = %d \n", ListSize( UnitTestList ) );
        }
    }
    else
    {
        printf( "List is Empty. \n");   
    }

    return 0;
}