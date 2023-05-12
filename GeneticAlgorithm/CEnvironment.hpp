#pragma once

#include "pch.h"
#include "CChrom.hpp"


template <typename ChromType>
class CEnvironment
{
public:
	
	template<typename InputIterator>
	void calculate_fitness(InputIterator first, InputIterator last);

	/**
		@brief 计算染色体在环境中的适应度
	**/
	virtual std::int32_t calculate_fitness(ChromType::decodeValue_t decodedValue) = 0;
};

template<typename ChromType>
template<typename InputIterator>
void CEnvironment<ChromType>::calculate_fitness(InputIterator first, InputIterator last)
{
	for(auto iter = first; iter != last; iter++)
	{
		iter -> set_fitness(calculate_fitness(iter -> decode()));
	}
}