class NHArtModifierMedusa: ModifierBase
{	
	override void Init()
	{
		NHDebugPrint("NHArtModifierMedusa::Init");
		m_TrackActivatedTime 	= true;
		m_IsPersistent 			= false;
		m_ID 					= NHArtefactsModifiers.MDF_ART_MEDUSA;
		m_TickIntervalInactive 	= DEFAULT_TICK_TIME_INACTIVE;
		m_TickIntervalActive 	= 1;
	}
	
	override void OnActivate(PlayerBase player)
	{
		NHDebugPrint("NHArtModifierMedusa :: OnActivate");
	}

	override void OnDeactivate(PlayerBase player)
	{
		NHDebugPrint("NHArtModifierMedusa :: OnDeactivate");
	}
	
	override bool ActivateCondition(PlayerBase player)
	{
		return false;
	}
	
	override bool DeactivateCondition(PlayerBase player)
	{
		return false;
	}
	
	override private void OnTick(PlayerBase player, float deltaT)
	{
		float currentBlood = player.GetHealth("", "Blood");
		float currentShock = player.GetHealth("", "Shock");
		
		player.SetHealth("", "Shock", currentShock + (NHArtefactsModifiersValues.SHOCK_INCREMENT_PER_SEC * deltaT));
		
		if(player.IsBleeding())
		{
			switch(player.GetBleedingBits())
			{
				case 0: 
					break;
				case 1: 
					player.SetHealth("", "Blood", currentBlood + ( 2.0 * deltaT));
					break;
				case 2: 
					player.SetHealth("", "Blood", currentBlood + ( 4.0 * deltaT));
					break;
				default:
					player.SetHealth("", "Blood", currentBlood + ( 8.0 * deltaT));
					break;
			}
		}
	}
}