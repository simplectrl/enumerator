// enum_v1.hpp -- Enumerator class

#pragma once

#include <vector>
#include <string>
#include <algorithm>
#include <stdexcept>
#include <cmath>

#define OUT

using uchar = unsigned char;

class Enumerator
{
public:
	Enumerator(
		const int maxLen,
		const std::vector<uchar>& charArray
	);

	bool     next              (OUT std::string& result);
	bool     preset            (const std::vector<uchar>& array);
	double   getMaxCombinations() const;

private:
    bool incrementSlider()
    {
        auto it = m_sliderPositions.begin();

        while (it != m_sliderPositions.end())
        {
            if (*it == nullptr)
            {
                *it = &m_userCharArray.front();
                m_level++;
                return true;
            }

            if (*it != &m_userCharArray.back())
            {
                (*it)++;
                return true;
            }
            else
            {
                *it = &m_userCharArray.front(); 
                ++it;
            }
        }

        return false;
    }
 
    std::vector<const uchar*> m_sliderPositions;
    size_t                    m_sliderPosition = 0;

private:
    size_t                    m_level = 0;
	const size_t              m_maxLevel = 0;
	const std::vector<uchar>  m_userCharArray;
};

Enumerator::Enumerator(const int maxLen, const std::vector<uchar>& charArray)
    : m_maxLevel(maxLen), m_userCharArray(charArray)
{
    m_sliderPositions.resize(m_maxLevel, nullptr);
}
 
bool Enumerator::next(OUT std::string& result)
{
    bool ret = incrementSlider();

    if (result.size() < m_level)
    {
        result.resize(m_level);
    }
    
    for (size_t i = 0; i < m_level; ++i)
    {
        result[m_level - 1 - i] = *m_sliderPositions[i];
    }

    return ret;
}

bool Enumerator::preset(const std::vector<uchar>& array)
{
    if (array.empty() || array.size() > m_maxLevel)
    {
        return false; 
    }

    for (size_t i = 0; i < array.size(); ++i)
    {
        auto it = std::find(m_userCharArray.begin(), m_userCharArray.end(), array[i]);
        if (it == m_userCharArray.end())
        {
            return false; 
        }
        m_sliderPositions[i] = &(*it);
    }

    m_level = array.size();
    return true;
}

double Enumerator::getMaxCombinations() const
{
	auto size = m_userCharArray.size();
	double ret = 0;
	for (int i = 1; i <= m_maxLevel; ++i)
	{
		ret += pow(size, i);
	}

	return ret;
}
