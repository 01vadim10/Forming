/*
	Проверка блокировок:
  	если сработала одна из блокировок возвращает 1, иначе 0
*/
BOOL blockingCheck(BOOL PrElmOn, BOOL DownControl, BOOL BordersControl, BOOL MoveControl)
{
	BOOL out;
	out = 0;
	if (PrElmOn || DownControl || BordersControl || MoveControl)
		out = 1;
	
	return out;
}


/* 	
	Mode = 0 - ручной режим
	Mode = 1 - автомат. режим
*/
BOOL blockingCheckMode(BOOL Mode, BOOL Ready, BOOL ElmBeltStart)
{
	BOOL out;
	out = 0;
	if (Mode == 0)
		out = !Ready;
	else out = !ElmBeltStart;
	
	return out;
}

/*	
	Запуск конвейера
	ConvStart - переменная DO, которая запускает данный конвейер
*/
void convH2XXStart(BOOL ConvStart)
{
	ConvStart = 1;
}

/*	
	Остановка конвейера
	ConvStart - переменная DO, которая запускает данный конвейер
*/
void convH2XXStop(BOOL ConvStart)
{
	ConvStart = 0;
}

/*
	convH2XX_DO_B - переменная привязываемая к кнопке панели, отвечающая за запуск конвейера ("Пуск/Стоп")
*/
void convH2XX(BOOL PrElmOn, BOOL DownControl, BOOL BordersControl, BOOL MoveControl, BOOL Mode, BOOL Ready, BOOL ElmBeltStart,
	BOOL ConvStart)
{
	if (!blockingCheck(PrElmOn, DownControl, BordersControl, MoveControl)/* && !blockingCheckMode(Mode, Ready, ElmBeltStart)*/ &&
		convH2XX_DO_B)
		convH2XXStart(ConvStart);
	else convH2XXStop(ConvStart);
}