#include "Operator.h"



Operator::Operator() : PrvekVyrazu(EnumDruhPrvku::OPERATOR)
{

}

Operator::Operator(char znakOperatoru) : PrvekVyrazu(EnumDruhPrvku::OPERATOR) {
	switch (znakOperatoru)
	{
	case'+':
		this->_operator = EnumOperatory::PLUS;
		break;
	case '-':
		this->_operator = EnumOperatory::MINUS;
		break;
	case '*':
		this->_operator = EnumOperatory::KRAT;
		break;
	case '/':
		this->_operator = EnumOperatory::DELENO;
		break;

	default:
		this->_operator = EnumOperatory::NEDEFINOVATELNY;
	}
}


EnumOperatory Operator::dejDruhOperatoru()
{
	return _operator;
}

Operator::~Operator()
{
}


