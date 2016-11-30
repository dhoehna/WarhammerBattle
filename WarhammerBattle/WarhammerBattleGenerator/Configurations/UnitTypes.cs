using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Serialization;

namespace WarhammerBattleGenerator.Configurations
{

    public class UnitTypes
    {
        [XmlElement("UnitType")]
        public List<string> types { get; set; }
    }
}
