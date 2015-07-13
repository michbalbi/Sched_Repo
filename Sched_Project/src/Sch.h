/*============================================================================*/
/*                        SV C BC SOFTWARE GROUP                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Include:        %Sch.h%
* Instance:         1
* %version:         1 %
* %created_by:      Michele Balbi %
* %date_created:    July 13 2015 %
*=============================================================================*/
/* DESCRIPTION : Header file for the Scheduler's main functionality.          */
/*============================================================================*/
/* FUNCTION COMMENT :   										              */
/*                                                                            */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*  REVISION |   DATE      |                               |      AUTHOR      */
/*----------------------------------------------------------------------------*/
/*  1.0      | 13/07/2015  |                               | Michele Balbi    */
/* First Draft 																  */
/*============================================================================*/

#ifndef _SCH_H_                               /* To avoid double inclusion */
#define _SCH_H_

/* Includes */
/* -------- */


/* Exported types and constants */
/* ---------------------------- */

/* Types definition */
/* typedef */


/*==================================================*/ 
/* Declaration of exported constants                */
/*==================================================*/ 
/* BYTE constants */


/* WORD constants */


/* LONG and STRUCTURE constants */



/*======================================================*/ 
/* Definition of RAM variables                          */
/*======================================================*/ 
/* BYTES */


/* WORDS */


/* LONGS and STRUCTURES */


/*======================================================*/ 
/* close variable declaration sections                  */
/*======================================================*/ 

/* Exported functions prototypes and macros */
/* ---------------------------------------- */

/* Functions prototypes */
 /*void Sch_Init(S_TASK_DESCRIPTOR *S_SCH_CONFIG);*/
 void Sch_DeInit(void);
 void Sch_OSTick(void);
 void Sch_Start(void);
 void Sch_Background(void);
 
/* Functions macros */


/* Exported defines */


#endif


