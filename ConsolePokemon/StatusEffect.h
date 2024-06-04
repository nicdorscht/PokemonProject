#pragma once

#include <string>

class StatusEffect
{
private:
	std::string effect_name;
	
protected:
	StatusEffect(std::string new_effect_name);
	~StatusEffect();

public:
	virtual void effect() {}
};

