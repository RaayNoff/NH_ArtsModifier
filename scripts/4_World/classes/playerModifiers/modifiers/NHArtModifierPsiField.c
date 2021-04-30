class NHArtModifierPsiField: ModifierBase
{
	
	override void Init()
	{
		Print("NHArtModifierPsiField::Init");
		m_TrackActivatedTime 	= true;
		m_IsPersistent 			= false;
		m_ID 					= NHArtefactsModifiers.MDF_ART_PSI_FIELD;
		m_TickIntervalInactive 	= DEFAULT_TICK_TIME_INACTIVE;
		m_TickIntervalActive 	= 1;
	}
	
	override void OnActivate(PlayerBase player)
	{
		NHDebugPrint("NHArtModifierPsiField :: OnActivate");
	}

	override void OnDeactivate(PlayerBase player)
	{
		NHDebugPrint("NHArtModifierPsiField :: OnDeactivate");
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
		player.GetAdditionalHealth().AddHealth("Mental", NHArtefactsModifiersValues.MENTAL_DECREMENT_PER_SEC * deltaT);
		player.GetAdditionalHealth().AddHealth("Psi", NHArtefactsModifiersValues.PSI_DECREMENT_PER_SEC * deltaT);
	}
}