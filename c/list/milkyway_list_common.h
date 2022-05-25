/*!*****************************************************************************
*  \author     Prashant Gandhi
*  \date       05/24/2022
********************************************************************************
*  \file       milkyway_list_common.h
*
*  \brief      milkyway common plugins for the list.
*
*  \details    None
*
*  \note       None
*
*******************************************************************************/
#ifndef __MILKYWAY_LIST_COMMON_H__
#define __MILKYWAY_LIST_COMMON_H__

#include <stdint.h>
#include <stdbool.h>

#include "milkyway_list_common_cfg.h"

#ifdef __cplusplus
extern "C"
{
#endif

/* Handler to access the Singly/Doubly linked list. */
typedef struct milkyway_list_common
{
   void *mListPtr;
   void *( *mInitializeList )( void );
   void (*mInsertItem)( void **ppHead, const LIST_TYPE cData );
   void *(*mSearchItem)( const void *pHead, const LIST_TYPE cData );
   LIST_TYPE (*mFront)( const void *pcHead);
   LIST_TYPE (*mBack)( const void *pcHead);
   bool (*mRemoveItem)( void **ppHead, const LIST_TYPE cData );
   void (*mPrintListForward)( const void *pcHead );
   void (*mPrintListBackward)( const void *pcHead );
   uint32_t (*mSize)( const void *pcHead );
   bool (*mEmpty)( const void *pcHead );
   void (*mDestroy)( void **ppHead );
} MILKYWAY_LIST_COMMON;


#ifdef __cplusplus
}
#endif

#endif /* __MILKYWAY_LIST_COMMON_H__ */