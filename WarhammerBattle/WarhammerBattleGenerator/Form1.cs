using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;
using System.Xml.Linq;
using WarhammerBattleGenerator.Configurations;

namespace WarhammerBattleGenerator
{
    public partial class Form1 : Form
    {
        const string STAT_FILE = "stats.xml";
        const string STAT_CONFIGURATION = "../Debug/Configurations/StatConfiguration.xml";
        private StatCollection statCollection { get; set; }

        private StatConfiguration statConfiguration { get; set; }
        public Form1()
        {
            InitializeComponent();

            if(!File.Exists(STAT_FILE))
            {
                File.Create(STAT_FILE);
                statCollection = new StatCollection();
            }
            else
            {
                statCollection = StatCollection.PullInfoFromConfig(STAT_FILE);
            }

            statConfiguration = StatConfiguration.Load(STAT_CONFIGURATION);
        }


        private void Form1_SaveUnits(object sender, FormClosingEventArgs e)
        {
            statCollection.Save(STAT_FILE);
        }
    }
}
