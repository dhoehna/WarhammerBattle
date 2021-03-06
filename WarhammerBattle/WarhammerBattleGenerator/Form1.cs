﻿using System;
using System.IO;
using System.Windows.Forms;
using WarhammerBattleGenerator.Configurations;

namespace WarhammerBattleGenerator
{
    public partial class Form1 : Form
    {
        const string UNITS_LOCATION = "units.xml";
        const string STAT_CONFIGURATION = "../Debug/Configurations/StatConfiguration.xml";
        private UnitCollection unitCollection { get; set; }

        private StatConfiguration statConfiguration { get; set; }
        public Form1()
        {
            InitializeComponent();

            if(!File.Exists(UNITS_LOCATION))
            {
                File.Create(UNITS_LOCATION);
                unitCollection = new UnitCollection();
            }
            else
            {
                unitCollection = UnitCollection.Load(UNITS_LOCATION);
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

            unitNameComboBox.Items.AddRange(unitCollection.GetUnitNames());

        }


        private void Form1_SaveUnits(object sender, FormClosingEventArgs e)
        {
            unitCollection.Save(UNITS_LOCATION);
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
            bool unitDeletedSuccessfully = unitCollection.Delete(unitNameComboBox.Text);

            if(unitDeletedSuccessfully)
            {
                MessageBox.Show("Unit deleted successfully", "Deletion Successful");
                ResetForm();
            }
            else
            {
                MessageBox.Show("Error with deleting unit", "Deletion not-successful");
            }
        }

        private void Form1_SaveUnit(object sender, EventArgs e)
        {
            Stats newStats = new Stats();

            newStats.weaponSkill = Convert.ToInt32(weaponSkillComboBox.SelectedItem);
            newStats.ballisticSkill = Convert.ToInt32(ballisticSkillComboBox.SelectedItem);
            newStats.strength = Convert.ToInt32(strengthComboBox.SelectedItem);
            newStats.toughness = Convert.ToInt32(toughnessComboBox.SelectedItem);
            newStats.attacks = Convert.ToInt32(attacksComboBox.SelectedItem);
            newStats.wounds = Convert.ToInt32(woundsComboBox.SelectedItem);
            newStats.initiative = Convert.ToInt32(initiativeComboBox.SelectedItem);
            newStats.leadership = Convert.ToInt32(leadershipComboBox.SelectedItem);
            newStats.save = Convert.ToInt32(saveComboBox.SelectedItem);

            Unit unit = new Unit();

            unit.unitName = unitNameComboBox.Text;
            unit.unitType = typeComboBox.SelectedItem.ToString();
            unit.stats = newStats;

            bool isUnitBeingAdded = unitCollection.DoesUnitExist(unit.unitName);

            bool wasAddedSuccessfully = unitCollection.AddOrUpdate(unit);


            if (isUnitBeingAdded)
            {
                if (wasAddedSuccessfully)
                {
                    MessageBox.Show("Unit added successfully");
                }
                else
                {
                    MessageBox.Show("Unit was not added");
                }
            }
            else
            {
                if (wasAddedSuccessfully)
                {
                    MessageBox.Show("Unit updated successfully");
                }
                else
                {
                    MessageBox.Show("Unit was not updated");
                }

            }
        }

        private void ResetForm()
        {
            FillFormWithUnit(Unit.MakeDefault());
            unitNameComboBox.Text = string.Empty;
        }

        private void DisplayUnit(object sender, EventArgs e)
        {
            string selectedUnitName = unitNameComboBox.SelectedItem.ToString();

            Unit selectedUnit = unitCollection.GetUnit(selectedUnitName);

            FillFormWithUnit(selectedUnit);
            

        }

        private void FillFormWithUnit(Unit unitToFill)
        {
            typeComboBox.SelectedText = unitToFill.unitType;

            weaponSkillComboBox.SelectedItem = unitToFill.stats.weaponSkill;
            ballisticSkillComboBox.SelectedItem = unitToFill.stats.ballisticSkill;
            strengthComboBox.SelectedItem = unitToFill.stats.strength;
            toughnessComboBox.SelectedItem = unitToFill.stats.toughness;
            woundsComboBox.SelectedItem = unitToFill.stats.wounds;
            attacksComboBox.SelectedItem = unitToFill.stats.attacks;
            initiativeComboBox.SelectedItem = unitToFill.stats.initiative;
            leadershipComboBox.SelectedItem = unitToFill.stats.leadership;
            saveComboBox.SelectedItem = unitToFill.stats.save;
        }
    }
}
