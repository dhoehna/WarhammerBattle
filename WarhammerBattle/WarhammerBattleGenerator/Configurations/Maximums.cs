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

        public int GetMaximum(string name)
        {
            Maximum maximumValue = maximums.FirstOrDefault(x => x.name.Equals(name, StringComparison.OrdinalIgnoreCase));

            if (maximumValue != null)
            {
                return maximumValue.maximum;
            }
            else
            {
                return 1;
            }
        }
    }
}
