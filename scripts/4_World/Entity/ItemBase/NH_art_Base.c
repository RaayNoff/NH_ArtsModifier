modded class NH_art_Base extends ItemBase
{
	int GetModifierID()
	{
		return ConfigGetInt("ArtModifier");	
	}
	
	bool FindAnotherArtefact(ItemBase artefact, PlayerBase player)
	{
		ItemBase itm = MiscGameplayFunctions.FindItemInInventory(artefact.GetType(), player);
		if(itm)
		{
			EntityAI parent = itm.GetParent();
			if(parent)
			{
				if(parent.IsInherited(NH_ArtContainerBase))
				{
					return false;
				}
				else 
				{
					return true;
				}	
			}
		}
		return false;
	}
	
	override void EEItemLocationChanged(notnull InventoryLocation oldLoc, notnull InventoryLocation newLoc)
	{
		super.EEItemLocationChanged(oldLoc, newLoc);
	
		if(GetGame().IsServer())
		{
			PlayerBase new_player;
			PlayerBase old_player;
			
			Print("Art modif id: " + GetModifierID());
			Print("newLoc.GetParent(): " + newLoc.GetParent());
			
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
			
			Print("		new_player: " + new_player);
			Print("		old_player: " + old_player);
			
			if(new_player)
			{
				Print("if new player passed ");
				EntityAI parent = newLoc.GetParent();
				
				if(!parent.IsInherited(NH_ArtContainerBase))
					new_player.GetModifiersManager().ActivateModifier(GetModifierID());
				else
					new_player.GetModifiersManager().DeactivateModifier(GetModifierID());
			}	
			
			if(old_player && (old_player != new_player))
			{
				ItemBase artefact = ItemBase.Cast(oldLoc.GetItem());
				
				Print("artefact :: " + artefact);
				Print("artefactType :: " + artefact.GetType());
				//Print("Condition :: " + MiscGameplayFunctions.FindItemInInventory(artefact.GetType(), old_player));
				
				//if(!FindAnotherArtefact(artefact, old_player))
					old_player.GetModifiersManager().DeactivateModifier(GetModifierID());
				
			}
		}
	}
}