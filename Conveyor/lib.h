/*
	�������� ����������:
  	���� ��������� ���� �� ���������� ���������� 1, ����� 0
*/
BOOL blockingCheck(BOOL Ready, BOOL PrElmOn, BOOL DownControl, BOOL BordersControl, BOOL MoveControl)
{
	BOOL out;
	out = 0;
	if (Ready || PrElmOn || DownControl || BordersControl || MoveControl)
		out = 1;
	
	return out;
}

/*	
	������ ���������
	ConvStart - ���������� DO, ������� ��������� ������ ��������
*/
void convH2XXStart(BOOL *ConvStart)
{
	*ConvStart = 1;
}

/*	
	��������� ���������
	ConvStart - ���������� DO, ������� ��������� ������ ��������
*/
void convH2XXStop(BOOL *ConvH2XX_DO_B, BOOL *ConvStart)
{
	*ConvStart = 0;
	*ConvH2XX_DO_B = 0;
}

/*
	��������� �������� � ������ �������� ����������.
*/
void contrPanel(BOOL Ready_DI, BOOL ElmBeltStart_DI, BOOL *Ready, BOOL *ElmOn)
{
	*Ready = Ready_DI;
	*ElmOn = ElmBeltStart_DI;
}

BOOL checkPanelLC(BOOL ElmBeltStart_DI, BOOL *ConvH2XX_DO_B)
{
	if (*ConvH2XX_DO_B)
		*ConvH2XX_DO_B = !ElmBeltStart_DI;
	return *ConvH2XX_DO_B;
}

/*
	convH2XX_DO_B - ���������� ������������� � ������ ������, ���������� �� ������ ��������� ("����/����")
*/
void convH2XX(BOOL Ready_DI, BOOL PrElmOn, BOOL DownControl, BOOL BordersControl, BOOL MoveControl, 
			  BOOL *ConvH2XX_DO_B, BOOL *ConvStart)
{
	if (!blockingCheck(Ready_DI, PrElmOn, DownControl, BordersControl, MoveControl) && *ConvH2XX_DO_B)
		convH2XXStart(&ConvStart);
	else convH2XXStop(&ConvH2XX_DO_B, &ConvStart);
}