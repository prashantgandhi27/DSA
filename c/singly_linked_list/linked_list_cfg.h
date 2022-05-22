/*!*****************************************************************************
*  \author     Prashant Gandhi
*  \date       02/14/2022
********************************************************************************
*  \file       ring_cfg.h
*
*  \brief      Defines for ring buffer.
*
*  \details    None
*
*  \note       None
*
*******************************************************************************/
#ifndef __LINKED_LIST_CFG_H__
#define __LINKED_LIST_CFG_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

/* Type of the ring buffer */
typedef uint32_t LINKED_LIST_TYPE;

/* Define NULL pointer */
#define LINKED_LIST_NULL          (void *)(0)

#ifdef __cplusplus
}
#endif


#endif /* __LINKED_LIST_CFG_H__ */