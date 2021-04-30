class NHArtModifierFireball: ModifierBase
{	
	override void Init()
	{
		NHDebugPrint("NHArtModifierFireball::Init");
		m_TrackActivatedTime 	= true;
		m_IsPersistent 			= false;
		m_ID 					= NHArtefactsModifiers.MDF_ART_FIREBALL;
		m_TickIntervalInactive 	= DEFAULT_TICK_TIME_INACTIVE;
		m_TickIntervalActive 	= 1;
	}
	
	override void OnActivate(PlayerBase player)
	{
		NHDebugPrint("NHArtModifierFireball :: OnActivate");
	}

	override void OnDeactivate(PlayerBase player)
	{
		NHDebugPrint("NHArtModifierFireball :: OnDeactivate");
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
		float currentheat = player.GetStatHeatBuffer().Get();
		float currentHeatComfort = player.GetStatHeatComfort().Get();
		
		player.GetStatHeatComfort().Set(currentHeatComfort + (NHArtefactsModifiersValues.HEATCOMFORT_INCREMENT_PER_SEC * deltaT));
		player.GetStatHeatBuffer().Set(currentheat + (NHArtefactsModifiersValues.HEATBUFFER_INCREMENT_PER_SEC * deltaT));
	}
}