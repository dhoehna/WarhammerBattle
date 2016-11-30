using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Serialization;

namespace WarhammerBattleGenerator.Configurations
{
    public class Maximums
    {
        [XmlElement("Maximum")]
        public List<Maximum> maximums { get; set; }
    }
}
