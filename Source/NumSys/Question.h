//����� �������
#pragma once
class Question
{
private:
	BYTE count_var_ans;//���������� ��������� ������
	CString *variants;//�������� ������
	BYTE count_ans;//���������� ���������� �������
	BYTE *ans;//���������� ������

public:
	CString name;//������
	BYTE GetVariantAnswerCount();//�������� ���������� ��������� ������
	bool SetVariantAnswerCount(BYTE a);//�������� ���������� ��������� ������
	BYTE GetAnswerCount();//�������� ���������� ���������� �������
	bool SetAnswerCount(BYTE a);//�������� ���������� ���������� �������
	CString GetVariant(BYTE index);//�������� ������� ������ �� �������
	bool SetVariant(BYTE index, CString str);//�������� ������� ������ �� �������
	BYTE GetAnswer(BYTE index);//�������� ���������� ����� �� �������
	bool SetAnswer(BYTE index, BYTE a);//�������� ���������� ����� �� �������
	Question();
	~Question();
};

