using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Serialization;

namespace WarhammerBattleGenerator
{
    [XmlRoot("units")]
    public class UnitCollection
    {
        [XmlElement("unit")]
        public List<Unit> units { get; set; }

        public static UnitCollection Load(string saveLocation)
        {
            XmlSerializer deserializer = new XmlSerializer(typeof(UnitCollection));
            TextReader reader = new StreamReader(saveLocation);

            object obj = deserializer.Deserialize(reader);
            UnitCollection XmlData = (UnitCollection)obj;
            reader.Close();

            
            return XmlData;
        }

        public void Save(string saveLocation)
        {
            XmlSerializer statSaver = new XmlSerializer(typeof(UnitCollection));

            TextWriter writer = new StreamWriter(saveLocation);

            statSaver.Serialize(writer, this);
            writer.Dispose();
        }

        public string[] GetUnitNames()
        {
            return units.Select(x => x.unitName).ToArray();
        }

        public Unit GetUnit(string unitName)
        {
            Unit retrievedUnit = units.FirstOrDefault(x => x.unitName.Equals(unitName));

            if(retrievedUnit == null)
            {
                retrievedUnit = Unit.MakeDefault();
            }

            return retrievedUnit;
        }

        public bool DoesUnitExist(string unitName)
        {
            //The unit exists if we found the name for it.
            return GetUnitNames().FirstOrDefault(x => x.Equals(unitName)) == null;
        }

        public bool AddOrUpdate(Unit unitToAdd)
        {
            Unit existingUnit = units.FirstOrDefault(x => x.unitName.Equals(unitToAdd.unitName, StringComparison.OrdinalIgnoreCase));

            if (existingUnit == null) //We are adding the unit
            {
                units.Add(unitToAdd);
                return true;
            }
            else //Updating
            {
                units.Remove(existingUnit);
                units.Add(unitToAdd);
                return true;
            }
        }

        public bool Delete(string unitName)
        {
            Unit existingUnit = units.FirstOrDefault(x => x.unitName.Equals(unitName, StringComparison.OrdinalIgnoreCase));

            if(existingUnit != null)
            {
                units.Remove(existingUnit);
                return true;
            }

            return true;
        }
    }
}
