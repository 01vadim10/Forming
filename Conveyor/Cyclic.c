
#include <bur/plctypes.h>
#include <lib.h>

#ifdef _DEFAULT_INCLUDES
	#include <AsDefault.h>
#endif

void _CYCLIC ProgramCyclic(void)
{
	/*Блок обработки работы конвейера H202*/
	void convH202()
	{
		if (checkPanelLC(H202_ElmBeltStart_DI, &H202_DO_B)){
			convH2XX(H202_Ready_DI, H202_PrElmOn_DI, H202_DownControl_DI, H202_BordersControl_DI, H202_MoveControl_DI,
					&H202_DO_B, &H202_ElmStartStop_DO);
		}
		contrPanel(H202_Ready_DI, H202_ElmBeltStart_DI, &H202_Ready_DO, &H202_ElmOn_DO);
	}
	/*Блок обработки работы конвейера H203*/
	void convH203()
	{
		if (checkPanelLC(H203_ElmBeltStart_DI, &H203_DO_B)){
			convH2XX(H203_Ready_DI, H203_PrElmOn_DI, H203_DownControl_DI, H203_BordersControl_DI, H203_MoveControl_DI,
				&H203_DO_B, &H203_ElmStartStop_DO);
		}
		contrPanel(H203_Ready_DI, H203_ElmBeltStart_DI, &H203_Ready_DO, &H203_ElmOn_DO);
	}	
	/*Блок обработки работы конвейера H204*/
	void convH204()
	{
		if (checkPanelLC(H204_ElmBeltStart_DI, &H204_DO_B)){
			convH2XX(H204_Ready_DI, H204_PrElmOn_DI, H204_DownControl_DI, H204_BordersControl_DI, H204_MoveControl_DI,
				&H204_DO_B, &H204_ElmStartStop_DO);
		}
		contrPanel(H204_Ready_DI, H204_ElmBeltStart_DI, &H204_Ready_DO, &H204_ElmOn_DO);
	}	
	/*Блок обработки работы конвейера H207*/
	void convH207()
	{
		if (checkPanelLC(H207_ElmBeltStart_DI, &H207_DO_B)){
			convH2XX(H207_Ready_DI, H207_PrElmOn_DI, H207_DownControl_DI, H207_BordersControl_DI, H207_MoveControl_DI,
				&H207_DO_B, &H207_ElmStartStop_DO);
		}
		contrPanel(H207_Ready_DI, H207_ElmBeltStart_DI, &H207_Ready_DO, &H207_ElmOn_DO);
	}	
	/*Блок обработки работы конвейера H209*/
	void convH209()
	{
		if (checkPanelLC(H209_ElmBeltStart_DI, &H209_DO_B)){
			convH2XX(H209_Ready_DI, H209_PrElmOn_DI, H209_DownControl_DI, H209_BordersControl_DI, H209_MoveControl_DI,
				&H209_DO_B, &H209_ElmStartStop_DO);
		}
	}	
	/*Блок обработки работы конвейера H212*/
	void convH212()
	{
		if (H212_DO_BF && checkPanelLC(H212_ElmBeltStart_DI, &H212_DO_BF)){
			convH2XX(H212_Ready_DI, H212_PrElmOn_DI, H212_DownControl_DI, H212_BordersControl_DI, H212_MoveControl_DI,
					&H212_DO_BF, &H212_Forward_DO);
		} else if (H212_DO_BB && checkPanelLC(H212_ElmBeltStart_DI, &H212_DO_BB)){
			convH2XX(H212_Ready_DI, H212_PrElmOn_DI, H212_DownControl_DI, H212_BordersControl_DI, H212_MoveControl_DI,
				&H212_DO_BB, &H212_Backward_DO);
		}
	}	
	/*Блок обработки работы конвейера H213*/
	void convH213()
	{
		convH2XX(H213_Ready_DI, H213_PrElmOn_DI, H213_DownControl_DI, H213_BordersControl_DI, H213_MoveControl_DI,
				&H213_DO_B, &H213_ElmStartStop_DO);
	}	
	/*Блок обработки работы конвейера H215*/
	void convH215()
	{
		convH2XX(H215_Ready_DI, H215_PrElmOn_DI, H215_DownControl_DI, H215_BordersControl_DI, H215_MoveControl_DI,
				&H215_DO_B, &H215_ElmStartStop_DO);
	}	
	/*Блок обработки работы конвейера H216*/
	void convH216()
	{
		convH2XX(H216_Ready_DI, H216_PrElmOn_DI, H216_DownControl_DI, H216_BordersControl_DI, H216_MoveControl_DI,
				&H216_DO_B, &H216_ElmStartStop_DO);
	}	
	/*Блок обработки работы конвейера H217*/
	void convH217()
	{
		convH2XX(H217_Ready_DI, H217_PrElmOn_DI, H217_DownControl_DI, H217_BordersControl_DI, H217_MoveControl_DI,
				&H217_DO_B, &H217_ElmStartStop_DO);
	}
}
