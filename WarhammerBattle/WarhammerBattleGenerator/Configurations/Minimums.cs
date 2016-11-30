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

        public int GetMinimum(string name)
        {
            Minimum minimumValue =  minumum.FirstOrDefault(x => x.name.Equals(name, StringComparison.OrdinalIgnoreCase));

            if(minimumValue != null)
            {
                return minimumValue.minimum;
            }
            else
            {
                return 1;
            }
        }
    }
}
