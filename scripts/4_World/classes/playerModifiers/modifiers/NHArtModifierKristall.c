class NHArtModifierKristall: ModifierBase
{
	
	override void Init()
	{
		Print("NHArtModifierKristall::Init");
		m_TrackActivatedTime 	= true;
		m_IsPersistent 			= false;
		m_ID 					= NHArtefactsModifiers.MDF_ART_KRISTALL;
		m_TickIntervalInactive 	= DEFAULT_TICK_TIME_INACTIVE;
		m_TickIntervalActive 	= 1;
	}
	
	override void OnActivate(PlayerBase player)
	{
		NHDebugPrint("NHArtModifierKristall :: OnActivate");
	}

	override void OnDeactivate(PlayerBase player)
	{
		NHDebugPrint("NHArtModifierKristall :: OnDeactivate");
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
		float currentWater = player.GetStatWater().Get();
		float currentEnergy = player.GetStatEnergy().Get();
		float currentHealth = player.GetHealth("GlobalHealth", "Health");
		
		player.GetStatWater().Set( currentWater + ( NHArtefactsModifiersValues.WATER_INCREMENT_PER_SEC * deltaT ));
		player.GetStatEnergy().Set( currentEnergy + ( NHArtefactsModifiersValues.ENERGY_INCREMENT_PER_SEC * deltaT ));
		
		player.SetHealth("GlobalHealth", "Health", currentHealth + ( NHArtefactsModifiersValues.HEALTH_DECREMENT_PER_SEC * deltaT ));
	}
}