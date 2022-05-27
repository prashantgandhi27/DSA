/*!*****************************************************************************
*  \author     Prashant Gandhi
*  \date       05/22/2022
********************************************************************************
*  \file       stack.h
*
*  \brief      Function declarations for the Stack data structure.
*
*  \note       None
*
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

/*!*****************************************************************************
*  \brief      Creats the node for the stack.
*
*  \param[in]  cData - Data with the node should be created.
*
*  \retval     Pointer to the created node.
*
******************************************************************************/
static void *CreateNode( const STACK_TYPE cData )
{
    STACK *localPtr     = (STACK *)malloc( sizeof( STACK ) );
    localPtr->mData     = cData;
    localPtr->mNextNode = STACK_NULL;

    return localPtr;
}

/******************************************************************************/
void ConfigureStack( void **ppStack )
{
    if ( ppStack != STACK_NULL )
    {
        if ( STACK_NULL == (*ppStack) )
        {
            (*ppStack) =
                (MILKYWAY_STACK_COMMON *)malloc( sizeof( MILKYWAY_STACK_COMMON ) );
        }

        ((MILKYWAY_STACK_COMMON*)(*ppStack))->mStackPtr        = STACK_NULL;
        ((MILKYWAY_STACK_COMMON*)(*ppStack))->mPush            = Push;
        ((MILKYWAY_STACK_COMMON*)(*ppStack))->mTop             = Top;
        ((MILKYWAY_STACK_COMMON*)(*ppStack))->mPop             = Pop;
        ((MILKYWAY_STACK_COMMON*)(*ppStack))->mEmpty           = Empty;
        ((MILKYWAY_STACK_COMMON*)(*ppStack))->mPrint           = PrintStack;
        ((MILKYWAY_STACK_COMMON*)(*ppStack))->mSize            = StackSize;
        ((MILKYWAY_STACK_COMMON*)(*ppStack))->mCopy            = CopyStack;
        ((MILKYWAY_STACK_COMMON*)(*ppStack))->mDestroy         = DestroyStack;
    }
    
    return;
}

/******************************************************************************/
void Push(void **ppStackHead, const STACK_TYPE cData)
{
    if ( STACK_NULL != ppStackHead )
    {
        if ( STACK_NULL == (*ppStackHead) )
        {
            (*ppStackHead)                       = (STACK *)malloc( sizeof( STACK ) );
            ((STACK *)(*ppStackHead))->mData     = cData;
            ((STACK *)(*ppStackHead))->mNextNode = STACK_NULL;
        }
        else
        {
            STACK *localPtr = (STACK *)malloc( sizeof( STACK ) );

            localPtr->mData     = cData;
            localPtr->mNextNode = (STACK *)(*ppStackHead);
            (*ppStackHead)      = localPtr;
        }
    }

    return;
}

/******************************************************************************/
STACK_TYPE Top( const void *ppStackHead )
{
    STACK_TYPE retVal = (STACK_TYPE)0x00;

    if ( ppStackHead != STACK_NULL )
    {
        retVal = ((STACK *)ppStackHead)->mData;
    }

    return retVal;
}

/******************************************************************************/
void Pop( void **ppStackHead )
{
    if ( ( STACK_NULL != ppStackHead ) && (STACK_NULL != (*ppStackHead) ) )
    {
        STACK *localPtr = (STACK *)(*ppStackHead);
        (*ppStackHead) = ((STACK *)(*ppStackHead))->mNextNode;

        free( localPtr );
    }

    return;
}

/******************************************************************************/
uint32_t StackSize( const void *pcStackHead)
{
    uint32_t size = 0;

    while ( STACK_NULL != pcStackHead )
    {
        size++;
        pcStackHead = ((STACK *)pcStackHead)->mNextNode;
    }
    
    return size;
}

/******************************************************************************/
void PrintStack( const void *pcStackHead )
{
    while ( STACK_NULL != pcStackHead ) 
    {
        printf("STACK DATA = %d \n", ((STACK *)pcStackHead)->mData );
        pcStackHead = ((STACK *)pcStackHead)->mNextNode;
    }
    
    return;
}

/******************************************************************************/
bool Empty( const void *pcStackHead )
{
    bool stackEmpty = false;

    if ( StackSize( pcStackHead ) == 0 )
    {
        stackEmpty = true;
    }

    return stackEmpty;
}

/******************************************************************************/
bool CopyStack( void **ppStackHead, const void *pcCopyStack )
{
    bool status = false;

    if ( STACK_NULL != ppStackHead )
    {
        DestroyStack( ppStackHead );

        if ( STACK_NULL == (*ppStackHead) )
        {
            status = true;
            while ( STACK_NULL !=  pcCopyStack )
            {
                Push( ppStackHead, ((STACK *)pcCopyStack)->mData );
                pcCopyStack = ((STACK *)pcCopyStack)->mNextNode;
            }
        }
    }

    return status;
}

/******************************************************************************/
void DestroyStack(void **ppStackHead)
{
    if ( ( STACK_NULL != ppStackHead ) &&
         ( STACK_NULL != (*ppStackHead) ) )
    {
        STACK *localPtr  = (STACK *)(*ppStackHead);
        STACK *deletePtr = localPtr;

        while ( STACK_NULL != localPtr )
        {
            deletePtr = localPtr;
            localPtr  = localPtr->mNextNode;

            free( deletePtr );
        }
        
        (*ppStackHead) = STACK_NULL;
    }

    return;
}

/******************************************************************************
 * Entry point.
 ******************************************************************************/
int main( void )
{
    MILKYWAY_STACK_COMMON *UnitTestStack = STACK_NULL;

    ConfigureStack( (void *)&UnitTestStack );

    if ( UnitTestStack->mEmpty( UnitTestStack->mStackPtr ) )
    {
        uint32_t idx = 0;

        for ( idx = 0; idx < 7; ++idx )
        {
            UnitTestStack->mPush( (void *)&UnitTestStack->mStackPtr, idx );
        }
    }

    UnitTestStack->mPrint( UnitTestStack->mStackPtr );

    if ( !( UnitTestStack->mEmpty( UnitTestStack->mStackPtr ) ) )
    {
        printf("Stack size = %d \n", UnitTestStack->mSize( UnitTestStack->mStackPtr ) );
        printf("Stack top element = %d \n", UnitTestStack->mTop( UnitTestStack->mStackPtr ) );

        UnitTestStack->mPop( (void *)&UnitTestStack->mStackPtr );
        UnitTestStack->mPop( (void *)&UnitTestStack->mStackPtr );

        printf("Stack size after two POP = %d \n", UnitTestStack->mSize( UnitTestStack->mStackPtr ) );
    }

    while ( !(UnitTestStack->mEmpty( UnitTestStack->mStackPtr ) ) )
    {
        UnitTestStack->mPop( (void *)&UnitTestStack->mStackPtr );
    }
    
    printf("Stack size = %d \n", UnitTestStack->mSize( UnitTestStack->mStackPtr ) );

    return 0;
}