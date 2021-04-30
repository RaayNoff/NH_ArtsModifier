class NHArtModifierMeat: ModifierBase
{		
	override void Init()
	{
		NHDebugPrint("NHArtModifierMeat::Init");
		m_TrackActivatedTime 	= true;
		m_IsPersistent 			= false;
		m_ID 					= NHArtefactsModifiers.MDF_ART_MINCER_MEAT;
		m_TickIntervalInactive 	= DEFAULT_TICK_TIME_INACTIVE;
		m_TickIntervalActive 	= 1;
	}
	
	override void OnActivate(PlayerBase player)
	{
		NHDebugPrint("NHArtModifierMeat :: OnActivate");
	}
	override void OnDeactivate(PlayerBase player)
	{
		NHDebugPrint("NHArtModifierMeat :: OnDeactivate");
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
		player.GetAdditionalHealth().AddHealth("Mental", NHArtefactsModifiersValues.MENTAL_INCREMENT_PER_SEC * deltaT);
		player.GetAdditionalHealth().AddHealth("Radiation", NHArtefactsModifiersValues.RADIATION_INCREMENT_PER_SEC * deltaT);
		
	}
}