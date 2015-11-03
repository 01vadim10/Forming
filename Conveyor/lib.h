/*
	Проверка блокировок:
  	если сработала одна из блокировок возвращает 1, иначе 0
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
	Запуск конвейера
	ConvStart - переменная DO, которая запускает данный конвейер
*/
void convH2XXStart(BOOL *ConvStart)
{
	*ConvStart = 1;
}

/*	
	Остановка конвейера
	ConvStart - переменная DO, которая запускает данный конвейер
*/
void convH2XXStop(BOOL *ConvH2XX_DO_B, BOOL *ConvStart)
{
	*ConvStart = 0;
	*ConvH2XX_DO_B = 0;
}

/*
	Обработка сигналов с пульта местного управления.
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
	convH2XX_DO_B - переменная привязываемая к кнопке панели, отвечающая за запуск конвейера ("Пуск/Стоп")
*/
void convH2XX(BOOL Ready_DI, BOOL PrElmOn, BOOL DownControl, BOOL BordersControl, BOOL MoveControl, 
			  BOOL *ConvH2XX_DO_B, BOOL *ConvStart)
{
	if (!blockingCheck(Ready_DI, PrElmOn, DownControl, BordersControl, MoveControl) && *ConvH2XX_DO_B)
		convH2XXStart(&ConvStart);
	else convH2XXStop(&ConvH2XX_DO_B, &ConvStart);
}