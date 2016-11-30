﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Serialization;

namespace WarhammerBattleGenerator
{
    public class Unit
    {
        [XmlElement("unitName")]
        public string unitName { get; set; }

        [XmlElement("unitType")]
        public string unitType { get; set; }

        [XmlElement("stats")]
        public Stats stats { get; set; }
    }
}
