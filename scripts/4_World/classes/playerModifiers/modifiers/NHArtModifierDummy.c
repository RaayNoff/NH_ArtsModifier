class NHArtModifierDummy: ModifierBase
{
	
	override void Init()
	{
		NHDebugPrint("NHArtModifierDummy::Init");
		m_TrackActivatedTime 	= true;
		m_IsPersistent 			= false;
		m_ID 					= NHArtefactsModifiers.MDF_ART_DUMMY_DUMMY;
		m_TickIntervalInactive 	= DEFAULT_TICK_TIME_INACTIVE;
		m_TickIntervalActive 	= 1;
	}
	
	override void OnActivate(PlayerBase player)
	{
		NHDebugPrint("NHArtModifierDummy :: OnActivate");
	}

	override void OnDeactivate(PlayerBase player)
	{
		NHDebugPrint("NHArtModifierDummy :: OnDeactivate");
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
		player.GetAdditionalHealth().AddHealth( NHArtefactsModifiersValues.MENTAL_INCREMENT_PER_SEC * deltaT );
	}
}