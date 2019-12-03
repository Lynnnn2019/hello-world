#pragma once
class __declspec(dllexport) CCondition
{
public:
	CCondition(const std::wstring& conditionStr);
	~CCondition(void);
	bool IsTrue();
	void SetParam(double val);
private:
	CCondition(void);
	CCondition(const CCondition&);
	CCondition& operator=(const CCondition&);
private:
	struct  ConditionImp;
	std::shared_ptr<ConditionImp> m_pImpl;
};
