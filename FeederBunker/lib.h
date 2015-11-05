/*
	�������� ����������:
  	���� ��������� ���� �� ���������� ���������� 1, ����� 0
	?MoveControl - H205_MoveControl_DI - �������� �������� ������� �������� - ������ ����� ����������
*/
BOOL blockingCheck(BOOL Ready, BOOL PrElmOn/*, BOOL MoveControl*/)
{
	BOOL out;
	out = 0;
	if (Ready || PrElmOn/* || MoveControl*/)
		out = 1;
	
	return out;
}

/*	
	������ �������
	*ElmStart - ���������� DO, ������� ��������� ������
*/
void elmStart(BOOL *ElmStart)
{
	*ElmStart = 1;
}

/*	
	��������� �������
	*ElmStop - ���������� DO, ������� ��������� ������
*/
void elmStop(BOOL *ElmStart_DO_B, BOOL *ElmStart)
{
	*ElmStart_DO_B = 0;
	*ElmStart = 0;
}

/*
	��������� �������� � ������ �������� ����������.
*/
void contrPanel(BOOL Ready_DI, BOOL ElmTranspStart_DI, BOOL StartForward_DI, BOOL StartBackward_DI,
	BOOL *Ready, BOOL *TranspElmOn_DO, BOOL *CombElmForwOn_DO, BOOL *CombElmBackwOn_DO)
{
	*Ready = Ready_DI;
	*TranspElmOn_DO = ElmTranspStart_DI;
	*CombElmForwOn_DO = StartForward_DI;
	*CombElmBackwOn_DO = StartBackward_DI;
}

/*
	������� ��������� ������� �� ������ ��������(c ������ �������� ����������), ���� ��,
	�� ��������� ������ ������� � ������
*/
BOOL checkElm(BOOL Transp_DI, BOOL TranspP_DI, BOOL *Elm_DO_B)
{
	if (Transp_DI || TranspP_DI)
		*Elm_DO_B = 0;
	return *Elm_DO_B;
}