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


            typeComboBox.DataSource = statConfiguration.unitTypes.types;
            InsertNumbersIntoComboBox(weaponSkillComboBox, "weaponSkill");
            InsertNumbersIntoComboBox(ballisticSkillComboBox, "ballisticSkill");
            InsertNumbersIntoComboBox(strengthComboBox, "strength");
            InsertNumbersIntoComboBox(toughnessComboBox, "toughness");
            InsertNumbersIntoComboBox(attacksComboBox, "attacks");
            InsertNumbersIntoComboBox(woundsComboBox, "wounds");
            InsertNumbersIntoComboBox(initiativeComboBox, "initiative");
            InsertNumbersIntoComboBox(leadershipComboBox, "leadership");
            InsertNumbersIntoComboBox(saveComboBox, "save");

        }


        private void Form1_SaveUnits(object sender, FormClosingEventArgs e)
        {
            statCollection.Save(STAT_FILE);
        }

        private void InsertNumbersIntoComboBox(ComboBox comboBox, string statName)
        {
            int minimumStat = statConfiguration.minimums.GetMinimum(statName);
            int maximumStat = statConfiguration.maximums.GetMaximum(statName);

            for(int index = minimumStat; index <= maximumStat; index++)
            {
                comboBox.Items.Add(index);
            }
        }

        private void Form1_DeleteUnit(object sender, EventArgs e)
        {

        }

        private void Form1_SaveUnit(object sender, EventArgs e)
        {
            Stats newStats = new Stats();

            
            newStats.name = unitNameComboBox.Text;
            newStats.weaponSkill = Convert.ToInt32(weaponSkillComboBox.SelectedItem);
            newStats.ballisticSkill = Convert.ToInt32(ballisticSkillComboBox.SelectedItem);
            newStats.strength = Convert.ToInt32(strengthComboBox.SelectedItem);
            newStats.toughness = Convert.ToInt32(toughnessComboBox.SelectedItem);
            newStats.attacks = Convert.ToInt32(attacksComboBox.SelectedItem);
            newStats.wounds = Convert.ToInt32(woundsComboBox.SelectedItem);
            newStats.initiative = Convert.ToInt32(initiativeComboBox.SelectedItem);
            newStats.leadership = Convert.ToInt32(leadershipComboBox.SelectedItem);
            newStats.save = Convert.ToInt32(saveComboBox.SelectedItem);

            statCollection.Add(newStats);
        }
    }
}
