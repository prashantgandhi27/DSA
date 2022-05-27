/*!*****************************************************************************
*  \author     Prashant Gandhi
*  \date       05/25/2022
********************************************************************************
*  \file       milkyway_stack_common.h
*
*  \brief      milkyway common plugins for the Stack DS.
*
*  \details    None
*
*  \note       None
*
*******************************************************************************/
#ifndef __MILKYWAY_STACK_COMMON_H__
#define __MILKYWAY_STACK_COMMON_H__

#include <stdint.h>
#include <stdbool.h>

#include "milkyway_stack_common_cfg.h"

#ifdef __cplusplus
extern "C"
{
#endif

/* Handler to access the stack. */
typedef struct milkyway_stack_common
{
    void *mStackPtr;
    void (*mPush)( void **, const STACK_TYPE);
    STACK_TYPE (*mTop)( const void * );
    void (*mPop)( void ** );
    uint32_t (*mSize)( const void * );
    void (*mPrint)( const void * );
    bool (*mEmpty)( const void * );
    bool (*mCopy)( void ** , const void * );
    void (*mDestroy)( void ** );
} MILKYWAY_STACK_COMMON;

#ifdef __cplusplus
}
#endif

#endif /* __MILKYWAY_STACK_COMMON_H__ */