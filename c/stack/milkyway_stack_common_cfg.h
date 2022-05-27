/*!*****************************************************************************
*  \author     Prashant Gandhi
*  \date       05/25/2022
********************************************************************************
*  \file       milkyway_stack_common_cfg.h
*
*  \brief      Defines for the stack data structure.
*
*  \details    None
*
*  \note       None
*
*******************************************************************************/
#ifndef __MILKYWAY_STACK_COMMON_CFG_H__
#define __MILKYWAY_STACK_COMMON_CFG_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

/* Type of the list */
typedef uint32_t STACK_TYPE;

/* Define NULL pointer */
#define STACK_NULL          (void *)(0)

#ifdef __cplusplus
}
#endif


#endif /* __MILKYWAY_STACK_COMMON_CFG_H__ */