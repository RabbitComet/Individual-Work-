#include "CharacterFactory.h"
#include "../Characters/Paladin.h"
#include "../Characters/Heretic.h"
#include "../Logging/LogLevel.h"

CharacterFactory::CharacterFactory(std::vector<ICharacterObserver*> observers)
	: observers(observers) {}

ICharacter* CharacterFactory::createCharacter(int type, const std::string& name) {
	ICharacter* created = nullptr;
	switch (type) {
		case 1: // Paladin
			created = new Paladin(name.empty() ? "Paladin" : name);
			break;
		case 2: // Heretic
			created = new Heretic(name.empty() ? "Heretic" : name);
			break;
		default:
			return nullptr;
	}

	if (created) {
		for (ICharacterObserver* observer : observers) {
            created->addObserver(observer);
        }
		std::string label = (type == 1) ? "Paladin" : "Heretic";
        for(ICharacterObserver* observer : observers) {
            observer->onAction(std::string("Created " + label), LogLevel::INFO);
        }
	}

	return created;
}
