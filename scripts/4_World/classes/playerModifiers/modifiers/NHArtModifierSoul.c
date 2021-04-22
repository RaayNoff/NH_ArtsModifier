class NHArtModifierSoul: ModifierBase
{		
	override void Init()
	{
		Print("NHArtModifier::Init");
		m_TrackActivatedTime 	= true;
		m_IsPersistent 			= false;
		m_ID 					= NHArtefactsModifiers.MDF_ART_SOUL;
		m_TickIntervalInactive 	= DEFAULT_TICK_TIME_INACTIVE;
		m_TickIntervalActive 	= 1;
	}
	
	override void OnActivate(PlayerBase player)
	{
		Print("NHArtModifierSoul :: OnActivate");
	}
	override void OnDeactivate(PlayerBase player)
	{
		Print("NHArtModifierSoul :: OnDeactivate");
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
			Print("NHArtModifierSoul :: OnTick");	
			float currenthealth = player.GetHealth("GlobalHealth", "Health");
			float currentblood  = player.GetHealth("", "Blood");
		
			player.SetHealth("GlobalHealth", "Health", (currenthealth + (NHArtefactsModifiersValues.HEALTH_INCREMENT_PER_SEC * deltaT)));
			player.SetHealth("", "Blood", (currentblood + (NHArtefactsModifiersValues.BLOOD_INCREMENT_PER_SEC * deltaT)));
			player.GetStaminaHandler().SetStamina(100);
	}
}