#include "UnitCollection.h"




UnitCollection::UnitCollection(const char* fileLocation)
{
	units = new std::list<Unit*>();

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

		Stats* stats = new Stats(weaponSkill, ballisticSkill, strength, toughness, wounds, attacks, initiative, leadership, save);

		Add(std::string(unitName), std::string(unitType), stats);


	}
}

void UnitCollection::Add(std::string name, std::string unitType, Unit* unit)
{

}

void UnitCollection::Add(std::string name, std::string unitType, Stats* stats)
{
	units->push_front(new Unit(name, unitType, stats));
}


UnitCollection::~UnitCollection()
{
	for (Unit* unit : (*units))
	{
		delete unit;
		unit = nullptr;
	}

	delete units;
	units = nullptr;
}
