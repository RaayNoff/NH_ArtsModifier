class NHArtModifierSoul: ModifierBase
{
	private float m_Time;
	
	override void Init()
	{
		Print("NHArtModifier::Init");
		m_TrackActivatedTime 	= true;
		m_IsPersistent 			= false;
		m_ID 					= NHArtefactsModifiers.MDF_ART_SOUL;
		m_TickIntervalInactive 	= DEFAULT_TICK_TIME_INACTIVE;
		m_TickIntervalActive 	= 1;
		m_Time					= 0.0;	
	}
	
	override void OnActivate(PlayerBase player)
	{
		if(MiscGameplayFunctions.GetPDAs(player))
			NH_NotificationsManager.SendNotificationToPlayerIdentity(player.GetIdentity(), 3, "Обнаружено радиационное излучение", "рекомендуется использование контейнера.");
	}

	override void OnDeactivate(PlayerBase player)
	{
		if(MiscGameplayFunctions.GetPDAs(player))
		NH_NotificationsManager.SendNotificationToPlayerIdentity(player.GetIdentity(), 3, "Модификатор деактивирован!", "Пиздец");
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
		if(GetGame().IsServer())
		{
			if(m_Time > 2.0)
			{	
				player.SetHealth("GlobalHealth", "Health", player.GetHealth("GlobalHealth", "Health") - 0.5);
				player.SetHealth("GlobalHealth", "Health", player.GetHealth("", "Blood") - 20);
				m_Time = 0.0;
			}
		}
	}
}