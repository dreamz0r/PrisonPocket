modded class PlayerBase
{
	override void EEItemAttached(EntityAI item, string slot_name)
	{
		super.EEItemAttached(item, slot_name);

		if (slot_name == "PrisonPocket")
			PrisonPocket_OnSlotUsed();
	}

	override void EEItemDetached(EntityAI item, string slot_name)
	{
		super.EEItemDetached(item, slot_name);

		if (slot_name == "PrisonPocket")
			PrisonPocket_OnSlotUsed();
	}

	override bool CanReceiveAttachment(EntityAI attachment, int slotId)
	{
		if (!super.CanReceiveAttachment(attachment, slotId))
			return false;

		if (InventorySlots.GetSlotName(slotId) != "PrisonPocket")
			return true;

		return PrisonPocket_IsItemAllowed(attachment);
	}

	protected bool PrisonPocket_IsItemAllowed(EntityAI attachment)
	{
		if (!attachment)
			return false;

		PrisonPocketConfig config = PrisonPocketConfig.Get();
		if (!config)
			return false;

		string attachmentType = attachment.GetType();
		foreach (string allowedItem: config.AllowedItems)
		{
			if (attachmentType == allowedItem || GetGame().IsKindOf(attachmentType, allowedItem))
				return true;
		}

		return false;
	}

	protected void PrisonPocket_OnSlotUsed()
	{
		if (!GetGame().IsServer())
			return;

		PrisonPocket_TryCauseBleeding();
	}

	protected void PrisonPocket_TryCauseBleeding()
	{
		if (!GetBleedingManagerServer())
			return;

		float bleedChance = 0.0;
		PrisonPocketConfig config = PrisonPocketConfig.Get();
		if (config)
			bleedChance = config.BleedChance;

		bleedChance = Math.Clamp(bleedChance, 0.0, 1.0);
		if (bleedChance <= 0.0 || m_BleedingSourcesUp.Count() == 0 || Math.RandomFloat01() > bleedChance)
			return;

		int bleedSourceIndex = Math.RandomIntInclusive(0, m_BleedingSourcesUp.Count() - 1);
		GetBleedingManagerServer().AttemptAddBleedingSourceBySelection(m_BleedingSourcesUp[bleedSourceIndex]);
	}
};
