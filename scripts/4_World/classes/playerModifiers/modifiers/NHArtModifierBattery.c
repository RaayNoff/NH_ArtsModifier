class NHArtModifierBattery: ModifierBase
{
	override void Init()
	{
		Print("NHArtModifierBattery::Init");
		m_TrackActivatedTime 	= true;
		m_IsPersistent 			= false;
		m_ID 					= NHArtefactsModifiers.MDF_ART_DUMMY_BATTERY;
		m_TickIntervalInactive 	= DEFAULT_TICK_TIME_INACTIVE;
		m_TickIntervalActive 	= 1;
	}
	
	override void OnActivate(PlayerBase player)
	{
		NHDebugPrint("NHArtModifierBattery :: OnActivate");
	}

	override void OnDeactivate(PlayerBase player)
	{
		NHDebugPrint("NHArtModifierBattery :: OnDeactivate");
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
		float currentStamina = player.GetStaminaHandler().GetStamina();
		int currentBleedingBits = player.GetBleedingBits();
		
		player.GetStaminaHandler().SetStamina(currentStamina + (NHArtefactsModifiersValues.STAMINA_INCREMENT_PER_SEC * deltaT));
		
		if(currentBleedingBits < 1)
			player.SetBleedingBits(1);
	}
}