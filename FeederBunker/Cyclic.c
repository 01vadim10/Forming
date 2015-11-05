
#include <bur/plctypes.h>
#include <lib.h>

#ifdef _DEFAULT_INCLUDES
	#include <AsDefault.h>
#endif

void _CYCLIC ProgramCyclic(void)
{
	contrPanel(H205_Ready_DI, H205_ElmTranspStart_DI, H205_StartForwardMan_DI, H205_StartBackwardMan_DI,
			  &H205_Ready_DO, &H205_TranspElmOn_DO, &H205_CombElmForwOn_DO, &H205_CombElmBackwOn_DO)
	if (!blockingCheck(H205_Ready_DI, H205_PrElmOn_DI))
	{
		if (checkElm(H205_TransporterOn_DI, H205_ElmTranspStart_DI, &H205_ElmStartStop_DO_B))
			elmStart(&H205_ElmStartStop_DO);
		else elmStop(&H205_ElmStartStop_DO_B, &H205_ElmStartStop_DO);
		if (checkElm(H205_StartForward_DI, H205_StartForwardMan_DI, &H205_StartForward_DO_B))
			elmStart(&H205_StartForward_DO);
		else elmStop(&H205_StartForward_DO_B, &H205_StartForward_DO);
		if (checkElm(H205_StartBackward_DI, H205_StartBackwardMan_DI, &H205_StartBackward_DO_B))
			elmStart(&H205_StartBackward_DO);
		else elmStop(&H205_StartBackward_DO_B, &H205_StartBackward_DO);
	}
}
