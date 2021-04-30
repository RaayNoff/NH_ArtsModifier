class NHArtModifierFireball: ModifierBase
{	
	override void Init()
	{
		Print("NHArtModifierFireball::Init");
		m_TrackActivatedTime 	= true;
		m_IsPersistent 			= false;
		m_ID 					= NHArtefactsModifiers.MDF_ART_FIREBALL;
		m_TickIntervalInactive 	= DEFAULT_TICK_TIME_INACTIVE;
		m_TickIntervalActive 	= 1;
	}
	
	override void OnActivate(PlayerBase player)
	{
		Print("NHArtModifierFireball :: OnActivate");
	}

	override void OnDeactivate(PlayerBase player)
	{
		Print("NHArtModifierFireball :: OnDeactivate");
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
		//Print("NHArtModifierFireball :: OnTick");
		float currentheat = player.GetStatHeatBuffer().Get();
		float currentHeatComfort = player.GetStatHeatComfort().Get();
		
		//Print("currentheat :: " + currentheat);
		//Print("currentHeatComfort :: " + currentHeatComfort);		
		
		player.GetStatHeatComfort().Set(currentHeatComfort + (NHArtefactsModifiersValues.HEATCOMFORT_INCREMENT_PER_SEC * deltaT));
		player.GetStatHeatBuffer().Set(currentheat + (NHArtefactsModifiersValues.HEATBUFFER_INCREMENT_PER_SEC * deltaT));
	}
}