#include "StdAfx.h"
#include "Question.h"

bool Question::SetAnswerCount(BYTE a)
{
	if (a == count_ans)
		return true;
	if (a >= 1)
	{
		if (ans != NULL)
			delete[] ans;
		ans = new BYTE[a];
		count_ans = a;
		return true;
	}
	else
		return false;
}

BYTE Question::GetAnswerCount()
{
	return count_ans;
}

bool Question::SetVariantAnswerCount(BYTE a)
{
	if (a == count_var_ans)
		return true;
	if (a >= 1)
	{
		if (variants != NULL)
			delete[] variants;
		variants = new CString[a];
		count_var_ans = a;
		return true;
	}
	else
		return false;
}


BYTE Question::GetVariantAnswerCount()
{
	return count_var_ans;
}

Question::Question()
{
	variants = NULL;
	ans = NULL;
}


Question::~Question()
{
	if (variants != NULL)
	{
		delete[] variants;
		variants = NULL;
	}

	if (ans != NULL)
	{
		delete[] ans;
		ans = NULL;
	}
}

CString Question::GetVariant(BYTE index)
{
	if (index >= count_var_ans)
		return NULL;
	
	return variants[index];
}

bool Question::SetVariant(BYTE index, CString str)
{
	if (index >= count_var_ans)
		return false;
	variants[index] = str;
	return true;
}

BYTE Question::GetAnswer(BYTE index)
{
	return ans[index];
}

bool Question::SetAnswer(BYTE index, BYTE a)
{
	if (index >= count_ans)
		return false;
	ans[index] = a;
	return true;
}