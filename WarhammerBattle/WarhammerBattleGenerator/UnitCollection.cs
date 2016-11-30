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

        public bool Add(Unit unitToAdd)
        {
            //Make sure we aren't adding a duplicate
            if (!units.Any(x => x.unitName.Equals(unitToAdd.unitName, StringComparison.OrdinalIgnoreCase)))
            {
                units.Add(unitToAdd);
            }
            return true;
        }
    }
}
