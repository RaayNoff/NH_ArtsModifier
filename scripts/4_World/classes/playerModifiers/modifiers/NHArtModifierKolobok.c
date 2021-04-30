class NHArtModifierKolobok: ModifierBase
{
	
	override void Init()
	{
		NHDebugPrint("NHArtModifierKolobok::Init");
		m_TrackActivatedTime 	= true;
		m_IsPersistent 			= false;
		m_ID 					= NHArtefactsModifiers.MDF_ART_FUZZ_KOLOBOK;
		m_TickIntervalInactive 	= DEFAULT_TICK_TIME_INACTIVE;
		m_TickIntervalActive 	= 1;
		int m_Time				= 0;
	}
	
	override void OnActivate(PlayerBase player)
	{
		NHDebugPrint("NHArtModifierKolobok :: OnActivate");
	}

	override void OnDeactivate(PlayerBase player)
	{
		NHDebugPrint("NHArtModifierKolobok :: OnDeactivate");
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
		float currentHealth = player.GetHealth("GlobalHealth", "Health");
		
		player.SetHealth("GlobalHealth", "Health", currentHealth + ((NHArtefactsModifiersValues.HEALTH_INCREMENT_PER_SEC * deltaT) * 2.0));
		player.GetAdditionalHealth().AddHealth("Radiation", NHArtefactsModifiersValues.RADIATION_INCREMENT_PER_SEC * deltaT);
	}
}