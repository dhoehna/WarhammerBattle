using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Serialization;

namespace WarhammerBattleGenerator.Configurations
{
    [XmlRoot("StatsConfiguration")]
    public class StatConfiguration
    {
        [XmlElement("UnitTypes")]
        public UnitTypes unitTypes { get; set; }

        [XmlElement("Maximums")]
        public Maximums maximums { get; set; }

        [XmlElement("Minumums")]
        public Minimums minimums { get; set; }

        public static StatConfiguration Load(string sourcePath)
        {
            XmlSerializer deserializer = new XmlSerializer(typeof(StatConfiguration));
            TextReader reader = new StreamReader(sourcePath);

            object obj = deserializer.Deserialize(reader);
            StatConfiguration XmlData = (StatConfiguration)obj;
            reader.Close();

            return XmlData;
        }
    }
}
