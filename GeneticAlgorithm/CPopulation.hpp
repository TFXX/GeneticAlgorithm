#pragma once

#include "pch.h"
#include "CEnvironment.hpp"

template<typename ChromType>
class CPopulation
{
private:
	std::uint32_t m_initalChromNum = 0;
	std::vector<ChromType> m_selectedChromVec;
	std::vector<ChromType> m_hereditaryChromVec;
private:
	
	void make_selection(double selectionCoefficient);
	void make_crossover();
	void make_mutation();
public:
	template<typename DecodeValueType>
	void evolve_at(const CEnvironment<DecodeValueType> &environment);

	CPopulation(std::uint32_t chromNum);
};

template<typename ChromType>
CPopulation<ChromType>::CPopulation(std::uint32_t initalChromNum)
	: m_initalChromNum(initalChromNum), m_hereditaryChromVec(initalChromNum)
{
	;
}



template<typename ChromType>
template<typename DecodedValueType>
void CPopulation<ChromType>::evolve_at(const CEnvironment<DecodedValueType> &environment)
{
	environment.calculate_fitness(m_hereditaryChromVec.begin(), m_hereditaryChromVec.end());
	make_selection(0.0f);
	
}

template <typename ChromType>
void CPopulation<ChromType>::make_selection(double selectionCoefficient)
{
	// 轮盘赌算法来选择个体
	std::vector<double>(m_initalChromNum);
	
	int totalFitness = 0;
	for(auto iter = m_hereditaryChromVec.cbegin(); iter != iter.cend(); iter++)
	{
		totalFitness += iter -> get_fitness();
	}

	double currentAFitness = 0.0f;
	for(auto iter = m_hereditaryChromVec.cbegin(); iter != iter.cend(); iter++)
	{
		currentAFitness += static_cast<double>(iter -> get_fitness()) / totalFitness();
		vector[iter - m_hereditaryChromVec.cbegin()] = currentAFitness;
	}

	for(size_t count = m_hereditaryChromVec.size() * selectionCoefficient; count > 0; count--)
	{
		;
	}
}