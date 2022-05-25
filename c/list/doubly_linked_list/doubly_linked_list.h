/*!*****************************************************************************
*  \author     Prashant Gandhi
*  \date       05/22/2022
********************************************************************************
*  \file       doubly_linked_list_cfg.h
*
*  \brief      Funtion declarations for Doubly Linked List.
*
*  \details    None
*
*  \note       None
*
*******************************************************************************/
#ifndef __DOUBLY_LINKED_LIST_H__
#define __DOUBLY_LINKED_LIST_H__

#include <stdbool.h>

#include "../milkyway_list_common_cfg.h"

#ifdef __cplusplus
extern "C"
{
#endif

typedef struct doubly_linked_list
{
    LIST_TYPE mData;
    struct doubly_linked_list *mNextNode;
    struct doubly_linked_list *mPreviousNode;
} DOUBLY_LINKED_LIST;

/*!*****************************************************************************
*  \brief      Initializes the doubly linked list.
*
*  \param[in]  None.
*
*  \retval     None
*
******************************************************************************/
void *InitializeDoublyLinkedList( void );

/*!*****************************************************************************
*  \brief      Inserts requested data into the list.
*
*  \param[in]  ppHead - pointer to the head of the list.
*  \param[in]  cData  - data that needs to be inserted in the list.
*
*  \retval     None
*
******************************************************************************/
void InsertItem( void **ppHead, const LIST_TYPE cData );

/*!*****************************************************************************
*  \brief      Removes the item/node from the list.
*
*  \param[in]  ppHead - pointer to the head of the list.
*  \param[in]  cData  - data that needs to be removed in the list.
*
*  \retval     true  - node/data successfully removed.
*              false - node/data removal operation failed.
*
******************************************************************************/
bool RemoveItem( void **ppHead, const LIST_TYPE cData );

/*!*****************************************************************************
*  \brief      Searches requested data inside the list.
*
*  \param[in]  pcHead - pointer to the head of the list.
*  \param[in]  cData  - data that needs to be searched in the list.
*
*  \retval     None
*
******************************************************************************/
void *SearchItem( const void *pcHead, const LIST_TYPE cData );

/*!*****************************************************************************
*  \brief      Returns front node's data.
*
*  \param[in]  pcHead - pointer to the head of the list.
*
*  \retval     Front nodes's data.
*
******************************************************************************/
LIST_TYPE Front( const void *pcHead );

/*!*****************************************************************************
*  \brief      Returns last node's data.
*
*  \param[in]  pcHead - pointer to the head of the list.
*
*  \retval     last node's data.
*
******************************************************************************/
LIST_TYPE Back( const void *pcHead );

/*!*****************************************************************************
*  \brief      Returns number of nodes inside list.
*
*  \param[in]  pcHead - pointer to the head of the list.
*
*  \retval     number of nodes in the list.
*
******************************************************************************/
uint32_t ListSize( const void *pcHead );

/*!*****************************************************************************
*  \brief      Verifies if list is empty or not.
*
*  \param[in]  pCHead - pointer to the head of the list.
*
*  \retval     true  - list is empty
*              false - list is not empty.
*
******************************************************************************/
bool IsListEmpty( const void *pCHead );

/*!*****************************************************************************
*  \brief      Prints the list from tail to head.
*
*  \param[in]  pcHead - pointer to the head of the list.
*
*  \retval     None
*
******************************************************************************/
void PrintListForward( const void *pcHead );

/*!*****************************************************************************
*  \brief      Prints the list from head to tail.
*
*  \param[in]  pcHead - pointer to the head of the list.
*
*  \retval     None
*
******************************************************************************/
void PrintListBackward( const void *pcHead );

/*!*****************************************************************************
*  \brief      Deletes all nodes from the list.
*
*  \param[in]  ppLinkedListHead - pointer to the head of the list.
*
*  \retval     None
*
******************************************************************************/
void DestroyList( void **ppHead );

#ifdef __cplusplus
}
#endif

#endif  /* __DOUBLY_LINKED_LIST_H__ */