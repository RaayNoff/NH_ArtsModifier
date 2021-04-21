class NHArtModifierFireball: ModifierBase
{	
	override void Init()
	{
		Print("NHArtModifier::Init");
		m_TrackActivatedTime 	= true;
		m_IsPersistent 			= false;
		m_ID 					= NHArtefactsModifiers.MDF_ART_FIREBALL;
		m_TickIntervalInactive 	= DEFAULT_TICK_TIME_INACTIVE;
		m_TickIntervalActive 	= 1;
	}
	
	override void OnActivate(PlayerBase player)
	{
		player.GetStatHeatComfort().Set(2);
	}

	override void OnDeactivate(PlayerBase player)
	{
		player.GetStatHeatComfort().Set(0);
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
		
		player.GetStatHeatBuffer().Set(currentheat + (NHArtefactsModifiersValues.HEATBUFFER_INCREMENT_PER_SEC * deltaT));
	}
}