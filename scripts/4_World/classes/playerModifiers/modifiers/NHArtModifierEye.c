class NHArtModifierEye: ModifierBase
{
	int m_Time;
	override void Init()
	{
		Print("NHArtModifierEye::Init");
		m_TrackActivatedTime 	= true;
		m_IsPersistent 			= false;
		m_ID 					= NHArtefactsModifiers.MDF_ART_EYE;
		m_TickIntervalInactive 	= DEFAULT_TICK_TIME_INACTIVE;
		m_TickIntervalActive 	= 1;
		m_Time					= 0;
	}
	
	override void OnActivate(PlayerBase player)
	{
		NHDebugPrint("NHArtModifierEye :: OnActivate");
	}

	override void OnDeactivate(PlayerBase player)
	{
		NHDebugPrint("NHArtModifierEye :: OnDeactivate");
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
		m_Time += deltaT;
		player.GetAdditionalHealth().AddHealth("Radiation", NHArtefactsModifiersValues.RADIATION_INCREMENT_PER_SEC * deltaT);
		
		if(player.IsBleeding())
		{
			if(m_Time > 5)
			{
				player.SetBleedingBits(player.GetBleedingBits() - 1);
				m_Time = 0;
			}
		}
	}
}