#pragma once

#include <string>
#include "../Characters/ICharacter.h"
#include "../Characters/ICharacterObserver.h"
#include "../Logging/LogLevel.h"
#include<vector>
class CharacterFactory {
public:
    CharacterFactory(std::vector<ICharacterObserver*> observers);
    ~CharacterFactory() = default;

    // type: 1 == Paladin, 2 == Heretic
    // Returned pointer is owned by the caller and must be deleted.
    ICharacter* createCharacter(int type, const std::string& name = "");

private:
    std::vector<ICharacterObserver*> observers;
};
