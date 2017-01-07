using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Serialization;

namespace WarhammerBattleGenerator
{
    public class Stats
    {
        [XmlElement("weaponSkill")]
        public int weaponSkill { get; set; }

        [XmlElement("ballisticSkill")]
        public int ballisticSkill { get; set; }

        [XmlElement("strength")]
        public int strength { get; set; }

        [XmlElement("toughness")]
        public int toughness { get; set; }

        [XmlElement("wounds")]
        public int wounds { get; set; }

        [XmlElement("attacks")]
        public int attacks { get; set; }

        [XmlElement("initiative")]
        public int initiative { get; set; }

        [XmlElement("leadership")]
        public int leadership { get; set; }

        [XmlElement("save")]
        public int save { get; set; }

        public static Stats MakeDefaultStats()
        {
            Stats defaultStats = new Stats();

            defaultStats.weaponSkill = 1;
            defaultStats.ballisticSkill = 1;
            defaultStats.strength = 1;
            defaultStats.toughness = 1;
            defaultStats.wounds = 1;
            defaultStats.attacks = 1;
            defaultStats.initiative = 1;
            defaultStats.leadership = 1;
            defaultStats.save = 6;

            return defaultStats;
        }
        
    }
}
