/*============================================================================*/
/*                        SV C CE SOFTWARE GROUP                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Source:         %Sch.c%
* Instance:         1
* %version:         1 %
* %created_by:      Michele Balbi %
* %date_created:    July 13 2015 %
*=============================================================================*/
/* DESCRIPTION : C source code for the scheduler's main functionality.        */
/*============================================================================*/
/* FUNCTION COMMENT : This file describes the C source used in the scheduler's*/
/* initialization, including the tick callback function.                      */
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
#include "MPC5606B_INTERRUPTS_lib.h"
#include "MPC5606B_PIT_lib.h"
#include "Sch_Types.h"
#include "Sch.h"


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


/* WORD RAM variables */


/* LONG and STRUCTURE RAM variables */
S_SCH_CONFIG *rps_SchConfig_ptr;

/*S_SCH_TASK_CONTROL ras_SchTaskControlBlock[];*/

S_SCH_TASK_CONTROL ras_SchTaskControlBlock[] = {
	{TASK_STATE_SUSPENDED, (void*)0 },
	{TASK_STATE_SUSPENDED, (void*)0 },
	{TASK_STATE_SUSPENDED, (void*)0 },
	{TASK_STATE_SUSPENDED, (void*)0 },
	{TASK_STATE_SUSPENDED, (void*)0 },
	{TASK_STATE_SUSPENDED, (void*)0 },
};

S_SCH_CONTROL rs_SchControl = {
	0,
	TASK_BKG,
	SCH_UNINIT,
};


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
 *  Name                 :	Sch_Init
 *  Description          :
 *  Parameters           :  void
 *  Return               :	void
 *  Critical/explanation :  
 **************************************************************/
 void Sch_Init(S_SCH_CONFIG *lps_SchConfig){
 	T_UBYTE lub_i, lub_NumberOfTasks;
 	S_TASK_DESCRIPTOR * lp_TaskDescriptorPtr; 
 	rps_SchConfig_ptr = lps_SchConfig;
 	
 	lp_TaskDescriptorPtr = (S_TASK_DESCRIPTOR *)(lps_SchConfig->SchTaskDescriptor);
 	lub_NumberOfTasks = lps_SchConfig->SchNumberOfTasks;
 	
 	/*static S_SCH_TASK_CONTROL ras_SchTaskControlBlock[];*/
 	
 	for(lub_i=0; lub_i<lub_NumberOfTasks; lub_i++){
 		/*lps_SchConfig->SchTaskDescriptor.*/
 		
 		/* Set all tasks to SUSPENDED */
 		ras_SchTaskControlBlock[lub_i].SchTaskState = TASK_STATE_SUSPENDED;
 		/*ras_SchTaskControlBlock[lub_i].TaskFunctionControlPtr = lps_SchConfig->SchTaskDescriptor[lub_i].TaskFunctionPtr;*/
 		ras_SchTaskControlBlock[lub_i].TaskFunctionControlPtr = lp_TaskDescriptorPtr->TaskFunctionPtr;
 		lp_TaskDescriptorPtr++;
 	}
  	
  	 /*TIMER_LOAD_VALUE_US(781,0);*/
    TIMER_LOAD_VALUE_CYCLES(49999U,0); /*781.25 us to cycles*/
    TIMER_ENABLE_INT(0);
    INTC_InstallINTCInterruptHandler(Sch_OSTick, PIT0_Vector, PRIORITY13);
    
    INT_LOWER_CPR(PRIORITY0);
    TIMER_INIT();
    INTC_InitINTCInterrupts(); 
  	
 	rs_SchControl.SchCounter = 0;
 	/*rs_SchControl.SchTaskRunning = TASK_BKG;*/
 	rs_SchControl.SchStatus = SCH_INIT;
 }
 
 /**************************************************************
 *  Name                 :	Sch_Start
 *  Description          :
 *  Parameters           :  void
 *  Return               :	void
 *  Critical/explanation :  
 **************************************************************/
 void Sch_Start(void){
 	/* Set scheduler status to RUNNING */
 	rs_SchControl.SchStatus = SCH_RUNNING;
 	TIMER_START(0);
 	
 	Sch_Background();
 }
 
 /**************************************************************
 *  Name                 :	Sch_DeInit
 *  Description          :
 *  Parameters           :  void
 *  Return               :	void
 *  Critical/explanation :  
 **************************************************************/
 void Sch_Stop(void){
 	TIMER_STOP(0);
 	rs_SchControl.SchStatus = SCH_HALTED;
 }

/**************************************************************
 *  Name                 :	Sch_OSTick
 *  Description          :
 *  Parameters           :  void
 *  Return               :	void
 *  Critical/explanation :  
 **************************************************************/
 void Sch_OSTick(void){
 	T_UBYTE lub_i, lub_NumberOfTasks;
 	S_TASK_DESCRIPTOR * lp_TaskDescriptorPtr; 
 	
 	lp_TaskDescriptorPtr = (S_TASK_DESCRIPTOR *)(rps_SchConfig_ptr->SchTaskDescriptor);
 
 	rs_SchControl.SchCounter++;
 	lub_NumberOfTasks = rps_SchConfig_ptr->SchNumberOfTasks;
 	/* Compare counter with each task mask and offset. Mark
 	   task as READY accordingly */
 	   
   	for(lub_i=0; lub_i<lub_NumberOfTasks; lub_i++){
   		
   		if(((lp_TaskDescriptorPtr->SchTaskMask)&(rs_SchControl.SchCounter))==(lp_TaskDescriptorPtr->SchTaskOffset)){
   			ras_SchTaskControlBlock[lub_i].SchTaskState = TASK_STATE_READY;
   		}
   		
   		lp_TaskDescriptorPtr++;
   		
   	}
 	TIMER_CLEAR_INT_FLAG(0);
 }
 
  /**************************************************************
 *  Name                 :	Sch_Background
 *  Description          :
 *  Parameters           :  void
 *  Return               :	void
 *  Critical/explanation :  
 **************************************************************/
 void Sch_Background(void){
 	/* iterate all tasks and see which one is marked as READY
 	   and execute it via their function ptr and mark it as RUNNING.
 	   Also update the SchControl.SchTaskRunning field*/
 	   	T_UBYTE lub_i, lub_NumberOfTasks;
 		lub_NumberOfTasks = rps_SchConfig_ptr->SchNumberOfTasks;
 		
 		/*lub_NumberOfTasks = (sizeof(cas_SchTaskDescriptorConfig)/sizeof(cas_SchTaskDescriptorConfig[0]))*/
 	
 	   for(;;){
 	   
 	   		for(lub_i=0; lub_i<lub_NumberOfTasks; lub_i++){	
 				
 				if(ras_SchTaskControlBlock[lub_i].SchTaskState == TASK_STATE_READY){
 					rs_SchControl.SchStatus = SCH_RUNNING;
 					ras_SchTaskControlBlock[lub_i].SchTaskState = TASK_STATE_RUNNING;
 					(ras_SchTaskControlBlock[lub_i].TaskFunctionControlPtr)();
 					ras_SchTaskControlBlock[lub_i].SchTaskState = TASK_STATE_SUSPENDED;
 					/* Set the scheduler state to idle. */
 				}
 				
 			}
 	   		
 	   			
 	   }
 }

