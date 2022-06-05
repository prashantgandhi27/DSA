/*!*****************************************************************************
*  \author     Prashant Gandhi
*  \date       06/04/2022
********************************************************************************
*  \file       milkyway_binary_tree_common.h
*
*  \brief      Common access APIs for the binary tree data structure.
*
*  \details    None
*
*  \note       None
*
*******************************************************************************/
#ifndef __MILKYWAY_BINARY_TREE_COMMON_H__
#define __MILKYWAY_BINARY_TREE_COMMON_H__

#include <stdbool.h>

#include "milkyway_binary_tree_cfg.h"

#ifdef __cplusplus
extern "C"
{
#endif

typedef struct milkyway_binary_tree_common
{
    void *mRoot;
    bool mSearchItem( const void *pcRoot, const BINARRY_TREE_TYPE cItem );
    void mInorderTraverse( const void *pcRoot );
    void mPreorderTraverse( const void *pcRoot );
    void mPostorderTraverse( const void *pcRoot );
    void mInsertItem( void **ppRoot );
    void mDeleteItem( void **ppRoot );
} MILKYWAY_BINARY_TREE_COMMON;

#ifdef __cplusplus
}
#endif

#endif /* __MILKYWAY_BINARY_TREE_COMMON_H__ */