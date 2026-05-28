class CfgPatches
{
	class PrisonPocket
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] =
		{
			"DZ_Data",
			"DZ_Scripts",
			"DZ_Characters",
			"DZ_Gear_Food"
		};
	};
};

class CfgMods
{
	class PrisonPocket
	{
		dir = "PrisonPocket";
		picture = "";
		action = "";
		hideName = 1;
		hidePicture = 1;
		name = "Prison Pocket";
		credits = "Griffin";
		author = "Griffin";
		authorID = "0";
		version = "1.0";
		type = "mod";
		dependencies[] = {"World","Mission"};

		class defs
		{
			class worldScriptModule
			{
				value = "";
				files[] = {"PrisonPocket/scripts/4_World"};
			};
			class missionScriptModule
			{
				value = "";
				files[] = {"PrisonPocket/scripts/5_Mission"};
			};
		};
	};
};

class CfgSlots
{
	class Slot_PrisonPocket
	{
		name = "PrisonPocket";
		displayName = "Prison Pocket";
		ghostIcon = "set:dayz_gui image:dot";
	};
};

class CfgVehicles
{
	class AllVehicles;
	class Man: AllVehicles {};
	class SurvivorBase: Man
	{
		attachments[] += {"PrisonPocket"};

		class InventoryEquipment
		{
			playerSlots[] += {"Slot_PrisonPocket"};
		};
	};

	class Edible_Base;
	class Zucchini: Edible_Base
	{
		inventorySlot[] += {"PrisonPocket"};
	};
};
