#pragma once

#include "pch.h"

template<size_t geneNum, typename DecodedValueType>
class CChrom
{
private:
	std::array<std::int8_t, geneNum> m_genes;
	std::int32_t m_fitness;
public:
	using DecodedValue_t = DecodedValueType;
public:
	CChrom()
	{
		int8_t random = 0;
		for(size_t i = 0; i < geneNum; i++)
		{
			random = rand();
			random %= 2;
			m_genes[i] = random;

		}
	}

	virtual DecodedValue_t decode() = 0;

	void inline set_fitness(std::int32_t fitness)
	{
		m_fitness = fitness;
	}

	std::int32_t inline get_fitness()
	{
		return m_fitness;
	}
};

template<size_t geneNum, typename DecodedValueType>
inline CChrom<geneNum, DecodedValueType> make_CChrom()
{
	return CChrom(geneNum);
}