#pragma once

#include "ICharacter.h"

class Paladin : public ICharacter {
public:
    explicit Paladin(const std::string& name = "Paladin");
    void specialMove(ICharacter& target) override;
};
