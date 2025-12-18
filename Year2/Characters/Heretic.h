#pragma once

#include "ICharacter.h"

class Heretic : public ICharacter {
public:
    explicit Heretic(const std::string& name = "Heretic");
    void specialMove(ICharacter& target) override;
};
