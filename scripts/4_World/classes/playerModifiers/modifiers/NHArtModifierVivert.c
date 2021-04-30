class NHArtModifierVivert: ModifierBase
{
	
	override void Init()
	{
		NHDebugPrint("NHArtModifierVivert::Init");
		m_TrackActivatedTime 	= true;
		m_IsPersistent 			= false;
		m_ID 					= NHArtefactsModifiers.MDF_ART_VIVERT;
		m_TickIntervalInactive 	= DEFAULT_TICK_TIME_INACTIVE;
		m_TickIntervalActive 	= 1;
	}
	
	override void OnActivate(PlayerBase player)
	{
		NHDebugPrint("NHArtModifierVivert :: OnActivate");
	}

	override void OnDeactivate(PlayerBase player)
	{
		NHDebugPrint("NHArtModifierVivert :: OnDeactivate");
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
		player.GetAdditionalHealth().AddHealth("Radiation", (NHArtefactsModifiersValues.RADIATION_INCREMENT_PER_SEC * deltaT));
		player.GetAdditionalHealth().AddHealth("Psi", (NHArtefactsModifiersValues.PSI_DECREMENT_PER_SEC * deltaT));
	}
}