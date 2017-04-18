#include "UnitFactory.h"


namespace UnitClasses
{
	UnitFactory::UnitFactory(const char* fileLocation)
	{
		tinyxml2::XMLDocument doc;
		doc.LoadFile(fileLocation);

		for (tinyxml2::XMLElement* child = doc.FirstChildElement("units")->FirstChildElement("unit"); child != NULL; child = child->NextSiblingElement())
		{
			const char* unitName = child->FirstChildElement("unitName")->GetText();
			const char* unitType = child->FirstChildElement("unitType")->GetText();

			tinyxml2::XMLElement* statsFromXML = child->FirstChildElement("stats");

			int weaponSkill = std::stoi(statsFromXML->FirstChildElement("weaponSkill")->GetText());
			int ballisticSkill = std::stoi(statsFromXML->FirstChildElement("ballisticSkill")->GetText());
			int strength = std::stoi(statsFromXML->FirstChildElement("strength")->GetText());
			int toughness = std::stoi(statsFromXML->FirstChildElement("toughness")->GetText());
			int wounds = std::stoi(statsFromXML->FirstChildElement("wounds")->GetText());
			int attacks = std::stoi(statsFromXML->FirstChildElement("attacks")->GetText());
			int initiative = std::stoi(statsFromXML->FirstChildElement("initiative")->GetText());
			int leadership = std::stoi(statsFromXML->FirstChildElement("leadership")->GetText());
			int save = std::stoi(statsFromXML->FirstChildElement("save")->GetText());

			UnitClasses::Stats* stats = new UnitClasses::Stats(weaponSkill, ballisticSkill, strength, toughness, wounds, attacks, initiative, leadership, save);

			Add(std::string(unitName), std::string(unitType), stats);


		}
	}

	UnitFactory::~UnitFactory()
	{
		for (std::pair<std::string, UnitClasses::Unit*> unit : units)
		{
			delete unit.second;
			unit.second = nullptr;
		}
	}

	void UnitFactory::GetUnitNames(const char *names[100])
	{
		int index = 0;
		for (std::pair<std::string, UnitClasses::Unit*> unit : units)
		{
			names[index] = unit.first.c_str();
			index++;
		}
	}

	void UnitFactory::Add(std::string name, std::string unitType, UnitClasses::Stats* stats)
	{
		units[name] = new UnitClasses::Unit(name, unitType, stats);
	}

	UnitClasses::Unit* UnitFactory::CreateUnit(std::string unitName)
	{
		return new UnitClasses::Unit(*units[unitName]);
	}
}