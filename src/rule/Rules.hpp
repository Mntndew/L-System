#pragma once
#include <string>
#include <map>

class Rules
{
public:
	Rules()
	{
		m_string = "F";
		registerRules();
	}

	~Rules()
	{}

	std::string getRule(const char& id) const
	{
		auto rule = m_rules.find(id);
		
		if(rule != m_rules.end())
		{
			return rule->second;	
		}
	}

	void iterate()
	{
		std::string tmp;
		
		for(int i = 0; i < m_string.size(); ++i)
		{
			if(m_string[i] != '+' && m_string[i] != '-')
			{
				tmp.append(getRule(m_string[i]));
			}
			else
			{
				tmp += m_string[i];
			}
		}

		m_string = tmp;
	}
	
	std::string getString() const
	{
		return m_string;
	}

private:
	std::map<char, std::string> m_rules;
	std::string m_string;
	
	void registerRules()
	{
		m_rules['F'] = "G+F+G";
		m_rules['G'] = "F-G-F";
	}
};

