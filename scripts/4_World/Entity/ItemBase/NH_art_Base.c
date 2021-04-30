modded class NH_art_Base extends ItemBase
{
	int GetModifierID()
	{
		NHDebugPrint("NH_art_Base :: GetModifierID");
		return ConfigGetInt("ArtModifier");	
	}
	
	bool GetDeactivateCondition(PlayerBase player, ItemBase art)
	{
		NHDebugPrint("NH_art_Base :: GetDeactivateCondition");
		array<NH_art_Base> artsInInventory = MiscGameplayFunctions.GetArtefacts(player);
		array<NH_art_Base> sanitaziedArtsInInvenroty = new array<NH_art_Base>;
				
		if(artsInInventory)
		{
			if(artsInInventory.Count() >= 1)
			{
				foreach(NH_art_Base artInInventory : artsInInventory)
				{
					if(artInInventory.GetType() == art.GetType())
					{
						sanitaziedArtsInInvenroty.Insert(artInInventory);
					}
				}
			}
			 
			foreach(NH_art_Base sanitaziedArtInInvenroty : sanitaziedArtsInInvenroty)
			{
				EntityAI parent = sanitaziedArtInInvenroty.GetParent();
				if(!parent.IsInherited(NH_ArtContainerBase))
				{
					return false;
				}
			}
		}
		
		return true;
	}
	
	
	
	override void EEItemLocationChanged(notnull InventoryLocation oldLoc, notnull InventoryLocation newLoc)
	{
		super.EEItemLocationChanged(oldLoc, newLoc);
		NHDebugPrint("NH_art_Base :: EEItemLocationChanged");
	
		if(GetGame().IsServer())
		{
			PlayerBase new_player;
			PlayerBase old_player;

			ItemBase itm_new = ItemBase.Cast(newLoc.GetParent());
			ItemBase itm_old = ItemBase.Cast(oldLoc.GetParent());
			
			if(!itm_new)
				new_player = PlayerBase.Cast(newLoc.GetParent());
			else
				new_player = PlayerBase.Cast(newLoc.GetParent().GetHierarchyRootPlayer());
			
			if(!itm_old)
				old_player = PlayerBase.Cast(oldLoc.GetParent());
			else
				old_player = PlayerBase.Cast(oldLoc.GetParent().GetHierarchyRootPlayer());
			
			ItemBase artefact = ItemBase.Cast(newLoc.GetItem());
			
			if(new_player)
			{
				EntityAI parent = newLoc.GetParent();
				
				if(!parent.IsInherited(NH_ArtContainerBase))
				{
					new_player.GetModifiersManager().ActivateModifier(GetModifierID());
				}
				else
				{
					if(GetDeactivateCondition(new_player, artefact)
						new_player.GetModifiersManager().DeactivateModifier(GetModifierID());
				}
			}	
			
			if(old_player && (old_player != new_player))
			{				
				if(GetDeactivateCondition(old_player, artefact))
					old_player.GetModifiersManager().DeactivateModifier(GetModifierID());
				
			}
		}
	}
}