#include "StdAfx.h"
#include "Condition.h"
#include "muParser.h"
#include "muParserGlobal.h"
struct  CCondition::ConditionImp
{
	ConditionImp(void):parser(new mu::Parser),parserVariable(0.)
	{
	}
	~ConditionImp(){}
	std::shared_ptr<mu::Parser> parser;
	double parserVariable; 
};

CCondition::CCondition( const std::wstring& conditionStr ):m_pImpl(new ConditionImp)
{
	m_pImpl->parser->DefineFun(L"Phy",PhysicalValue,false);
	m_pImpl->parser->DefineFun(L"BufBit",BufferBitValue,false);
	m_pImpl->parser->DefineFun(L"Code",Code,false);
	m_pImpl->parser->DefineFun(L"Vol",VoltageValue,false);
	m_pImpl->parser->DefineFun(L"ACode",AdjustCode,false);
	m_pImpl->parser->DefineVar(L"param", &m_pImpl->parserVariable);  
	m_pImpl->parser->SetExpr( conditionStr.c_str());
}

CCondition::~CCondition(void)
{
}

bool CCondition::IsTrue()
{
	return Calculate(m_pImpl->parser)>0;
}

void CCondition::SetParam( double val )
{
	m_pImpl->parserVariable=val;
}
