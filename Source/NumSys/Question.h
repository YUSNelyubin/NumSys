//Класс вопроса
#pragma once
class Question
{
private:
	BYTE count_var_ans;//Количество вариантов ответа
	CString *variants;//Варианты ответа
	BYTE count_ans;//Количество правельных ответов
	BYTE *ans;//Правельные ответы

public:
	CString name;//Вопрос
	BYTE GetVariantAnswerCount();//Получает количество вариантов ответа
	bool SetVariantAnswerCount(BYTE a);//Изменяет количество вариантов ответа
	BYTE GetAnswerCount();//Получает количество правельных ответов
	bool SetAnswerCount(BYTE a);//Изменяет количество правельных ответов
	CString GetVariant(BYTE index);//Получает вариант ответа по индексу
	bool SetVariant(BYTE index, CString str);//Изменяет вариант ответа по индексу
	BYTE GetAnswer(BYTE index);//Получает правельный ответ по индексу
	bool SetAnswer(BYTE index, BYTE a);//Изменяет правельный ответ по индексу
	Question();
	~Question();
};

