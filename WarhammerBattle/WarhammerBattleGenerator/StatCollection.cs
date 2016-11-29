using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Serialization;

namespace WarhammerBattleGenerator
{
    public class StatCollection
    {

        [XmlElement("units")]
        public List<Stats> stats { get; set; }

        public static StatCollection PullInfoFromConfig(string sourcePath)
        {
            XmlSerializer deserializer = new XmlSerializer(typeof(StatCollection));
            TextReader reader = new StreamReader(sourcePath);

            object obj = deserializer.Deserialize(reader);
            StatCollection XmlData = (StatCollection)obj;
            reader.Close();

            return XmlData;
        }

        public void Save(string saveLocation)
        {
            XmlSerializer statSaver = new XmlSerializer(typeof(StatCollection));

            TextWriter writer = new StreamWriter(saveLocation);

            statSaver.Serialize(writer, this);
            writer.Dispose();
        }
    }
}
