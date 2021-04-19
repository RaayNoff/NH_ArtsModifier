class NHArtModifier: ModifierBase
{
	private float m_Time;
	override void Init()
	{
		Print("NHArtModifier::Init");
		m_TrackActivatedTime 	= true;
		m_IsPersistent 			= true;
		m_ID 					= NHModifiers1.MDF_ART_Modifier;
		m_TickIntervalInactive 	= DEFAULT_TICK_TIME_INACTIVE;
		m_TickIntervalActive 	= 1;
		m_Time					= 0.0;	
	}
	
	override void OnReconnect(PlayerBase player)
	{
		Print("ArtMdfr::OnReconnect");
		OnActivate(player);
	}
	
	override void OnActivate(PlayerBase player)
	{		
		Print("ArtMdfr::OnActivate");
		player.OnEnterRadiation();
		//player.SetPsiInside();
	}
	
	override bool ActivateCondition(PlayerBase player)
	{
		Print("ArtMdfr::ActivateCondition");
		if(player) return true;
		return false;
	}
	
	override private void OnTick(PlayerBase player, float deltaT)
	{
		m_Time += deltaT;
		if(m_Time > 0.33)
		{	
			player.GetStaminaHandler().SetStamina(100);
			m_Time = 0;
		}
	}
	
	override void OnDeactivate(PlayerBase player)
	{
		player.OnLeaveRadiation();
		Print("ArtMdfr::OnDeactivate");
	}
	
	override bool DeactivateCondition(PlayerBase player)
	{
		Print("ArtMdfr::DeactivateCondition");
		if(player) return false;
		return true;
	}
}