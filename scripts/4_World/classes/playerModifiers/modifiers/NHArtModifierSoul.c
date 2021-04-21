class NHArtModifierSoul: ModifierBase
{	
	private static int HEALTH_INCREMENT_PER_SEC = 5;
	
	override void Init()
	{
		Print("NHArtModifier::Init");
		m_TrackActivatedTime 	= true;
		m_IsPersistent 			= false;
		m_ID 					= NHArtefactsModifiers.MDF_ART_SOUL;
		m_TickIntervalInactive 	= DEFAULT_TICK_TIME_INACTIVE;
		m_TickIntervalActive 	= 1;
	}
	
	override void OnActivate(PlayerBase player)
	{
		//if(MiscGameplayFunctions.GetPDAs(player))
		//	NH_NotificationsManager.SendNotificationToPlayerIdentity(player.GetIdentity(), 3, "Обнаружено радиационное излучение", "рекомендуется использование контейнера.");
		Print("Some shit");
	}

	override void OnDeactivate(PlayerBase player)
	{
		//if(MiscGameplayFunctions.GetPDAs(player))
		//NH_NotificationsManager.SendNotificationToPlayerIdentity(player.GetIdentity(), 3, "Модификатор деактивирован!", "Пиздец");
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
			float currenthealth = player.GetHealth("GlobalHealth", "Health");
		
			player.SetHealth("GlobalHealth", "Health", (currenthealth + (HEALTH_INCREMENT_PER_SEC * deltaT)));
	}
}