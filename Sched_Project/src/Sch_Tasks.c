/*============================================================================*/
/*                        SV C CE SOFTWARE GROUP                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Source:         %Sch_Tasks.c%
* Instance:         1
* %version:         1 %
* %created_by:      Michele Balbi %
* %date_created:    July 13 2015 %
*=============================================================================*/
/* DESCRIPTION : C source code for the scheduler's configured tasks.          */
/*============================================================================*/
/* FUNCTION COMMENT : This file describes the C source used in the scheduler's*/
/* tasks.                                                                     */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*  REVISION |   DATE      |                               |      AUTHOR      */
/*----------------------------------------------------------------------------*/
/*  1.0      | 13/07/2015  |                               | Michele Balbi    */
/* 	First draft.                                                              */
/*============================================================================*/

/* Includes */
/* -------- */
#include "conti_typedefs.h"
#include "Sch_Tasks.h"
#include "MPC5606B_GPIO_lib.h"

/* Functions macros, constants, types and datas         */
/* ---------------------------------------------------- */
/* Functions macros */

/*==================================================*/ 
/* Definition of constants                          */
/*==================================================*/ 
/* BYTE constants */


/* WORD constants */


/* LONG and STRUCTURE constants */



/*======================================================*/ 
/* Definition of RAM variables                          */
/*======================================================*/ 
/* BYTE RAM variables */
T_UBYTE counter100ms = 0;
T_UBYTE counter50ms = 0;
T_UBYTE counter25ms = 0;
T_UBYTE counter3p125ms = 0;

/* WORD RAM variables */


/* LONG and STRUCTURE RAM variables */


/*======================================================*/ 
/* close variable declaration sections                  */
/*======================================================*/ 

/* Private defines */


/* Private functions prototypes */
/* ---------------------------- */



/* Exported functions prototypes */
/* ----------------------------- */

/* Inline functions */
/* ---------------- */
/**************************************************************
 *  Name                 : inline_func	2
 *  Description          :
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :
 *  Critical/explanation :    [yes / No]
 **************************************************************/


/* Private functions */
/* ----------------- */
/**************************************************************
 *  Name                 : private_func
 *  Description          :
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :
 *  Critical/explanation :    [yes / No]
 **************************************************************/


/* Exported functions */
/* ------------------ */
/**************************************************************
 *  Name                 :	export_func
 *  Description          :
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :
 *  Critical/explanation :    [yes / No]
 **************************************************************/

void Sch_Task_3P125MS(void){

	/*T_UWORD i;
	
	OUTPUT_HIGH(PC2);
	
	for(i=0;i<1000;i++){
		
	}	
	
	OUTPUT_LOW(PC2);
	counter3p125ms++;
	
	if(counter3p125ms==160){
		LED_TOGGLE(LED4);
		counter3p125ms=0;
	}*/
}

void Sch_Task_6P25MS(void){
	T_UWORD i;
	
	OUTPUT_HIGH(PC3);
	
	for(i=0;i<1000;i++){
		
	}	
	
	OUTPUT_LOW(PC3);
}

void Sch_Task_12P5MS(void){
	T_UWORD i;
	
	OUTPUT_HIGH(PC4);
	
	for(i=0;i<1000;i++){
		
	}	
	
	OUTPUT_LOW(PC4);
	
}

void Sch_Task_25MS(void){
	T_UWORD i;
	
	OUTPUT_HIGH(PC5);
	
	for(i=0;i<1000;i++){
		
	}	
	
	OUTPUT_LOW(PC5);
}

void Sch_Task_50MS(void){
	T_UWORD i;
	
	OUTPUT_HIGH(PC6);
	
	for(i=0;i<1000;i++){
		
	}	
	
	OUTPUT_LOW(PC6);
	
}

void Sch_Task_100MS(void){
	T_UWORD i;
	
	OUTPUT_HIGH(PC2);
	
	for(i=0;i<1000;i++){
		
	}	
	
	OUTPUT_LOW(PC2);
}