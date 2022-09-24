class CfgPatches
{
	class ZenFireFuel
	{
		requiredVersion = 0.1;
		requiredAddons[] =
		{
			"DZ_Data",
			"DZ_Gear_Cooking"
		};
		units[] =
		{
			"Zen_FireFuel",
		};
	};
};

class CfgMods
{
	class ZenFireFuel
	{
		dir = "ZenFireFuel";
		picture = "";
		action = "";
		hideName = 1;
		hidePicture = 1;
		name = "ZenFireFuel";
		credits = "";
		author = "Zenarchist";
		authorID = "0";
		version = "1.0";
		extra = 0;
		type = "mod";
		dependencies[] = { "Game","World","Mission" };
		class defs
		{
			class gameScriptModule
			{
				value = "";
				files[] = { "ZenFireFuel/scripts/3_Game"; };
			};
			class worldScriptModule
			{
				value = "";
				files[] = { "ZenFireFuel/scripts/4_World" };
			};
			class missionScriptModule
			{
				value = "";
				files[] = { "ZenFireFuel/scripts/5_Mission" };
			};
		};
	};
};

class CfgVehicles
{
	// Define fire fuel object. This object is locked to fire when poured so players should never be able to interact with it unless it's spawned in by an admin
	class Inventory_Base;
	class Zen_FireFuel : Inventory_Base
	{
		scope = 2;
		itemSize[] = { 1,1 };
		model = "\dz\vehicles\parts\JerryCan.p3d";
		displayName = "$STR_ZenFireFuel0";
		descriptionShort = "$STR_ZenFireFuel1";
		inventorySlot[] = { "ZenFuel" };
		canBeSplit = 0;
		varQuantityInit = 1;
		varQuantityMin = 0;
		varQuantityMax = 1;
		varQuantityDestroyOnMin = 1;
	};

	// Add fuel attachment to fireplaces
	class FireplaceBase;
	class Fireplace : FireplaceBase
	{
		attachments[] +=
		{
			"ZenFuel"
		};
		class GUIInventoryAttachmentsProps
		{
			class Gasoline
			{
				name = "$STR_ZenFireFuel0";
				description = "";
				attachmentSlots[] =
				{
					"ZenFuel"
				};
				icon = "gascanister";
				view_index = 7;
			}
		}
	};
	class FireplaceIndoor : FireplaceBase
	{
		attachments[] +=
		{
			"ZenFuel"
		};
		class GUIInventoryAttachmentsProps
		{
			class Gasoline
			{
				name = "$STR_ZenFireFuel0";
				description = "";
				attachmentSlots[] =
				{
					"ZenFuel"
				};
				icon = "gascanister";
				view_index = 7;
			}
		}
	};
	class OvenIndoor : FireplaceBase
	{
		attachments[] +=
		{
			"ZenFuel"
		};
		class GUIInventoryAttachmentsProps
		{
			class Gasoline
			{
				name = "$STR_ZenFireFuel0";
				description = "";
				attachmentSlots[] =
				{
					"ZenFuel"
				};
				icon = "gascanister";
				view_index = 7;
			}
		}
	};
	class BarrelHoles_ColorBase : FireplaceBase
	{
		attachments[] +=
		{
			"ZenFuel"
		};
		class GUIInventoryAttachmentsProps
		{
			class Gasoline
			{
				name = "$STR_ZenFireFuel0";
				description = "";
				attachmentSlots[] =
				{
					"ZenFuel"
				};
				icon = "gascanister";
				view_index = 7;
			}
		}
	}
};

class CfgSlots
{
	class Slot_ZenFuel
	{
		name = "ZenFuel";
		displayName = "$STR_ZenFireFuel0";
		ghostIcon = "gascanister";
	};
};
