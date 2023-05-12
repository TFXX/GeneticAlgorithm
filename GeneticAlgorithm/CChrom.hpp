#pragma once

#include "pch.h"

template<size_t geneNum>
class CChrom
{
public:
	//constexpr size_t bitNum = bitNum;
private:
	std::array<std::int8_t, geneNum> m_genes;
	std::int32_t m_fitness;
public:
	CChrom()
	{
		int8_t random = 0;
		for(size_t i = 0; i < bitNum; i++)
		{
			random = rand();
			random %= 2;
			m_genes[i] = random;

		}
	}

	void inline set_fitness(std::int32_t fitness)
	{
		m_fitness = fitness;
	}

	std::int32_t inline get_fitness()
	{
		return m_fitness;
	}
};

template<size_t geneNum>
inline CChrom<geneNum> make_CChrom()
{
	return CChrom(geneNum);
}