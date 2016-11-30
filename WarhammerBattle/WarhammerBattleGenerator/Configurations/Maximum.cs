using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Serialization;

namespace WarhammerBattleGenerator.Configurations
{
    public class Maximum
    {
        [XmlAttribute("name")]
        public string name { get; set; }

        [XmlAttribute("value")]
        public string maximum { get; set; }
    }
}
