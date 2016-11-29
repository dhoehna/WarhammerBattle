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

namespace WarhammerBattleGenerator
{
    public partial class Form1 : Form
    {
        const string STAT_FILE = "stats.xml";
        private StatCollection statCollection { get; set; }
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

        }

        private void Form1_SaveUnits(object sender, FormClosingEventArgs e)
        {
            statCollection.Save(STAT_FILE);
        }
    }
}
