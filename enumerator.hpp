#pragma once

#include <vector>
#include <string>
#include <algorithm>
#include <stdexcept>
#include <cmath>

using uchar = unsigned char;

class Enumerator
{
public:
	Enumerator(
		const int maxLen,
		const std::vector<uchar>& charArray
	);

	std::string next              ();
	bool        preset            (const std::vector<uchar>& array);
	bool        setLimit          (const std::vector<uchar>& array);
	double      getMaxCombinations() const;
  
private:
  
  struct Slider
	{
		Slider(const int trigger);

		bool      inc();

		int       get() const;
		void      set(const int val);

		void      attachLeftReferece(Slider* ref);

	private:
		int       m_val     = -1;
		Slider*   m_leftRef = nullptr;

		const int m_trigger;
	};

private:
	void        init();

private:
	int                 m_level    = 0;
	int                 m_maxLevel = 0;

	std::vector<Slider> m_sliderBox;
	std::vector<uchar>  m_userCharArray;
	
	std::string         m_limitArray;

	bool                m_hasLimit         = false;
	bool                m_isLimitTriggered = false;
};


Enumerator::Enumerator(
	const int maxLen,
	const std::vector<uchar>& charArray)

	: m_maxLevel(maxLen)
	, m_sliderBox(maxLen, Slider(charArray.size()))
	, m_userCharArray(charArray)
{
	init();
}

Enumerator::Slider::Slider(const int trigger)
	: m_trigger(trigger)
{
}

bool Enumerator::Slider::inc()
{
	if (++m_val == m_trigger)
	{
		m_val = 0;
		if (m_leftRef != nullptr)
		{
			return m_leftRef->inc();
		}
		return true;
	}
	return false;
}

int Enumerator::Slider::get() const
{
	return m_val;
}

void Enumerator::Slider::set(const int val)
{
	m_val = val;
}

void Enumerator::Slider::attachLeftReferece(Slider* ref)
{
	m_leftRef = ref;
}
 
std::string Enumerator::next()
{
	std::string ret;

	if (m_isLimitTriggered) return ret;

	if (m_sliderBox[m_level].inc())
	{
		m_level++;
		if (m_level > m_maxLevel - 1) return ret;
		else m_sliderBox[m_level].inc();
	}

	for (auto& el : m_sliderBox)
	{
		if (el.get() == -1) break;
		ret += m_userCharArray[el.get()];
	}

	if (m_hasLimit)
	{
		if (ret == m_limitArray)
		{
			m_isLimitTriggered = true;
		}
	}

	return ret;
}

bool Enumerator::preset(const std::vector<uchar>& array)
{
	//TODO: need to refactor this

    if (array.empty() || array.size() > m_maxLevel)
    {
        return false;
    }

    for (const auto& elem : array)
    {
        if (std::find(m_userCharArray.begin(), m_userCharArray.end(), elem) == m_userCharArray.end())
        {
            return false;
        }
    }

    for (int i = 0; i < array.size(); ++i)
    {
        if (i == m_maxLevel) break;

        for (int j = 0; j < m_userCharArray.size(); ++j)
        {
            if (m_userCharArray[j] == array[i])
            {
                m_sliderBox[i].set(j);

                if (i > 0)
                {
                    m_level++;
                }
            }
        }
    }
    return true;
}

bool Enumerator::setLimit(const std::vector<uchar>& array)
{
	//TODO: need to refactor this
	
    if (array.empty() || array.size() > m_maxLevel)
    {
        return false;
    }

    for (const auto& elem : array)
    {
        if (std::find(m_userCharArray.begin(), m_userCharArray.end(), elem) == m_userCharArray.end())
        {
            return false;
        }
    }

    for (int i = 0; i < array.size(); ++i)
    {
        if (i == m_maxLevel) break;
        m_limitArray += array[i];
    }

    if (!m_limitArray.empty()) 
    {
        m_hasLimit = true;
        return true;
    }
    return false;
}

void Enumerator::init()
{
	for (int i = 1; i < m_maxLevel; ++i)
	{
		m_sliderBox[i].attachLeftReferece(&m_sliderBox[i - 1]);
	}
}

double Enumerator::getMaxCombinations() const
{
	double ret = 0;
	for (int i = 1; i <= m_maxLevel; ++i)
	{
		ret += pow(m_userCharArray.size(), i);
	}

	return ret;
}
