/*!*****************************************************************************
*  \author     Prashant Gandhi
*  \date       05/22/2022
********************************************************************************
*  \file       stack.h
*
*  \brief      Function definations for the Stack data structure.
*
*  \note       None
*
*******************************************************************************/
#ifndef __STACK_H__
#define __STACK_H__

#include <stdint.h>
#include <stdbool.h>

#include "milkyway_stack_common_cfg.h"
#include "milkyway_stack_common.h"

#ifdef __cplusplus
extern "C"
{
#endif

typedef struct stack
{
    STACK_TYPE mData;
    struct stack *mNextNode;
} STACK;

/*!*****************************************************************************
*  \brief      Configures stack handler. 
*
*  \param[in]  ppStack - pointer to the handler.
*
*  \retval     None.
*
******************************************************************************/
void ConfigureStack( void **ppStack );

/*!*****************************************************************************
*  \brief      Adds data to the stack.
*
*  \param[in]  ppStackHead - pointer to the head of the stack.
*  \param[in]  cData       - data that needs to be pushed on to stack.
*
*  \retval     None
*
******************************************************************************/
void Push(void **ppStackHead, const STACK_TYPE data);

/*!*****************************************************************************
*  \brief      Returns last added elements.
*
*  \param[in]  ppStackHead - pointer to the head of the stack.
*
*  \retval     Last added element.
*
******************************************************************************/
STACK_TYPE Top( const void *ppStackHead );

/*!*****************************************************************************
*  \brief      Removes last added elements.
*
*  \param[in]  ppStackHead - pointer to the head of the stack.
*
*  \retval     None.
*
******************************************************************************/
void Pop( void **ppStackHead );

/*!*****************************************************************************
*  \brief      Returns total elements on to the Stack.
*
*  \param[in]  pcStackHead - pointer to the head of the stack.
*
*  \retval     Number of elements on to the Stack.
*
******************************************************************************/
uint32_t StackSize( const void *pcStackHead);

/*!*****************************************************************************
*  \brief      Prints all nodes' data inside the Stack.
*
*  \param[in]  pcStackHead - pointer to the head of the stack.
*
*  \retval     None
*
******************************************************************************/
void PrintStack( const void *pcStackHead );

/*!*****************************************************************************
*  \brief      Determines whether the input Stack is empty or not.
*
*  \param[in]  pcStackHead - pointer to the head of the stack.
*
*  \retval     true  - stack is empty
*              false - stack is not empty
*
******************************************************************************/
bool Empty( const void *pcStackHead );

/*!*****************************************************************************
*  \brief      Copys the one stack into another.
*
*  \param[in]  ppStackHead - pointer to the head of the destication stack.
*  \param[in]  pcCopyStack - pointer to the head of the source stack.
*
*  \retval     true  - copy operation successfully completed.
*              false - copy operation failed.
*
******************************************************************************/
bool CopyStack( void **ppStackHead, const void *pcCopyStack );

/*!*****************************************************************************
*  \brief      Deletes all nodes from the stack.
*
*  \param[in]  ppStackHead - pointer to the head of the stack.
*
*  \retval     None
*
******************************************************************************/
void DestroyStack(void **ppStackHead);

#ifdef __cplusplus
}
#endif


#endif /* __STACK_H__ */