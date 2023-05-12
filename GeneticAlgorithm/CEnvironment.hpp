#pragma once

#include "pch.h"
#include "CChrom.hpp"


template <typename Chrom_t>
class CEnvironment
{
private:
	uint32_t m_chromNum = 0;
	std::vector<Chrom_t> m_selectedChromVec;
	std::vector<Chrom_t> m_hereditaryChromVec;
private
	void make_selection();
	void make_crossover();
	void make_mutation();
public:
	/**
		@brief ģ�⻷�������ݻ�
	**/
	template<typename OutputIterator, typename InputIterator>
	void evolve(InputIterator srcFirst, InputIterator srcLast, OutputIterator dstFirst);
	
	/**
		@brief ����Ⱦɫ���ڻ����е���Ӧ��
	**/
	virtual int calculate_fitness(const Chrom_t &chrom) = 0;
	
	/**
		@brief ģ����Ϊѡ��
	**/
	void select_chrom();

	/**
		@brief	����Ⱦɫ��
	**/
	//template<typename OutputIterator>
	void make_new_generation(std::uint32_t chromNum);
};


template<typename Chrom_t>
template<typename OutputIterator, typename InputIterator>
void CEnvironment<Chrom_t>::evolve(InputIterator srcFirst, InputIterator srcLast, OutputIterator dstFirst)
{
	;
}

template<typename Chrom_t>
void CEnvironment<Chrom_t>::make_new_generation(std::uint32_t chromNum)
{
	m_chromNum = chromNum;
	m_hereditaryChromVec.reserve(m_chromNum);
	for(auto iter = m_hereditaryChromVec.begin(); iter != m_hereditaryChromVec.end() && chromNum > 0; i++)
	{
		*iter = Chrom_t();
		chromNum--;
	}

	for(; chromNum > 0; chromNum--)
	{
		m_hereditaryChromVec.emplace_back();
	}	
}