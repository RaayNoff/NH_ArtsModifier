class NHArtModifierVivert: ModifierBase
{
	private float m_Time;
	
	override void Init()
	{
		Print("NHArtModifier::Init");
		m_TrackActivatedTime 	= true;
		m_IsPersistent 			= false;
		m_ID 					= NHArtefactsModifiers.MDF_ART_VIVERT;
		m_TickIntervalInactive 	= DEFAULT_TICK_TIME_INACTIVE;
		m_TickIntervalActive 	= 1;
		m_Time					= 0.0;	
	}
	
	override void OnActivate(PlayerBase player)
	{
		NH_NotificationsManager.SendNotificationToPlayerIdentity(player.GetIdentity(), 3, "Модификатор активирован!", "Ура");
	}

	override void OnDeactivate(PlayerBase player)
	{
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
		if(m_Time > 0.33)
		{	
			player.GetStaminaHandler().SetStamina(100);
			m_Time = 0.0;
		}
	}
}