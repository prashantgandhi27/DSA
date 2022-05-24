/*!*****************************************************************************
*  \author     Prashant Gandhi
*  \date       05/22/2022
********************************************************************************
*  \file       linked_list.h
*
*  \brief      This files contains Singly linked list function declaration.
*
*  \note       None
*
*******************************************************************************/
#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

#include "linked_list_cfg.h"

#ifdef __cplusplus
extern "C"
{
#endif

typedef struct linked_list
{
    LINKED_LIST_TYPE data;
    struct linked_list *nextNode;
} LINKED_LIST;


/*!*****************************************************************************
*  \brief      Does nothing. Only returns custom NULL pointer. 
*
*  \param[in]  None
*
*  \retval     custom NULL pointer.
*
******************************************************************************/
void *InitializeLinkedList( void );

/*!*****************************************************************************
*  \brief      Adds data to the list.
*
*  \param[in]  ppLinkedListHead - pointer to the head of the list.
*  \param[in]  cData            - data that needs to be removed.
*
*  \retval     None
*
******************************************************************************/
void InsertItem(void **ppLinkedListHead, const LINKED_LIST_TYPE data);

/*!*****************************************************************************
*  \brief      Looks for the requested item in the list.
*
*  \param[in]  pLinkedListHead - pointer to the head of the list.
*  \param[in]  cData            - data that needs to be removed.
*
*  \retval     if requested node found then pointer to that node, otherwise
*              NULL.
*
******************************************************************************/
void *SearchItem(void *pLinkedListHead, const LINKED_LIST_TYPE cData);

/*!*****************************************************************************
*  \brief      Removes/deletes the requested node.
*
*  \param[in]  ppLinkedListHead - pointer to the head of the list.
*  \param[in]  cData            - data that needs to be removed.
*
*  \retval     true  - Node containing item was present and node is successfully
*                      deleted.
*              false - Node containing item was not present and operation
*                      failed.
*
******************************************************************************/
bool RemoveItem(void **ppLinkedListHead, const LINKED_LIST_TYPE cData);

/*!*****************************************************************************
*  \brief      Prints all nodes' data inside the list.
*
*  \param[in]  pcLinkedListHead - pointer to the head of the list.
*
*  \retval     None
*
******************************************************************************/
void PrintLinkedList(const void *pcLinkedListHead);

/*!*****************************************************************************
*  \brief      Returns size of the list.
*
*  \param[in]  pcLinkedListHead - pointer to the head of the list.
*
*  \retval     number of nodes in the list.
*
******************************************************************************/
uint32_t LinkedListSize(const void *pcLinkedListHead);

/*!*****************************************************************************
*  \brief      Determines whether the input list is empty or not.
*
*  \param[in]  pcLinkedListHead - pointer to the head of the list.
*
*  \retval     true  - list is empty
*              false - list is not empty
*
******************************************************************************/
bool IsLinkedListEmpty(const void *pcLinkedListHead);

/*!*****************************************************************************
*  \brief      Deletes all nodes from the list.
*
*  \param[in]  ppLinkedListHead - pointer to the head of the list.
*
*  \retval     None
*
******************************************************************************/
void DestroyLinkedList(void **ppLinkedListHead);

#ifdef __cplusplus
}
#endif


#endif /* __LINKED_LIST_H__ */