modded class NH_art_Base extends ItemBase
{
	int						m_ModifierID = NHModifiers1.MDF_ART_Modifier;
	protected PlayerBase	m_ModifiedPlayer;
	
	override void EEItemLocationChanged(notnull InventoryLocation oldLoc, notnull InventoryLocation newLoc)
	{
		super.EEItemLocationChanged(oldLoc, newLoc);
		PlayerBase	old_player;
		PlayerBase	new_player;
		
		new_player = PlayerBase.Cast(newLoc.GetParent().GetHierarchyRootPlayer());
		old_player = PlayerBase.Cast(oldLoc.GetParent().GetHierarchyRootPlayer());
			
		if(new_player)
		{
			EntityAI parent = newLoc.GetParent();
			
			if(!parent.IsInherited(NH_ArtContainerBase))
			{
				if(!m_ModifiedPlayer)
				{
					new_player.GetModifiersManager().ActivateModifier(m_ModifierID);
					m_ModifiedPlayer = new_player;
					Print("Modifier has been added");
				}
				else
				{
					Print("Player has attached art in different slot");
				}
				return;
			}
			else if(parent.IsInherited(NH_ArtContainerBase))
			{
				if(m_ModifiedPlayer)
				{
					m_ModifiedPlayer.GetModifiersManager().DeactivateModifier(m_ModifierID);
					m_ModifiedPlayer = null;
					Print("Modifier was deleted");
				}
				return;
			}
			
		}
		
		if(old_player && (old_player != new_player))
		{
			m_ModifiedPlayer.GetModifiersManager().DeactivateModifier(m_ModifierID);
			Print("Player dropped an art " + m_ModifiedPlayer.ToString());
			m_ModifiedPlayer = null;
		}		
	}
	
	int GetModifierID()
	{
		return 1;
	}
}