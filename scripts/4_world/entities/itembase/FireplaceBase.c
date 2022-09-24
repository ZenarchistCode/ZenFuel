modded class FireplaceBase
{
	// Define gasoline fuel fire consumable
	const static string ATT_FIREFUEL = "ZenFuel";
	typename ATTACHMENT_ZENFUEL = Zen_FireFuel;

	// Create new consumable type
	void FireplaceBase()
	{
		m_FireConsumableTypes.Insert(ATTACHMENT_ZENFUEL, new FireConsumableType(ATTACHMENT_ZENFUEL, 500, true, ATT_FIREFUEL));
	}

	// Lock fuel once it's on fire
	override void EEItemAttached(EntityAI item, string slot_name)
	{
		super.EEItemAttached(item, slot_name);

		if (item.IsInherited(Zen_FireFuel))
		{
			GetInventory().SetSlotLock(InventorySlots.GetSlotIdFromString(slot_name), true);
		}
	}

	// Don't allow taking fireplace if it's doused in fuel
	override bool CanPutInCargo(EntityAI parent)
	{
		ItemBase item = ItemBase.Cast(FindAttachmentBySlotName(ATT_FIREFUEL));
		if (item && item.IsInherited(Zen_FireFuel))
		{
			return false;
		}

		return super.CanPutInCargo(parent);
	}

	// Don't allow taking fireplace if it's doused in fuel
	override bool CanPutIntoHands(EntityAI parent)
	{
		ItemBase item = ItemBase.Cast(FindAttachmentBySlotName(ATT_FIREFUEL));
		if (item && item.IsInherited(Zen_FireFuel))
		{
			return false;
		}

		return super.CanPutIntoHands(parent);
	}

	// Only display gasoline category after fireplace has been doused in fuel
	override bool CanDisplayAttachmentCategory(string category_name)
	{
		if (category_name == "Gasoline")
		{
			ItemBase item = ItemBase.Cast(FindAttachmentBySlotName(ATT_FIREFUEL));
			if (item && item.IsInherited(Zen_FireFuel))
			{
				return true;
			}
			else
			{
				return false;
			}
		}

		return super.CanDisplayAttachmentCategory(category_name);
	}

	// Check if all wooden sticks/firewood has been detached, if so delete fuel
	override void EEItemDetached(EntityAI item, string slot_name)
	{
		super.EEItemDetached(item, slot_name);

		if (GetFuelCount() == 0)
		{
			ItemBase fuel = ItemBase.Cast(FindAttachmentBySlotName(ATT_FIREFUEL));
			if (fuel && fuel.IsInherited(Zen_FireFuel))
			{
				GetGame().ObjectDelete(fuel);
			}
		}
	}

	// If fire has stopped, delete gasoline attachment
	override void StopFire(FireplaceFireState fire_state = FireplaceFireState.END_FIRE)
	{
		super.StopFire(fire_state);

		// If gas exists, delete
		ItemBase fuel = ItemBase.Cast(FindAttachmentBySlotName(ATT_FIREFUEL));
		if (fuel && fuel.IsInherited(Zen_FireFuel))
		{
			GetGame().ObjectDelete(fuel);
		}
	}

	// Returns fuel item count
	int GetFuelCount_ZenFireFuel()
	{
		return GetFuelCount();
	}
};