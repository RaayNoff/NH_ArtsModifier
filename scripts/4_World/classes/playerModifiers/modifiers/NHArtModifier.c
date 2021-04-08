class NHArtModifier: ModifierBase
{
	
	override void Init()
	{
		Print("NHArtModifier::Init");
		m_TrackActivatedTime 	= true;
		m_IsPersistent 			= true;
		m_ID 					= NHModifiers1.MDF_ART_Modifier;
		m_TickIntervalInactive 	= DEFAULT_TICK_TIME_INACTIVE;
		m_TickIntervalActive 	= 1;
	}
	
	override void OnReconnect(PlayerBase player)
	{
		Print("ArtMdfr::OnReconnect");
		OnActivate(player);
	}
	
	override void OnActivate(PlayerBase player)
	{		
		Print("ArtMdfr::OnActivate");
	}
	
	override bool ActivateCondition(PlayerBase player)
	{
		Print("ArtMdfr::ActivateCondition");
		return false;
	}
	
	override private void OnTick(PlayerBase player, float deltaT)
	{
		player.SetStamina(100, 100);
	}
	
	override void OnDeactivate(PlayerBase player)
	{
		Print("ArtMdfr::OnDeactivate");
	}
	
	override bool DeactivateCondition(PlayerBase player)
	{
		Print("ArtMdfr::DeactivateCondition");
		return false;
	}
}