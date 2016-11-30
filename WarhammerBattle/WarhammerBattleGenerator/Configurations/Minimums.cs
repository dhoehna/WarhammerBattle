using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Serialization;

namespace WarhammerBattleGenerator.Configurations
{
    public class Minimums
    {
        [XmlElement("Minimum")]
        public List<Minimum> minumum { get; set; }
    }
}
